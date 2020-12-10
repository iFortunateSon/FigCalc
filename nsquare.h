#ifndef NSQUARE_H
#define NSQUARE_H
#include "flatfigure.h"

class Nsquare : FlatFigure
{
/*
 * a - кол-во сторон
 * b - размер стороны
*/
public:
    Nsquare(const float a,const float b);
    Nsquare(const Nsquare& copy);


    void setCount(const int count);
    void setSize(const float size);

    int getCount() const;
    float getSize() const;

    float getPerimeter() const;
    float getSquare() const;

    float getInnerR() const;
    float getOuterR() const;
private:

};

#endif // NSQUARE_H
