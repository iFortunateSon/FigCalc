#ifndef FLATCALC_H
#define FLATCALC_H
#include <list>
#include <iterator>
#include "flatfigure.h"
#include <QString>

class FlatCalc
{
/*
 * resultOne - операции периметра/площади поверхности
 * resultTwo - операции площади/объема
*/
public:
    FlatCalc();
    FlatCalc(const FlatCalc &copy);

    void addFigure(FlatFigure* figure);
    FlatFigure* getFigure(void);
    void removeTop(void);
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
    int count, mode;
    std::list<FlatFigure*> list;

};

#endif // FLATCALC_H
