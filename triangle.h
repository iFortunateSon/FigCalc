#ifndef TRIANGLE_H
#define TRIANGLE_H
#include "flatfigure.h"


class triangle : public FlatFigure
{
/*
 * a, b, c - стороны треугольника

*/
public:
    triangle(const float a, const float b,const float c);
    triangle(const triangle &triangle);



    void setSideA(const float size);
    void setSideB(const float size);
    void setSideC(const float size);

    float getSideA() const;
    float getSideB() const;
    float getSideC() const;

    float getPerimeter() const;
    float getSquare() const;

    float getOuterRadius() const;
    float getInnerRadius() const;
    float getHeight() const;

protected:
    void setC(const float size);
    float getC() const;

private:
    float c;

};

#endif // TRIANGLE_H
