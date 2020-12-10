#include "volumfigure.h"

VolumeFigure::VolumeFigure(const float a, const float b, const float c)
{
    mode = 1;
    if(a > 0 && b > 0 && c > 0){
        setA(a);
        setB(b);
        setC(c);
    }else{
        //err
    }
}

VolumeFigure::VolumeFigure(const VolumeFigure &figure)
{
    setA(figure.getA());
    setB(figure.getB());
    setC(figure.getC());
    mode = figure.getMode();

}



void VolumeFigure::setA(const float size){
    if(size > 0){
        a = size;
    }else{
        //err
    }
}

void VolumeFigure::setB(const float size){
    if(size > 0){
        b = size;
    }else{
        //err
    }
}

void VolumeFigure::setC(const float size){
    if(size > 0){
        c = size;
    }else{
        //err
    }
}

float VolumeFigure::getA() const
{
    return a;
}


float VolumeFigure::getB() const
{
    return b;
}


float VolumeFigure::getC() const
{
    return c;
}

int VolumeFigure::getMode() const
{
    return mode;
}
