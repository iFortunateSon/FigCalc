#include "fatfigure.h"


FatFigure::FatFigure(const float a, const float b)
{
    if(a > 0 && b > 0){
        setA(a);
        setB(b);
    }else{
        //err
    }
};


FatFigure::FatFigure(const FatFigure &copy){
    setA(copy.getA());
    setB(copy.getB());
};
