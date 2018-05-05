//submit this file
//you do NOT need to include any header in this file
//just write your BST implementation here right away

template <typename KeyType, typename ValueType>
BST<KeyType, ValueType>::BST(const BST &another) {
    if (another.isEmpty()) {
        return;
    }
    
    /* Recursively copy from the root. */
    root = new BSTNode<KeyType, ValueType>(*another.root);
}

template <typename KeyType, typename ValueType>
bool BST<KeyType, ValueType>::isEmpty() const {
    /* Empty iff no node at all. */
    return !root;
}

template <typename KeyType, typename ValueType>
const BST<KeyType, ValueType> *BST<KeyType, ValueType>::findMin() const {
    /* Returns nullptr if the tree is empty. */
    if (isEmpty()) {
        return nullptr;
    }
//    /* Returns itself if only 1 node. */
//    if (count() == 1) {
//        return this;
//    }
//
//    /* When size >= 2, find the min of the left subtree. */
//    return leftSubtree().findMin();
    const BST<KeyType, ValueType> *bst_ptr = this;
    while (!bst_ptr->leftSubtree().isEmpty()) {
        bst_ptr = &bst_ptr->leftSubtree();
    }
    return bst_ptr;
}

template <typename KeyType, typename ValueType>
const BST<KeyType, ValueType> &BST<KeyType, ValueType>::rightSubtree() const {
    /**
     * Assuming the root is not nullptr when calling rightSubtree().
     */
    return root->right;
}

template <typename KeyType, typename ValueType>
const BST<KeyType, ValueType> &BST<KeyType, ValueType>::leftSubtree() const {
    /**
     * Assuming the root is not nullptr when calling leftSubtree().
     */
    return root->left;
}

template <typename KeyType, typename ValueType>
bool BST<KeyType, ValueType>::add(KeyType key, ValueType value) {
    //TODO: handle int type
//    if (typeid(ValueType) == typeid(int)) {
//        if (get(key) != 0) { return false; }
//    } else {
    if (get(key) != ValueType()) { /* Duplicate key, cannot add. */
        return false;
    }
//    }
    
    if (isEmpty()) {
        root = new BSTNode<KeyType, ValueType>(key, value);
    } else if (key < root->data.key) { /* Adds smaller key to the left subtree. */
        root->left.add(key, value);
    } else { /* Adds larger key to the right subtree. */
        root->right.add(key, value);
    }
    
    /* Updates the size after adding a node. */
    ++size;
    return true;
}

template <typename KeyType, typename ValueType>
bool BST<KeyType, ValueType>::remove(KeyType key) {
    //TODO: handle int type
//    if (typeid(ValueType) == typeid(int)) {
//        if (get(key) == 0) { return false; }
//    } else {
    if (get(key) == ValueType()) { /* default value means not found, cannot remove the key. */
        return false;
    }
//    }
    
    if (key < root->data.key) {
        root->left.remove(key);
    } else if (key > root->data.key) {
        root->right.remove(key);
    } else { /* Deletes the not-nullptr root. */
        if (root->left.isEmpty() || root->right.isEmpty()) {
            BSTNode <KeyType, ValueType> *deleting_root = root;
            root = root->right.isEmpty() ? root->left.root : root->right.root;
            deleting_root->left.root = deleting_root->right.root = nullptr;
            delete deleting_root;
        } else { /* Has 2 subtrees. */
            /* Copies the data of min of right subtree to the root and removes the node. */
            root->data = (rightSubtree().findMin())->root->data;
            root->right.remove(root->data.key);
        }
    }
    
    /* Updates the size after removing the key. */
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
    
    /* Cannot get the key, returns the default special value. */
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
    if (n < 0 || n >= size) { /* Index is out of range. */
        return nullptr;
    }
    
    if (n == root->left.count()) { /* The root has the (n+1)th smallest key. */
        return &root->data;
    } else if (n < root->left.count()) { /* The node is in the left subtree. */
        return root->left[n];
    } else { /* The node is in the right subtree. */
        return root->right[n - root->left.count() - 1];
    }
}

template <typename KeyType, typename ValueType>
void BST<KeyType, ValueType>::print(ostream &os) const {
    for (int i = 0; i < size; ++i) {
        os << "(" << operator[](i)->key << "," << operator[](i)->value << ")";
    }
}