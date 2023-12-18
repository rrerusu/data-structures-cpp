#include "DLinkedList.h"

int main() {
    DLinkedList<int> myList;
    myList.pushFront(10);
    myList.pushFront(9);
    myList.pushFront(8);
    myList.pushFront(7);
    myList.pushBack(6);

    std::cout << myList.toString();
    myList.reverse();
    std::cout << std::endl << "Reversed: " << myList.toString();

    return EXIT_SUCCESS;
}