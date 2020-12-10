#ifndef CONE_H
#define CONE_H
#include "volumfigure.h"

class cone:VolumeFigure
{
    /*
     * a - радиус
     * b - высота
    */
    public:
        cone(const float a, const float b);
        cone(const cone &copy);

        void setRadius(const float size);
        void setHeight(const float size);

        float getRadius() const;
        float getHeight() const;

        float getVolume() const;
        float getSquare() const;

        float getAngle() const;


    private:

    };

#endif // CONE_H
