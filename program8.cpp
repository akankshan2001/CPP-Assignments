/*
Description
Problem Statement:
Elaborate the program to compute an integer y such that y is produced by reversing x.
For example, if x is 6787, y is 7876, and if x is 80, y is 8.
*/

#include <iostream>

//Function to reverse the integer

size_t reverseInteger(size_t x) {
    size_t y = 0;
    
    while (x != 0) {
        size_t lastDigit = x % 10;
        y = y * 10 + lastDigit;
        x /= 10;
    }
    
    return y;
}

int main() {

    size_t x;
    
    std::cout << "Enter a positive integer x: ";
    std::cin >> x;
    
    size_t y = reverseInteger(x);
    
    std::cout << "Reversed integer y: " << y << std::endl;
    
    return 0;
}
