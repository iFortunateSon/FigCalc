#include "oval.h"

oval::oval(const float a, const float b):
    FlatFigure(a, b){
};

oval::oval(const oval &copy):
    FlatFigure(copy){};

void oval::setFirstR(const float size){
    if(size > 0)
    {
        setA(size);
    }else{
        //err
    }
}

QString oval::getInfoAsStr() const{

    return QString("Square: %1\nPerimeter: %2\n").arg(QString::number(getSquare()), QString::number(getPerimeter()));
}

void oval::setSecondR(const float size){
    if(size > 0)
    {
        setB(size);
    }else{
        //err
    }
}

float oval::getFirstR() const{
    return getA();
}

float oval::getSecondR() const{
    return getB();
}

float oval::getLarge() const{
    return (getA() - getB() < accuracy) ? getB() : getA();
}

float oval::getSmall() const{
    return (getA() - getB() < accuracy) ? getA() : getB();
}

float oval::getPerimeter() const{

    auto a = getA();
    auto b = getB();
    auto pi = 3.14;
    auto P = 2*pi*sqrt((a*a+b*b)/2);

    return P;
}

float oval::getSquare() const{

    auto a = getA();
    auto b = getB();
    auto pi = 3.14;
    auto S = pi*a*b;

    return S;
}
