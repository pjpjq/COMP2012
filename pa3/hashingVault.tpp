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
    delete table;
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
    int old_size = this->size;
    Container<KeyType, ValueType> **old_table = this->table;
    
    this->fun = fun;
    this->size = size;
    this->table = table;
    
    for (int i = 0; i < old_size; ++i) {
        delete old_table[i];
    }
    delete old_table;
}
