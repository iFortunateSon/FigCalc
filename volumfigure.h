#ifndef VOLUMFIGURE_H
#define VOLUMFIGURE_H

class VolumeFigure
{
public:

    VolumeFigure(const float a, const float b);
    VolumeFigure(const VolumeFigure &figure);
    ~VolumeFigure();

    void setA(const float a);
    void setB(const float b);
    void setC(const float c);

    float getA() const;
    float getB() const;
    float getC() const;

    float getPerimeter() const;
    float getSquare() const;

private:

    float a, b, c;


};
#endif // VOLUMFIGURE_H
