#include <string>

#include "Figures.h"

using std::string;

class Rectangle : public Figure {
    double *width;
    double *height;

public:
    Rectangle(double width, double height) {
        this->width = new double(width);
        this->height = new double(height);
    }

    ~Rectangle() override {
        delete this->width;
        delete this->height;
    };

    double calc_area() override {
        return *width * *height;
    };

    string to_string() override;
};