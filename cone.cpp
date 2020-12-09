#include "cone.h"

cone::cone(const float a, const float b):
    FatFigure(a, b){
};

void cone::setRadius(const float size){
    if(size > 0)
    {
        setA(size);
    }else{
        //err
    }
}

void cone::setHeight(const float size){
    if(size > 0)
    {
        setB(size);
    }else{
        //err
    }
}

float cone::getRadius() const{
    return getA();
}

float cone::getHeight() const{
    return getB();
}

float cone::getVolume() const{
    auto r = getA();
    auto h = getB();
    auto pi = 3.14;
    auto V = 1/3*pi*r*r*h;

    return V;
}

float cone::getSquare() const{
    auto r = getA();
    auto h = getB();
    auto pi = 3.14;
    auto l = sqrt(r*r+h*h);
    auto S = pi*r*(l+r);

    return S;
}

float cone::getAngle() const{
    //?
}
