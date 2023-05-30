#ifndef BLOCKCHIAN_NODE_H
#define BLOCKCHIAN_NODE_H

using namespace std;
template <typename T>
struct NodeBT {
    T data;
    NodeBT* left;
    NodeBT* right;
    int height;
    NodeBT() : left(nullptr), right(nullptr), height(0) {}
    NodeBT(T values) : data(values), left(nullptr), right(nullptr), height(0) {}

    void killSelf(){
        if(left != nullptr) left->killSelf();
        if(right != nullptr) right->killSelf();
        delete this;
    }
};

#endif //BLOCKCHIAN_NODE_H
