#ifndef BLOCKCHIAN_AVL_H
#define BLOCKCHIAN_AVL_H

#include "node.h"
#include <vector>
#include "record.h"

using namespace std;

template <typename T>
class AVLTree {
private:
    NodeBT<T> *root;

public:
    AVLTree() : root(nullptr) {}
    void insert(const T& value);
    bool find(const T& value);
    vector<T> searchRange(double lower, double upper);

private:
    void insert(NodeBT<T> *&node, const T& value);
    bool find(NodeBT<T> *node, const T& value);
    void searchRange(NodeBT<T> *node, double lower, double upper, vector<T> &result);
    void updateHeight(NodeBT<T> *node);
    int getHeightDiff(NodeBT<T> *node);
    void rotateLeft(NodeBT<T> *&node);
    void rotateRight(NodeBT<T> *&node);
    void balance(NodeBT<T> *&node);
};


template <typename T>
void AVLTree<T>::insert(const T& value) {
    insert(this->root, value);
}

template <typename T>
bool AVLTree<T>::find(const T& value) {
    return find(this->root, value);
}

template <typename T>
vector<T> AVLTree<T>::searchRange(double lower, double upper) {
    vector<T> result;
    searchRange(root, lower, upper, result);
    return result;
}

template <typename T>
void AVLTree<T>::insert(NodeBT<T> *&node, const T& value) {
    if (node == nullptr)
        node = new NodeBT<T>(value);
    else if (value.monto < node->data.monto)
        insert(node->left, value);
    else
        insert(node->right, value);

    updateHeight(node);
    balance(node);
}

template <typename T>
bool AVLTree<T>::find(NodeBT<T> *node, const T& value) {
    if (node == nullptr)
        return false;
    else if (value.monto < node->data.monto)
        return find(node->left, value);
    else if (value.monto > node->data.monto)
        return find(node->right, value);
    else
        return true;
}

template<typename T>
void AVLTree<T>::searchRange(NodeBT<T> *node, double lower, double upper, vector<T> &result) {
    if (node == nullptr)
        return;

    if (node->data.monto >= lower && node->data.monto <= upper)
        result.push_back(node->data);

    if (node->data.monto >= lower)
        searchRange(node->left, lower, upper, result);

    if (node->data.monto <= upper)
        searchRange(node->right, lower, upper, result);
}

template <typename T>
void AVLTree<T>::updateHeight(NodeBT<T> *node) {
    if (node == nullptr)
        return;

    int leftHeight = (node->left != nullptr) ? node->left->height : -1;
    int rightHeight = (node->right != nullptr) ? node->right->height : -1;

    node->height = 1 + max(leftHeight, rightHeight);
}

template <typename T>
int AVLTree<T>::getHeightDiff(NodeBT<T> *node) {
    if (node == nullptr)
        return 0;

    int leftHeight = (node->left != nullptr) ? node->left->height : -1;
    int rightHeight = (node->right != nullptr) ? node->right->height : -1;

    return leftHeight - rightHeight;
}

template <typename T>
void AVLTree<T>::rotateLeft(NodeBT<T> *&node) {
    NodeBT<T> *pivot = node->right;
    node->right = pivot->left;
    pivot->left = node;

    updateHeight(node);
    updateHeight(pivot);

    node = pivot;
}

template <typename T>
void AVLTree<T>::rotateRight(NodeBT<T> *&node) {
    NodeBT<T> *pivot = node->left;
    node->left = pivot->right;
    pivot->right = node;

    updateHeight(node);
    updateHeight(pivot);

    node = pivot;
}

template <typename T>
void AVLTree<T>::balance(NodeBT<T> *&node) {
    int balanceFactor = getHeightDiff(node);

    if (balanceFactor > 1) {
        if (getHeightDiff(node->left) < 0)
            rotateLeft(node->left);

        rotateRight(node);
    } else if (balanceFactor < -1) {
        if (getHeightDiff(node->right) > 0)
            rotateRight(node->right);

        rotateLeft(node);
    }
}

std::ostream& operator<<(std::ostream& os, const record& r) {
    os << "Cliente: " << r.cliente << ", ";
    os << "Lugar: " << r.lugar << ", ";
    os << "Monto: " << r.monto << ", ";
    os << "Fecha: " << r.fecha;

    return os;
}


#endif //BLOCKCHIAN_AVL_H
