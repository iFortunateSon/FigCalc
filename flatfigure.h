#ifndef FLATFIGURE_H
#define FLATFIGURE_H

class FlatFigure
{
public:

    FlatFigure(const float a, const float b);
    FlatFigure(const FlatFigure &figure);
    ~FlatFigure();

    void setA(const float a);
    void setB(const float b);

    float getA() const;
    float getB() const;

    float getPerimeter() const;
    float getSquare() const;

private:

    float a, b;

};


#endif // FLATFIGURE_H
