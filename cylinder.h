#ifndef CYLINDER_H
#define CYLINDER_H
#include "--.h"

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

        void setRadius(const float size);
        void setHeight(const float size);

        float getRadius() const;
        float getHeight() const;

        float getVolume() const;
        float getSquare() const;


    private:

    };

#endif // CYLINDER_H
