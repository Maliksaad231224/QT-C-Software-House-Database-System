#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtSql/QSqlQuery>
#include<QSqlDatabase>
#include<QDebug>
#include<QSqlDriver>
#include<QSql>
#include<QSqlQuery>
#include<QMessageBox>
#include <QDir>
#include <QDebug>
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


    connect(ui->pushButton_80, &QPushButton::clicked, this, &MainWindow::on_pushButton_80_clicked);

 connect(ui->pushButton_6, &QPushButton::clicked, this, &MainWindow::on_pushButton_6_clicked);
connect(ui->pushButton_2, &QPushButton::clicked, this, &MainWindow::on_pushButton_2_clicked);
    QDir databasePath;
    QString path = databasePath.currentPath()+"/database.db"; // Not "myDb.db"
    db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setDatabaseName("project");//replace with the databse file name
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
    QString Fname=ui->firstname->text();
    QString Lname=ui->lastname->text();
    QString Sex=ui->gender->text();
    QString email=ui->email->text();
    QString teamID=ui->teamid->text();
    QString Address=ui->address->text();
    QString teamtitle="A";
    QString empdepat="A";
    QString EmployeeID="A";
    QString empsalary="A";
    QString Supervisor_ID="A";
    QString empstatus="A";

    // QSqlQuery qry;

    // qry.prepare("INSERT INTO emp (id, name) VALUES (:EmployeeID, :Fname)");
    // qry.bindValue(":EmployeeID","3");
    // qry.bindValue(":Fname","Fname");


    // if(qry.exec()){
    //     QMessageBox::information(this,"insertion","Successful");
    // }
    // else{
    //     QMessageBox::information(this,"insertion","unsuccessful"/*+ QString(qry.lastError().text())*/);
    // }


ui->stackedWidget->setCurrentIndex(0);

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

  QSqlQuery query("project");
    QString username = ui->loginuser->toPlainText();
    QString password = ui->loginpassword->toPlainText();
    QString HR = "HR";
    QString M = "Manager";
    QString hrusername="hruser";
        QString hrpassword="hrpass";
    QString mgusername="manager";
    QString mgpassword="mpass";




        if (username == hrusername && password == hrpassword)
        {
                ui->stackedWidget->setCurrentIndex(3); // HR dashboard
        }
        else if(username == mgusername && password == mgpassword){
                // Invalid user type (not HR or Manager)
             ui->stackedWidget->setCurrentIndex(12);
        }
        else{
                QMessageBox::warning(this, "Invalid User Type", "Your account does not have the required permissions.");
            }




    }





void MainWindow::on_pushButton_7_clicked()
{
     ui->stackedWidget->setCurrentIndex(17);
}





void MainWindow::on_pushButton_clicked()
{
     ui->stackedWidget->setCurrentIndex(6);

}


void MainWindow::on_pushButton_6_clicked()
{
 ui->stackedWidget->setCurrentIndex(4);


}


void MainWindow::on_pushButton_3_clicked()
{

    ui->stackedWidget->setCurrentIndex(7);

}

void MainWindow::homenaviagte()
{
    ui->stackedWidget->setCurrentIndex(3);

}

void MainWindow::on_homebutton_clicked()
{
   homenaviagte();
}


void MainWindow::on_homebutton_2_clicked()
{
    employeeview();
}


void MainWindow::on_homebutton_3_clicked()
{
    employeeview();
}


void MainWindow::on_homebutton_4_clicked()
{
    employeeview();
}
/*

void MainWindow::on_pushButton_4_clicked()
{

      ui->stackedWidget->setCurrentIndex(3);
}
*/

void MainWindow::on_homebutton_5_clicked()
{
    if(manager==true){
        managerview();
    }
    else{


    employeeview();
    }}


void MainWindow::on_pushButton_5_clicked()
{
       ui->stackedWidget->setCurrentIndex(9);
}


void MainWindow::on_homebutton_32_clicked()
{
    if(manager==true){
          ui->stackedWidget->setCurrentIndex(12);
    }
    else{
        teamview();}
}


void MainWindow::on_homebutton_31_clicked()
{
    homenaviagte();
}


void MainWindow::on_homebutton_15_clicked()
{
    teamview();
}


void MainWindow::on_homebutton_14_clicked()
{
    teamview();
}


void MainWindow::on_homebutton_13_clicked()
{
    if(manager==true){
     ui->stackedWidget->setCurrentIndex(12);
    }
    else{
        departmentview();}
}

