#ifndef LABUBA3_TRAPEZOID_H
#define LABUBA3_TRAPEZOID_H

#include <string>

#include "Figures.h"

using std::string;


class Trapezoid : public Figure
{
    double *up;
    double *down;
    double *h;

public:
    Trapezoid(double up, double down, double h)
    {
        this->up = new double(up);
        this->down = new double(down);
        this->h = new double(h);
    }

    ~Trapezoid() override
    {
        delete this->up;
        delete this->down;
        delete this->h;
    }

    double calc_area() override
    {
        const double a = *this->up;
        const double b = *this->down;
        const double c = *this->h;

        return ((a*b)/2)*c;
    }

    string to_string() override;
};


#endif //LABUBA3_TRAPEZOID_H