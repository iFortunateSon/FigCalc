#include "trapezoid.h"

trapezoid::trapezoid(const float a, const float b,const float c,const float d):FlatFigure(a,b){
    set(d);
    setLeft(c);
}

void trapezoid::setRight(const float size)
{
    if(size > 0){
        d = size;
    }else{
        //err
    }
};

void trapezoid::setLeft(const float size)
{
    if(size > 0){
        c = size;
    }else{
        //err
    }
};


float trapezoid::getDown() const
{
    return getA();
};

float trapezoid::getUp() const
{
    return getB();
};

float trapezoid::getLeft() const
{
    return getLeft();
};

float trapezoid::getRight() const
{
    return getRight();
};

QString trapezoid::getInfoAsStr() const{

    return QString("Square: %1\nVolume: %2\nInner radius: %3\nOuter radius: %4\nHeight: %5\nDiagonals: %6 ; %7").
            arg(QString::number(getSquare()), QString::number(getPerimeter()), QString::number(getInnerR()),QString::number(getOuterR())
                , QString::number(getHeight()), QString::number(getDiagonale1()), QString::number(getDiagonale2()));
}


float trapezoid::getPerimeter() const{
    auto a = getA();
    auto b = getB();
    auto c = getLeft();
    auto d = getRight();
    auto P = a+b+c+d;

    return P;
}

float trapezoid::getSquare() const{
    auto a = getA();
    auto b = getB();
    auto c = getLeft();
    auto d = getRight();
    auto S = (a+b)*(sqrt(c*c-((b-a)*(b-a)+ c*c - d*d)/(2*(b-a))*
                         ((b-a)*(b-a)+ c*c - d*d)/(2*(b-a))))/2;

    return S;
}


float trapezoid::getHeight() const{
    auto a = getA();
    auto b = getB();
    auto c = getLeft();
    auto d = getRight();
    auto h = sqrt(c*c-(((b-a)*(d-b)+c*c-d*d)/(2*(b-a)))*
                  (((b-a)*(d-b)+c*c-d*d)/(2*(b-a))));

    return h;

}

float trapezoid::getOuterR() const{
    auto a = getA();
    auto b = getB();
    auto c = getLeft();
    auto d = getRight();
    double OR;
    if (c == d){
        OR = (c*sqrt(a*b+c*c))/(sqrt((2*c-a+b)*(2*c+a-b)));
    }
    else OR =0;

    return OR;

}

float trapezoid::getInnerR() const{
    auto a = getA();
    auto b = getB();
    auto c = getLeft();
    auto d = getRight();
    double IR;
    if( (a+b) == (c+d)){
        IR = getHeight()/2;
    }
    else IR = 0;

    return IR;

}

float trapezoid::getDiagonale1() const{
    auto a = getA();
    auto b = getB();
    auto c = getLeft();
    auto d = getRight();
    auto D1 = sqrt((a*a*b-a*b*b-b*c*c+a*d*d)/(a-b));

    return D1;
}

float trapezoid::getDiagonale2() const{
    auto a = getA();
    auto b = getB();
    auto c = getLeft();
    auto d = getRight();
    auto D2 = sqrt((a*a*b-a*b*b-b*d*d+a*c*c)/(a-b));

    return D2;
}
