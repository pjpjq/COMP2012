//
// Created by pwd on 16/03/2018.
//

#ifndef LAB5_DOG_H
#define LAB5_DOG_H


#include "Animal.h"

class Dog : public Animal {
public:
    Dog(string name);

    virtual ~Dog() override;

    virtual void speak() const override;

    virtual void eat(string food) const override;

    void swim() const;

private:
};


#endif //LAB5_DOG_H
