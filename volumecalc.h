#ifndef VOLUMECALH_H
#define VOLUMECALC_H
#include <list>
#include <iterator>
#include "volumfigure.h"

class VolumeCalc
{
/*
 * resultOne - операции периметра/площади поверхности
 * resultTwo - операции площади/объема
*/
public:
    VolumeCalc();
    VolumeCalc(const VolumeCalc &copy);

    void addFigure(VolumeFigure* figure);
    VolumeFigure* getFigure(void);
    void calculate(const char sign);


    float getResultOne() const;
    float getResultTwo() const;
    int getCount() const;

private:
    void addition();
    void subtraction();
    void multiplication();
    void division();
    float resultOne, resultTwo;
    int count;
    std::list<VolumeFigure*> list;

};

#endif // VOLUMECALC_H
