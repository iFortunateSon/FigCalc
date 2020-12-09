#ifndef PRISM_H
#define PRISM_H
#include "fatfigure.h"

class prism : FatFigure
{
    /*
     * a - сторона
     * b - высота
     * с - кол-во сторон
    */
    public:
        prism(const float a, const float b,const float c);
        prism(const prism &oval);
        virtual ~prism();

        void setA(const float size);
        void setB(const float size);
        void setC(const float size);

        float getA() const;
        float getB() const;
        float getC() const;

        float getVolume() const;
        float getSquare() const;

        float getDiagonale() const;

    private:

    };

#endif // PRISM_H
