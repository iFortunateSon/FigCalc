#include "prism.h"

prism::prism(const float a, const float b,const float c):VolumeFigure(a, b, c)
{}

void prism::setC(const float size)
{
    if(size > 0){
        c = size;
    }else{
        //err
    }
};

float prism::getC() const
{
    return c;
};

void prism::setSide(const float size){
    if(size > 0)
    {
        setA(size);
    }else{
        //err
    }
}

void prism::setHeight(const float size){
    if(size > 0)
    {
        setB(size);
    }else{
        //err
    }
}

void prism::setCount(const float size){
    if(size > 0)
    {
        setC(size);
    }else{
        //err
    }
}

float prism::getSide() const{
    return getA();
}

float prism::getHeight() const{
    return getB();
}

float prism::getCount() const{
    return getC();
}

float prism::getVolume() const{
    float a = getA();
    float h = getB();
    int n = getC();
    float pi = 3.14;
    float r = a/(2*tan(360/(2*n)*pi/180));
    float Socn = a*r*n/2;

    float S = Socn*h/3;

    return S;
}

float prism::getSquare() const{
    float a = getA();
    float h = getB();
    int n = getC();
    float pi = 3.14;
    float r = a/(2*tan(360/(2*n)*pi/180));
    float Socn = a*r*n/2;

    float l = sqrt(a*a+h*h);
    float Sbok = l*a/2;

    float S = n*Sbok + Socn;

    return S;
}

QString prism::getInfoAsStr() const{
    return QString("Square: %1\nVolume: %2").arg(QString::number(getSquare()),QString::number(getVolume()));
}
