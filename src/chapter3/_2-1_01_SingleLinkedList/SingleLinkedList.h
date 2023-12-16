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
        void addFront(const E & e);
        void removeFront();
};

template <typename E>
SingleLinkedList<E>::~SingleLinkedList() {
    while(!empty())
        removeFront();
}

template <typename E>
void SingleLinkedList<E>::addFront(const E & e) {
    SNode<E> * v = new SNode<E>();
    v->elem = e;
    v->next = head;
    head = v;
}

template <typename E>
void SingleLinkedList<E>::removeFront() {
    SNode<E> * old = head;
    head = old->next;
    delete old;
}