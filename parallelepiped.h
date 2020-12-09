#ifndef PARALLELEPIPED_H
#define PARALLELEPIPED_H
#include "fatfigure.h"

class parallelepiped : FatFigure
{
    /*
     * a, b, c - стороны
    */
    public:
        parallelepiped(const float a, const float b,const float c);
        parallelepiped(const parallelepiped &oval);
        virtual ~parallelepiped();

        void setA(const float size);
        void setB(const float size);
        void setC(const float size);

        float getA() const;
        float getB() const;
        float getC() const;

        float getVolume() const;
        float getSquare() const;

        float getDiagonal() const;

    private:

    };


#endif // PARALLELEPIPED_H
