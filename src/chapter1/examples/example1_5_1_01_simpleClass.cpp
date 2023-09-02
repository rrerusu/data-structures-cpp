#include <cstdlib>
#include <iostream>

class Counter {
    public:
        Counter();
        int getCount();
        void increaseBy(int x);
    private:
        int count;
};

Counter::Counter() {
    count = 0;
}

int Counter::getCount() {
    return count;
}

void Counter::increaseBy(int x) {
    count += x;
}

int main() {
    Counter myCounter;
    std::cout << myCounter.getCount() << std::endl;
    myCounter.increaseBy(3);
    std::cout << myCounter.getCount() << std::endl;
    myCounter.increaseBy(5);
    std::cout << myCounter.getCount() << std::endl;


    return EXIT_SUCCESS;
}