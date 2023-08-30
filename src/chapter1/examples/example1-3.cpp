#include <cstdlib>
#include <iostream>

int main() {
    double f[5];
    int m[10];
    f[4] = 2.5;
    m[2] = 4;
    std::cout << f[m[2]];

    int a[] = {10, 11, 12, 13};                 // declares and initialized a[4]
    bool b[] = {false, true};                   // declares and initialized b[2]
    char c[] = {'c', 'a', 't'};                 // declares and initializes c[3]

    char* p = c;
    char* q = &c[0];
    std::cout << c[2] << p[2] << q[2];

    return EXIT_SUCCESS;
}