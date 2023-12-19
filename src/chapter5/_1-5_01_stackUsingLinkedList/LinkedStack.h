#include <iostream>
#include "../../chapter3/_2-1_01_SingleLinkedList/SingleLinkedList.h"
#include "StackException.h"

template <class> class LinkedStack;

template <typename Elem>
class LinkedStack {
    public:
        LinkedStack(int val = 0) : S(), n(val) {}
        int size() const { return n; }
        bool empty() const { return n == 0; }
        const Elem & top() const;
        void push(const Elem & e);
        void pop();
    private:
        SingleLinkedList<Elem> S;
        int n;
};

template <typename Elem>
const Elem & LinkedStack<Elem>::top() const {
    if(empty())
        throw StackException("Top of empty stack");
    return S.front();
}

template <typename Elem>
void LinkedStack<Elem>::push(const Elem & e) {
    ++n;
    S.push(e);
}

template <typename Elem>
void LinkedStack<Elem>::pop() {
    if(empty())
        throw StackException("Pop from empty stack");
    --n;
    S.pop();
}