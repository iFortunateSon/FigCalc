#ifndef CONE_H
#define CONE_H


#include "fatfigure.h"

class cone:FatFigure
{
    /*
     * a - радиус
     * b - высота
    */
    public:
        cone(const float a, const float b);
        cone(const cone &oval);
        virtual ~cone();

        void setA(const float size);
        void setB(const float size);

        float getA() const;
        float getB() const;

        float getVolume() const;
        float getSquare() const;

        float getAngle() const;


    private:

    };

#endif // CONE_H
