#include "rectangle.h"

rectangle::rectangle(const float a, const float b):
    FlatFigure(a, b){};

rectangle::rectangle(const rectangle &copy):
    FlatFigure(copy){};

void rectangle::setHeight(const float size){
    if(size > 0)
    {
        setA(size);
    }else{
        //err
    }
}

void rectangle::setWidth(const float size){
    if(size > 0)
    {
        setB(size);
    }else{
        //err
    }
}

QString rectangle::getInfoAsStr() const{

    return QString("Square: %1\nPerimeter: %2\nDiagonale: %3\n").arg(QString::number(getSquare()), QString::number(getPerimeter()), QString::number(getDiagonal()));
}

float rectangle::getHeight() const{
    return getA();
}

float rectangle::getWidth() const{
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

    return sqrt(a*a+b*b);
}
