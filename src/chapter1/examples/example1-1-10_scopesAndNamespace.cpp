#include <cstdlib>
#include <iostream>

using std::string;
using std::cout;
using namespace myglobals;

namespace myglobals {
    int cat;
    std::string dog = "bow wow";
}

const int Cat = 1;

int main() {
    const int Cat = 2;
    std::cout << Cat << std::endl;
    return EXIT_SUCCESS;
}

int dog = Cat;