#ifndef PYRAMID_H
#define PYRAMID_H
#include "volumfigure.h"

class pyramid : VolumeFigure
{
    /*
     * a - сторона
     * b - высота
     * с - кол-во сторон
    */
    public:
        pyramid(const float a, const float b,const float c);
        pyramid(const pyramid &oval);


        void setSide(const float size);
        void setHeight(const float size);
        void setCount(const float size);

        float getSide() const;
        float getHeight() const;
        float getCount() const;

        float getVolume() const override;
        float getSquare() const override;
        QString getInfoAsStr() const override;
        float getAngle() const;


    };
#endif // PYRAMID_H
