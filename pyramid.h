#ifndef PYRAMID_H
#define PYRAMID_H


#include "--.h"

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

        void setSide(const float size);
        void setHeight(const float size);
        void setCount(const float size);

        float getSide() const;
        float getHeight() const;
        float getCount() const;

        float getVolume() const;
        float getSquare() const;

        float getAngle() const;

    protected:
        void setC(const float c);
        float getC() const;


    private:
        float c;

    };
#endif // PYRAMID_H
