#pragma once
#include <stdexcept>
using namespace std;

/**
 * A generic N-ary tree class.
 * NIL is implemented as a singleton sentinel node representing an empty tree.
 */
template <class T, int N>
class Tree {
private:
    T key;                     // Value stored in the node (non-const to allow modification)
    Tree<T, N> * children[N]; // Child pointers

    /**
     * Private default constructor for NIL node only.
     */
    Tree() : key(T()) {
        for ( int i = 0; i < N; i++ ) {
            children[i] = this;  // NIL's children point to itself
        }
    }

public:
    static Tree<T, N> NIL;

    /**
     * Constructor for a proper (non-NIL) tree node.
     */
    Tree(const T & k) : key(k) {
        for ( int i = 0; i < N; i++ ) {
            children[i] = &NIL;
        }
    }

    /**
     * Destructor.
     */
    ~Tree() {
        if ( this != &NIL ) {
            for ( int i = 0; i < N; i++ ) {
                if ( children[i] != &NIL ) {
                    delete children[i];
                    children[i] = &NIL;
                }
            }
        }
    }

    /**
     * Check if this node is the NIL sentinel.
     */
    bool isEmpty() const {
        return this == &NIL;
    }

    /**
     * Returns the key (modifiable).
     */
    T & getKey() {
        if ( isEmpty() ) {
            throw runtime_error("Cannot get key from NIL node");
        }
        return key;
    }

    /**
     * Returns the key (read-only).
     */
    const T & getKey() const {
        if ( isEmpty() ) {
            throw runtime_error("Cannot get key from NIL node");
        }
        return key;
    }

    /**
     * Access a child node by index.
     */
    Tree<T, N> & operator[](int index) const {
        if ( index < 0 || index >= N ) {
            throw out_of_range("Index out of range");
        }
        if ( isEmpty() ) {
            throw runtime_error("Cannot access children of NIL node");
        }
        return *children[index];
    }

    /**
     * Attach a subtree.
     */
    void attachTree(int index, Tree<T, N> * subtree) {
        if ( index < 0 || index >= N ) {
            throw out_of_range("Index out of range");
        }
        if ( isEmpty() ) {
            throw runtime_error("Cannot attach to NIL node");
        }
        if ( subtree == nullptr ) {
            throw invalid_argument("Cannot attach nullptr");
        }

        if ( children[index] != &NIL ) {
            delete children[index];
        }

        children[index] = subtree;
    }

    /**
     * Detach subtree.
     */
    Tree<T, N> * detachTree(int index) {
        if ( index < 0 || index >= N ) {
            throw out_of_range("Index out of range");
        }
        if ( isEmpty() ) {
            throw runtime_error("Cannot detach from NIL node");
        }

        Tree<T, N> * detached = children[index];
        children[index] = &NIL;
        return detached;
    }
};

// Define static NIL node
template <class T, int N>
Tree<T, N> Tree<T, N>::NIL;
