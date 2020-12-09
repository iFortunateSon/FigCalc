#ifndef CYLINDER_H
#define CYLINDER_H
#include "fatfigure.h"

class cylinder:FatFigure
{
    /*
     * a - радиус
     * b - высота
    */
    public:
        cylinder(const float a, const float b);
        cylinder(const cylinder &oval);
        virtual ~cylinder();

        void setA(const float size);
        void setB(const float size);

        float getA() const;
        float getB() const;

        float getVolume() const;
        float getSquare() const;


    private:

    };

#endif // CYLINDER_H
