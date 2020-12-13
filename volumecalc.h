#ifndef VOLUMECALH_H
#define VOLUMECALC_H
#include <list>
#include <iterator>
#include <QString>
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
    void removeTop();
    void removeElementWithID(const int index);

    void calculate(const char sign);


    float getResultOne() const;
    float getResultTwo() const;
    int getCount() const;

    QString getInfo(const int index) const;

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
