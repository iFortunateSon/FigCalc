#ifndef TRAPEZOID_H
#define TRAPEZOID_H
#include "flatfigure.h"


class trapezoid : FlatFigure
{
    /*
     * a, b - основания
     * b, c - боковые стороны
    */
public:
    trapezoid(const float a, const float b);
    trapezoid(const trapezoid &trapezoid);
    virtual ~trapezoid();

    void setDown(const float size);
    void setUp(const float size);
    void setLeft(const float size);
    void setRight(const float size);

    float getDown() const;
    float getUp() const;
    float getLeft() const;
    float getRight() const;


protected:
    void setC(const float c);
    float getC() const;
    void setD(const float d);
    float getD() const;

private:
    float c, d;


};

#endif // TRAPEZOID_H
