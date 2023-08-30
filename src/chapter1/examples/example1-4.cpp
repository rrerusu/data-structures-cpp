#include <string>
#include <cstdlib>
#include <iostream>

using std::string;

int main() {
    string s = "to be";
    string t = "not " + s;
    string u = s + " ro " + t;
    if(s > t)
        std::cout << u;
    
    string s2 = "John";
    int i = s2.size();
    char c = s2[3];
    s2 += " Smith";
    std::cout << std::endl << c << std::endl;
    std::cout << s2 << std::endl;

    return EXIT_SUCCESS;
}