#include "flatfigure.h"

FlatFigure::FlatFigure(const float a, const float b)
{
    setA(a);
    setB(b);
};


FlatFigure::FlatFigure(const FlatFigure &copy){
    setA(copy.getA());
    setB(copy.getB());
};
