#ifndef FORWARD_LIST_H
#define FORWARD_LIST_H

#include "node.h"

template <typename T>
class ForwardIterator {
public:
    ForwardIterator(NodeFW<T>* curr) {
        this->current = curr;
    }

    bool operator!=(ForwardIterator other){
        return current != other.current;
    }

    T& operator*() {
        return current->data;
    }

    ForwardIterator operator++() {
        return current = current->next;
    }

private:
    typedef NodeFW<T> Nodo;
    Nodo* current;
};

template <typename T>
class ForwardList {
private:
    NodeFW<T>* head;
    NodeFW<T>* tail;
public:
    typedef ForwardIterator<T> iterator;
public:


    ForwardList() : head(nullptr), tail(nullptr) {}

    ForwardList(const ForwardList& other) : head(nullptr), tail(nullptr) {
        NodeFW<T>* currentNode = other.head;
        while (currentNode != nullptr) {
            push_back(currentNode->data);
            currentNode = currentNode->next;
        }
    }

    ~ForwardList() {
        clear();
    }

    void push_front(const T& value) {
        NodeFW<T>* newNode = new NodeFW(value);
        if (empty()) {
            head = newNode;
            tail = newNode;
        } else {
            newNode->next = head;
            head = newNode;
        }
    }

    void push_back(const T& value) {
        NodeFW<T>* newNode = new NodeFW(value);
        if (empty()) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    void clear() {
        while (!empty()) {
            NodeFW<T>* temp = head;
            head = head->next;
            delete temp;
        }
        tail = nullptr;
    }

    bool empty() const {
        return head == nullptr;
    }

    iterator begin() const {
        return iterator(head);
    }

    iterator end() const {
        return iterator(nullptr);
    }


    const T& front() const {
        return head->data;
    }
};




#endif // FORWARD_LIST_H
