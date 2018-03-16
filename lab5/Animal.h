#ifndef ANIMAL_H
#define ANIMAL_H

#include <string>
#include <iostream>

using namespace std;

class Animal {
public:
    Animal(string name);

    virtual ~Animal();

    virtual void speak() const;

    virtual void eat(string food) const = 0;

private:
    string name;
};

#endif