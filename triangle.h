#ifndef TRIANGLE_H
#define TRIANGLE_H
#include "flatfigure.h"


class triangle : FlatFigure
{
/*
 * a, b, c - стороны треугольника

*/
public:
    triangle(const float a, const float b);
    triangle(const triangle &triangle);
    virtual ~triangle();


    void setA(const float size);
    void setB(const float size);
    void setC(const float size);

    float getA() const;
    float getB() const;
    float getC() const;


private:
    float c;

};

#endif // TRIANGLE_H
