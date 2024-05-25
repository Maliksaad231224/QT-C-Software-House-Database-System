#include "mainwindow.h"
#include <QtWidgets>
#include <QLineEdit>
#include <QSqlTableModel>
#include <QTableView>
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
ui->loginpassword->setEchoMode(QLineEdit::Password);
    ui->loginuser->setAlignment(Qt::AlignCenter);
    ui->loginpassword->setAlignment(Qt::AlignCenter);
    connect(ui->pushButton_80, &QPushButton::clicked, this, &MainWindow::on_pushButton_80_clicked);
connect(ui->pushButton_80, &QPushButton::clicked, this, &MainWindow::on_pushButton_80_clicked);
connect(ui->searchresetemp, &QPushButton::clicked, this, &MainWindow:: on_searchresetemp_clicked);


        connect(ui->delempbut, &QPushButton::clicked, this, &MainWindow::on_delempbut_clicked);
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




    QString username = ui->loginuser->toPlainText();
    QString password = ui->loginpassword->text();
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

void MainWindow::on_pushButton_clicked()
{
     ui->stackedWidget->setCurrentIndex(6);

}


void MainWindow::on_pushButton_6_clicked()
{
 ui->stackedWidget->setCurrentIndex(4);
empviewtable();

}


void MainWindow::emprecords(){

    if( db.open())
    {
        QSqlTableModel *model = new QSqlTableModel;
        model->setTable("employee");

        model->select();
        ui->updemptable->setModel(model);
        ui->updemptable->setVisible(true);
        for (int column = 0; column < model->columnCount(); column++) {
            ui->updemptable->resizeColumnToContents(column);
        }
    }
    else {
        // Handle query execution error
        qDebug() << "Error executing query:";
    }

}
void MainWindow::on_pushButton_3_clicked()
{

    ui->stackedWidget->setCurrentIndex(7);

    if( db.open())
    {
        QSqlTableModel *model = new QSqlTableModel;
        model->setTable("employee");
        model->select();
        ui->updemptable->setModel(model);
        ui->updemptable->setVisible(true);
        for (int column = 0; column < model->columnCount(); column++) {
            ui->updemptable->resizeColumnToContents(column);
        }
    }
    else {
        // Handle query execution error
        qDebug() << "Error executing query:";
    }

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
    if( db.open())
    {
        QSqlTableModel *model = new QSqlTableModel;
        model->setTable("employee");
        ui->searchemptable->setEditTriggers(QAbstractItemView::NoEditTriggers);
        model->select();
        ui->searchemptable->setModel(model);
        ui->searchemptable->setVisible(true);
        for (int column = 0; column < model->columnCount(); column++) {
            ui->searchemptable->resizeColumnToContents(column);
        }
    }
    else {
        // Handle query execution error
        qDebug() << "Error executing query:";
    }

   }

