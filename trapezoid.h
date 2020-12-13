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
    trapezoid(const float a, const float b, const float c, const float d);
    trapezoid(const trapezoid &trapezoid);


    void setDown(const float size);
    void setUp(const float size);
    void setLeft(const float size);
    void setRight(const float size);

    float getDown() const;
    float getUp() const;
    float getLeft() const;
    float getRight() const;

    float getPerimeter() const override; // !!!!
    float getSquare() const override; // !!!!
    QString getInfoAsStr() const override;
    float getInnerR() const;
    float getOuterR() const;
    float getHeight() const;
    float getDiagonale1() const;
    float getDiagonale2() const;
protected:
    void setC(const float c);
    float getC() const;
    void setD(const float d);
    float getD() const;

private:
    float c, d;


};

#endif // TRAPEZOID_H
