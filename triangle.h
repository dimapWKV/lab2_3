#ifndef LABUBA3_TRIANGLE_H
#define LABUBA3_TRIANGLE_H

#include <string>
#include "Figures.h"

using std::string;

class Triangle : public Figure
{
    double *base;
    double *height;

public:
    Triangle(double base, double height)
    {
        this->base = new double(base);
        this->height = new double(height);
    }

    ~Triangle() override
    {
        delete this->base;
        delete this->height;
    }

    double calc_area() override
    {
        const double b = *this->base;
        const double h = *this->height;

        return (b * h) / 2;
    }

    string to_string() override;
};


#endif //LABUBA3_TRIANGLE_H