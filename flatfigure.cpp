#include "flatfigure.h"

FlatFigure::FlatFigure(const float a, const float b)
{
    if(a > 0 && b > 0){
        setA(a);
        setB(b);
    }else{
        //err
    }
};


FlatFigure::FlatFigure(const FlatFigure &copy){
    setA(copy.getA());
    setB(copy.getB());
};
