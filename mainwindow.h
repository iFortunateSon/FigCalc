#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStringList>
#include "flatcalc.h"
#include "volumecalc.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_switch_2_clicked();

    void on_add_clicked();

private:
    Ui::MainWindow *ui;
    int mode;
    FlatCalc flatCalc;
    VolumeCalc volumeCalc;
};
#endif // MAINWINDOW_H
