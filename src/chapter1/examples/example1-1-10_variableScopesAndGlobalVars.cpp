#include <cstdlib>
#include <iostream>

namespace myglobals {
    int cat;
    string dog = "bow wow";
}

const int Cat = 1;

int main() {
    const int Cat = 2;
    std::cout << Cat << std::endl;
    return EXIT_SUCCESS;
}

int dog = Cat;