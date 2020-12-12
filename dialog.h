#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QLabel>

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
    ~Dialog();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::Dialog *ui;
    float* data;
};

#endif // DIALOG_H