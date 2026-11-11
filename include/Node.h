#pragma once

template <class T>
class Node {
public:
	T data;
	Node<T> * prev;
	Node<T> * next;

	static Node<T> * NIL;

	// Normal constructor for real nodes
	Node(const T & value)
		: data(value), prev(NIL), next(NIL) {}

	// Special constructor for NIL sentinel
	Node()
		: prev(this), next(this) {}   // NIL points to itself
};

// Initialize NIL
template <class T>
Node<T> * Node<T>::NIL = new Node<T>();