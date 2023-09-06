#include <cstdlib>
#include <iostream>

void f(int value, int& ref) {
    value++;
    ref++;
    std::cout << value << std::endl;
    std::cout << ref << std::endl;
}

int main() {
    int cat = 1;
    int dog = 5;
    f(cat, dog);
    std::cout << cat << std::endl;
    std::cout << dog << std::endl;

    return EXIT_SUCCESS;
}