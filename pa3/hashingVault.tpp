//submit this file
//you do NOT need to include any header in this file
//just write your HashingVault implementation here right away

template <typename KeyType, typename ValueType>
HashingVault<KeyType, ValueType>::HashingVault(int size, Container<KeyType, ValueType> **table, int (*fun)(KeyType))
        : size(size), table(table), fun(fun) {
}

template <typename KeyType, typename ValueType>
HashingVault<KeyType, ValueType>::~HashingVault() {
    for (int i = 0; i < size; ++i) {
        delete table[i];
    }
    delete[] table;
}

template <typename KeyType, typename ValueType>
bool HashingVault<KeyType, ValueType>::add(KeyType key, ValueType value) {
    return table[fun(key)]->add(key, value);
}

template <typename KeyType, typename ValueType>
ValueType HashingVault<KeyType, ValueType>::get(KeyType key) const {
    return table[fun(key)]->get(key);
}

template <typename KeyType, typename ValueType>
bool HashingVault<KeyType, ValueType>::remove(KeyType key) {
    return table[fun(key)]->remove(key);
}

template <typename KeyType, typename ValueType>
void HashingVault<KeyType, ValueType>::rehash(int size, Container<KeyType, ValueType> **table, int (*fun)(KeyType)) {
    /* Temporarily saves the old size and table for later deletion. */
    int old_size = this->size;
    Container<KeyType, ValueType> **old_table = this->table;
    
    /* Updates the size, fun and table. */
    this->size = size;
    this->fun = fun;
    if (this->table != table) { /* Using a new table. */
        this->table = table;
    } else {
        /* Keeps the same old table but size and fun may be different,
         * constructs a new table instead of using the given table for ease of deleting the old table later.  */
        this->table = new Container<KeyType, ValueType> *[this->size];
    }
    
    /* Adds new items into the new table from the old one. */
    for (int i = 0; i < old_size; ++i) {
        for (int j = 0; j < old_table[i]->count(); ++j) {
            add(old_table[i]->operator[](j)->key, old_table[i]->operator[](j)->value);
        }
    }
    
    /* Deletes the old table. */
    for (int i = 0; i < old_size; ++i) {
        delete old_table[i];
    }
    delete[] old_table;
}
