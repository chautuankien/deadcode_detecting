#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
// #include <set>  // Unused include

/**
 * Sample class containing various types of unused/dead code for detection testing
 */
class DeadCodeExample {
private:
    // Unused private member variable
    int unusedField = 42;
    
    // Used private member variable
    std::string name = "DeadCodeExample";
    
    // Unused private static constant
    static constexpr double PI = 3.14159;
    
    // Dead code - this variable is assigned but never read
    std::vector<std::string> assignedButNeverRead;
    
    // Unused private inner class
    class UnusedInnerClass {
    private:
        std::string data;
        
    public:
        UnusedInnerClass(const std::string& data) : data(data) {}
        
        std::string getData() {
            return data;
        }
    };
    
    // Unused private method
    void unusedMethod() {
        std::cout << "This method is never called" << std::endl;
    }
    
public:
    // Constructor
    DeadCodeExample() {
        // Initialize the vector that's never read
        assignedButNeverRead.push_back("This vector is never read");
        
        // Local variable never used
        int localUnused = 10;
        
        std::cout << "Initialized " << name << std::endl;
    }
    
    // Dead code - method with unreachable block
    void methodWithUnreachableBlock(int value) {
        if (value > 0) {
            std::cout << "Value is positive" << std::endl;
            return;
        } else {
            std::cout << "Value is negative or zero" << std::endl;
        }
        
        // Unreachable code - execution never reaches here if value > 0
        std::cout << "This will never be printed for positive values" << std::endl;
        
        // Dead code - condition always evaluates to false
        if (false) {
            std::cout << "This will never execute" << std::endl;
        }
    }
    
    // Method with unused parameters
    void methodWithUnusedParameters(const std::string& requiredParam, int unusedParam) {
        std::cout << "Processing: " << requiredParam << std::endl;
        // unusedParam is never used
    }
    
    // Method that is actually used
    std::string getDescription() {
        return "This is " + name;
    }
};

// Main function with various dead code scenarios
int main() {
    DeadCodeExample example;
    
    // Dead store - value overwritten without being used
    int result = 100;
    result = 200;  // Previous value never used
    
    std::cout << "Result: " << result << std::endl;
    
    // Unused local variable
    std::unordered_map<std::string, int> unusedMap;
    
    // Dead code in conditional
    if (true) {
        std::cout << "This will always execute" << std::endl;
    } else {
        // Unreachable branch
        std::cout << "This will never execute" << std::endl;
    }
    
    std::cout << example.getDescription() << std::endl;
    
    // Loop that only executes once
    for (int i = 0; i < 10; i++) {
        std::cout << "First iteration" << std::endl;
        break;  // Rest of iterations are dead code
    }
    
    return 0;
}