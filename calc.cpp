#include "calc.h"

template <class T>
Calc<T>::Calc()
{
    T tmp;
    mode = tmp.getMode();
    resultOne = 0;
    resultTwo = 0;
}


template <class T>
Calc<T>::Calc(const Calc &copy)
{
    resultOne = copy.getResultOne();
    resultTwo = copy.getResultTwo();
    count = copy.getCount();
    //todo list copy
}


template <class T>
void Calc<T>::addFigure(T &figure){
    T* tmp = new T(figure);
    list.push_back(tmp);
}


template <class T>
T Calc<T>::getFigure(){
    T* tmp = list.pop_back();
    T object(&tmp);
    delete tmp;
    return object;
}


template <class T>
void Calc<T>::calculate(const char sign){
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

template <class T>
void Calc<T>::addition(){
    T* tmp1 = list.pop_back();
    T* tmp2 = list.pop_back();
    if(mode == 0){
        resultOne = tmp1->getPerimeter() + tmp2->getPerimeter();
        resultTwo = tmp1->getSquare() + tmp2->getSquare();
    }else{
        resultOne = tmp1->getSquare() + tmp2->getSquare();
        resultTwo = tmp1->getVolume() + tmp2->getVolume();
    }
}


template <class T>
void Calc<T>::subtraction(){
    T* tmp1 = list.pop_back();
    T* tmp2 = list.pop_back();
    if(mode == 0){
        resultOne = tmp1->getPerimeter() - tmp2->getPerimeter();
        resultTwo = tmp1->getSquare() - tmp2->getSquare();
    }else{
        resultOne = tmp1->getSquare() - tmp2->getSquare();
        resultTwo = tmp1->getVolume() - tmp2->getVolume();
    }
}


template <class T>
void Calc<T>::multiplication(){
    T* tmp1 = list.pop_back();
    T* tmp2 = list.pop_back();
    if(mode == 0){
        resultOne = tmp1->getPerimeter() * tmp2->getPerimeter();
        resultTwo = tmp1->getSquare() * tmp2->getSquare();
    }else{
        resultOne = tmp1->getSquare() * tmp2->getSquare();
        resultTwo = tmp1->getVolume() * tmp2->getVolume();
    }
}

template <class T>
void Calc<T>::division(){
    T* tmp1 = list.pop_back();
    T* tmp2 = list.pop_back();
    if(mode == 0){
        resultOne = tmp1->getPerimeter() / tmp2->getPerimeter();
        resultTwo = tmp1->getSquare() / tmp2->getSquare();
    }else{
        resultOne = tmp1->getSquare() / tmp2->getSquare();
        resultTwo = tmp1->getVolume() / tmp2->getVolume();
    }
}
