#ifndef LABUBA3_FLYINGBIRD_H
#define LABUBA3_FLYINGBIRD_H

#include "Bird.h"
#include <iostream>

using namespace std;

class FlyingBird : public Bird
{
public:
    void breathe() override
    {
        cout << "Flying bird breathes air efficiently for flight" << endl;
    }
    
    void eat() override
    {
        cout << "Flying bird eats high-energy food for flight" << endl;
    }
    
    void fly()
    {
        cout << "Flying bird soars through the sky" << endl;
    }
};

#endif //LABUBA3_FLYINGBIRD_H