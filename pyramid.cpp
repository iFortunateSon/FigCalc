#include "pyramid.h"

pyramid::pyramid(const float a, const float b,const float c):VolumeFigure(a, b, c)
{}


void pyramid::setSide(const float size){
    if(size > 0)
    {
        setA(size);
    }else{
        //err
    }
}

void pyramid::setHeight(const float size){
    if(size > 0)
    {
        setB(size);
    }else{
        //err
    }
}

QString pyramid::getInfoAsStr() const{

    return QString("Square: %1\nVolume: %2").arg(QString::number(getSquare()),QString::number(getVolume()));

}


void pyramid::setCount(const float size){
    if(size > 0)
    {
        setC(size);
    }else{
        //err
    }
}

float pyramid::getSide() const{
    return getA();
}

float pyramid::getHeight() const{
    return getB();
}

float pyramid::getCount() const{
    return getC();
}

float pyramid::getVolume() const{
    auto a = getA();
    auto h = getB();
    auto n = getC();
    auto pi = 3.14;
    auto r = a/(2*tan(360/(2*n)*pi/180));
    auto Socn = a*r*n/2;

    auto S = Socn*h/3;

    return S;
}

float pyramid::getSquare() const{
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
