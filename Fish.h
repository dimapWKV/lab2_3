#ifndef LABUBA3_FISH_H
#define LABUBA3_FISH_H

#include <iostream>
#include "Animal.h"

using namespace std;

class Fish : public Animal
{
public:
    void breathe() override
    {
        cout << "Fish breathes through gills in water" << endl;
    }

    void eat() override
    {
        cout << "Fish eats small organisms and plants in water" << endl;
    }

    void swim()
    {
        cout << "Fish swims using fins" << endl;
    }
};



#endif //LABUBA3_FISH_H