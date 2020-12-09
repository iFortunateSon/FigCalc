#include "trapezoid.h"

trapezoid::trapezoid(const float a, const float b, const float c, const float d):FlatFigure(a, b)
{
    if(c > 0 && d > 0){
        setC(c);
        setD(d);
    }
}
