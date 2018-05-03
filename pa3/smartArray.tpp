#include "smartArray.h" // Include only for syntax correction
#include "pair.h"       // Include only for syntax correction
#include <iostream>

// submit this file
// you do NOT need to include any header in this file
// just write your SmartArray implementation here right away
template <typename KeyType, typename ValueType>
SmartArray<KeyType, ValueType>::SmartArray() : data(nullptr), size(0) {
}

template <typename KeyType, typename ValueType>
SmartArray<KeyType, ValueType>::~SmartArray() {
    for (int i = 0; i < size; ++i) {
        delete data[i];
    }
    delete data;
}

template <typename KeyType, typename ValueType>
bool SmartArray<KeyType, ValueType>::add(KeyType key, ValueType value) {
    if (has(key)) {
        return false;
    }
    /* Finds the position for the new pair. */
    int new_pair_pos = 0;
    for (int i = 0; i < size; ++i) {
        if (key < data[i]->key) {
            new_pair_pos = i;
        }
    }
    /* Constructs the new_data array. */
    Pair<KeyType, ValueType> **new_data = new Pair<KeyType, ValueType> *[size + 1];
    for (int i = 0; i < new_pair_pos; ++i) {
        new_data[i] = new Pair<KeyType, ValueType>{*(data[i])};
    }
    for (int i = new_pair_pos + 1; i < size + 1; ++i) {
        new_data[i] = new Pair<KeyType, ValueType>{*(data[i - 1])};
    }
    new_data[new_pair_pos] = new Pair<KeyType, ValueType>(key, value);
    /* Deletes the original data array. */
    for (int i = 0; i < size; ++i) {
        delete data[i];
    }
    /* Points to the new_data. */
    data = new_data;
    ++size;
    return true;
}

template <typename KeyType, typename ValueType>
bool SmartArray<KeyType, ValueType>::remove(KeyType key) {
    if (!has(key)) {
        return false;
    }
    /* Finds the position for the new pair. */
    int old_pair_pos = 0;
    for (int i = 0; i < size; ++i) {
        if (key == data[i]->key) {
            old_pair_pos = i;
        }
    }
    /* Constructs the new_data array. */
    Pair<KeyType, ValueType> **new_data = new Pair<KeyType, ValueType> *[size - 1];
    for (int i = 0; i < old_pair_pos; ++i) {
        new_data[i] = new Pair<KeyType, ValueType>{*(data[i])};
    }
    for (int i = old_pair_pos; i < size - 1; ++i) {
        new_data[i] = new Pair<KeyType, ValueType>{*(data[i + 1])};
    }
    /* Points to the new_data.*/
    data = new_data;
    --size;
    return true;
}

template <typename KeyType, typename ValueType>
ValueType SmartArray<KeyType, ValueType>::get(KeyType key) const {
    if (!has(key)) {
        return typeid(ValueType) == typeid(int) ? 0 : ValueType();
    }
    for (int i = 0; i < size; ++i) {
        if (key == data[i]->key) {
            return data[i]->value;
        }
    }
}

template <typename KeyType, typename ValueType>
int SmartArray<KeyType, ValueType>::count() const {
    return size;
}

template <typename KeyType, typename ValueType>
const Pair<KeyType, ValueType> *SmartArray<KeyType, ValueType>::operator[](int n) const {
    if (n < 0 || n >= size) { /* Index out of range */
        return nullptr;
    }
    
    return data[n];
}

template <typename KeyType, typename ValueType>
void SmartArray<KeyType, ValueType>::print(ostream &os) const {
    for (int i = 0; i < size; ++i) {
        os << "(" << data[i]->key << "," << data[i]->value << ")";
    }
}

template <typename KeyType, typename ValueType>
bool SmartArray<KeyType, ValueType>::has(KeyType key) const {
    for (int i = 0; i < size; ++i) {
        if (key == data[i]->key) {
            return true;
        }
    }
    return false;
}
