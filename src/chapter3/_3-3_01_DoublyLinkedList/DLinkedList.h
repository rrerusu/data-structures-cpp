#include <iostream>
#include <sstream>

#pragma once

template <class> class DLinkedList;

template <typename Elem>
class DNode {
    public:
        DNode(Elem val = NULL) : elem(val), prev(nullptr), next(nullptr) {}
        std::string toString();
    private:
        Elem elem;
        DNode<Elem> * prev;
        DNode<Elem> * next;
        friend class DLinkedList<Elem>;
};

template <typename Elem>
std::string DNode<Elem>::toString() {
    std::stringstream ss;
    ss << this->elem;
    return ss.str();
}

template <typename Elem>
class DLinkedList {
    public:
        DLinkedList();
        ~DLinkedList();
        bool empty() const { return head->next == tail; }
        const Elem & front() const { return head->next->elem; }
        const Elem & back() const { return tail->prev->elem; }
        void pushFront(const Elem & e);
        void pushBack(const Elem & e);
        void popFront();
        void popBack();
        std::string toString();
    private:
        DNode<Elem> * head;
        DNode<Elem> * tail;
    protected:
        void push(DNode<Elem> * v, const Elem & e);
        void pop(DNode<Elem> * v);
};

template <typename Elem>
DLinkedList<Elem>::DLinkedList() {
    head = new DNode<Elem>();
    tail = new DNode<Elem>();
    head->next = tail;
    tail->prev = head;
}

template <typename Elem>
DLinkedList<Elem>::~DLinkedList() {
    while(!empty())
        popFront();
    delete head;
    delete tail;
}

template <typename Elem>
void DLinkedList<Elem>::push(DNode<Elem> * v, const Elem & e) {
    DNode<Elem> * u = new DNode<Elem>(e);
    u->next = v;
    u->prev = v->prev;
    u->prev->next = u;
    v->prev = u;
}

template <typename Elem>
void DLinkedList<Elem>::pushFront(const Elem & e) {
    push(head->next, e);
}

template <typename Elem>
void DLinkedList<Elem>::pushBack(const Elem & e) {
    push(tail, e);
}

template <typename Elem>
void DLinkedList<Elem>::pop(DNode<Elem> * v) {
    DNode<Elem> * u = v->prev;
    DNode<Elem> * w = v->next;
    u->next = w;
    w->prev = u;
    delete v;
}

template <typename Elem>
void DLinkedList<Elem>::popFront() {
    pop(head->next);
}

template <typename Elem>
void DLinkedList<Elem>::popBack() {
    pop(tail->prev);
}

template <typename Elem>
std::string DLinkedList<Elem>::toString() {
    std::string output = "head ⟷  ";
    DNode<Elem> * current = head->next;
    while(current->next != nullptr) {
        output += current->toString() + " ⟷  ";
        current = current->next;
    }
    output += "tail";
    return output;
}