#include "rectangle.h"

rectangle::rectangle(const float a, const float b):
    FlatFigure(a, b){};

rectangle::rectangle(const rectangle &copy):
    FlatFigure(copy){};

void rectangle::setFirstSide(const float size){
    if(size > 0)
    {
        setA(size);
    }else{
        //err
    }
}

void rectangle::setSecondSide(const float size){
    if(size > 0)
    {
        setB(size);
    }else{
        //err
    }
}

float rectangle::getFirstSide() const{
    return getA();
}

float rectangle::getSecondSide() const{
    return getB();
}

float rectangle::getPerimeter() const{
    return (getA()+getB())*2;
}

float rectangle::getSquare() const{
    return getA() * getB();
}

float rectangle::getDiagonal() const{
    int a = getA();
    int b = getB();

    return sqrt(a*a*+b*b);
}
