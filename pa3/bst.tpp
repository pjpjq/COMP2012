//submit this file
//you do NOT need to include any header in this file
//just write your BST implementation here right away

#include "bst.h"

template <typename KeyType, typename ValueType>
BST<KeyType, ValueType>::BST(const BST &another) {
    if (another.isEmpty()) {
        return;
    }
    root = new BSTNode(*another.root);
}

template <typename KeyType, typename ValueType>
bool BST<KeyType, ValueType>::isEmpty() const {
    return !root;
}

template <typename KeyType, typename ValueType>
const BST *BST<KeyType, ValueType>::findMin() const {
    if (!root) {
        return this;
    }
    const BSTNode *node = root;
    while (!node->left.isEmpty()) {
        node = node->left.root;
    }
    return node;
}

template <typename KeyType, typename ValueType>
const BST &BST<KeyType, ValueType>::rightSubtree() const {
    return root ? root->right : BST();
}

template <typename KeyType, typename ValueType>
const BST &BST<KeyType, ValueType>::leftSubtree() const {
    return root ? root->left : BST();
}

template <typename KeyType, typename ValueType>
bool BST<KeyType, ValueType>::add(KeyType key, ValueType value) {
    bool found = !(typeid(int) != typeid(ValueType) && get(key) == ValueType() ||
                   typeid(int) == typeid(ValueType) && get(key) == 0);
    if (found) { /* Cannot add */
        return false;
    }
    if (isEmpty()) {
        root = new BSTNode(key, value);
    } else if (key < root->data.key) {
        root->left.add(key, value);
    } else {
        root->right.add(key, value);
    }
    ++size;
    return true;
    
}

template <typename KeyType, typename ValueType>
bool BST<KeyType, ValueType>::remove(KeyType key) {
    bool found = !(typeid(int) != typeid(ValueType) && get(key) == ValueType() ||
                   typeid(int) == typeid(ValueType) && get(key) == 0);
    if (!found) { /* Cannot remove */
        return false;
    }
    --size;
    return true;
}

template <typename KeyType, typename ValueType>
ValueType BST<KeyType, ValueType>::get(KeyType key) const {
    BSTNode *node = root;
    while (node) {
        if (node->data.key == key) {
            return node->data.value;
        } else if (key < node->data.key) {
            node = node->left.root;
        } else {
            node = node->right.root;
        }
    }
    return typeid(ValueType) == typeid(int) ? 0 : ValueType();
}

template <typename KeyType, typename ValueType>
int BST<KeyType, ValueType>::count() const {
    return size;
}

template <typename KeyType, typename ValueType>
int BST<KeyType, ValueType>::height() const {
    if (count() <= 1) {
        return 0;
    }
}

template <typename KeyType, typename ValueType>
const Pair<KeyType, ValueType> *BST<KeyType, ValueType>::operator[](int n) const {
    return nullptr;
}

template <typename KeyType, typename ValueType>
void BST<KeyType, ValueType>::print(ostream &os) const {

}