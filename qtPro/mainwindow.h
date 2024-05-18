#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QtSql/QSqlDatabase>
#include<QDebug>
//#include<QSqlDriver>
//#include<QSql>
#include<QSqlQuery>
#include<QMessageBox>
#include <QDir>

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


    void on_pushButton_2_clicked();

    void on_pushButton_7_clicked();



    void on_pushButton_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_3_clicked();

    void on_homebutton_clicked();

    void on_homebutton_2_clicked();

    void on_homebutton_3_clicked();

    void on_homebutton_4_clicked();
    void homenaviagte();

    void on_pushButton_4_clicked();

    void on_homebutton_5_clicked();

    void on_pushButton_5_clicked();

    void on_homebutton_32_clicked();

    void on_homebutton_31_clicked();

    void on_homebutton_15_clicked();

    void on_homebutton_14_clicked();

    void on_homebutton_13_clicked();

    void on_homebutton_12_clicked();

    void on_homebutton_11_clicked();

    void on_homebutton_10_clicked();

    void on_homebutton_9_clicked();

    void on_homebutton_8_clicked();

    void on_homebutton_6_clicked();

    void on_pushButton_79_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_19_clicked();

    void on_pushButton_20_clicked();

    void on_pushButton_21_clicked();

    void on_pushButton_22_clicked();



private:
    Ui::MainWindow *ui;

};
#endif
