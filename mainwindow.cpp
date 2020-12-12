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
        break;
        case 1:
            //oval
            window.setLabels(2, {"First radius", "Second radius"});
            window.exec();
            tmp = window.getDataArray();
            figure = (FlatFigure*)new oval(tmp[0], tmp[1]);

        break;
        case 2:
            //parallelogram
            window.setLabels(3, {"First side", "Second side", "Angle"});
            window.exec();
            tmp = window.getDataArray();
            figure = (FlatFigure*)new parallelogram(tmp[0], tmp[1],tmp[2]);

        break;
        case 3:
            //rectangle
            window.setLabels(2, {"First side", "Second side"});
            window.exec();
            tmp = window.getDataArray();
            figure = (FlatFigure*)new rectangle(tmp[0], tmp[1]);
        break;
        case 4:
            //trapezoid
            window.setLabels(4, {"First side", "Second side", "Third side", "Fourth side"});
            window.exec();
            tmp = window.getDataArray();
//            figure = (FlatFigure*)new trapezoid(tmp[0], tmp[1]);
        break;
        case 5:
            //triangle
            window.setLabels(3, {"First side", "Second side", "Third side"});
            window.exec();
            tmp = window.getDataArray();
            //triangle
            figure = (FlatFigure*)new triangle(tmp[0], tmp[1], tmp[2]);
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
        break;
        case 1:
            //cylinder
            window.setLabels(2, {"Height", "Side radius"});
            window.exec();
            tmp = window.getDataArray();
            figure = (VolumeFigure*)new cylinder(tmp[0], tmp[1]);
        break;
        case 2:
            //parallelepiped
            window.setLabels(3, {"First side", "Second side", "Third side"});
            window.exec();
            tmp = window.getDataArray();
            figure = (VolumeFigure*)new parallelepiped(tmp[0], tmp[1], tmp[2]);

        break;
        case 3:
            //prism
            window.setLabels(3, {"Side count", "Side size", "Height"});
            window.exec();
            tmp = window.getDataArray();
            figure = (VolumeFigure*)new prism(tmp[0], tmp[1], tmp[2]);
        break;
        case 4:
            //pyramid
            window.setLabels(3, {"Side count", "Side size", "Height"});
            window.exec();
            tmp = window.getDataArray();
            figure = (VolumeFigure*)new pyramid(tmp[0], tmp[1], tmp[2]);
        break;
        }
    }
}

void MainWindow::log(const QString &text_) {
    ui->textEdit->setText(ui->textEdit->toPlainText() + text_ + "\n");

}
