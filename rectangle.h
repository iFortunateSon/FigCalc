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


    void setHeight(const float size);
    void setWidth(const float size);

    float getHeight() const;
    float getWidth() const;

    float getPerimeter() const override;
    float getSquare() const override;
    float getDiagonal() const;

    QString getInfoAsStr() const override;
private:
    void sortSide();


};

#endif // RECTANGLE_H
