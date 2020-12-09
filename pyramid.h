#ifndef PYRAMID_H
#define PYRAMID_H


#include "fatfigure.h"

class pyramid : FatFigure
{
    /*
     * a - сторона
     * b - высота
     * с - кол-во сторон
    */
    public:
        pyramid(const float a, const float b,const float c);
        pyramid(const pyramid &oval);
        virtual ~pyramid();

        void setA(const float size);
        void setB(const float size);
        void setC(const float size);

        float getA() const;
        float getB() const;
        float getC() const;

        float getVolume() const;
        float getSquare() const;

        float getAngle() const;

    private:

    };
#endif // PYRAMID_H
