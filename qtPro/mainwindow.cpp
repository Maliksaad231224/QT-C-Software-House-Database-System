#include "mainwindow.h"
#include "ui_mainwindow.h"
bool emp=false;
bool dept=false;
bool team=false;
bool proj=false;
bool manager=false;
bool ins=false;
bool upd=false;
bool dis=false;
bool del=false;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->pushButton_7, &QPushButton::clicked, this, &MainWindow::on_pushButton_7_clicked);
     connect(ui->pushButton, &QPushButton::clicked, this, &MainWindow::on_pushButton_clicked);
 connect(ui->pushButton_6, &QPushButton::clicked, this, &MainWindow::on_pushButton_6_clicked);
connect(ui->pushButton_2, &QPushButton::clicked, this, &MainWindow::on_pushButton_2_clicked);
    QDir databasePath;
    QString path = databasePath.currentPath()+"/database.db"; // Not "myDb.db"
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setDatabaseName("qtdb");//replace with the databse file name
    db.setUserName("root");
    db.setPassword("231224");//replace with password of db



    db.open();

    if (db.open())
    {
        QMessageBox::information(this, "Connection", "Connected to the database successfully.");
    }
    else
    {
        QMessageBox::critical(this, "Connection", "Failed to connect to the database: " );

    }

ui->stackedWidget->setCurrentIndex(7);

}

MainWindow::~MainWindow()
{
    delete ui;
}

/*
void MainWindow::on_conn_clicked()
{

    QSqlQuery query; // And he should insert some data, as the answer above mentioned
    //talha umar all the backend code will be written here
    query.exec("insert into person "
              "(id,firstname,lastname,age)"
               "values()");

    ui->plainTextEdit->appendPlainText(QString("Query Executed!!"));

}

*/

void MainWindow::on_pushButton_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}


void MainWindow::on_pushButton_7_clicked()
{
     ui->stackedWidget->setCurrentIndex(0);
}





void MainWindow::on_pushButton_clicked()
{
     ui->stackedWidget->setCurrentIndex(2);
    ins=true;

}


void MainWindow::on_pushButton_6_clicked()
{
emp=true;
    if(emp==true&&ins==true){
     ui->stackedWidget->setCurrentIndex(3);
    }
    else if(emp==true&&upd==true){
          ui->stackedWidget->setCurrentIndex(4);
    }
     else if(emp==true&&del==true)
   {
     ui->stackedWidget->setCurrentIndex(5);
    }
    else if(emp==true&&dis==true)
    {
        ui->stackedWidget->setCurrentIndex(6);
    }

}


void MainWindow::on_pushButton_3_clicked()
{

    ui->stackedWidget->setCurrentIndex(2);
upd=true;
}

void MainWindow::homenaviagte()
{
    ui->stackedWidget->setCurrentIndex(1);
    emp=false;
    dept=false;
    team=false;
    proj=false;
    upd=false;
    ins=false;
    dis=false;
    del=false;
}

void MainWindow::on_homebutton_clicked()
{
   homenaviagte();
}


void MainWindow::on_homebutton_2_clicked()
{
    homenaviagte();
}


void MainWindow::on_homebutton_3_clicked()
{
    homenaviagte();
}


void MainWindow::on_homebutton_4_clicked()
{
    homenaviagte();
}


void MainWindow::on_pushButton_4_clicked()
{
    del=true;
      ui->stackedWidget->setCurrentIndex(2);
}


void MainWindow::on_homebutton_5_clicked()
{
    if(manager==true){
        ui->stackedWidget->setCurrentIndex(7);
        manager=false;
    }
    else{
        homenaviagte();}
}


void MainWindow::on_pushButton_5_clicked()
{
    dis=true;
       ui->stackedWidget->setCurrentIndex(2);
}


void MainWindow::on_homebutton_32_clicked()
{
    if(manager==true){
        ui->stackedWidget->setCurrentIndex(7);
        manager=false;
    }
    else{
        homenaviagte();
    }
}


void MainWindow::on_homebutton_31_clicked()
{
    homenaviagte();
}


void MainWindow::on_homebutton_15_clicked()
{
    homenaviagte();
}


void MainWindow::on_homebutton_14_clicked()
{
    homenaviagte();
}


void MainWindow::on_homebutton_13_clicked()
{
    if(manager==true){
         ui->stackedWidget->setCurrentIndex(7);
        manager=false;
    }
    else{
        homenaviagte();}
}


void MainWindow::on_homebutton_12_clicked()
{
    homenaviagte();
}


void MainWindow::on_homebutton_11_clicked()
{
    homenaviagte();
}

void MainWindow::on_homebutton_10_clicked()
{
    if(manager==true){
        ui->stackedWidget->setCurrentIndex(7);
        manager=false;
    }
    else{
    homenaviagte();
    }
}


void MainWindow::on_homebutton_9_clicked()
{
    homenaviagte();
}


void MainWindow::on_homebutton_8_clicked()
{
    homenaviagte();
}


void MainWindow::on_homebutton_6_clicked()
{
    homenaviagte();
}


void MainWindow::on_pushButton_79_clicked()
{
ui->stackedWidget->setCurrentIndex(0);
}


void MainWindow::on_pushButton_9_clicked()
{
    dept=true;
    if(dept==true&&dis==true){
        ui->stackedWidget->setCurrentIndex(14);
    }
    else if(dept==true&&ins==true){
          ui->stackedWidget->setCurrentIndex(12);
    }
    else if(dept==true&&upd==true){
           ui->stackedWidget->setCurrentIndex(13);
    }
}


void MainWindow::on_pushButton_10_clicked()
{
    team=true;
    if(team==true&&dis==true){
        ui->stackedWidget->setCurrentIndex(18);
    }
    else if(team==true&&ins==true){
        ui->stackedWidget->setCurrentIndex(15);
    }
    else if(team==true&&upd==true){
        ui->stackedWidget->setCurrentIndex(16);
    }
    else if(team==true&&del==true){
      ui->stackedWidget->setCurrentIndex(17);
    }
}


void MainWindow::on_pushButton_8_clicked()
{
    proj=true;
    if(proj==true&&dis==true){
        ui->stackedWidget->setCurrentIndex(11);
    }
    else if(proj==true&&ins==true){
        ui->stackedWidget->setCurrentIndex(8);
    }
    else if(proj==true&&upd==true){
        ui->stackedWidget->setCurrentIndex(9);
    }
    else if(proj==true&&del==true){
        ui->stackedWidget->setCurrentIndex(10);
    }
}


void MainWindow::on_pushButton_19_clicked()
{
    manager=true;
       ui->stackedWidget->setCurrentIndex(6);
}


void MainWindow::on_pushButton_20_clicked()
{
    manager=true;
    ui->stackedWidget->setCurrentIndex(11);
}


void MainWindow::on_pushButton_21_clicked()
{
    manager=true;
    ui->stackedWidget->setCurrentIndex(14);
}


void MainWindow::on_pushButton_22_clicked()
{
    manager=true;
    ui->stackedWidget->setCurrentIndex(18);
}

