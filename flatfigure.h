#ifndef FLATFIGURE_H
#define FLATFIGURE_H
#include "math.h"

class FlatFigure
{
public:
    static const int def_a = 0;
    static const int def_b = 0;
    FlatFigure(const float a = def_a, const float b = def_b);
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

    int getMode() const;

private:
    float a, b;
    int mode;

};


#endif // FLATFIGURE_H
