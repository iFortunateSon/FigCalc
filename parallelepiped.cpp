#include "parallelepiped.h"

parallelepiped::parallelepiped(const float a, const float b,const float c):FatFigure(a,b){
    setC(c);
}

void parallelepiped::setA(const float size){
    if(size > 0)
    {
        setA(size);
    }else{
        //err
    }
}

void parallelepiped::setB(const float size){
    if(size > 0)
    {
        setB(size);
    }else{
        //err
    }
}

void parallelepiped::setC(const float size){
    if(size > 0)
    {
        setC(size);
    }else{
        //err
    }
}

float parallelepiped::getA() const{
    return getA();
}

float parallelepiped::getB() const{
    return getB();
}

float parallelepiped::getC() const{
    return getC();
}

float parallelepiped::getVolume() const{
    auto a = getA();
    auto b = getB();
    auto c = getC();
    auto V = a*b*c;

    return V;
}

float parallelepiped::getSquare() const{
    auto a = getA();
    auto b = getB();
    auto c = getC();
    auto S = 2*(a*b+b*c+c*a);

    return S;
}

float parallelepiped::getDiagonal() const{
    auto a = getA();
    auto b = getB();
    auto c = getC();
    auto D = sqrt(a*a+b*b+c*c);

    return D;
}
