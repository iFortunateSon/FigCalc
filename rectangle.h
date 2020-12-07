#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "flatfigure.h"


class rectangle : public FlatFigure
{
    /*
     * a - first side
     * b - second size
    */
public:
    rectangle(const float a, const float b);
    rectangle(const rectangle &copy);
    virtual ~rectangle();

    void setFirstSide(const float size);
    void setSecondSide(const float size);

    float getFirstSide() const;
    float getSecondSide() const;

    float getPerimeter() const;
    float getSquare() const;
    float getDiagonal() const;


private:
    void sortSide();


};

#endif // RECTANGLE_H
