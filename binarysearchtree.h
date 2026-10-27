//***************************************************************************
//
// Karina Torhan
// Z2111032
// CSCI 340 -OPE1 20268
// Assignment 08 Binary Search Tree
// Due Date: 11/03/26, 5:00 PM
// I certify that this is my own work and where appropriate an extension
// of the starter code provided for the assignment.
//
//***************************************************************************

#ifndef BINARYSEARCHTREE_H_
#define BINARYSEARCHTREE_H_

#include "btree.h"

template <typename T>
class BinarySearchTree : public BinaryTree<T> {
public:
    void Insert(const T &x);
    bool Search(const T &x) const;
    bool Remove(const T &x);

private:
    void _Insert(Node<T> *&, const T &);
    bool _Search(Node<T> *, const T &) const;
    void _Remove(Node<T> *&, const T &);
    bool _Leaf(Node<T> *node) const;
};

// insert a new value if it is not already in the tree
template <typename T>
void BinarySearchTree<T>::Insert(const T &x) {
    _Insert(this->root, x);
}

template <typename T>
void BinarySearchTree<T>::_Insert(Node<T> *&node, const T &x) {
    if (node == nullptr) {
        node = new Node<T>(x);
    } else if (x < node->data) {
        _Insert(node->left, x);
    } else if (x > node->data) {
        _Insert(node->right, x);
    }
}

// search only for leaves
template <typename T>
bool BinarySearchTree<T>::Search(const T &x) const {
    return _Search(this->root, x);
}

template <typename T>
bool BinarySearchTree<T>::_Search(Node<T> *node, const T &x) const {
    if (node == nullptr)
        return false;

    if (x == node->data)
        return _Leaf(node);

    if (x < node->data)
        return _Search(node->left, x);

    return _Search(node->right, x);
}

// remove a value only when it is a leaf
template <typename T>
bool BinarySearchTree<T>::Remove(const T &x) {
    if (!Search(x))
        return false;

    _Remove(this->root, x);
    return true;
}

template <typename T>
void BinarySearchTree<T>::_Remove(Node<T> *&node, const T &x) {
    if (node == nullptr)
        return;

    if (x < node->data) {
        _Remove(node->left, x);
    } else if (x > node->data) {
        _Remove(node->right, x);
    } else if (_Leaf(node)) {
        delete node;
        node = nullptr;
    }
}

template <typename T>
bool BinarySearchTree<T>::_Leaf(Node<T> *node) const {
    return node != nullptr &&
           node->left == nullptr &&
           node->right == nullptr;
}

#endif // BINARYSEARCHTREE_H_