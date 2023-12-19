#include <iostream>
#include <exception>

#pragma once

template <class> class ArrayStack;

class StackException : public std::exception {
    public:
        StackException(const std::string & err) : msg(err) {}
        const char * what() const noexcept { return msg.c_str(); }
    private:
        std::string msg;
};

template <typename E>
class ArrayStack {
    enum { DEF_CAPACITY = 100 };
    public:
        ArrayStack(int cap = DEF_CAPACITY);
        int size() const;
        bool empty() const;
        const E & top() const;
        void push(const E & e);
        void pop();
    private:
        E * S;
        int capacity;
        int t;
};


template <typename E>
ArrayStack<E>::ArrayStack(int cap) : S(new E[cap]), capacity(cap), t(-1) {}

template <typename E>
int ArrayStack<E>::size() const {
    return t + 1;
}

template <typename E>
bool ArrayStack<E>::empty() const {
    return t < 0;
}

template <typename E>
const E & ArrayStack<E>::top() const {
    if(empty())
        throw StackException("Top of empty stack");
    return S[t];
}

template <typename E>
void ArrayStack<E>::push(const E & e) {
    if(size() == capacity)
        throw StackException("Push to full stack");
    S[++t] = e;
}

template <typename E>
void ArrayStack<E>::pop() {
    if(empty())
        throw StackException("Pop from empty stack");
    --t;
}