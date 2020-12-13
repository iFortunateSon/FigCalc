#include "parallelepiped.h"

parallelepiped::parallelepiped(const float a, const float b,const float c):VolumeFigure(a,b){
    setC(c);
}

void parallelepiped::setSideA(const float size){
    if(size > 0)
    {
        setSideA(size);
    }else{
        //err
    }
}

void parallelepiped::setSideB(const float size){
    if(size > 0)
    {
        setSideB(size);
    }else{
        //err
    }
}

QString parallelepiped::getInfoAsStr() const{

    return QString("Square: %1\nVolume: %2\nDiagonale: %3\n").arg(QString::number(getSquare()), QString::number(getVolume()), QString::number(getDiagonal()));
}

void parallelepiped::setSideC(const float size){
    if(size > 0)
    {
        setA(size);
    }else{
        //err
    }
}

float parallelepiped::getSideA() const{
    return getA();
}

float parallelepiped::getSideB() const{
    return getB();
}

float parallelepiped::getSideC() const{
    return getC();
}

float parallelepiped::getVolume() const{
    auto a = getA();
    auto b = getB();
    auto c = getC();
    auto V = a*b*c;

    return V;
}

float parallelepiped::getSquare() const{
    auto a = getA();
    auto b = getB();
    auto c = getC();
    auto S = 2*(a*b+b*c+c*a);

    return S;
}

float parallelepiped::getDiagonal() const{
    auto a = getA();
    auto b = getB();
    auto c = getC();
    auto D = sqrt(a*a+b*b+c*c);

    return D;
}
