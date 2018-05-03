//submit this file
//you do NOT need to include any header in this file
//just write your BST implementation here right away

template <typename KeyType, typename ValueType>
BST<KeyType, ValueType>::BST(const BST &another) {
    if (another.isEmpty()) {
        return;
    }
    root = new BSTNode<KeyType, ValueType>(*another.root);
}

template <typename KeyType, typename ValueType>
bool BST<KeyType, ValueType>::isEmpty() const {
    return !root;
}

template <typename KeyType, typename ValueType>
const BST<KeyType, ValueType> *BST<KeyType, ValueType>::findMin() const {
    if (isEmpty()) {
        return nullptr;
    }
    if (count() == 1) {
        return this;
    }
    /* Count() >= 2. */
    const BST<KeyType, ValueType> *tree_root = &leftSubtree();
    while (tree_root->count() > 1) {
        tree_root = &tree_root->leftSubtree();
    }
    return tree_root;
}

template <typename KeyType, typename ValueType>
const BST<KeyType, ValueType> &BST<KeyType, ValueType>::rightSubtree() const {
//    return root ? root->right : BST();
    return root->right;
}

template <typename KeyType, typename ValueType>
const BST<KeyType, ValueType> &BST<KeyType, ValueType>::leftSubtree() const {
//    return root ? root->left : BST();
    return root->left;
}

template <typename KeyType, typename ValueType>
bool BST<KeyType, ValueType>::add(KeyType key, ValueType value) {
//    if (typeid(ValueType) == typeid(int)) {
//        if (get(key) != 0) { return false; }
//    } else {
    if (get(key) != ValueType()) { return false; }
//    }
    
    if (isEmpty()) {
        root = new BSTNode<KeyType, ValueType>(key, value);
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
//    if (typeid(ValueType) == typeid(int)) {
//        if (get(key) == 0) { return false; }
//    } else {
    if (get(key) == ValueType()) { return false; }
//    }
    
    if (key < root->data.key) {
        root->left.remove(key);
    } else if (key > root->data.key) {
        root->right.remove(key);
    } else { /* Deletes the root. */
        if (root->left.isEmpty()) {
            BSTNode <KeyType, ValueType> *new_root = root->right.root;
            delete root;
            root = new_root;
        } else if (root->right.isEmpty()) {
            BSTNode <KeyType, ValueType> *new_root = root->left.root;
            delete root;
            root = new_root;
        } else { /* Has 2 subtrees. */
            root->data = root->right.findMin()->root->data;
            root->right.remove(root->data.key);
        }
    }
    --size;
    return true;
}

template <typename KeyType, typename ValueType>
ValueType BST<KeyType, ValueType>::get(KeyType key) const {
    BSTNode <KeyType, ValueType> *node = root;
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
    return 1 + max(root->left.height(), root->right.height());
}

template <typename KeyType, typename ValueType>
const Pair<KeyType, ValueType> *BST<KeyType, ValueType>::operator[](int n) const {
    if (n < 0 || n >= size) {
        return nullptr;
    }
    if (n == root->left.count()) {
        return &root->data;
    } else if (n < root->left.count()) { /* Node is in the left subtree. */
        return root->left[n];
    } else { /* Node is in the right subtree. */
        return root->right[n - root->left.count() - 1];
    }
}

template <typename KeyType, typename ValueType>
void BST<KeyType, ValueType>::print(ostream &os) const {
    for (int i = 0; i < size; ++i) {
        os << "(" << this->operator[](i)->key << "," << this->operator[](i)->value << ")";
    }
}