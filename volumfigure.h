#ifndef VOLUMFIGURE_H
#define VOLUMFIGURE_H
#include <cmath>
#include <QString>

class VolumeFigure
{
public:
    static const int def_a = 0;
    static const int def_b = 0;
    static const int def_c = 0;
    VolumeFigure(const float a = def_a, const float b = def_b, const float c = def_c);
    VolumeFigure(const VolumeFigure &figure);



    virtual float getVolume() const = 0;
    virtual float getSquare() const = 0;
    virtual QString getInfoAsStr() const = 0;

protected:

    void setA(const float size);
    void setB(const float size);
    void setC(const float size);

    float getA() const;
    float getB() const;
    float getC() const;

    int getMode() const;

private:

    float a, b, c;
    int mode;


};
#endif // VOLUMFIGURE_H