void MainWindow::on_homebutton_12_clicked()
{
    departmentview();
}


void MainWindow::on_homebutton_11_clicked()
{
    departmentview();
}

void MainWindow::on_homebutton_10_clicked()
{
    if(manager==true){
        ui->stackedWidget->setCurrentIndex(12);
    }
    else{
        projectview();}
}


void MainWindow::on_homebutton_9_clicked()
{
    projectview();
}


void MainWindow::on_homebutton_8_clicked()
{
    projectview();
}


void MainWindow::on_homebutton_6_clicked()
{
    projectview();
}


void MainWindow::on_pushButton_79_clicked()
{
ui->stackedWidget->setCurrentIndex(0);
    manager=false;
}


void MainWindow::on_pushButton_9_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);

}


void MainWindow::on_pushButton_10_clicked()
{
       ui->stackedWidget->setCurrentIndex(11);


}


void MainWindow::on_pushButton_8_clicked()
{
     ui->stackedWidget->setCurrentIndex(10);
}


void MainWindow::on_pushButton_19_clicked()
{
    manager=true;
       ui->stackedWidget->setCurrentIndex(9);
}


void MainWindow::on_pushButton_20_clicked()
{
    manager=true;
    ui->stackedWidget->setCurrentIndex(16);
}


void MainWindow::on_pushButton_21_clicked()
{
    manager=true;
    ui->stackedWidget->setCurrentIndex(19);
}


void MainWindow::on_pushButton_22_clicked()
{
    ui->stackedWidget->setCurrentIndex(23);
    manager=true;
}


void MainWindow::on_pushButton_80_clicked()
{
     ui->stackedWidget->setCurrentIndex(0);
}


void MainWindow::on_pushButton_30_clicked()
{
      ui->stackedWidget->setCurrentIndex(2);
}





void MainWindow::on_pushButton_14_clicked()
{
     departmentview();
}


void MainWindow::on_pushButton_15_clicked()
{
     ui->stackedWidget->setCurrentIndex(18);
}


void MainWindow::on_pushButton_12_clicked()
{
     ui->stackedWidget->setCurrentIndex(19);
}


void MainWindow::on_pushButton_16_clicked()
{
     ui->stackedWidget->setCurrentIndex(13);
}


void MainWindow::on_pushButton_23_clicked()
{
     ui->stackedWidget->setCurrentIndex(14);
}


void MainWindow::on_pushButton_18_clicked()
{
     ui->stackedWidget->setCurrentIndex(15);
}


void MainWindow::on_pushButton_17_clicked()
{
      ui->stackedWidget->setCurrentIndex(16);
}


void MainWindow::on_pushButton_24_clicked()
{
      ui->stackedWidget->setCurrentIndex(20);
}


void MainWindow::on_pushButton_28_clicked()
{
      ui->stackedWidget->setCurrentIndex(21);
}


void MainWindow::on_pushButton_27_clicked()
{
      ui->stackedWidget->setCurrentIndex(22);
}


void MainWindow::on_pushButton_25_clicked()
{
      ui->stackedWidget->setCurrentIndex(23);
}


void MainWindow::on_pushButton_32_clicked()
{
     projectview();
}


void MainWindow::on_pushButton_31_clicked()
{
     teamview();
}


void MainWindow::on_pushButton_33_clicked()
{
     projectview();
}

void MainWindow::projectview()
{
    ui->stackedWidget->setCurrentIndex(10);
}
void MainWindow::employeeview()
{
    ui->stackedWidget->setCurrentIndex(4);
}
void MainWindow::departmentview()
{
    ui->stackedWidget->setCurrentIndex(5);
}
void MainWindow::teamview()
{
    ui->stackedWidget->setCurrentIndex(11);
}

void MainWindow::on_pushButton_37_clicked()
{
    employeeview();
}


void MainWindow::on_pushButton_40_clicked()
{
    teamview();
}


void MainWindow::on_pushButton_41_clicked()
{
    departmentview();
}


void MainWindow::on_pushButton_42_clicked()
{
    teamview();
}


void MainWindow::on_pushButton_43_clicked()
{
    employeeview();
}


void MainWindow::on_pushButton_44_clicked()
{
    employeeview();
}


void MainWindow::on_pushButton_45_clicked()
{
    departmentview();
}


