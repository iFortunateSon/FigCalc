#ifndef FLATFIGURE_H
#define FLATFIGURE_H
#include "math.h"

class FlatFigure
{
public:
    FlatFigure(const float a, const float b);
    FlatFigure(const FlatFigure &copy);
    virtual ~FlatFigure();


    virtual float getPerimeter() const = 0;
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


#endif // FLATFIGURE_H
