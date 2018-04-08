#include <iostream>

using namespace std;
const int STACK_CAPACITY = 64;

template <typename T>
class Stack {
public:
    Stack() {};
    
    ~Stack() {};
    
    /****** START YOUR DECLARATION FOR PART 1 HERE ******/
    
    // ACCESSOR member functions:
    bool empty() const;    // Check if the stack is empty
    bool full() const;       // Check if the stack is full
    int size() const;       // Give the number of data currently stored
    
    // Overload operator "~" to retrieve the top item from the stack
    const T &operator~() const;
    
    // Overload operator "==" to check the equality of stack objects
    bool operator==(const Stack<T> &stack) const;
    
    // MUTATOR member functions:
    
    // Overload operator "+=" to add a new item to the top
    const Stack &operator+=(const T &item);
    
    // Overload operator "--" to remove the top item from the stack
    //       and return the new top item (** SYNTAX: Stack<int> A; --stack; **)
    // pre-decrement
    T operator--();
    
    // Overload operator "--" to return the top item and remove it
    //       from the stack (** SYNTAX: Stack<int> A; stack--; **)
    // post-decrement
    T operator--(int);
    
    /******* END YOUR DECLARATION FOR PART 1 HERE *******/

private:
    int top_index{-1};            // Start from 0; -1 when empty
    T data[STACK_CAPACITY];   // Use an array to store the data
    
};

/****** START YOUR IMPLEMENTATION FOR PART 1 HERE ******/
template <typename T>
bool Stack<T>::empty() const {
    return size() == 0;
}

template <typename T>
bool Stack<T>::full() const {
    return size() >= STACK_CAPACITY;
}

template <typename T>
int Stack<T>::size() const {
    return top_index + 1;
}

template <typename T>
const T &Stack<T>::operator~() const {
    if (empty()) {
        cerr << "[ERROR] Stack is empty, returning a garbage value" << endl;
//        cout << "[ERROR] Stack is empty, returning a garbage value" << endl;
        return *(new T);
    }
    return data[top_index];
}

template <typename T>
bool Stack<T>::operator==(const Stack<T> &stack) const {
    if (size() != stack.size()) {
        return false;
    }
    for (int i = 0; i < size(); ++i) {
        if (data[i] != stack.data[i]) {
            return false;
        }
    }
    return true;
}

template <typename T>
const Stack<T> &Stack<T>::operator+=(const T &item) {
    if (full()) {
        cerr << "[ERROR] Stack is full, can't add new value" << endl;
//        cout << "[ERROR] Stack is full, can't add new value" << endl;
        return *this;
    }
    data[++top_index] = item;
    return *this;
}

template <typename T>
T Stack<T>::operator--() {
    if (empty()) {
        cerr << "[ERROR] Stack is empty, returning a garbage value" << endl;
//        cout << "[ERROR] Stack is empty, returning a garbage value" << endl;
        return *(new T);
    }
    --top_index;
    return ~*this;
}

template <typename T>
T Stack<T>::operator--(int) {
    if (empty()) {
//        cout << "[ERROR] Stack is empty, returning a garbage value" << endl;
        cerr << "[ERROR] Stack is empty, returning a garbage value" << endl;
        return *(new T);
    }
    return data[top_index--];
}

// Overload operator "<<" to show the items stored in the stack object
template <typename T>
ostream &operator<<(ostream &out, const Stack<T> &stack) {
    Stack<T> temp{stack};
    while (!temp.empty()) {
        out << temp-- << endl;
    }
    return out;
}

/******* END YOUR IMPLEMENTATION FOR PART 1 HERE *******/
