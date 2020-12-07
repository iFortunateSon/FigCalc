#include "nsquare.h"

Nsquare::Nsquare(const float a, const float b):
    FlatFigure(a, b){};

Nsquare::Nsquare(const Nsquare &copy):
    FlatFigure(copy){};

void Nsquare::setCount(const int count)
{
    setA(count);
};

void Nsquare::setSize(const float size)
{
    setB(size);
};

int Nsquare::getCount() const
{
    return getA();
}

float Nsquare::getSize() const
{
    return getA();
}

float Nsquare::getPerimeter() const
{
    float P = getA() * getB();
    return P;
}

float Nsquare::getSquare() const
{
    float size = getA();
    int n = getB();
    auto r = getOuterR();
    double S = size * r * n/2;

    return S;
};

float Nsquare::getInnerR() const
{
    int n = getA();
    float size = getB();
    auto pi = 3.14;
    auto IR = size/(2*tan(360/(2*n)*pi/180));

    return IR;
};

float Nsquare::getOuterR() const
{
    int cnt = getA();
    int size = getB();
    auto pi = 3.14;
    auto OR = cnt/(2*sin(360/(2*size)*pi/180));

    return OR;
}
