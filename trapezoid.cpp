#include <sstream>

#include "trapezoid.h"


using std::stringstream;

string Trapezoid::to_string()
{
    stringstream ss;

    ss << "{"
        << "\n\t"
        << "\"figure_type\": \"trapezoid\","
        << "\n\t"
        << "\"area\": " << this->calc_area()
        << "\n"
        << "}";

    return ss.str();

}