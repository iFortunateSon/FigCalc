#include "prism.h"

prism::prism(const float a, const float b,const float c):FatFigure(a,b){
    setC(c);
}

void prism::setA(const float size){
    if(size > 0)
    {
        setA(size);
    }else{
        //err
    }
}

void prism::setB(const float size){
    if(size > 0)
    {
        setB(size);
    }else{
        //err
    }
}

void prism::setC(const float size){
    if(size > 0)
    {
        setC(size);
    }else{
        //err
    }
}

float prism::getA() const{
    return getA();
}

float prism::getB() const{
    return getB();
}

float prism::getC() const{
    return getC();
}

float prism::getVolume() const{
    auto a = getA();
    auto h = getB();
    auto n = getC();
    auto pi = 3.14;
    auto r = a/(2*tan(360/(2*n)*pi/180));
    auto Socn = a*r*n/2;

    auto S = Socn*h/3;

    return S;
}

float prism::getSquare() const{
    auto a = getA();
    auto h = getB();
    auto n = getC();
    auto pi = 3.14;
    auto r = a/(2*tan(360/(2*n)*pi/180));
    auto Socn = a*r*n/2;

    auto l = sqrt(a*a+h*h);
    auto Sbok = l*a/2;

    auto S = n*Sbok + Socn;

    return S;
}
