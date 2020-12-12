#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dialog.h"
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
#include <iostream>
#include <string>



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    mode = 0;
    ui->comboBox->addItems({"nsquare", "oval", "parallelogram", "rectangle", "trapezoid", "triangle"});
    ui ->statusbar->showMessage("2D mode enable");
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_switch_2_clicked()
{
    if (mode == 0) {
        //3D mode
        mode = 1;
        ui->switch_2->setText("Switch to 2D");

        int len = ui->comboBox->count();
        for(int i=0;i<len;i++)
        {
           ui->comboBox->removeItem(0);
        }
        ui->comboBox->clear();

        ui ->statusbar->showMessage("3D mode enable");

        ui->comboBox->addItems({"cone", "cylinder", "parallelepiped", "prism", "pyramid"});

        ui->textEdit->clear();
    }
    else {
        //2D mode
        mode = 0;
        ui->switch_2->setText("Switch to 3D");

        int len = ui->comboBox->count();
        for(int i=0;i<len;i++)
        {
           ui->comboBox->removeItem(0);
        }
        ui->comboBox->clear();

        ui ->statusbar->showMessage("2D mode enable");

        ui->comboBox->addItems({"nsquare", "oval", "parallelogram", "rectangle", "trapezoid", "triangle"});

        ui->textEdit->clear();
    }
}

void MainWindow::on_add_clicked()
{
    int i = ui->comboBox->currentIndex();
    Dialog window;
    float *tmp;
    window.setModal(true);

    if(mode == 0){
        //2D mode
        FlatFigure* figure;
        switch (i)
        {
        case 0:
            //nsquare
            window.setLabels(2, {"Side count", "Side size"});
            window.exec();
            tmp = window.getDataArray();
            figure = (FlatFigure*)new Nsquare(tmp[0], tmp[1]);
            log(QString("Nsquare:  Side count= %1, Side size= %2").arg(QString::number(tmp[0]),QString::number(tmp[1])));
        break;
        case 1:
            //oval
            window.setLabels(2, {"First radius", "Second radius"});
            window.exec();
            tmp = window.getDataArray();
            figure = (FlatFigure*)new oval(tmp[0], tmp[1]);
            log(QString("Oval:  First radius= %1, Second radius= %2").arg(QString::number(tmp[0]),QString::number(tmp[1])));

        break;
        case 2:
            //parallelogram
            window.setLabels(3, {"First side", "Second side", "Angle"});
            window.exec();
            tmp = window.getDataArray();
            figure = (FlatFigure*)new parallelogram(tmp[0], tmp[1],tmp[2]);
            log(QString("Parallelogram:  First side= %1, Second side= %2, Angle= %3").arg(QString::number(tmp[0]),QString::number(tmp[1]),QString::number(tmp[2])));

        break;
        case 3:
            //rectangle
            window.setLabels(2, {"First side", "Second side"});
            window.exec();
            tmp = window.getDataArray();
            figure = (FlatFigure*)new rectangle(tmp[0], tmp[1]);
            log(QString("Rectangle:  First side= %1, Second side= %2").arg(QString::number(tmp[0]),QString::number(tmp[1])));
        break;
        case 4:
            //trapezoid
            window.setLabels(4, {"First side", "Second side", "Third side", "Fourth side"});
            window.exec();
            tmp = window.getDataArray();
            figure = (FlatFigure*)new trapezoid(tmp[0], tmp[1],tmp[2],tmp[3]);
            log(QString("Trapezoid:  First side= %1, Second side= %2, Third side= %2, Fourth side= %2").arg(QString::number(tmp[0]),QString::number(tmp[1])
                                                                                                        ,QString::number(tmp[2]),QString::number(tmp[3])));
        break;
        case 5:
            //triangle
            window.setLabels(3, {"First side", "Second side", "Third side"});
            window.exec();
            tmp = window.getDataArray();
            //triangle
            figure = (FlatFigure*)new triangle(tmp[0], tmp[1], tmp[2]);
            log(QString("Triangle:  First side= %1, Second side= %2, Third side= %3").arg(QString::number(tmp[0]),QString::number(tmp[1]),QString::number(tmp[2])));
        break;
        }

        flatCalc.addFigure(figure);
    }else{
        //3D mode
        VolumeFigure* figure;
        switch (i)
        {
        case 0:
            //cone
            window.setLabels(2, {"Height", "Side radius"});
            window.exec();
            tmp = window.getDataArray();
            figure = (VolumeFigure*)new cone(tmp[0], tmp[1]);
            log(QString("Cone:  Height= %1, Side radius= %2").arg(QString::number(tmp[0]),QString::number(tmp[1])));
        break;
        case 1:
            //cylinder
            window.setLabels(2, {"Height", "Side radius"});
            window.exec();
            tmp = window.getDataArray();
            figure = (VolumeFigure*)new cylinder(tmp[0], tmp[1]);
            log(QString("Cylinder:  Height= %1, Side radius= %2").arg(QString::number(tmp[0]),QString::number(tmp[1])));
        break;
        case 2:
            //parallelepiped
            window.setLabels(3, {"First side", "Second side", "Third side"});
            window.exec();
            tmp = window.getDataArray();
            figure = (VolumeFigure*)new parallelepiped(tmp[0], tmp[1], tmp[2]);
            log(QString("Parallelepiped:  First side= %1, Second side= %2, Third side= %3").arg(QString::number(tmp[0]),QString::number(tmp[1]),QString::number(tmp[2])));

        break;
        case 3:
            //prism
            window.setLabels(3, {"Side count", "Side size", "Height"});
            window.exec();
            tmp = window.getDataArray();
            figure = (VolumeFigure*)new prism(tmp[0], tmp[1], tmp[2]);
            log(QString("Prism:  Side count= %1, Side size= %2, Height= %3").arg(QString::number(tmp[0]),QString::number(tmp[1]),QString::number(tmp[2])));

        break;
        case 4:
            //pyramid
            window.setLabels(3, {"Side count", "Side size", "Height"});
            window.exec();
            tmp = window.getDataArray();
            figure = (VolumeFigure*)new pyramid(tmp[0], tmp[1], tmp[2]);
            log(QString("Pyramid:  Side count= %1, Side size= %2, Height= %3").arg(QString::number(tmp[0]),QString::number(tmp[1]),QString::number(tmp[2])));

        break;
        }
    }
}


