//
// Created by pwd on 16/03/2018.
//

#include "Dog.h"

Dog::Dog(string name) : Animal(name) {
}

Dog::~Dog() {
    cout << "~Dog()" << endl;
}

void Dog::speak() const {
    Animal::speak();
    cout << " I am a Dog. Woof!" << endl;
}

void Dog::eat(string food) const {
    cout << "The dog swings its tail furiously and eats " << food << "!" << endl;
}

void Dog::swim() const {
    cout << "The dog swims freely!" << endl;
}
