#include "cylinder.h"

cylinder::cylinder(const float a, const float b):
    VolumeFigure(a, b){
};

cylinder::cylinder(const cylinder& copy):
VolumeFigure(copy)
{};




void cylinder::setRadius(const float size){
    if(size > 0)
    {
        setA(size);
    }else{
        //err
    }
}

void cylinder::setHeight(const float size){
    if(size > 0)
    {
        setB(size);
    }else{
        //err
    }
}

float cylinder::getRadius() const{
    return getA();
}

float cylinder::getHeight() const{
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
