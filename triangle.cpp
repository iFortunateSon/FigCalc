#include "triangle.h"

triangle::triangle(const float a, const float b,const float c):FlatFigure(a,b){
    setC(c);
}

void triangle::setC(const float size)
{
    if(size > 0){
        c = size;
    }else{
        //err
    }
};

float triangle::getC() const
{
    return c;
};

void triangle::setSideA(const float size){
    if(size > 0)
    {
        setA(size);
    }else{
        //err
    }
}

void triangle::setSideB(const float size){
    if(size > 0)
    {
        setB(size);
    }else{
        //err
    }
}

void triangle::setSideC(const float size){
    if(size > 0)
    {
        setC(size);
    }else{
        //err
    }
}

float triangle::getSideA() const{
    return getA();
}

float triangle::getSideB() const{
    return getB();
}

float triangle::getSideC() const{
    return getC();
}

float triangle::getPerimeter() const{
    auto a = getA();
    auto b = getB();
    auto c = getC();
    auto pi = 3.14;
    double P = a+b+c;

    return P;
}

QString triangle::getInfoAsStr() const{

    return QString("Square: %1\nPerimeter: %2\nInner radius: %3\nOuter radius: %4").arg(QString::number(getSquare()), QString::number(getPerimeter()),
                                                                                        QString::number(getInnerRadius()),QString::number(getOuterRadius()));
}

float triangle::getSquare() const{
    auto a = getA();
    auto b = getB();
    auto c = getC();
    auto p = getPerimeter()/2;
    double S = sqrt(p*(p-a)*(p-b)*(p-c));

    return S;
}

float triangle::getOuterRadius() const{
    auto a = getA();
    auto b = getB();
    auto c = getC();
    double OR;
    if ( a!=b && a!=c && b!=c){
        auto p = getPerimeter()/2;
        OR = (a*b*c)/(4*sqrt(p*(p-a)*(p-b)*(p-c)));
    }
    else if(a==b || b==c || c==a){
        auto p = getPerimeter()/2;

        if(a==b){
            OR = (a*a*c)/(4*sqrt(p*(p-a)*(p-a)*(p-c)));
        }
        else if(b==c){
            OR = (a*b*b)/(4*sqrt(p*(p-a)*(p-b)*(p-b)));
        }
        else {
            OR = (a*b*a)/(4*sqrt(p*(p-a)*(p-b)*(p-a)));
        }
    }
    else if(a==b && b ==c){
        auto p = getPerimeter()/2;
        OR = (a*a*a)/(4*sqrt(p*(p-a)*(p-a)*(p-a)));
    }
//    else if(ab == 90 || bc == 90 || ac == 90){

//        if(ab == 90){
//            OR = (sqrt(a*a+b*b))/2;
//        }
//        else if (bc == 90) {
//            OR = (sqrt(c*c+b*b))/2;
//        }
//        else{
//            OR = (sqrt(c*c+a*a))/2;
//        }
//    } НУЖНО СДЕАТЬ УГЛЫ МЕЖДУ СТОРОНАМИ СЕЙЧАС ЛЕНЬ <3
    else {
        OR = 0;
    }

    return OR;
}

float triangle::getInnerRadius() const{
    auto a = getA();
    auto b = getB();
    auto c = getC();
    double IR;
    if ( a!=b && a!=c && b!=c){
        auto p = getPerimeter()/2;
        IR = sqrt((p-a)*(p-b)*(p-c)/p);
    }
    else if(a==b || b==c || c==a){
        auto p = getPerimeter()/2;

        if(a==b){
            IR = sqrt((p-a)*(p-a)*(p-c)/p);
        }
        else if(b==c){
            IR = sqrt((p-a)*(p-b)*(p-b)/p);
        }
        else {
            IR = sqrt((p-a)*(p-b)*(p-a)/p);
        }
    }
    else if(a==b && b ==c){
        auto p = getPerimeter()/2;
        IR = sqrt((p-a)*(p-a)*(p-a)/p);
    }
    else {
        IR = 0;
    }

    return IR;
}


float triangle::getHeight() const{
    auto a = getA();
    auto b = getB();
    auto c = getC();
    auto ab = acos((b*b-c*c+a*a)/(2*b*a)); // Формула для угла
    auto S = getSquare();
    auto h = 2*S/a;

    return h;

}
