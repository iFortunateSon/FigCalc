#include "volumecalc.h"
#include "volumfigure.h"


VolumeCalc::VolumeCalc(void)
{
    resultOne = 0;
    resultTwo = 0;
    count = 0;
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


void VolumeCalc::removeTop()
{
    if(count > 0){
        list.pop_front();
        count--;
    }
}


void VolumeCalc::removeElementWithID(const int index)
{
    auto it = list.begin();
    for(int i = 0; i < index; i++){
        it++;
    }
    list.erase(it);
    count--;
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
    auto it = list.begin();
    VolumeFigure* tmp1 = *it;
    it++;
    VolumeFigure* tmp2 = *it;

    resultOne = tmp1->getSquare() + tmp2->getSquare();
    resultTwo = tmp1->getVolume() + tmp2->getVolume();
}



void VolumeCalc::subtraction()
{
    auto it = list.begin();
    VolumeFigure* tmp1 = *it;
    it++;
    VolumeFigure* tmp2 = *it;


    resultOne = tmp1->getSquare() - tmp2->getSquare();
    resultTwo = tmp1->getVolume() - tmp2->getVolume();
}



void VolumeCalc::multiplication()
{
    auto it = list.begin();
    VolumeFigure* tmp1 = *it;
    it++;
    VolumeFigure* tmp2 = *it;


    resultOne = tmp1->getSquare() * tmp2->getSquare();
    resultTwo = tmp1->getVolume() * tmp2->getVolume();
}


void VolumeCalc::division()
{
    auto it = list.begin();
    VolumeFigure* tmp1 = *it;
    it++;
    VolumeFigure* tmp2 = *it;


    resultOne = tmp1->getSquare() / tmp2->getSquare();
    resultTwo = tmp1->getVolume() / tmp2->getVolume();
}
