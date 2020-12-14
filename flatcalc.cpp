#include "flatcalc.h"
#include "flatfigure.h"


FlatCalc::FlatCalc(void)
{
    resultOne = 0;
    resultTwo = 0;
    count = 0;
}


FlatCalc::FlatCalc(const FlatCalc &copy)
{
    resultOne = copy.getResultOne();
    resultTwo = copy.getResultTwo();
    count = copy.getCount();
    //todo list copy
}




void FlatCalc::addFigure(FlatFigure *figure)
{
    list.push_back(figure);
    count++;
}



FlatFigure* FlatCalc::getFigure()
{
    FlatFigure* tmp = list.back();
    list.pop_back();
    count--;
    return tmp;
}

void FlatCalc::removeTop()
{
    if(count > 0){
        list.pop_front();
        count--;
    }
}

void FlatCalc::removeElementWithID(const int index)
{
    auto it = list.begin();
    for(int i = 0; i < index; i++){
        it++;
    }
    list.erase(it);
    count--;
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

QString FlatCalc::getInfo(const int index) const{
    auto it = list.begin();
    for(int i = 0; i < index; i++){
        it++;
    }
    return (*it)->getInfoAsStr();
};


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
    auto it = list.begin();
    FlatFigure* tmp1 = *it;
    it++;
    FlatFigure* tmp2 = *it;
    resultOne = tmp1->getPerimeter() + tmp2->getPerimeter();
    resultTwo = tmp1->getSquare() + tmp2->getSquare();

}



void FlatCalc::subtraction(){
    auto it = list.begin();
    FlatFigure* tmp1 = *it;
    it++;
    FlatFigure* tmp2 = *it;
    resultOne = tmp1->getPerimeter() - tmp2->getPerimeter();
    resultTwo = tmp1->getSquare() - tmp2->getSquare();

}



void FlatCalc::multiplication(){
    auto it = list.begin();
    FlatFigure* tmp1 = *it;
    it++;
    FlatFigure* tmp2 = *it;
    resultOne = tmp1->getPerimeter() * tmp2->getPerimeter();
    resultTwo = tmp1->getSquare() * tmp2->getSquare();

}



void FlatCalc::division(){
    auto it = list.begin();
    FlatFigure* tmp1 = *it;
    it++;
    FlatFigure* tmp2 = *it;
    resultOne = tmp1->getPerimeter() / tmp2->getPerimeter();
    resultTwo = tmp1->getSquare() / tmp2->getSquare();

}
