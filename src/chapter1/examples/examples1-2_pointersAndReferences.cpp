#include <cstdlib>
#include <iostream>

int main() {
    char ch = 'Q';
    char* p = &ch;
    std::cout << *p;
    ch = 'Z';
    std::cout << *p;
    *p = 'X';
    std::cout << ch;
}