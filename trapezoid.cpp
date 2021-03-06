#include "trapezoid.h"

trapezoid::trapezoid(const float a, const float b,const float c,const float d):FlatFigure(a, b){
    setRight(d);
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
    return c;
};

float trapezoid::getRight() const
{
    return d;
};

QString trapezoid::getInfoAsStr() const{

    return QString("Square: %1\nPerimeter: %2\nInner radius: %3\nOuter radius: %4\nHeight: %5\nDiagonals: %6, %7").
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

    auto s1 = (a+b)/2;
    auto s2 = ((b-a)*(b-a)+ c*c - d*d);
    auto s3 = (2*(b-a));

    auto s4 = s2/s3;

    auto S = s1*sqrt(c*c-s4*s4);

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
