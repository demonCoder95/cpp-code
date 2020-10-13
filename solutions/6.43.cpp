// Computing distance between two algebraic points
#include <cmath>

inline double distance(double, double, double, double);

inline double distance(double x1, double y1, double x2, double y2){
    return sqrt(pow(x2-x1, 2) + pow(y2-y1, 2));
}