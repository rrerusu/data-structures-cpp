#include "SingleLinkedList.h"

int main() {
    SingleLinkedList<std::string> a;
    a.addFront("MSP");

    SingleLinkedList<int> b;
    b.addFront(13);

    return EXIT_SUCCESS;
}