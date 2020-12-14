#include "cone.h"

cone::cone(const float a, const float b):
    VolumeFigure(a, b){
};

cone::cone(const cone& copy):
VolumeFigure(copy)
{};


void cone::setRadius(const float size){
    if(size > 0)
    {
        setA(size);
    }else{
        //err
    }
}

QString cone::getInfoAsStr() const{

    return QString("Square: %1\nVolume: %2\n").arg(QString::number(getSquare()), QString::number(getVolume()));
}

void cone::setHeight(const float size){
    if(size > 0)
    {
        setB(size);
    }else{
        //err
    }
}

float cone::getRadius() const{
    return getA();
}

float cone::getHeight() const{
    return getB();
}

float cone::getVolume() const{
    auto r = getA();
    auto h = getB();
    auto pi = 3.14;
    auto V = pi*r*r*h/3;

    return V;
}

float cone::getSquare() const{
    auto r = getA();
    auto h = getB();
    auto pi = 3.14;
    auto l = std::sqrt(r*r+h*h);
    auto S = pi*r*(l+r);

    return S;
}

float cone::getAngle() const{
    return 0.0;
    //todo
}
