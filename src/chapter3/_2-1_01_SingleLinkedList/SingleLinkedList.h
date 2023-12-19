#include <iostream>

#pragma once

template <class> class SingleLinkedList;

template <typename E>
class SNode {
    private:
        E elem;
        SNode<E> * next;
        friend class SingleLinkedList<E>;
};

template <typename E>
class SingleLinkedList {
    private:
        SNode<E> * head;
    public:
        SingleLinkedList() : head(NULL) {}
        ~SingleLinkedList();
        bool empty() const { return head == NULL; }
        const E & front() const { return head->elem; }
        void push(const E & e);
        void pop();
};

template <typename E>
SingleLinkedList<E>::~SingleLinkedList() {
    while(!empty())
        pop();
}

template <typename E>
void SingleLinkedList<E>::push(const E & e) {
    SNode<E> * v = new SNode<E>();
    v->elem = e;
    v->next = head;
    head = v;
}

template <typename E>
void SingleLinkedList<E>::pop() {
    SNode<E> * old = head;
    head = old->next;
    delete old;
}