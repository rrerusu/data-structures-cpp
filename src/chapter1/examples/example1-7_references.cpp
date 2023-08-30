#include <cstdlib>
#include <iostream>

int main() {
    std::string author = "Samuel Clemens";
    std::string& penName = author;
    penName = "Mark Twain";
    std::cout << author;

    return EXIT_SUCCESS;
}