#include "oval.h"

oval::oval(const float a, const float b):
    FlatFigure(a, b){
};

void oval::setFirstR(const float size){
    if(size > 0)
    {
        setA(size);
    }else{
        //err
    }
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

}
