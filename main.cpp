#include "mainwindow.h"
#include <QApplication>
#include <iostream>

#include "cone.h"
#include "cylinder.h"
#include "flatfigure.h"
#include "nsquare.h"
#include "oval.h"
#include "parallelepiped.h"
#include "parallelogram.h"
#include "prism.h"
#include "pyramid.h"
#include "rectangle.h"
#include "trapezoid.h"
#include "triangle.h"
#include "volumfigure.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
