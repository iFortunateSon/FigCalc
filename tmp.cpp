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

double SquareTriangle(double a,double b, double ab){

    double S = (a*b*sin(ab))/2;

    return S;
}

double PerimetrTriangle(double a,double b, double c){

    double P = a+b+c;

    return P;
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


double HeightTriangle(double a,double b, double c){
    auto S = SquareTriangle(a,b,c);
    auto h = 2*S/a;

    return h;

}


double SquareParallelogram(double a,double b, double ab){

    double S = a*b*sin(ab);

    return S;
}

double PerimetrParallelogram(double a,double b){

    double P = (a+b)*2;

    return P;
}




double SquareNangle(double a,double n){

    double S = 1;

    return S;
}

double PerimetrNangle(double a,double n){

    double P = a*n;

    return P;
}

double OuterRadiusNangle(double a,double n){
    auto pi = 3.14;
    auto OR = a/(2*sin(360/(2*n)));

    return OR;
}

double InnerRadiusNangle(double a,double n){

    auto IR = a/(2*tan(360/(2*n)));

    return IR;
}
