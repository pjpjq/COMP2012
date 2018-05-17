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
    delete[] data;
}

template <typename KeyType, typename ValueType>
bool SmartArray<KeyType, ValueType>::add(KeyType key, ValueType value) {
    if (has(key)) { /* Cannot add an existed key. */
        return false;
    }
    
    /* Finds the position of the new pair in the new array.
     * Keeps incrementing new_pair_pos until find data[i] > new_pair. */
    int new_pair_pos = 0;
    for (int i = 0; i < size; ++i) {
        if (data[i]->key < key) { /* Still not the position. */
            new_pair_pos = i + 1;
        } else {
            break;
        }
    }
    
    /* Constructs the new_data array. */
    Pair<KeyType, ValueType> **new_data = new Pair<KeyType, ValueType> *[size + 1];
    for (int i = 0; i < new_pair_pos; ++i) {
        new_data[i] = new Pair<KeyType, ValueType>{*(data[i])};
    }
    new_data[new_pair_pos] = new Pair<KeyType, ValueType>(key, value);
    for (int i = new_pair_pos + 1; i < size + 1; ++i) {
        new_data[i] = new Pair<KeyType, ValueType>{*(data[i - 1])};
    }
    
    /* Deletes the original data array. */
    for (int i = 0; i < size; ++i) {
        delete data[i];
    }
    delete[] data;
    
    /* Points to the new_data and updates size. */
    data = new_data;
    ++size;
    return true;
}

template <typename KeyType, typename ValueType>
bool SmartArray<KeyType, ValueType>::remove(KeyType key) {
    if (!has(key)) { /* Cannot remove if there is no such key. */
        return false;
    }
    
    /* Finds the deleting pair position. */
    int deleting_pair_pos = 0;
    for (int i = 0; i < size; ++i) {
        if (key == data[i]->key) {
            deleting_pair_pos = i;
        }
    }
    
    /* Constructs the new_data array. */
    Pair<KeyType, ValueType> **new_data = new Pair<KeyType, ValueType> *[size - 1];
    for (int i = 0; i < deleting_pair_pos; ++i) {
        new_data[i] = new Pair<KeyType, ValueType>{*(data[i])};
    }
    for (int i = deleting_pair_pos; i < size - 1; ++i) {
        new_data[i] = new Pair<KeyType, ValueType>{*(data[i + 1])};
    }
    
    /* Deletes the original data array. */
    for (int i = 0; i < size; ++i) {
        delete data[i];
    }
    delete[] data;
    
    /* Points to the new_data and updates size.*/
    data = new_data;
    --size;
    return true;
}

template <typename KeyType, typename ValueType>
ValueType SmartArray<KeyType, ValueType>::get(KeyType key) const {
    if (!has(key)) { /* Returns special value if there is no such key. */
        return typeid(ValueType) == typeid(int) ? 0 : ValueType();
    }
    /* O(n) sequential search, too lazy to use binary search... */
    for (int i = 0; i < size; ++i) {
        if (key == data[i]->key) {
            return data[i]->value;
        }
    }
    return ValueType(); // Redundant statement just to silent the compiler...
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
