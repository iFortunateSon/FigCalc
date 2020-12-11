#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    mode = 0;
    ui->comboBox->addItems({"nsquare", "oval", "parallelogram", "rectangle", "trapezoid", "triangle"});

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

        ui->comboBox->addItems({"nsquare", "oval", "parallelogram", "rectangle", "trapezoid", "triangle"});
    }
}

void MainWindow::on_add_clicked()
{
    int i = ui->comboBox->currentIndex();
}
