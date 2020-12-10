#ifndef PARALLELOGRAM_H
#define PARALLELOGRAM_H
#include "flatfigure.h"


class parallelogram : FlatFigure
{
    /*
     * a, b - стороны
     * с - угол между a и b
    */
public:
    parallelogram(const float a, const float b,float const c);
    parallelogram(const parallelogram &parallelogram);


    void setWidth(const float size);
    void setThicknness(const float size);
    void setAngle(const float angle);

    float getWidth() const;
    float getThicknness() const;
    float getAngle() const;

    float getSquare() const;
    float getPerimetr() const;
    float getDiagonale() const;

protected:
    void setC(const float c);
    float getC() const;


private:
    float c;

};

#endif // PARALLELOGRAM_H
