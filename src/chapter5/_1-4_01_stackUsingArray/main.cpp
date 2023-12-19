#include "ArrayStack.h"

int main() {
    ArrayStack<int> A;
    A.push(7);
    A.push(13);
    std::cout << A.top() << std::endl;
    A.pop();
    A.push(9);
    std::cout << A.top() << std::endl;
    std::cout << A.top() << std::endl;
    A.pop();
    ArrayStack<std::string> B(10);
    B.push("Bob");
    B.push("Alice");
    std::cout << B.top() << std::endl;
    B.pop();
    B.push("Eve");

    return EXIT_SUCCESS;
}