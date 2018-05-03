//submit this file
//you do NOT need to include any header in this file
//just write your BST implementation here right away

#include "bst.h"

template <typename KeyType, typename ValueType>
BST<KeyType, ValueType>::BST(const BST &another) {

}

template <typename KeyType, typename ValueType>
bool BST<KeyType, ValueType>::isEmpty() const {
    return false;
}

template <typename KeyType, typename ValueType>
const BST *BST<KeyType, ValueType>::findMin() const {
    return nullptr;
}

template <typename KeyType, typename ValueType>
const BST &BST<KeyType, ValueType>::rightSubtree() const {
    return <#initializer#>;
}

template <typename KeyType, typename ValueType>
const BST &BST<KeyType, ValueType>::leftSubtree() const {
    return <#initializer#>;
}

template <typename KeyType, typename ValueType>
bool BST<KeyType, ValueType>::add(KeyType key, ValueType value) {
    return false;
}

template <typename KeyType, typename ValueType>
bool BST<KeyType, ValueType>::remove(KeyType key) {
    return false;
}

template <typename KeyType, typename ValueType>
ValueType BST<KeyType, ValueType>::get(KeyType key) const {
    return nullptr;
}

template <typename KeyType, typename ValueType>
int BST<KeyType, ValueType>::count() const {
    return 0;
}

template <typename KeyType, typename ValueType>
int BST<KeyType, ValueType>::height() const {
    return 0;
}

template <typename KeyType, typename ValueType>
const Pair<KeyType, ValueType> *BST<KeyType, ValueType>::operator[](int n) const {
    return nullptr;
}

template <typename KeyType, typename ValueType>
void BST<KeyType, ValueType>::print(ostream &os) const {

}