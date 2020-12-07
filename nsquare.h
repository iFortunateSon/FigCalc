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
    virtual ~Nsquare();

    void setCount(const int count);
    void setSize(const float size);

    int getCount() const;
    float getSize() const;
private:

};

#endif // NSQUARE_H
