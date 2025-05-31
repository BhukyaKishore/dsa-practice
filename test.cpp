#include<iostream>
#include<string>
int main() {
    std::string str = "Hello World";
    int position = 5; // Position of the character to remove (0-based indexing)
    str.erase(position, 1); // Remove 1 character at the given position
    std::cout << str << std::endl; // Output: "Helloorld"
    return 0;
}