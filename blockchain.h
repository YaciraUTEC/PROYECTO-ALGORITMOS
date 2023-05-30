#ifndef BLOCKCHAIN_H
#define BLOCKCHAIN_H

#include "forward.h"
#include <iomanip>
#include <iostream>
#include <openssl/evp.h>
#include "avl.h"
#include "record.h"
#include "block.h"
#include "chainhash.h"

using namespace std;

class Blockchain {
private:
    ForwardList<Block> blocks;
    AVLTree<record> avlTree;
    ChainHash<string, record> clientHash;

public:
    void addBlock(Block& block);
    void printBlockchain() const;
    vector<record> search(const string& cliente) ;
    template <typename TV>
    vector<record> range_search(TV lower, TV upper);
};

void Blockchain::addBlock(Block& block) {
    if (blocks.empty()) {
        block.prevHash = "0000000000000000000000000000000000000000000000000000000000000000";
    } else {
        const Block& prevBlock = blocks.front();
        block.prevHash = prevBlock.hash;
    }

    for (const auto& record : block.data) {
        avlTree.insert(record);
        clientHash.insert(record.cliente, record);
    }

    block.idblock = Block::nextId++;
    block.mineBlock(4);
    blocks.push_front(block);
}

void Blockchain::printBlockchain() const {
    for (const auto& block : blocks) {
        cout << "Block ID: " << block.idblock << endl;
        cout << "Nonce: " << block.nonce << endl;
        cout << "Previous Hash: " << block.prevHash << endl;
        cout << "Data:" << endl;
        for (const auto& record : block.data) {
            cout << "Cliente: " << record.cliente << endl;
            cout << "Lugar: " << record.lugar << endl;
            cout << "Monto: " << record.monto << endl;
            cout << "Fecha: " << record.fecha << endl;
            cout << endl;
        }
        cout << "Block Hash: " << block.hash << endl;
        cout << endl;
    }
}

vector<record> Blockchain::search(const string& cliente) {
    return clientHash.find(cliente);
}

template <typename TV>
vector<record> Blockchain::range_search(TV lower, TV upper){
    return avlTree.searchRange(lower, upper);
}

#endif // BLOCKCHAIN_H
