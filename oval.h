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


    void setFirstR(const float size);
    void setSecondR(const float size);

    float getFirstR() const;
    float getSecondR() const;


    float getLarge() const;
    float getSmall() const;
    QString getInfoAsStr() const override;
    float getPerimeter() const override;
    float getSquare() const override;

private:

};

#endif // OVAL_H
