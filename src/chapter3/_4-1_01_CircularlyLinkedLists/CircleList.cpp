#include "CircleList.h"

CircleList::~CircleList() {
    while(!empty())
        remove();
}

bool CircleList::empty() const {
    return cursor == NULL;
}

const Elem & CircleList::back() const {
    return cursor->elem;
}

const Elem & CircleList::front() const {
    return cursor->next->elem;
}

void CircleList::advance() {
    cursor = cursor->next;
}

void CircleList::add(const Elem & e) {
    CNode * v = new CNode();
    v->elem = e;
    if(cursor == NULL) {
        v->next = v;
        cursor = v;
    } else {
        v->next = cursor->next;
        cursor->next = v;
    }
}

void CircleList::remove() {
    CNode * old = cursor->next;
    if(old == cursor)
        cursor = NULL;
    else
        cursor->next = old->next;

    delete old;
}

void CircleList::print() {
    CNode * stop = cursor;
    cursor = cursor->next;
    while(cursor != stop) {
        std::cout << cursor->elem << " ";
        cursor = cursor->next;
    }
    std::cout << cursor->elem << "|";
}