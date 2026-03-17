#ifndef LABUBA3_BIRD_H
#define LABUBA3_BIRD_H

#include <iostream>
#include "Animal.h"


using namespace std;

class Bird : public Animal
{
public:
    void breathe() override
    {
        cout << "Bird breathes air with lungs" << endl;
    }

    void eat() override
    {
        cout << "Bird eats seeds, insects or fish" << endl;
    }

    void lay_eggs()
    {
        cout << "Bird lays eggs in nest" << endl;
    }
};


#endif //LABUBA3_BIRD_H