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
    Nsquare(const float a = def_a,const float b = def_b);
    Nsquare(const Nsquare& copy);


    void setCount(const int count);
    void setSize(const float size);

    int getCount() const;
    float getSize() const;

    float getPerimeter() const override;
    float getSquare() const override;

    float getInnerR() const;
    float getOuterR() const;
private:

};

#endif // NSQUARE_H
