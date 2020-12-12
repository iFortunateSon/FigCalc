#include "math.h"


float VolumeSphere(double r){

    auto pi = 3.14;
    auto V = 4/3*pi*r*r*r;

    return V;
}

float SquareSphere(double r){

    auto pi = 3.14;
    auto S = 4*pi*r*r;

    return S;
}

//float VolumeParallelepiped(double a, double b, double c){

//    auto V = a*b*c;

//    return V;
//}

//float SquareParallelepiped(double a, double b, double c){

//    auto S = 2*(a*b+b*c+c*a);

//    return S;
//}

//float DiagonaleParallelepiped(double a, double b, double c){

//    auto D = sqrt(a*a+b*b+c*c);

//    return D;
//}

//float VolumeCylinder(double r,double h){

//    auto pi = 3.14;
//    auto V = pi*r*r*h;

//    return V;
//}

//float SquareCylinder(double r, double h){

//    auto pi = 3.14;
//    auto S = 2*pi*r*(h+r);

//    return S;
//}

//float VolumeCone(double r,double h){

//    auto pi = 3.14;
//    auto V = 1/3*pi*r*r*h;

//    return V;
//}

//float SquareCone(double r, double h){

//    auto pi = 3.14;
//    auto l = sqrt(r*r+h*h);
//    auto S = pi*r*(l+r);

//    return S;
//}

//float AngleCone(double r,double h){
//    // ??
//}

//float SquarePyramid(double a, double h, double n){

//    auto pi = 3.14;
//    auto r = a/(2*tan(360/(2*n)*pi/180));
//    auto Socn = a*r*n/2;

//    auto l = sqrt(a*a+h*h);
//    auto Sbok = l*a/2;

//    auto S = n*Sbok + Socn;

//    return S;

//}

//float VolumePyramid(double a, double h, double n){

//    auto pi = 3.14;
//    auto r = a/(2*tan(360/(2*n)*pi/180));
//    auto Socn = a*r*n/2;

//    auto S = Socn*h/3;

//    return S;

//}

float SquarePrism(double a, double h, double n){

    auto pi = 3.14;
    auto r = a/(2*tan(360/(2*n)*pi/180));
    auto Socn = a*r*n/2;

    auto l = sqrt(a*a+h*h);
    auto Sbok = l*a/2;

    auto S = n*Sbok + 2*Socn;

    return S;

}

float VolumePrism(double a, double h, double n){

    auto pi = 3.14;
    auto r = a/(2*tan(360/(2*n)*pi/180));
    auto Socn = a*r*n/2;

    auto S = Socn*h;

    return S;

}

float DiagonalePrism(){

//??
}


