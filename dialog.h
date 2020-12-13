#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QLabel>
#include <QDoubleValidator>
#include <QIntValidator>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    void setLabels(const int cnt, const QStringList &str);
    float* getDataArray() const;
    void switchValidator();

    ~Dialog();

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::Dialog *ui;
    float* data;
    bool result;
    QDoubleValidator floatValid;
    QIntValidator intValid;
    bool intValidBool;
};

#endif // DIALOG_H
