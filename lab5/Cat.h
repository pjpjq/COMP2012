//
// Created by pwd on 16/03/2018.
//

#ifndef LAB5_CAT_H
#define LAB5_CAT_H


#include "Animal.h"

class Cat : public Animal {
public:
    Cat(string name);

    virtual ~Cat() override;

    virtual void speak() const override;

    virtual void eat(string food) const override;

private:

};


#endif //LAB5_CAT_H
