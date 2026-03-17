#ifndef LABUBA3_FIGURES_H
#define LABUBA3_FIGURES_H

#include <string>

using std::string;
using std::stringstream;

class Figure {
public:
    virtual ~Figure() = default;

    virtual double calc_area() = 0;

    virtual string to_string();
};

double calc_cylinder_volume(Figure *base, double height);

#endif //LABUBA3_FIGURES_H