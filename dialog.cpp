#include "dialog.h"
#include "ui_dialog.h"
#include <QStringList>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog),
    floatValid(0, 50, 2),
    intValid(3, 100)
{
    ui->setupUi(this);
    data = NULL;
    ui->lOne->setValidator(&floatValid);
    ui->lTwo->setValidator(&floatValid);
    ui->lThree->setValidator(&floatValid);
    ui->lFour->setValidator(&floatValid);

    intValidBool = false;

}

Dialog::~Dialog()
{
    delete ui;
    delete[] data;
}

void Dialog::setLabels(const int cnt,const QStringList &str)
{

    switch (cnt) {
    case 1:
    case 2:
        ui->pThree->setHidden(true);
        ui->lThree->setHidden(true);
    case 3:
        ui->pFour->setHidden(true);
        ui->lFour->setHidden(true);
        break;
    }

    switch (cnt) {
    case 4:
        ui->pFour->setText(str[3]);
    case 3:
        ui->pThree->setText(str[2]);
    case 2:
        ui->pTwo->setText(str[1]);
    case 1:
        ui->pOne->setText(str[0]);
        break;
    }
}


void Dialog::switchValidator(){
    if(intValidBool){
        intValidBool = false;
        ui->lOne->setValidator(&floatValid);

    }else{
        intValidBool = true;
        ui->lOne->setValidator(&intValid);

    }
}


float* Dialog::getDataArray() const{
    return data;
}


void Dialog::on_buttonBox_accepted()
{

    data = new float[4];
    data[0] = ui->lOne->text().toFloat();
    data[1] = ui->lTwo->text().toFloat();
    data[2] = ui->lThree->text().toFloat();
    data[3] = ui->lFour->text().toFloat();
}

void Dialog::on_buttonBox_rejected()
{

}
