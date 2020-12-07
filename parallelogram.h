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
    parallelogram(const float a, const float b);
    parallelogram(const parallelogram &parallelogram);
    virtual ~parallelogram();

    void setLarge(const float size);
    void setSmall(const float size);
    void setAngle(const float angle);

    float getLarge() const;
    float getSmall() const;
    float getAngle() const;


protected:
    void setC(const float c);
    float getC() const;


private:
    float c;

};

#endif // PARALLELOGRAM_H
