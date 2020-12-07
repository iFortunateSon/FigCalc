double SquareElipse(double a,double b){

    auto pi = 3.14;
    auto S = pi*a*b;

    return S;
}

double PerimetrElipse(double a,double b){

    auto pi = 3.14;
    auto P = 2*pi*sqrt((a*a+b*b)/2);

    return P;
}

double SquareRectangle(double w,double h){

    auto S = w*h;

    return S;
}

double PerimetrRectangle(double w,double h){

    auto P = (w+h)*2;

    return P;
}

double DiagonalRectangle(double w,double h){

    auto D = sqrt(w*w+h*h);

    return D;
}

double OuterRadiusRectangle(double w,double h){

    auto OR = DiagonalRectangle(w,h)/2;

    return OR;
}

double InnerRadiusRectangle(double w,double h){

    double IR;
    if (w != h){
        std::cout << "Inner radius does not exist\n";
        return 0;
    }
    else {
        IR = w/2;
    }

    return IR;
}

double PerimetrTriangle(double a,double b, double c){

    double P = a+b+c;

    return P;
}

double SquareTriangle(double a,double b, double c){

    auto p = PerimetrTriangle(a,b,c)/2;
    double S = sqrt(p*(p-a)*(p-b)*(p-c));

    return S;
}

double OuterRadiusTriangle(double a,double b, double c,
                           double ab,double bc, double ac){


    double OR;
    if ( a!=b && a!=c && b!=c){
        auto p = PerimetrTriangle(a,b,c)/2;
        OR = (a*b*c)/(4*sqrt(p*(p-a)*(p-b)*(p-c)));
    }
    else if(a==b || b==c || c==a){
        auto p = PerimetrTriangle(a,b,c)/2;

        if(a==b){
            OR = (a*a*c)/(4*sqrt(p*(p-a)*(p-a)*(p-c)));
        }
        else if(b==c){
            OR = (a*b*b)/(4*sqrt(p*(p-a)*(p-b)*(p-b)));
        }
        else {
            OR = (a*b*a)/(4*sqrt(p*(p-a)*(p-b)*(p-a)));
        }
    }
    else if(a==b && b ==c){
        auto p = PerimetrTriangle(a,b,c)/2;
        OR = (a*a*a)/(4*sqrt(p*(p-a)*(p-a)*(p-a)));
    }
    else if(ab == 90 || bc == 90 || ac == 90){

        if(ab == 90){
            OR = (sqrt(a*a+b*b))/2;
        }
        else if (bc == 90) {
            OR = (sqrt(c*c+b*b))/2;
        }
        else{
            OR = (sqrt(c*c+a*a))/2;
        }
    }
    else {
        OR = 0;
    }

    return OR;
}

double InnerRadiusTriangle(double a,double b, double c,
                           double ab,double bc, double ac){


    double IR;
    if ( a!=b && a!=c && b!=c){
        auto p = PerimetrTriangle(a,b,c)/2;
        IR = sqrt((p-a)*(p-b)*(p-c)/p);
    }
    else if(a==b || b==c || c==a){
        auto p = PerimetrTriangle(a,b,c)/2;

        if(a==b){
            IR = sqrt((p-a)*(p-a)*(p-c)/p);
        }
        else if(b==c){
            IR = sqrt((p-a)*(p-b)*(p-b)/p);
        }
        else {
            IR = sqrt((p-a)*(p-b)*(p-a)/p);
        }
    }
    else if(a==b && b ==c){
        auto p = PerimetrTriangle(a,b,c)/2;
        IR = sqrt((p-a)*(p-a)*(p-a)/p);
    }
//    else if(ab == 90 || bc == 90 || ac == 90){

//        if(ab == 90){
//            IR = (sqrt(a*a+b*b))/2;
//        }
//        else if (bc == 90) {
//            IR = (sqrt(c*c+b*b))/2;
//        }
//        else{
//            IR = (sqrt(c*c+a*a))/2;
//        }
//    }
    else {
        IR = 0;
    }

    return IR;
}


double HeightTriangle(double a,double b, double ab){

    auto S = SquareTriangle(a,b,ab);
    auto h = 2*S/a;

    return h;

}


double SquareParallelogram(double a,double b, double ab){
    auto pi = 3.14;
    double S = a*b*sin(ab*pi/180);

    return S;
}

double PerimetrParallelogram(double a,double b){

    double P = (a+b)*2;

    return P;
}

double DiagonalParallelogram(double a,double b, double ab){
    auto pi = 3.14;
    auto D = sqrt(a*a+b*b-2*b*a*cos(ab*pi/180));

    return D;
}

double OuterRadiusNangle(double a,double n){
    auto pi = 3.14;
    auto OR = a/(2*sin(360/(2*n)*pi/180));

    return OR;
}

double SquareNangle(double a,double n){

    auto r = OuterRadiusNangle(a,n);
    double S = a*r*n/2;

    return S;
}

double PerimetrNangle(double a,double n){

    double P = a*n;

    return P;
}

double InnerRadiusNangle(double a,double n){

    auto pi = 3.14;
    auto IR = a/(2*tan(360/(2*n)*pi/180));

    return IR;
}

double SquareTrapezoid(double a,double b, double c, double d){

    auto S = (a+b)*(sqrt(c*c-((b-a)*(b-a)+ c*c - d*d)/(2*(b-a))*
                         ((b-a)*(b-a)+ c*c - d*d)/(2*(b-a))))/2;

    return S;
}

double PerimetrTrapezoid(double a,double b, double c, double d){

    auto P = a+b+c+d;

    return P;
}

double HeightTrapezoid(double a,double b,double c,double d){

    auto h = sqrt(c*c-(((b-a)*(d-b)+c*c-d*d)/(2*(b-a)))*
                  (((b-a)*(d-b)+c*c-d*d)/(2*(b-a))));

    return h;

}

double OuterRadiusTrapezoid(double a,double b,double c,double d){
    double OR;
    if (c == d){
        OR = (c*sqrt(a*b+c*c))/(sqrt((2*c-a+b)*(2*c+a-b)));
    }
    else OR =0;

    return OR;
}

double InnerRadiusTrapezoid(double a,double b,double c,double d){

    double IR;
    if( (a+b) == (c+d)){
        IR = HeightTrapezoid(a,b,c,d)/2;
    }
    else IR = 0;

    return IR;
}

double DiagonalTrapezoid1(double a,double b,double c,double d){

    auto D1 = sqrt((a*a*b-a*b*b-b*c*c+a*d*d)/(a-b));

    return D1;
}

double DiagonalTrapezoid2(double a,double b,double c,double d){

    auto D2 = sqrt((a*a*b-a*b*b-b*d*d+a*c*c)/(a-b));

    return D2;
}
