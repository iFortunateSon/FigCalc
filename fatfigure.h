#ifndef FATFIGURE_H
#define FATFIGURE_H
#include "math.h"

class FatFigure
{
public:
    FatFigure(const float a, const float b);
    FatFigure(const FatFigure &copy);
    virtual ~FatFigure();


    virtual float getVolume() const = 0;
    virtual float getSquare() const = 0;
protected:
    const float accuracy = 0.001;

    void setA(const float size);
    void setB(const float size);

    float getA() const;
    float getB() const;

private:
    float a, b;
};

#endif


