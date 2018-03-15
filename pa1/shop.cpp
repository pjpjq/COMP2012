//Submit this file
#include "shop.h"
//You are NOT allowed to include any additional library

Shop::Shop(string name, int shopNumber) : name(name), shopNumber(shopNumber) {
    productCount = 0;
    products = nullptr;
}

Shop::Shop(Shop &another) {
    this->name = another.getName();
    this->shopNumber = another.getShopNumber();
    // Deep copy dynamic array
    this->productCount = another.productCount;
    products = new Product *[productCount];
    for (int i = 0; i < productCount; i++) {
        products[i] = new Product(another.products[i]->getName(), another.products[i]->getType(),
                                  another.products[i]->getPrice());
        products[i]->setQuantity(another.products[i]->getQuantity());
    }
}

Shop::~Shop() {
    for (int i = 0; i < productCount; i++) {
        delete products[i];
    }
}

string Shop::getName() {
    return name;
}

int Shop::getShopNumber() {
    return shopNumber;
}

void Shop::setName(string name) {
    this->name = name;
}

void Shop::setShopNumber(int shopNumber) {
    this->shopNumber = shopNumber;
}

void Shop::addProduct(string name, ProductType type, float price, int quantityToAdd) {
    Product *temp = findProduct(name);
    if (temp == nullptr) {
        // If there don't have the product to be added, add a new product and
        // Create a new array and copy original one and compare new product to decide which one go first
        Product **tempArr = new Product *[productCount + 1];
        Product *newProduct = new Product(name, type, price);
        newProduct->setQuantity(quantityToAdd);
        for (int i = 0, j = 0; i < productCount + 1; i++) {
            // `j == i` will reduce compare times if new product already added;
            // `products != nullptr` will prevent from empty array;
            // `j != productCount` will prevent products from out of bound
            if (j != i || (products != nullptr && j != productCount && products[j]->compare(newProduct) == -1)) {
                tempArr[i] = new Product(products[j]->getName(), products[j]->getType(),
                                         products[j]->getPrice());
                tempArr[i]->setQuantity(products[j]->getQuantity());
                ++j;
            } else {
                tempArr[i] = newProduct;
            }
        }
        for (int i = 0; i < productCount; i++) {
            delete products[i];
        } // Free original one and point to new array
        productCount++;

        products = tempArr;
    }
        // Add quantity to original one
    else {
        temp->setQuantity(quantityToAdd + temp->getQuantity());
    }
}

bool Shop::removeProduct(string name, int quantityToRemove) {
    Product *temp = findProduct(name);
    if (temp == nullptr || temp->getQuantity() < quantityToRemove) {
        return false;
    } else if (temp->getQuantity() == quantityToRemove) {
        // Remove the element pointed by temp
        Product **arr = new Product *[productCount - 1];
        for (int i = 0, j = 0; i < productCount; i++) {
            if (temp == products[i]) {
                continue;
            }
            arr[j] = new Product(products[i]->getName(), products[i]->getType(),
                                 products[i]->getPrice());
            arr[j]->setQuantity(products[i]->getQuantity());
            j++;
        }
        for (int i = 0; i < productCount; i++) {
            delete products[i];
        } // Free original one
        productCount--;
        products = arr;
    } else {
        temp->setQuantity(temp->getQuantity() - quantityToRemove);
    }
    return true;
}

Product *Shop::findProduct(string name) {
    for (int i = 0; i < productCount; i++) {
        if (products[i]->getName() == name) {
            return products[i];
        }
    }
    return nullptr;
}

void swap(Product *&a, Product *&b) {
    Product *temp = a;
    a = b;
    b = temp;
    temp = nullptr;
}

bool Shop::updatePrice(string name, float price) {
    Product *temp = findProduct(name);
    if (temp == nullptr || price <= 0) {
        return false;
    }
    temp->setPrice(price);
    // Insert sort products
    for (int i = 0; i < productCount; i++) {
        for (int j = i; j > 0; j--) {
            if (products[j]->compare(products[j - 1]) == -1) {
                swap(products[j - 1], products[j]);
            }
        }
    }
    return true;
}
