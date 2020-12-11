#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dialog.h"
#include <iostream>

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
        switch (i)
        {
        case 0:
            //nsquare
            window.setLabels(2, {"Side count", "Side size"});
            window.exec();
            tmp = window.getDataArray();

        break;
        case 1:
            //oval
            window.setLabels(2, {"First radius", "Second radius"});
            window.exec();
            tmp = window.getDataArray();
        break;
        case 2:
            //parallelogram
            window.setLabels(3, {"First side", "Second side", "Angle"});
            window.exec();
            tmp = window.getDataArray();
        break;
        case 3:
            //rectangle
            window.setLabels(2, {"First side", "Second side"});
            window.exec();
            tmp = window.getDataArray();
        break;
        case 4:
            //trapezoid
            window.setLabels(4, {"First side", "Second side", "Third side", "Fourth side"});
            window.exec();
            tmp = window.getDataArray();
        break;
        case 5:
            //triangle
            window.setLabels(3, {"First side", "Second side", "Third side"});
            window.exec();
            tmp = window.getDataArray();
            //triangle
        break;
        }
    }else{
        //3D mode
        switch (i)
        {
        case 0:
            //cone
            window.setLabels(2, {"Height", "Side radius"});
            window.exec();
            tmp = window.getDataArray();
        break;
        case 1:
            //cylinder
            window.setLabels(2, {"Height", "Side radius"});
            window.exec();
            tmp = window.getDataArray();
        break;
        case 2:
            //parallelepiped
            window.setLabels(3, {"First side", "Second side", "Third side"});
            window.exec();
            tmp = window.getDataArray();
        break;
        case 3:
            //prism
            window.setLabels(3, {"Side count", "Side size", "Height"});
            window.exec();
            tmp = window.getDataArray();
        break;
        case 4:
            //pyramid
            window.setLabels(3, {"Side count", "Side size", "Height"});
            window.exec();
            tmp = window.getDataArray();
        break;
        }
    }
}
