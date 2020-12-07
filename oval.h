#ifndef OVAL_H
#define OVAL_H
#include "flatfigure.h"


class oval : FlatFigure
{
/*
 * a - большая полуось
 * b - малая полуось
*/
public:
    oval(const float big, const float small);
    oval(const oval &oval);
    virtual ~oval();

    void setFirstR(const float size);
    void setSecondR(const float size);

    float getFirstR() const;
    float getSecondR() const;


    float getLarge() const;
    float getSmall() const;

    float getPerimeter() const;
    float getSquare() const;

private:

};

#endif // OVAL_H
