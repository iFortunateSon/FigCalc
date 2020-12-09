#include "cylinder.h"

cylinder::cylinder(const float a, const float b):
    FatFigure(a, b){
};

void cylinder::setA(const float size){
    if(size > 0)
    {
        setA(size);
    }else{
        //err
    }
}

void cylinder::setB(const float size){
    if(size > 0)
    {
        setB(size);
    }else{
        //err
    }
}

float cylinder::getA() const{
    return getA();
}

float cylinder::getB() const{
    return getB();
}

float cylinder::getVolume() const{
    auto r = getA();
    auto h = getB();
    auto pi = 3.14;
    auto V = pi*r*r*h;

    return V;
}

float cylinder::getSquare() const{
    auto r = getA();
    auto h = getB();
    auto pi = 3.14;
    auto S = 2*pi*r*(h+r);

    return S;
}
