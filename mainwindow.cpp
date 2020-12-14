#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dialog.h"
#include "info.h"

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
    ui->switch_2->setText("Clear and switch\n to 3D");
    ui->comboBox->addItems({"nsquare", "oval", "parallelogram", "rectangle", "trapezoid", "triangle"});
    ui ->statusbar->showMessage("2D mode enable");
    ui->lRes1->setText("Perimeter");
    ui->lRes2->setText("Square");

    ui -> listWidget->setContextMenuPolicy(Qt::CustomContextMenu);
    connect(ui->listWidget, SIGNAL(customContextMenuRequested(QPoint)), this, SLOT(showContextMenu(QPoint)));

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::showContextMenu(const QPoint &pos)
{
    QPoint globalPos = ui->listWidget->mapToGlobal(pos);

    QMenu myMenu;
    myMenu.addAction("Delete",  this, SLOT(deleteElement()));
    myMenu.addAction("Get Info",  this, SLOT(getInfo()));

    myMenu.exec(globalPos);
}


void MainWindow::on_switch_2_clicked()
{
    on_deleteAll_clicked();
    if (mode == 0) {
        //3D mode
        mode = 1;
        ui->switch_2->setText("Clear and switch\n to 2D");

        ui ->statusbar->showMessage("3D mode enable");

        ui->lRes1->setText("Square");
        ui->lRes2->setText("Volume");

        int len = ui->comboBox->count();
        for(int i=0;i<len;i++)
        {
           ui->comboBox->removeItem(0);
        }
        ui->comboBox->clear();

        ui->comboBox->addItems({"cone", "cylinder", "parallelepiped", "prism", "pyramid"});
    }
    else {
        //2D mode
        mode = 0;
        ui->switch_2->setText("Clear and switch\n to 3D");

        ui ->statusbar->showMessage("2D mode enable");

        ui->lRes1->setText("Perimeter");
        ui->lRes2->setText("Square");

        int len = ui->comboBox->count();
        for(int i=0;i<len;i++)
        {
           ui->comboBox->removeItem(0);
        }
        ui->comboBox->clear();

        ui->comboBox->addItems({"nsquare", "oval", "parallelogram", "rectangle", "trapezoid", "triangle"});
    }
    ui->lineResult1->clear();
    ui->lineResult2->clear();
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
            window.switchValidator();
            window.exec();
            tmp = window.getDataArray();
            if(tmp == NULL){
                return;
            }
            if(tmp[0] <= 3){
                tmp[0] = 3;
            }
            figure = (FlatFigure*)new Nsquare(tmp[0], tmp[1]);
            log(QString("Nsquare:\n  Side count= %1, Side size= %2").arg(QString::number(tmp[0]),QString::number(tmp[1])));
            window.switchValidator();
        break;
        case 1:
            //oval
            window.setLabels(2, {"First radius", "Second radius"});
            window.exec();
            tmp = window.getDataArray();
            if(tmp == NULL){
                return;
            }
            figure = (FlatFigure*)new oval(tmp[0], tmp[1]);
            log(QString("Oval:\n  First radius= %1, Second radius= %2").arg(QString::number(tmp[0]),QString::number(tmp[1])));

        break;
        case 2:
            //parallelogram
            window.setLabels(3, {"First side", "Second side", "Angle"});
            window.exec();
            tmp = window.getDataArray();
            if(tmp == NULL){
                return;
            }
            figure = (FlatFigure*)new parallelogram(tmp[0], tmp[1],tmp[2]);
            log(QString("Parallelogram:\n  First side= %1, Second side= %2\n Angle= %3").arg(QString::number(tmp[0]),QString::number(tmp[1]),QString::number(tmp[2])));

        break;
        case 3:
            //rectangle
            window.setLabels(2, {"First side", "Second side"});
            window.exec();
            tmp = window.getDataArray();
            if(tmp == NULL){
                return;
            }
            figure = (FlatFigure*)new rectangle(tmp[0], tmp[1]);
            log(QString("Rectangle:\n  First side= %1, Second side= %2").arg(QString::number(tmp[0]),QString::number(tmp[1])));
        break;
        case 4:
            //trapezoid
            window.setLabels(4, {"First side", "Second side", "Third side", "Fourth side"});
            window.exec();
            tmp = window.getDataArray();
            if(tmp == NULL){
                return;
            }
            if(tmp[0] > (tmp[1]+tmp[2] +tmp[3]) ){
                return;
            }
            if(tmp[1] > (tmp[0]+tmp[2] +tmp[3]) ){
                return;
            }
            if(tmp[2] > (tmp[1]+tmp[0] +tmp[3]) ){
                return;
            }
            if(tmp[3] > (tmp[1]+tmp[2] +tmp[0]) ){
                return;
            }

            figure = (FlatFigure*)new trapezoid(tmp[0], tmp[1],tmp[2],tmp[3]);
            log(QString("Trapezoid:\n  First side= %1, Second side= %2\n Third side= %3, Fourth side= %4").arg(QString::number(tmp[0]),QString::number(tmp[1])
                                                                                                        ,QString::number(tmp[2]),QString::number(tmp[3])));
        break;
        case 5:
            //triangle
            window.setLabels(3, {"First side", "Second side", "Third side"});
            window.exec();
            tmp = window.getDataArray();
            if(tmp == NULL){
                return;
            }
            figure = (FlatFigure*)new triangle(tmp[0], tmp[1], tmp[2]);
            log(QString("Triangle:\n  First side= %1, Second side= %2\n Third side= %3").arg(QString::number(tmp[0]),QString::number(tmp[1]),QString::number(tmp[2])));
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
            if(tmp == NULL){
                return;
            }
            figure = (VolumeFigure*)new cone(tmp[0], tmp[1]);
            log(QString("Cone:\n  Height= %1, Side radius= %2").arg(QString::number(tmp[0]),QString::number(tmp[1])));
        break;
        case 1:
            //cylinder
            window.setLabels(2, {"Height", "Side radius"});
            window.exec();
            tmp = window.getDataArray();
            if(tmp == NULL){
                return;
            }
            figure = (VolumeFigure*)new cylinder(tmp[0], tmp[1]);
            log(QString("Cylinder:\n  Height= %1, Side radius= %2").arg(QString::number(tmp[0]),QString::number(tmp[1])));
        break;
        case 2:
            //parallelepiped
            window.setLabels(3, {"First side", "Second side", "Third side"});
            window.exec();
            tmp = window.getDataArray();
            if(tmp == NULL){
                return;
            }
            figure = (VolumeFigure*)new parallelepiped(tmp[0], tmp[1], tmp[2]);
            log(QString("Parallelepiped:\n  First side= %1, Second side= %2\n Third side= %3").arg(QString::number(tmp[0]),QString::number(tmp[1]),QString::number(tmp[2])));

        break;
        case 3:
            //prism
            window.setLabels(3, {"Side count", "Side size", "Height"});
            window.switchValidator();
            window.exec();
            tmp = window.getDataArray();
            if(tmp == NULL){
                return;
            }
            if(tmp[0] <= 3){
                tmp[0] = 3;
            }
            figure = (VolumeFigure*)new prism(tmp[0], tmp[1], tmp[2]);
            log(QString("Prism:\n  Side count= %1, Side size= %2\n Height= %3").arg(QString::number(tmp[0]),QString::number(tmp[1]),QString::number(tmp[2])));
            window.switchValidator();

        break;
        case 4:
            //pyramid
            window.setLabels(3, {"Side count", "Side size", "Height"});
            window.switchValidator();
            window.exec();
            tmp = window.getDataArray();
            if(tmp == NULL){
                return;
            }
            if(tmp[0] <= 3){
                tmp[0] = 3;
            }
            figure = (VolumeFigure*)new pyramid(tmp[0], tmp[1], tmp[2]);
            log(QString("Pyramid:\n  Side count= %1, Side size= %2\n Height= %3").arg(QString::number(tmp[0]),QString::number(tmp[1]),QString::number(tmp[2])));
            window.switchValidator();
        break;
        }
        volumeCalc.addFigure(figure);
    }
}


