//Submit this file
#include "mall.h"
//You are NOT allowed to include any additional library

//NOTE: Mall::duplicateShopLinkedList must NOT be implemented here

Mall::Mall(string name, string address) : name(name), address(address) {
    shopHead = nullptr;
}

Mall::Mall(Mall &another) {
    // Use duplicateShopLinkedList() to copy
    shopHead = duplicateShopLinkedList(another.shopHead);
    name = another.name;
    address = another.address;
}

Mall::~Mall() {
    // Delete the whole list
    Node *head = shopHead;
    Node *temp = shopHead;
    while (temp != nullptr) {
        temp = temp->getNext();
        delete head;
        head = temp;
    }
}

Shop *Mall::getShop(int shopNumber) {
    if (shopHead == nullptr) { return nullptr; }
    else {
        // Traverse the list
        Node *temp = shopHead;
        while (temp != nullptr) {
            if (temp->getShop()->getShopNumber() == shopNumber) {
                return temp->getShop();
            }
            temp = temp->getNext();
        }
        return nullptr;
    }
}

void Mall::setName(string name) {
    this->name = name;
}

void Mall::setAddress(string address) {
    this->address = address;
}

string Mall::getName() {
    return name;
}

string Mall::getAddress() {
    return address;
}

bool Mall::addShop(string name, int shopNumber) {
    if (shopHead == nullptr) {
        shopHead = new Node(new Shop(name, shopNumber), nullptr);
        return true;
    }
    Node *temp = shopHead;
    do {
        if (temp->getShop()->getShopNumber() == shopNumber) { return false; }
        if (temp->getNext() == nullptr) {
            temp->setNext(new Node(new Shop(name, shopNumber), nullptr));
            return true;
        }
        temp = temp->getNext();
    }
    while (temp != nullptr);
}

bool Mall::removeShop(int shopNumber) {
    Node *fence = shopHead;
    Node *formerPointer = fence;
    if (fence == nullptr) { return false; }
    while (fence->getNext() != nullptr) {
        formerPointer = fence; // Save fence former pointer
        if (fence->getShop()->getShopNumber() == shopNumber) {
            // Swap next Node and current Node and delete next Node
            Shop *tempShop = fence->getShop();
            fence->setShop(fence->getNext()->getShop());
            Node *temp = fence->getNext();
            fence->setNext(temp->getNext());
            temp->setShop(tempShop);
            delete temp;
            return true;
        } else { fence = fence->getNext(); }
    }
    if (fence->getShop()->getShopNumber() == shopNumber) { // In tail node
        formerPointer->setNext(nullptr);
        delete fence;
        return true;
    }
    return false;
}
