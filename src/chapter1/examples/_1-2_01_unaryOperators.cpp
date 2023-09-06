#include <cstdlib>
#include <iostream>

int main() {
    int a[] = {0, 1, 2, 3};
    int i = 2;
    int j = i++;
    int k = --i;
    std::cout << a[k++];

    return EXIT_SUCCESS;
}