void MainWindow::on_plus_clicked(){

    if (mode == 0) {
        //2D mode
        if(flatCalc.getCount() >=2 ){
            flatCalc.calculate('+');
            auto ans1 = flatCalc.getResultOne();
            auto ans2 = flatCalc.getResultTwo();

            ui->lineResult1->setText(QString::number(ans1));
            ui->lineResult2->setText(QString::number(ans2));
        }

    }
    else {
        //3D mode
        if(volumeCalc.getCount() >= 2){

            volumeCalc.calculate('+');
            auto ans1 = volumeCalc.getResultOne();
            auto ans2 = volumeCalc.getResultTwo();

            ui->lineResult1->setText(QString::number(ans1));
            ui->lineResult2->setText(QString::number(ans2));
        }
    }

}

void MainWindow::on_minus_clicked(){

    if (mode == 0) {
        //2D mode
        if(flatCalc.getCount() >=2 ){
            flatCalc.calculate('-');
            auto ans1 = flatCalc.getResultOne();
            auto ans2 = flatCalc.getResultTwo();

            ui->lineResult1->setText(QString::number(ans1));
            ui->lineResult2->setText(QString::number(ans2));
        }

    }
    else {
        //3D mode
        if(volumeCalc.getCount() >= 2){

            volumeCalc.calculate('-');
            auto ans1 = volumeCalc.getResultOne();
            auto ans2 = volumeCalc.getResultTwo();

            ui->lineResult1->setText(QString::number(ans1));
            ui->lineResult2->setText(QString::number(ans2));
        }
    }

}

