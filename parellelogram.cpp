#include "parallelogram.h"

parallelogram::parallelogram(const float a, const float b,const float c):FlatFigure(a,b){
    setC(c);
}

void parallelogram::setC(const float size)
{
    if(size > 0){
        c = size;
    }else{
        //err
    }
};

float parallelogram::getC() const
{
    return c;
};

void parallelogram::setWidth(const float size){
    if(size > 0)
    {
        setA(size);
    }else{
        //err
    }
}

void parallelogram::setThicknness(const float size){
    if(size > 0)
    {
        setB(size);
    }else{
        //err
    }
}

void parallelogram::setAngle(const float angle){ // ?????????
    if(angle > 0)
    {
        setC(angle);
    }else{
        //err
    }
}

float parallelogram::getWidth() const{
    return getA();
}

float parallelogram::getThicknness() const{
    return getB();
}

float parallelogram::getAngle() const{
    return getC();
}

float parallelogram::getSquare() const{
    auto a = getA();
    auto b = getB();
    auto ab = getC();
    auto pi = 3.14;
    double S = a*b*sin(ab*pi/180);

    return S;
}

float parallelogram::getPerimeter() const{
    auto a = getA();
    auto b = getB();
    double P = (a+b)*2;

    return P;
}

float parallelogram::getDiagonale() const{
    auto a = getA();
    auto b = getB();
    auto ab = getC();
    auto pi = 3.14;
    auto D = sqrt(a*a+b*b-2*b*a*cos(ab*pi/180));

    return D;
}