void MainWindow::on_pushButton_46_clicked()
{
    homenaviagte();
}


void MainWindow::on_homebutton_16_clicked()
{
    homenaviagte();
}


void MainWindow::on_homebutton_17_clicked()
{
    homenaviagte();
}


void MainWindow::on_homebutton_18_clicked()
{
    if(manager==true){
        managerview();

    }
    else{
    homenaviagte();
    }}


void MainWindow::on_homebutton_20_clicked()
{
    homenaviagte();
}


void MainWindow::on_homebutton_21_clicked()
{
    homenaviagte();
}


void MainWindow::on_homebutton_19_clicked()
{
    homenaviagte();
}


void MainWindow::on_homebutton_22_clicked()
{
    homenaviagte();
}


void MainWindow::on_homebutton_23_clicked()
{
    homenaviagte();
}


void MainWindow::on_homebutton_24_clicked()
{
    if(manager==true){
        managerview();
    }
    else{
        homenaviagte();
    }
}


void MainWindow::on_homebutton_25_clicked()
{
    homenaviagte();
}


void MainWindow::on_homebutton_26_clicked()
{
    homenaviagte();
}


void MainWindow::on_homebutton_27_clicked()
{
    if(manager==true){
        managerview();
    }
    else{
        homenaviagte();}
}


void MainWindow::on_homebutton_28_clicked()
{
    homenaviagte();
}


void MainWindow::on_homebutton_29_clicked()
{
    homenaviagte();
}


void MainWindow::on_homebutton_30_clicked()
{
    teamview();
}


void MainWindow::on_homebutton_33_clicked()
{
    if(manager==true){
        managerview();
    }
    else{
    homenaviagte();
    }}


void MainWindow::managerview()
{
    ui->stackedWidget->setCurrentIndex(12);
}
void MainWindow::on_pushButton_47_clicked()
{
    homenaviagte();
}


void MainWindow::on_pushButton_48_clicked()
{
    homenaviagte();
}


void MainWindow::on_pushButton_49_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);

}


void MainWindow::on_pushButton_50_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}


void MainWindow::on_pushButton_51_clicked()
{
      ui->stackedWidget->setCurrentIndex(10);
}

void MainWindow::on_pushButton_29_clicked()
{
     ui->stackedWidget->setCurrentIndex(3);
}


void MainWindow::on_pushButton_11_clicked()
{

    // QSqlQuery qry;

    // qry.prepare("INSERT INTO emp (id, name) VALUES (:EmployeeID, :Fname)");
    // qry.bindValue(":EmployeeID","3");
    // qry.bindValue(":Fname","Fname");


    // if(qry.exec()){
    //     QMessageBox::information(this,"insertion","Successful");
    // }
    // else{
    //     QMessageBox::information(this,"insertion","unsuccessful"/*+ QString(qry.lastError().text())*/);
    // }



    db.open();

    if (db.open())
    {
        QMessageBox::information(this,"insertion","DB is Open");
        QString Fname=ui->firstname->text();
        QString Lname=ui->lastname->text();
        QString Sex=ui->gender->text();
        QString email=ui->email->text();
        QString teamID=ui->teamid->text();
        QString Address=ui->address->text();
        QString teamtitle=ui->teamtitle->text();
        QString empdepat=ui->departname->text();
        QString employeeID=ui->empid->text();
        QString empsalary=ui->salaryemp->text();
        QString Supervisor_ID=ui->superid->text();
        QString empstatus=ui->statusemp->text();



        QSqlQuery empqry,;
        empqry.prepare("INSERT INTO employee(EmployeeID,Fname,Lname,Address,Sex,email) "
                    "VALUES (:emid, :fnam,:lnam,:add,:se,:emai)");

//these are binding values


//        qry.prepare("INSERT INTO emp(EmployeeID,Fname) VALUES(:EmployeeID,:Fname)");
        empqry.bindValue(":emid",employeeID);
        empqry.bindValue(":fnam",Fname);
        empqry.bindValue(":lnam",Lname);
        empqry.bindValue(":add",Address);
        empqry.bindValue(":se",Sex);
        empqry.bindValue(":emai",email);






        if(qry.exec()){
            QMessageBox::information(this,"insertion","Successful");
        }
        else{
          QMessageBox::information(this,"insertion","unsuccessful");
        }


    }
    else
    {
        QMessageBox::critical(this, "Connection", "Failed to connect to the database: " );

    }

}

