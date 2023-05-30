#ifndef BLOCKCHIAN_CHAINHASH_H
#define BLOCKCHIAN_CHAINHASH_H

#include <iostream>
#include "forward.h"
#include <functional>

using namespace std;

const float maxFillFactor = 0.4;
const int maxColision = 3;

template<typename TK, typename TV>
class ChainHash {
public:
    struct Entry {
        TK key;
        vector<TV> values;
        Entry(TK k, TV v) {
            this->key = k;
            this->values.push_back(v);
        }
    };

private:
    ForwardList<Entry>* array;
    int capacity;
    int size;
    hash<TK> hasher;

public:
    ChainHash(int cap = 13) {
        this->capacity = cap;
        this->size = 0;
        array = new ForwardList<Entry>[this->capacity];
    }

    void insert(TK key, TV value) {
        int index = hasher(key) % capacity;
        array[index].push_front(Entry(key, value));
        size++;

        if (fillFactor() >= maxFillFactor || bucket_size(index) >= maxColision) {
            rehashing();
        }

    }

    vector<TV> find(TK key) {
        int index = hasher(key) % capacity;
        vector<TV> result;

        for (const auto& entry : array[index]) {
            if (entry.key == key) {
                result.insert(result.end(), entry.values.begin(), entry.values.end());
            }
        }

        return result;
    }

    void remove(TK key) {
        int index = hasher(key) % capacity;
        array[index].remove_if([&key](const Entry& entry) {
            return entry.key == key;
        });
    }

    int bucket_count() {
        return capacity;
    }

    int bucket_size(int i) {
        int count = 0;
        for (const auto& entry : array[i]) {
            count++;
        }
        return count;
    }

    typename ForwardList<Entry>::iterator begin(int i) {
        return array[i].begin();
    }

    typename ForwardList<Entry>::iterator end(int i) {
        return array[i].end();
    }

    ~ChainHash() {
        delete[] array;
    }

private:
    float fillFactor() {
        return static_cast<float>(size) / (capacity * maxColision);
    }

    void rehashing() {
        int newCapacity = capacity * 2;
        auto* newArray = new ForwardList<Entry>[newCapacity];

        for (int i = 0; i < capacity; ++i) {
            for (const auto& entry : array[i]) {
                int newIndex = hasher(entry.key) % newCapacity;
                newArray[newIndex].push_front(entry);
            }
        }

        delete[] array;
        array = newArray;
        capacity = newCapacity;
    }
};

#endif //BLOCKCHIAN_CHAINHASH_H
