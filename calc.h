#ifndef CALC_H
#define CALC_H
#include <iostream>
#include <list>
#include <iterator>

template <class T>
class Calc
{
/*
 * resultOne - операции периметра/площади поверхности
 * resultTwo - операции площади/объема
*/
public:
    Calc();
    Calc(const Calc &copy);
    ~Calc();

    void addFigure(T& figure);
    T getFigure(void);
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
    int count, mode;
    std::list<T*> list;

};

#endif // CALC_H
