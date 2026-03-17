#include <sstream>
#include "triangle.h"

using std::stringstream;

string Triangle::to_string()
{
    stringstream ss;

    ss << "{"
        << "\n\t"
        << "\"figure_type\": \"triangle\","
        << "\n\t"
        << "\"area\": " << this->calc_area()
        << "\n"
        << "}";

    return ss.str();
}