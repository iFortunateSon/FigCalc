#ifndef OVAL_H
#define OVAL_H
#include "flatfigure.h"


class oval : FlatFigure
{
/*
 * a - большая полуось
 * b - малая полуось
*/
public:
    oval(const float big, const float small);
    oval(const oval &oval);
    virtual ~oval();

    void setLarge(const float size);
    void setSmall(const float size);

    float getLarge() const;
    float getSmall() const;

private:

};

#endif // OVAL_H
