#include <iostream>

typedef int Elem;
class CNode {
    private:
        Elem elem;
        CNode * next;
        friend class CircleList;
};

class CircleList {
    public:
        CircleList() : cursor(NULL) {}
        ~CircleList();
        bool empty() const;
        const Elem & front() const;
        const Elem & back() const;
        void advance();
        void add(const Elem & e);
        void remove();
        void print();
    private:
        CNode * cursor;
};