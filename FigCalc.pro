QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    cone.cpp \
    cylinder.cpp \
    dialog.cpp \
    flatcalc.cpp \
    flatfigure.cpp \
    main.cpp \
    mainwindow.cpp \
    nsquare.cpp \
    oval.cpp \
    parallelepiped.cpp \
    parellelogram.cpp \
    prism.cpp \
    pyramid.cpp \
    rectangle.cpp \
    trapezoid.cpp \
    triangle.cpp \
    volumecalc.cpp \
    volumfigure.cpp

HEADERS += \
    cone.h \
    cylinder.h \
    dialog.h \
    flatcalc.h \
    flatfigure.h \
    mainwindow.h \
    nsquare.h \
    oval.h \
    parallelepiped.h \
    parallelogram.h \
    prism.h \
    pyramid.h \
    rectangle.h \
    trapezoid.h \
    triangle.h \
    volumecalc.h \
    volumfigure.h

FORMS += \
    dialog.ui \
    mainwindow.ui

TRANSLATIONS += \
    FigCalc_ru_RU.ts

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
