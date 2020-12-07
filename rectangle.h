#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "flatfigure.h"


class rectangle : FlatFigure
{
    /*
     * a, b - стороны
    */
public:
    rectangle(const float a, const float b);
    rectangle(const rectangle &rectangle);
    virtual ~rectangle();

    void setLarge(const float size);
    void setSmall(const float size);

    float getLarge() const;
    float getSmall() const;


private:



};

#endif // RECTANGLE_H
