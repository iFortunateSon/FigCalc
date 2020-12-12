#include "volumecalc.h"
#include "flatfigure.h"
#include "volumfigure.h"


VolumeCalc::VolumeCalc(void)
{
    resultOne = 0;
    resultTwo = 0;
}


VolumeCalc::VolumeCalc(const VolumeCalc &copy)
{
    resultOne = copy.getResultOne();
    resultTwo = copy.getResultTwo();
    count = copy.getCount();
    //todo list copy
}


void VolumeCalc::addFigure(VolumeFigure* figure)
{
    list.push_back(figure);
    count++;
}


VolumeFigure* VolumeCalc::getFigure()
{
    VolumeFigure* tmp = list.back();
    list.pop_back();
    count--;
    return tmp;
}


float VolumeCalc::getResultOne() const
{
    return  resultOne;
}


float VolumeCalc::getResultTwo() const{
    return  resultTwo;
}


int VolumeCalc::getCount() const{
    return  count;
}


void VolumeCalc::calculate(const char sign)
{
    switch (sign) {
    case '+':
        addition();
        break;
    case '-':
        subtraction();
        break;
    case '*':
        multiplication();
        break;
    case '/':
        division();
        break;
    }
}


void VolumeCalc::addition()
{
    VolumeFigure* tmp1 = list.back();
    list.pop_back();
    VolumeFigure* tmp2 = list.back();
    list.pop_back();


    resultOne = tmp1->getSquare() + tmp2->getSquare();
    resultTwo = tmp1->getVolume() + tmp2->getVolume();
}



void VolumeCalc::subtraction()
{
    VolumeFigure* tmp1 = list.back();
    list.pop_back();
    VolumeFigure* tmp2 = list.back();
    list.pop_back();


    resultOne = tmp1->getSquare() - tmp2->getSquare();
    resultTwo = tmp1->getVolume() - tmp2->getVolume();
}



void VolumeCalc::multiplication()
{
    VolumeFigure* tmp1 = list.back();
    list.pop_back();
    VolumeFigure* tmp2 = list.back();
    list.pop_back();


    resultOne = tmp1->getSquare() * tmp2->getSquare();
    resultTwo = tmp1->getVolume() * tmp2->getVolume();
}


void VolumeCalc::division()
{
    VolumeFigure* tmp1 = list.back();
    list.pop_back();
    VolumeFigure* tmp2 = list.back();
    list.pop_back();


    resultOne = tmp1->getSquare() / tmp2->getSquare();
    resultTwo = tmp1->getVolume() / tmp2->getVolume();
}
