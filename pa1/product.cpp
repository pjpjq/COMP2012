//Submit this file
#include "product.h"
//You are NOT allowed to include any additional library

Product::Product(string name, ProductType type, float price) : name(name), type(type), price(price) {
    quantity = 0;
}

string Product::getName() {
    return name;
}

ProductType Product::getType() {
    return type;
}

float Product::getPrice() {
    return price;
}

int Product::getQuantity() {
    return quantity;
}

bool Product::setPrice(float price) {
    if (price <= 0) { return false; }
    this->price = price;
    return true;
}

bool Product::setQuantity(int quantity) {
    if (quantity < 0) { return false; }
    this->quantity = quantity;
    return true;
}

int Product::compare(Product *other) {
    if (fabs(this->price - other->getPrice()) < 0.01f) {
        // Assume no two product will have the same name
        if (this->name > other->getName()) { return 1; }
        else if (this->name < other->getName()) { return -1; }
        else { return 0; } // In case it compares to itself
    } else if (this->price > other->getPrice()) { return 1; }
    else { return -1; }
}
