#include <iostream>
#include <string>

int main() {
    std::string binaryString = "A"; // Example binary string
    
    // Convert binary string to integer using stoi with base 16,2,3,4,5,6,7...
    int decimalValue = std::stoi(binaryString, nullptr, 16); 
    
    std::cout << "Binary: " << binaryString << std::endl;
    std::cout << "Decimal: " << decimalValue << std::endl; 
    
    return 0;
}