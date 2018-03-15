//Submit this file
#include "mall.h"
//You are NOT allowed to include any additional library

//NOTE: Mall::duplicateShopLinkedList must be implemented here
//NOTE: recursion is a requirement - NO loops of any kind is allowed in this file
//a checking needs to be done by you after you finish your code,
// please refer to the 4th item in "Additional notes" on the webpage
Node *Mall::duplicateShopLinkedList(Node *node) {
    Node *temp = nullptr;
    if (node == nullptr) { return temp; }
    else {
        Shop *dup = new Shop(*node->getShop());
        temp = new Node(dup, duplicateShopLinkedList(node->getNext()));
        return temp;
    }
}