#ifndef PRISM_H
#define PRISM_H
#include "volumfigure.h"

class prism : VolumeFigure
{
    /*
     * a - сторона
     * b - высота
     * с - кол-во сторон
    */
    public:
        prism(const float a, const float b,const float c);
        prism(const prism &oval);


        void setSide(const float size);
        void setHeight(const float size);
        void setCount(const float size);

        float getSide() const;
        float getHeight() const;
        float getCount() const;

        float getVolume() const override;
        float getSquare() const override;
        QString getInfoAsStr() const override;

        float getDiagonale() const;

    };

#endif // PRISM_H
