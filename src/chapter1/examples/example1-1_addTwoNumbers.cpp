#include <cstdlib>
#include <iostream>

/* This program inputs 2 numbers num1 and num2 and outputs their sum */

int main() {
    int num1, num2;
    std::cout << "Please enter two numbers: ";
    std::cin >> num1 >> num2;
    int sum = num1 + num2;
    std::cout << "Their sum is " << sum << std::endl;
    return EXIT_SUCCESS;
}