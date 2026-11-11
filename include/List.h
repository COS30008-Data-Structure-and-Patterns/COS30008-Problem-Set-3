#pragma once
#include "Node.h"
#include <iostream>
#include <stdexcept>
using namespace std;

template <class T>
class List {
private:
    Node<T> * head;
    Node<T> * tail;
    int size;

public:
    List()
        : head(Node<T>::NIL), tail(Node<T>::NIL), size(0) {}

    ~List() {
        Node<T> * current = head;
        while ( current != Node<T>::NIL ) {
            Node<T> * tmp = current;
            current = current->next;
            delete tmp;
        }
    }

    void add(const T & value) {
        Node<T> * newNode = new Node<T>(value);

        if ( head == Node<T>::NIL ) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }

        size++;
    }

    void removeAt(int index) {
        if ( index < 0 || index >= size ) return;

        Node<T> * current = head;
        for ( int i = 0; i < index; i++ )
            current = current->next;

        if ( current == head ) {
            head = current->next;
            if ( head != Node<T>::NIL )
                head->prev = Node<T>::NIL;
        }

        if ( current == tail ) {
            tail = current->prev;
            if ( tail != Node<T>::NIL )
                tail->next = Node<T>::NIL;
        }

        if ( current->prev != Node<T>::NIL )
            current->prev->next = current->next;

        if ( current->next != Node<T>::NIL )
            current->next->prev = current->prev;

        delete current;
        size--;
    }

    // operator[]
    T & operator[](int index) {
        if ( index < 0 || index >= size )
            throw std::out_of_range("Index out of range");

        Node<T> * current = head;
        for ( int i = 0; i < index; i++ )
            current = current->next;

        return current->data;
    }

    const T & operator[](int index) const {
        if ( index < 0 || index >= size )
            throw std::out_of_range("Index out of range");

        Node<T> * current = head;
        for ( int i = 0; i < index; i++ )
            current = current->next;

        return current->data;
    }

    int getSize() const { return size; }
};