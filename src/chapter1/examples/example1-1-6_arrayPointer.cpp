#include <cstdlib>
#include <iostream>

int main() {
    char* buffer = new char[500];
    buffer[3] = 'a';
    delete [] buffer;

    return EXIT_SUCCESS;
}