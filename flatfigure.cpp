#include "flatfigure.h"

FlatFigure::FlatFigure(const float a, const float b)
{
    mode = 0;
    if(a > 0 && b > 0){
        setA(a);
        setB(b);
    }else{
        //err
    }
};


FlatFigure::FlatFigure(const FlatFigure &copy)
{
    setA(copy.getA());
    setB(copy.getB());
};


int FlatFigure::getMode() const
{
    return mode;
}

void FlatFigure::setA(const float size){
    if(size > 0){
        a = size;
    }else{
        //err
    }
}

void FlatFigure::setB(const float size){
    if(size > 0){
        b = size;
    }else{
        //err
    }
}

float FlatFigure::getA() const{
    return a;
}

float FlatFigure::getB() const{
    return b;
}
