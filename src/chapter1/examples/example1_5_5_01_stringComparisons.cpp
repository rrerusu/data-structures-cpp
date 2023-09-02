#include <cstdlib>
#include <iostream>
#include <string>

int main() {
    std::string s = "a dog";
    s += " is a dog";
    std::cout << s.find("dog") << std::endl;
    std::cout << s.find("dog", 3) << std::endl;

    std::cout << (s.find("Doug") == std::string::npos) << std::endl;

    s.replace(2, 3, "frog");
    s.erase(6, 3);
    s.insert(0, "is ");

    std::cout << (s == "is a frog a dog") << std::endl;
    std::cout << (s < "is a frog a toad") << std::endl;
    std::cout << (s < "is a frog a cat") << std::endl;

    return EXIT_SUCCESS;
}