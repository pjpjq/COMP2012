#include <iostream>

#include "matrix.h"

using namespace std;

bool print_step{false};

/**
 * Constructor for generating an num_rows * num_cols matrix.
 * The default value for each element is 0.
 * @param num_rows the number of rows
 * @param num_cols the number of columns
 */
Matrix::Matrix(int num_rows, int num_cols) : num_rows(num_rows), num_cols(num_cols) {
    if (print_step) { cout << "constructor" << endl; }
    ptr = new int[num_rows * num_cols];
    for (int i = 0; i < num_rows * num_cols; ++i) {
        ptr[i] = 0;
    }
}

/**
 * Constructor for generating an num_rows * num_cols matrix.
 * The value of elements will be assigned according to given array.
 * @param data the data array
 * @param num_rows the number of rows
 * @param num_cols the number of columns
 */
Matrix::Matrix(int *data, int num_rows, int num_cols) : num_rows(num_rows), num_cols(num_cols) {
    if (print_step) { cout << "constructor" << endl; }
    ptr = new int[num_rows * num_cols];
    for (int i = 0; i < num_rows * num_cols; ++i) {
        ptr[i] = data[i];
    }
}

/**
 * Destructor
 */
Matrix::~Matrix() {
    if (ptr != nullptr) {
        delete[] ptr;
    }
}

/**
 * Copy constructor
 * TODO: To be implemented in Task 1
 * @param mat
 */
Matrix::Matrix(const Matrix &mat) : num_cols(mat.num_cols), num_rows(mat.num_rows) {
    if (print_step) { cout << "copy constructor" << endl; }     // please keep this line
    ptr = new int[num_rows * num_cols];
    for (int i = 0; i < num_cols * num_rows; ++i) {
        ptr[i] = mat.ptr[i];
    }
}

/**
 * Move constructor
 * TODO: To be implemented in Task 1
 * @param mat
 */
Matrix::Matrix(Matrix &&mat) : num_rows(mat.num_rows), num_cols(mat.num_cols), ptr(mat.ptr) {
    if (print_step) { cout << "move constructor" << endl; }     // please keep this line
    mat.num_rows = 0;
    mat.num_cols = 0;
    mat.ptr = nullptr;
}

/**
 * Assignment operator
 * TODO: To be implemented in Task 1
 * @param mat
 */
const Matrix &Matrix::operator=(const Matrix &mat) {
    if (print_step) { cout << "operator =" << endl; }     // please keep this line
    if (this == &mat) {
        return *this;
    }
    delete[] ptr;
    num_cols = mat.num_cols;
    num_rows = mat.num_rows;
    ptr = new int[num_cols * num_rows];
    for (int i = 0; i < num_cols * num_rows; ++i) {
        ptr[i] = mat.ptr[i];
    }
    return *this;
}

/**
 * Move assignment operator
 * TODO: To be implemented in Task 1
 * @param mat
 */
const Matrix &Matrix::operator=(Matrix &&mat) {
    if (print_step) { cout << "move operator =" << endl; }     // please keep this line
    if (this == &mat) {
        return *this;
    }
    delete[] ptr;
    num_cols = mat.num_cols;
    num_rows = mat.num_rows;
    ptr = mat.ptr;
    
    mat.num_cols = 0;
    mat.num_rows = 0;
    mat.ptr = nullptr;
    return *this;
}

/**
 * Operator + overloading
 * TODO: To be implemented in Task 2; no rvalue is required
 * @param mat the reference of another Matrix
 * @return
 */
Matrix Matrix::operator+(const Matrix &mat) {
    if (print_step) { cout << "operator +" << endl; }     // please keep this line
    Matrix result{*this};
    for (int i = 0; i < num_rows * num_cols; ++i) {
        result.ptr[i] += mat.ptr[i];
    }
    return result;
}

/**
 * Operator + for rvalue overloading
 * TODO: To be implemented in Task 2
 * @param mat the rvalue reference of another Matrix
 * @return
 */
Matrix &Matrix::operator+(Matrix &&mat) {
    if (print_step) { cout << "operator + for rvalue" << endl; }     // please keep this line
    Matrix &&result = move(mat);
    for (int i = 0; i < num_rows * num_cols; ++i) {
        result.ptr[i] += ptr[i];
    }
    return result;
}

/**
 * Operator (x, y) for getting the matrix element
 * TODO: To be implemented in Task 2
 * @return the value at x-th row and y-th column
 */
int Matrix::operator()(int x, int y) const {
    if (x < 0 || x >= num_rows || y < 0 || y >= num_cols) {
        cerr << "Invalid index!" << endl;
        return -1;
    }
    return ptr[x * num_rows + y];
}

/* Print the elements of the matrix */
void Matrix::print() const {
    for (int i = 0; i < num_rows; i++) {
        cout << (i == 0 ? "[" : " ");
        for (int j = 0; j < num_cols; j++) {
            cout << ptr[i * num_cols + j];
            if (j != num_cols - 1) { cout << ", "; }
        }
        cout << (i == num_rows - 1 ? "]" : ";");
        cout << endl;
    }
}

/* Switcher for result printing.
 * Please do not modify the following methods. */
void enable_print_step() { print_step = true; }

void disable_print_step() { print_step = false; }
