#include <iostream>
#include <sstream>

#pragma once

template <class> class DLinkedList;

template <typename Elem>
class DNode {
    public:
        template <typename T = Elem, typename std::enable_if_t<std::is_integral_v<T>, bool> = true>
        DNode(T val = 0) : elem(val), prev(nullptr), next(nullptr) {}
        DNode(Elem val = NULL) : elem(val), prev(nullptr), next(nullptr) {}
        template <typename T = Elem, typename std::enable_if_t<std::is_integral_v<T>, bool> = true>
        std::string toString() {
            return std::to_string(elem);
        }
        std::string toString() {
            std::stringstream ss;
            ss << elem;
            return ss.str();
        }
    private:
        Elem elem;
        DNode<Elem> * prev;
        DNode<Elem> * next;
        friend class DLinkedList<Elem>;
};

template <>
class DNode<std::string> {
    public:
        DNode(std::string val = "") : elem(val), prev(nullptr), next(nullptr) {}
        std::string toString() {
            std::stringstream ss;
            ss << elem;
            return ss.str();
        }
    private:
        std::string elem;
        DNode<std::string> * prev;
        DNode<std::string> * next;
        friend class DLinkedList<std::string>;
};

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
        void reverse();
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

template <typename Elem>
void DLinkedList<Elem>::reverse() {
    DLinkedList<Elem> T;
    while(!this->empty()) {
        Elem val = this->front();
        this->popFront();
        T.pushFront(val);
    }
    while(!T.empty()) {
        Elem val = T.front();
        T.popFront();
        this->pushBack(val);
    }
}