void MainWindow::on_plus_clicked(){

    if (mode == 0) {
        //2D mode

        flatCalc.calculate('+');
        auto ans1 = flatCalc.getResultOne();
        auto ans2 = flatCalc.getResultTwo();

        ui->lineEdit->setText(QString::number(ans1));
        ui->lineEdit_2->setText(QString::number(ans2));

    }
    else {
        //3D mode
        volumeCalc.calculate('+');
        auto ans1 = volumeCalc.getResultOne();
        auto ans2 = volumeCalc.getResultTwo();

        ui->lineEdit->setText(QString::number(ans1));
        ui->lineEdit_2->setText(QString::number(ans2));
    }

}

void MainWindow::on_minus_clicked(){

    if (mode == 0) {
        //2D mode

        flatCalc.calculate('-');
        auto ans1 = flatCalc.getResultOne();
        auto ans2 = flatCalc.getResultTwo();

        ui->lineEdit->setText(QString::number(ans1));
        ui->lineEdit_2->setText(QString::number(ans2));

    }
    else {
        //3D mode
        volumeCalc.calculate('-');
        auto ans1 = volumeCalc.getResultOne();
        auto ans2 = volumeCalc.getResultTwo();

        ui->lineEdit->setText(QString::number(ans1));
        ui->lineEdit_2->setText(QString::number(ans2));
    }

}

void MainWindow::on_multiply_clicked(){

    if (mode == 0) {
        //2D mode

        flatCalc.calculate('*');
        auto ans1 = flatCalc.getResultOne();
        auto ans2 = flatCalc.getResultTwo();

        ui->lineEdit->setText(QString::number(ans1));
        ui->lineEdit_2->setText(QString::number(ans2));

    }
    else {
        //3D mode
        volumeCalc.calculate('*');
        auto ans1 = volumeCalc.getResultOne();
        auto ans2 = volumeCalc.getResultTwo();

        ui->lineEdit->setText(QString::number(ans1));
        ui->lineEdit_2->setText(QString::number(ans2));
    }

}

void MainWindow::on_division_clicked(){

    if (mode == 0) {
        //2D mode

        flatCalc.calculate('/');
        auto ans1 = flatCalc.getResultOne();
        auto ans2 = flatCalc.getResultTwo();

        ui->lineEdit->setText(QString::number(ans1));
        ui->lineEdit_2->setText(QString::number(ans2));

    }
    else {
        //3D mode
        volumeCalc.calculate('/');
        auto ans1 = volumeCalc.getResultOne();
        auto ans2 = volumeCalc.getResultTwo();

        ui->lineEdit->setText(QString::number(ans1));
        ui->lineEdit_2->setText(QString::number(ans2));
    }

}







void MainWindow::log(const QString &text_) {
    ui->textEdit->setText(ui->textEdit->toPlainText() + text_ + "\n");

}