void MainWindow::empviewtable(){
    if( db.open())
    {
        QSqlTableModel *model = new QSqlTableModel;
        model->setTable("employee");
        ui->employeeviewtable->setEditTriggers(QAbstractItemView::NoEditTriggers);
        model->select();
        ui->employeeviewtable->setModel(model);
        ui->employeeviewtable->setVisible(true);
        for (int column = 0; column < model->columnCount(); column++) {
            ui->employeeviewtable->resizeColumnToContents(column);
        }
    }
    else {
        // Handle query execution error
        qDebug() << "Error executing query:";
    }

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


/*void MainWindow::on_homebutton_24_clicked()
{
    if(manager==true){
        managerview();
    }
    else{
        homenaviagte();
    }
}
*/

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

    db.open();

    if (db.open())
    {
        QSqlQuery empqry,empteamqry;
     QSqlQuery empsup;
   empqry.prepare("INSERT INTO employee(EmployeeID,Fname,Lname,Address,Sex,email,Birth_date,Status,Job_Title,department) "
                    "VALUES (:emid, :fnam,:lnam,:add,:se,:emai,:bird,:status,:title,:dept)");

    empqry.bindValue(":bird",ui->DOB->date());
   empqry.bindValue(":emid",ui->empid->text());
    empqry.bindValue(":fnam",ui->firstname->text());
   empqry.bindValue(":lnam",ui->lastname->text());
    empqry.bindValue(":add",ui->address->text());
   empqry.bindValue(":se",ui->gender->currentText());
    empqry.bindValue(":emai",ui->email->text());
        empqry.bindValue(":status",ui->statusemp->text());
        empqry.bindValue(":title",ui->designation->currentText());
        empqry.bindValue(":dept",ui->insdept->currentText());

    empteamqry.prepare("INSERT INTO emp_team(emp_id,teamname)"
                           "VALUES(:empid,:teamtitle)");
        empteamqry.bindValue(":empid",ui->empid->text());
        empteamqry.bindValue(":teamtitle",ui->teamtitle->currentText());

    empsup.prepare("INSERT INTO employee_supervisors(employeeid,supervisorname)"
                       "VALUES(:emmid,:supname)");
        empsup.bindValue(":emmid",ui->empid->text());
        empsup.bindValue(":supname",ui->supername->text());


    empsup.prepare("INSERT INTO employee_supervisors(employeeid, supervisorname)"
                       "VALUES(:empid, :supname)");
        empsup.bindValue(":empid", ui->empid->text());
        empsup.bindValue(":supname", ui->supername->text());

        if(empqry.exec()&&empteamqry.exec()&&empsup.exec()){
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


void MainWindow::on_pushButton_13_clicked()
{
/*
    ui->firstname->clear();
    ui->teamid->clear();
   ui->teamtitle->clear();
   ui->lastname->clear();
   ui->gender->clear();
   ui->email->clear();
  ui->teamid->clear();
  ui->address->clear();
   ui->teamtitle->clear();
   ui->departname->clear();
   ui->empid->clear();
   ui->superid->clear();
    ui->statusemp->clear();
    ui->DOB-->clear();
    */
}


void MainWindow::on_ProjSubmit_clicked()
{

    db.open();

    if (db.open())
    {
        QMessageBox::information(this,"insertion","DB is Open");


        QSqlQuery proqry,client;
        proqry.prepare("INSERT INTO project(Proj_ID,Title,start_date,delivery_date,Project_Cost,Last_Updated) "
                       "VALUES (:projid,:title,:sdate,:ddate,:procost,:projupd)");

        proqry.bindValue(":projid",ui->projID->toPlainText());
        proqry.bindValue(":projtitle",ui->projtitle->toPlainText());
        proqry.bindValue(":sdate",ui->projsdate->date());
        proqry.bindValue(":ddate",ui->projdelievery->date());
        proqry.bindValue(":procost",ui->projcost->toPlainText());
        proqry.bindValue(":projupd",ui->projlastupd->date());

        client.prepare("INSERT INTO client(Client_ID,Name,billing_address,contact_info) "
                       "VALUES (:clientid,:name,:bill,:coninfo)");
        //these are binding values

        client.bindValue(":clientid",ui->clientid->toPlainText());
        client.bindValue(":name",ui->clientname->toPlainText());
        client.bindValue(":bill",ui->clientaddress->toPlainText());
        client.bindValue(":coninfo",ui->clientinfo->toPlainText());

        if(proqry.exec()&&client.exec()){
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


void MainWindow::on_pushButton_54_clicked()
{
    ui->stackedWidget->setCurrentIndex(17);
}



void MainWindow::on_pushButton_52_clicked()
{
    employeeview();
}


/*


    if( db.open())
    {
        QSqlTableModel *model = new QSqlTableModel;
        model->setTable("employee");

        model->select();
        ui->updemptable->setModel(model);
        ui->updemptable->setVisible(true);
        for (int column = 0; column < model->columnCount(); column++) {
            ui->updemptable->resizeColumnToContents(column);
        }
    }
    else {
        // Handle query execution error
        qDebug() << "Error executing query:";
    }
*/



void MainWindow::on_displayempup_clicked()
{
    if (!db.open()) {
        QMessageBox::critical(this, "Database Error", "Failed to open the database.");
        return;
    }

    QString id = ui->empidupdate->text().trimmed();

    if (id.isEmpty()) {
        QMessageBox::warning(this, "Input Error", "Please enter an employee ID.");
        return;
    }

    QSqlTableModel *filteredModel = new QSqlTableModel(this, db);
    filteredModel->setTable("employee");
    filteredModel->setFilter(QString("LOWER(EmployeeID) = LOWER('%1')").arg(id));
    filteredModel->select();



    // Debugging output
    qDebug() << "Filter applied: " << filteredModel->filter();
    qDebug() << "Number of rows: " << filteredModel->rowCount();

    if (filteredModel->rowCount() == 0) {
        QMessageBox::information(this, "No Results", "No employee found with the given ID.");
    }

    ui->updemptable->setModel(filteredModel);
}


void MainWindow::on_pushButton_7_clicked()
{
    emprecords();
}


void MainWindow::on_pushButton_39_clicked()
{
    if (!db.open()) {
        QMessageBox::critical(this, "Database Error", "Failed to open the database.");
        return;
    }

    QString id = ui->disemp->toPlainText().trimmed();

    if (id.isEmpty()) {
        QMessageBox::warning(this, "Input Error", "Please enter an employee ID.");
        return;
    }

    QSqlTableModel *filteredModel = new QSqlTableModel(this, db);
    filteredModel->setTable("employee");
    filteredModel->setFilter(QString("LOWER(EmployeeID) = LOWER('%1')").arg(id));
    filteredModel->select();



    // Debugging output
    qDebug() << "Filter applied: " << filteredModel->filter();
    qDebug() << "Number of rows: " << filteredModel->rowCount();

    if (filteredModel->rowCount() == 0) {
        QMessageBox::information(this, "No Results", "No employee found with the given ID.");
    }

    ui->searchemptable->setModel(filteredModel);
}



void MainWindow::on_searchresetemp_clicked()
{
    if( db.open())
    {
        QSqlTableModel *model = new QSqlTableModel;
        model->setTable("employee");
        ui->searchemptable->setEditTriggers(QAbstractItemView::NoEditTriggers);

        model->select();
        ui->searchemptable->setModel(model);
        ui->searchemptable->setVisible(true);
        for (int column = 0; column < model->columnCount(); column++) {
            ui->searchemptable->resizeColumnToContents(column);
        }
    }
    else {
        // Handle query execution error
        qDebug() << "Error executing query:";
    }

}


void MainWindow::on_pushButton_24_clicked()
{
    if (!db.open()) {
        QMessageBox::critical(this, "Database Error", "Failed to open the database.");
        return;
    }



    QString id = ui->searchempdelete->toPlainText().trimmed();

    if (id.isEmpty()) {
        QMessageBox::warning(this, "Input Error", "Please enter an employee ID.");
        return;
    }

    QSqlTableModel *filteredModel = new QSqlTableModel(this, db);
    filteredModel->setTable("employee");
    filteredModel->setFilter(QString("LOWER(EmployeeID) = LOWER('%1')").arg(id));
    filteredModel->select();
         ui->deletemptable->setEditTriggers(QAbstractItemView::NoEditTriggers);


    // Debugging output
    qDebug() << "Filter applied: " << filteredModel->filter();
    qDebug() << "Number of rows: " << filteredModel->rowCount();

    if (filteredModel->rowCount() == 0) {
        QMessageBox::information(this, "No Results", "No employee found with the given ID.");
    }

    ui->deletemptable->setModel(filteredModel);


}


void MainWindow::on_pushButton_4_clicked()
{


    ui->stackedWidget->setCurrentIndex(8);
    if( db.open())
    {
        QSqlTableModel *model = new QSqlTableModel;
        model->setTable("employee");
        ui->deletemptable->setEditTriggers(QAbstractItemView::NoEditTriggers);
        model->select();
        ui->deletemptable->setModel(model);
        ui->deletemptable->setVisible(true);
        for (int column = 0; column < model->columnCount(); column++) {
            ui->deletemptable->resizeColumnToContents(column);
        }
    }
    else {
        // Handle query execution error
        qDebug() << "Error executing query:";
    }

}


void MainWindow::on_delempbut_clicked()
{
    if(db.open())
    {
    QString employeeid = ui->searchempdelete->toPlainText();

    // Update the employee's status in the database
    QSqlQuery query;
    query.prepare("UPDATE employee SET Status = 'Inactive' WHERE EmployeeID = :id");
    query.bindValue(":id", employeeid);

    if(query.exec()){
        QMessageBox::information(this,"Employee Status","Employee has been Offboarded successfully");
    }

    }
}







