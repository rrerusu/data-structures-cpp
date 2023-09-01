#include <cstdlib>
#include <iostream>

int main() {
    // Static Casting
    double d1 = 3.2;
    double d2 = 3.9999;
    int    i1 = static_cast<int>(d1);
    int    i2 = static_cast<int>(d2);
    std::cout << "i1: " << i1 << "\ni2: " << i2 << std::endl;


    // implicit cast
    int    i = 3;
    double d = 4.8;
    double d3 = i / d;
    int    i3 = d3;

    std::cout << "\nd3: " << d3 << "\ni3: " << i3 << std::endl;

    return EXIT_SUCCESS;
}