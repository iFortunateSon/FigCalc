#include "flatcalc.h"
#include "flatfigure.h"
#include "volumfigure.h"


FlatCalc::FlatCalc(void)
{
    resultOne = 0;
    resultTwo = 0;
}


FlatCalc::FlatCalc(const FlatCalc &copy)
{
    resultOne = copy.getResultOne();
    resultTwo = copy.getResultTwo();
    count = copy.getCount();
    //todo list copy
}




void FlatCalc::addFigure(FlatFigure *figure){
    list.push_back(figure);
    count++;
}



FlatFigure* FlatCalc::getFigure(){
    FlatFigure* tmp = list.back();
    list.pop_back();
    count--;
    return tmp;
}


float FlatCalc::getResultOne() const
{
    return  resultOne;
}


float FlatCalc::getResultTwo() const{
    return  resultTwo;
}


int FlatCalc::getCount() const{
    return  count;
}



void FlatCalc::calculate(const char sign){
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


void FlatCalc::addition(){
    FlatFigure* tmp1 = list.back();
    list.pop_back();
    FlatFigure* tmp2 = list.back();
    list.pop_back();
    resultOne = tmp1->getPerimeter() + tmp2->getPerimeter();
    resultTwo = tmp1->getSquare() + tmp2->getSquare();

}



void FlatCalc::subtraction(){
    FlatFigure* tmp1 = list.back();
    list.pop_back();
    FlatFigure* tmp2 = list.back();
    list.pop_back();
    resultOne = tmp1->getPerimeter() - tmp2->getPerimeter();
    resultTwo = tmp1->getSquare() - tmp2->getSquare();

}



void FlatCalc::multiplication(){
    FlatFigure* tmp1 = list.back();
    list.pop_back();
    FlatFigure* tmp2 = list.back();
    list.pop_back();
    resultOne = tmp1->getPerimeter() * tmp2->getPerimeter();
    resultTwo = tmp1->getSquare() * tmp2->getSquare();

}



void FlatCalc::division(){
    FlatFigure* tmp1 = list.back();
    list.pop_back();
    FlatFigure* tmp2 = list.back();
    list.pop_back();
    resultOne = tmp1->getPerimeter() / tmp2->getPerimeter();
    resultTwo = tmp1->getSquare() / tmp2->getSquare();

}