void MainWindow::on_multiply_clicked(){

    if (mode == 0) {
        //2D mode
        if(flatCalc.getCount() >=2 ){
            flatCalc.calculate('*');
            auto ans1 = flatCalc.getResultOne();
            auto ans2 = flatCalc.getResultTwo();

            ui->lineResult1->setText(QString::number(ans1));
            ui->lineResult2->setText(QString::number(ans2));
        }

    }
    else {
        //3D mode
        if(volumeCalc.getCount() >= 2){

            volumeCalc.calculate('*');
            auto ans1 = volumeCalc.getResultOne();
            auto ans2 = volumeCalc.getResultTwo();

            ui->lineResult1->setText(QString::number(ans1));
            ui->lineResult2->setText(QString::number(ans2));
        }
    }

}

void MainWindow::on_division_clicked(){

    if (mode == 0) {
        //2D mode
        if(flatCalc.getCount() >=2 ){
            flatCalc.calculate('/');
            auto ans1 = flatCalc.getResultOne();
            auto ans2 = flatCalc.getResultTwo();

            ui->lineResult1->setText(QString::number(ans1));
            ui->lineResult2->setText(QString::number(ans2));
        }

    }
    else {
        //3D mode
        if(volumeCalc.getCount() >= 2){

            volumeCalc.calculate('/');
            auto ans1 = volumeCalc.getResultOne();
            auto ans2 = volumeCalc.getResultTwo();

            ui->lineResult1->setText(QString::number(ans1));
            ui->lineResult2->setText(QString::number(ans2));
        }
    }

}


void MainWindow::log(const QString &text_) {
    ui->listWidget->addItem(text_);
}


void MainWindow::on_deleteTop_clicked()
{
    int cnt = 0;
    if (mode == 0) {
        //2D mode
         cnt = flatCalc.getCount();
         flatCalc.removeTop();
    }
    else {
        //3D mode
        cnt = volumeCalc.getCount();
        volumeCalc.removeTop();
    }
    if(cnt > 0){

        delete ui->listWidget->takeItem(cnt-1);
    }
}


void MainWindow::deleteElement(){
    int cnt = ui->listWidget->currentRow();
    if(mode == 0)
    {
        flatCalc.removeElementWithID(cnt);
    }else{
        volumeCalc.removeElementWithID(cnt);
    }
    delete ui->listWidget->takeItem(cnt);

}


void MainWindow::getInfo(){
    int cnt = ui->listWidget->currentRow();
    Info window;
    QString info;
    if(mode == 0)
    {
        info = flatCalc.getInfo(cnt);
        window.setTexte(info);
        window.exec();
    }else{
        //что-то не работает
        info = volumeCalc.getInfo(cnt);
        window.setTexte(volumeCalc.getInfo(cnt));
        window.exec();
    }
}


void MainWindow::on_deleteAll_clicked()
{
    int cnt = 0;
    if (mode == 0) {
        //2D mode
        cnt = flatCalc.getCount();
        for(int i = 0; i < cnt; i++){

            flatCalc.removeTop();
            delete ui->listWidget->takeItem(0);
        }
    }
    else {
        //3D mode
        cnt = volumeCalc.getCount();
        for(int i = 0; i < cnt; i++){
            volumeCalc.removeTop();
            delete ui->listWidget->takeItem(0);
        }

    }

}
