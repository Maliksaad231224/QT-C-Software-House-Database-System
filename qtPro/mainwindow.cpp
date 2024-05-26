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
bool manager=false;
QString empjoin="select e.EmployeeID,e.Fname,e.Lname,e.Birth_date,e.Address,e.Sex,e.email,e.Status,e.Job_Title,e.department,s.salary,t.teamname,es.supervisorname from employee as e inner join emp_team as t on e.EmployeeID=t.emp_id inner join employee_supervisors as es on e.EmployeeID=es.employeeid inner join salary as s on es.employeeid=s.employeeID;";
QString projteam="SELECT t.TeamID,t.Title AS Team_Title,t.Description AS Team_Description,p.Title AS Working_On_Project,t.Team_Lead,Members,p.start_date,p.deadline,p.Project_Cost,p.status,p.Last_Updated FROM project as p JOIN works_on as w ON p.Proj_ID = w.Project_Proj_ID JOIN team as t ON w.Team_TeamID = t.TeamID order by TeamID ;";
QString projclient="SELECT p.Proj_ID, p.Title AS Project_Title, p.start_date,p.deadline, p.status,p.Project_Cost,c.Client_ID,c.Name AS Client_Name,c.billing_address,c.contact_info FROM project_client as pc JOIN project as p ON pc.Project_Proj_ID = p.Proj_ID JOIN client as c ON pc.Client_Client_ID = c.Client_ID order by p.Proj_ID asc;";
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
ui->loginpassword->setEchoMode(QLineEdit::Password);
    ui->loginuser->setAlignment(Qt::AlignCenter);
    ui->loginpassword->setAlignment(Qt::AlignCenter);
    connect(ui->pushButton_80, &QPushButton::clicked, this, &MainWindow::on_pushButton_80_clicked);
    connect(ui->pushButton_13, &QPushButton::clicked, this, &MainWindow::on_pushButton_13_clicked);

    connect(ui->Projclear, &QPushButton::clicked, this, &MainWindow::on_Projclear_clicked);
connect(ui->pushButton_80, &QPushButton::clicked, this, &MainWindow::on_pushButton_80_clicked);
connect(ui->searchresetemp, &QPushButton::clicked, this, &MainWindow:: on_searchresetemp_clicked);

connect(ui->searchdepbutton, &QPushButton::clicked, this, &MainWindow:: on_searchdepbutton_clicked);
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


//active employee
            if (db.open()) {
                QSqlQuery query(db);
                query.prepare("SELECT count(EmployeeID) FROM employee Where Status='Active';");
                query.exec();
                if (query.next()) {
                    int count = query.value(0).toInt();
                    ui->noactiveemp->setNum(count);
                    ui->mangactiveep->setNum(count);
                }
//deadlines
                QSqlQuery quer(db);
                quer.prepare("SELECT COUNT(deadline) FROM project WHERE deadline > CURDATE();");
                quer.exec();

                    int count = quer.size();
                    ui->deadline->setNum(count);
                    ui->mdeadline->setNum(count);

           //total teams
                QSqlQuery que(db);
                que.prepare("SELECT COUNT(TeamID) FROM team ;");
                que.exec();
                if (que.next()) {
                    int count = que.value(0).toInt();
                    ui->managdevteam->setNum(count);

                }
                //inactive employees
                QSqlQuery qu(db);
                qu.prepare("SELECT count(EmployeeID) FROM employee Where Status='Inactive';");
                qu.exec();
                if (qu.next()) {
                    int count = qu.value(0).toInt();
                    ui->inactiveemp->setNum(count);

                }


                //complete
                QSqlQuery q(db);
                q.prepare("SELECT count(Proj_ID) from project where status='Complete';");
                q.exec();
                if (q.next()) {
                    int count = q.value(0).toInt();
                    ui->projectcomplete->setNum(count);
                    ui->mprojcomplete->setNum(count);

                }


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



   /*

        QSqlQueryModel *model = new QSqlQueryModel;

        model->setQuery(projclient);

            ui->projectviewtable->setModel(model);
            ui->projectviewtable->setVisible(true);

            // Resize columns to fit contents
            for (int column = 0; column < model->columnCount(); column++)
            {
                ui->projectviewtable->resizeColumnToContents(column);
            }

*/
void MainWindow::empviewtable(){
    if( db.open())
    {
         QSqlQueryModel  *model = new  QSqlQueryModel;
        model->setQuery(empjoin);
        ui->employeeviewtable->setEditTriggers(QAbstractItemView::NoEditTriggers);

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
     employeeview();
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
    departviewtable();

}


void MainWindow::teamviewtable()
{
    if (db.open()) {
        QSqlQueryModel *model = new QSqlQueryModel;

        model->setQuery(projteam);

        ui->teaamviewtable->setModel(model);
        ui->teaamviewtable->setVisible(true);


        // Resize columns to fit contents
        for (int column = 0; column < model->columnCount(); column++)
        {
            ui->teaamviewtable->resizeColumnToContents(column);
        }


    } else {
        // Handle database connection error
        qDebug() << "Error opening database:";
    }

}

void MainWindow::on_pushButton_10_clicked()///////////
{
       ui->stackedWidget->setCurrentIndex(11);
teamviewtable();


}


void MainWindow::on_pushButton_8_clicked()
{
     ui->stackedWidget->setCurrentIndex(10);
    projectviewtable();


}

void MainWindow::projectviewtable(){///////////////

    if (db.open()) {
        QSqlQueryModel *model = new QSqlQueryModel;

        model->setQuery(projclient);

            ui->projectviewtable->setModel(model);
            ui->projectviewtable->setVisible(true);

            // Resize columns to fit contents
            for (int column = 0; column < model->columnCount(); column++)
            {
                ui->projectviewtable->resizeColumnToContents(column);
            }


    } else {
        // Handle database connection error
        qDebug() << "Error opening database:";
    }

}

void MainWindow::on_pushButton_19_clicked()
{
    manager=true;
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


void MainWindow::on_pushButton_20_clicked()
{
    manager=true;
    ui->stackedWidget->setCurrentIndex(16);


    if( db.open())
    {
        QSqlTableModel *model = new QSqlTableModel;
        model->setTable("project");
        ui->searchprojecttable->setEditTriggers(QAbstractItemView::NoEditTriggers);
        model->select();
        ui->searchprojecttable->setModel(model);
        ui->searchprojecttable->setVisible(true);
        for (int column = 0; column < model->columnCount(); column++) {
            ui->searchprojecttable->resizeColumnToContents(column);
        }

    }
    else {
        // Handle query execution error
        qDebug() << "Error executing query:";
    }


}


void MainWindow::on_pushButton_21_clicked()
{
    manager=true;
    ui->stackedWidget->setCurrentIndex(19);



    if( db.open())
    {
        QSqlTableModel *model = new QSqlTableModel;
        model->setTable("department");

        model->select();
        ui->searchdepartmenttableview->setModel(model);
        ui->searchdepartmenttableview->setVisible(true);
        for (int column = 0; column < model->columnCount(); column++) {
            ui->searchdepartmenttableview->resizeColumnToContents(column);
        }

        ui->searchdepartmenttableview->setEditTriggers(QAbstractItemView::NoEditTriggers);

        QHeaderView *horizontalHeader = ui->searchdepartmenttableview->horizontalHeader();
        horizontalHeader->setSectionResizeMode(QHeaderView::Stretch);
    }
    else {
        // Handle query execution error
        qDebug() << "Error executing query:";
    }


}


void MainWindow::on_pushButton_22_clicked()
{
    ui->stackedWidget->setCurrentIndex(23);
    manager=true;


    if( db.open())
    {
        QSqlTableModel *model = new QSqlTableModel;
        model->setTable("team");
        ui->searchteamtable->setEditTriggers(QAbstractItemView::NoEditTriggers);
        model->select();
        ui->searchteamtable->setModel(model);
        ui->searchteamtable->setVisible(true);
        for (int column = 0; column < model->columnCount(); column++) {
            ui->searchteamtable->resizeColumnToContents(column);
        }



        ui->searchteamtable->horizontalHeader()->setStretchLastSection(true);

    }
    else {
        // Handle query execution error
        qDebug() << "Error executing query:";
    }

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

    departviewtable();

}


void MainWindow::on_pushButton_15_clicked()
{
     ui->stackedWidget->setCurrentIndex(18);


     if( db.open())
     {
         QSqlTableModel *model = new QSqlTableModel;
         model->setTable("department");

         model->select();
         ui->departmentupdate->setModel(model);
         ui->departmentupdate->setVisible(true);
         for (int column = 0; column < model->columnCount(); column++) {
             ui->departmentupdate->resizeColumnToContents(column);
         }



         QHeaderView *horizontalHeader = ui->departmentupdate->horizontalHeader();
         horizontalHeader->setSectionResizeMode(QHeaderView::Stretch);
     }
     else {
         // Handle query execution error
         qDebug() << "Error executing query:";
     }



}


void MainWindow::on_pushButton_12_clicked()
{
     ui->stackedWidget->setCurrentIndex(19);




     if( db.open())
     {
         QSqlTableModel *model = new QSqlTableModel;
         model->setTable("department");

         model->select();
         ui->searchdepartmenttableview->setModel(model);
         ui->searchdepartmenttableview->setVisible(true);
         for (int column = 0; column < model->columnCount(); column++) {
             ui->searchdepartmenttableview->resizeColumnToContents(column);
         }

       ui->searchdepartmenttableview->setEditTriggers(QAbstractItemView::NoEditTriggers);

         QHeaderView *horizontalHeader = ui->searchdepartmenttableview->horizontalHeader();
         horizontalHeader->setSectionResizeMode(QHeaderView::Stretch);
     }
     else {
         // Handle query execution error
         qDebug() << "Error executing query:";
     }


}


void MainWindow::on_pushButton_16_clicked()
{
     ui->stackedWidget->setCurrentIndex(13);
}


/*
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

*/
void MainWindow::on_pushButton_23_clicked()
{
     ui->stackedWidget->setCurrentIndex(14);

    if( db.open())
    {
        QSqlTableModel *model = new QSqlTableModel;
        model->setTable("project");

        model->select();
        ui->updatetableproject->setModel(model);
        ui->updatetableproject->setVisible(true);
        for (int column = 0; column < model->columnCount(); column++) {
            ui->updatetableproject->resizeColumnToContents(column);
        }

    }



}


void MainWindow::on_pushButton_18_clicked()
{
     ui->stackedWidget->setCurrentIndex(15);
    if( db.open())
    {
        QSqlTableModel *model = new QSqlTableModel;
        model->setTable("project");
        ui->removeproject->setEditTriggers(QAbstractItemView::NoEditTriggers);
        model->select();
        ui->removeproject->setModel(model);
        ui->removeproject->setVisible(true);
        for (int column = 0; column < model->columnCount(); column++) {
            ui->removeproject->resizeColumnToContents(column);
        }



    }
    else {
        // Handle query execution error
        qDebug() << "Error executing query:";
    }


}


void MainWindow::on_pushButton_17_clicked()
{
      ui->stackedWidget->setCurrentIndex(16);

    if( db.open())
    {
        QSqlTableModel *model = new QSqlTableModel;
        model->setTable("project");
        ui->searchprojecttable->setEditTriggers(QAbstractItemView::NoEditTriggers);
        model->select();
        ui->searchprojecttable->setModel(model);
        ui->searchprojecttable->setVisible(true);
        for (int column = 0; column < model->columnCount(); column++) {
            ui->searchprojecttable->resizeColumnToContents(column);
        }




    }
    else {
        // Handle query execution error
        qDebug() << "Error executing query:";
    }



}


/*
        QSqlTableModel *model = new QSqlTableModel;
        model->setTable("team");
        ui->searchteamtable->setEditTriggers(QAbstractItemView::NoEditTriggers);
        model->select();
        ui->searchteamtable->setModel(model);
        ui->searchteamtable->setVisible(true);
        for (int column = 0; column < model->columnCount(); column++) {
            ui->searchteamtable->resizeColumnToContents(column);
        }



        ui->searchteamtable->horizontalHeader()->setStretchLastSection(true);

*/
void MainWindow::on_pushButton_28_clicked()
{
      ui->stackedWidget->setCurrentIndex(21);

    if( db.open())
    {
        QSqlTableModel *model = new QSqlTableModel;
        model->setTable("team");
        model->select();
        ui->updateamview->setModel(model);
        ui->updateamview->setVisible(true);

        for (int column = 0; column < model->columnCount(); column++) {
            ui->updateamview->resizeColumnToContents(column);
        }

         ui->updateamview->horizontalHeader()->setStretchLastSection(true);


 }
    else {
        // Handle query execution error
        qDebug() << "Error executing query:";
    }


}


void MainWindow::on_pushButton_27_clicked()
{
    if( db.open())
    {
        QSqlTableModel *model = new QSqlTableModel;
        model->setTable("project");
        model->select();
        ui->updatetableproject->setModel(model);
        ui->updatetableproject->setVisible(true);
        for (int column = 0; column < model->columnCount(); column++) {
            ui->updatetableproject->resizeColumnToContents(column);
        }
    }
    else {
        // Handle query execution error
        qDebug() << "Error executing query:";
    }



}


void MainWindow::on_pushButton_25_clicked()
{
      ui->stackedWidget->setCurrentIndex(23);

    if( db.open())
    {
        QSqlTableModel *model = new QSqlTableModel;
        model->setTable("team");
        ui->searchteamtable->setEditTriggers(QAbstractItemView::NoEditTriggers);
        model->select();
        ui->searchteamtable->setModel(model);
        ui->searchteamtable->setVisible(true);
        for (int column = 0; column < model->columnCount(); column++) {
            ui->searchteamtable->resizeColumnToContents(column);
        }



        ui->searchteamtable->horizontalHeader()->setStretchLastSection(true);

    }
    else {
        // Handle query execution error
        qDebug() << "Error executing query:";
    }



}


void MainWindow::on_pushButton_32_clicked()
{
     projectview();

    projectviewtable();

}


void MainWindow::on_pushButton_31_clicked()
{
     teamview();
teamviewtable();


}


void MainWindow::on_pushButton_33_clicked()
{
     projectview();
    projectviewtable();

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
    empviewtable();

}


void MainWindow::on_pushButton_40_clicked()
{

    teamview();
    teamviewtable();
}


void MainWindow::on_pushButton_41_clicked()
{
    departmentview();
    departviewtable();
}


void MainWindow::on_pushButton_42_clicked()
{
    teamview();
    teamviewtable();
}


void MainWindow::on_pushButton_43_clicked()
{
    employeeview();
    empviewtable();
}


void MainWindow::on_pushButton_44_clicked()
{
    employeeview();
    empviewtable();
}


void MainWindow::on_pushButton_45_clicked()
{
    departmentview();
    departviewtable();
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
    projectviewtable();

}

void MainWindow::on_pushButton_29_clicked()
{

    if(manager==true){
        ui->stackedWidget->setCurrentIndex(12);
    }else{
     ui->stackedWidget->setCurrentIndex(3);
    }
}


void MainWindow::on_pushButton_11_clicked()
{

    db.open();

    if (db.open())
    {
        QSqlQuery empqry,empteamqry,salqry;
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


        salqry.prepare("INSERT INTO salary(employeeID, salary)"
                       "VALUES(:empid, :sal)");
        salqry.bindValue(":empid", ui->empid->text());
        salqry.bindValue(":sal", ui->salary->text());

        if(empqry.exec()&&empteamqry.exec()&&empsup.exec()&&salqry.exec()){
            QMessageBox::information(this,"insertion","Successful");
        }
        else{
          QMessageBox::information(this,"insertion","Primary Key Already Exists");
        }



    }
    else
    {
        QMessageBox::critical(this, "Connection", "Failed to connect to the database: " );

    }

}


void MainWindow:: departviewtable()
{

    if( db.open())
    {
        QSqlTableModel *model = new QSqlTableModel;
        model->setTable("department");
        ui->departmentViewTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
        model->select();
        ui->departmentViewTable->setModel(model);
        ui->departmentViewTable->setVisible(true);
        for (int column = 0; column < model->columnCount(); column++) {
            ui->departmentViewTable->resizeColumnToContents(column);
        }



        QHeaderView *horizontalHeader = ui->departmentViewTable->horizontalHeader();
        horizontalHeader->setSectionResizeMode(QHeaderView::Stretch);
    }
    else {
        // Handle query execution error
        qDebug() << "Error executing query:";
    }


}
void MainWindow::on_pushButton_13_clicked()
{

    ui->firstname->clear();

   ui->lastname->clear();
   ui->gender->clear();
   ui->email->clear();

  ui->address->clear();


   ui->empid->clear();
   ui->statusemp->clear();


}




void MainWindow::on_ProjSubmit_clicked()
{


    if (db.open())
    {

        QSqlQuery proqry,client,add;
        proqry.prepare("INSERT INTO project(Proj_ID,Title,start_date,deadline,Project_Cost) "
                       "VALUES (:projid,:title,:sdate,:ddate,:procost)");

        proqry.bindValue(":projid",ui->projID->toPlainText());
        proqry.bindValue(":title",ui->projtitle->toPlainText());
        proqry.bindValue(":sdate",ui->projsdate->date());
        proqry.bindValue(":ddate",ui->projdelievery->date());
        proqry.bindValue(":procost",ui->projcost->toPlainText());

        add.prepare("UPDATE project SET status = 'Inomplete' WHERE Proj_ID =:p");
        add.bindValue(":p", ui->projID->toPlainText());

        client.prepare("INSERT INTO client(Client_ID,Name,billing_address,contact_info) "
                       "VALUES (:clientid,:name,:bill,:coninfo)");
        //these are binding values

        client.bindValue(":clientid",ui->clientid->toPlainText());
        client.bindValue(":name",ui->clientname->toPlainText());
        client.bindValue(":bill",ui->clientaddress->toPlainText());
        client.bindValue(":coninfo",ui->clientinfo->toPlainText());


        if(proqry.exec()&&client.exec()&&add.exec()){
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



void MainWindow::on_pushButton_52_clicked()
{
    employeeview();
    empviewtable();
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








void MainWindow::on_pushButton_55_clicked()
{
    if (!db.open()) {
        QMessageBox::critical(this, "Database Error", "Failed to open the database.");
        return;
    }

    QString did = ui->searchupdatedept->text().trimmed();

    if (did.isEmpty()) {
        QMessageBox::warning(this, "Input Error", "Please enter an employee ID.");
        return;
    }

    QSqlTableModel *filteredModel = new QSqlTableModel(this, db);
    filteredModel->setTable("department");
    filteredModel->setFilter(QString("LOWER(Dpt_no) = LOWER('%1')").arg(did));
    filteredModel->select();



    // Debugging output
    qDebug() << "Filter applied: " << filteredModel->filter();
    qDebug() << "Number of rows: " << filteredModel->rowCount();

    if (filteredModel->rowCount() == 0) {
        QMessageBox::information(this, "No Results", "No employee found with the given ID.");
    }

    ui->departmentupdate->setModel(filteredModel);
}


void MainWindow::on_pushButton_56_clicked()
{
    if( db.open())
    {
        QSqlTableModel *model = new QSqlTableModel;
        model->setTable("department");


        model->select();
        ui->departmentupdate->setModel(model);
        ui->departmentupdate->setVisible(true);
        for (int column = 0; column < model->columnCount(); column++) {
            ui->departmentupdate->resizeColumnToContents(column);
        }
    }
    else {
        // Handle query execution error
        qDebug() << "Error executing query:";
    }

}


void MainWindow::on_searchdepbutton_clicked()
{
    if (!db.open()) {
        QMessageBox::critical(this, "Database Error", "Failed to open the database.");
        return;
    }

    QString did = ui->displaydeptid->toPlainText().trimmed();

    if (did.isEmpty()) {
        QMessageBox::warning(this, "Input Error", "Please enter an employee ID.");
        return;
    }

    QSqlTableModel *filteredModel = new QSqlTableModel(this, db);
    filteredModel->setTable("department");
    filteredModel->setFilter(QString("LOWER(Dpt_no) = LOWER('%1')").arg(did));
    filteredModel->select();


    // Debugging output
    qDebug() << "Filter applied: " << filteredModel->filter();
    qDebug() << "Number of rows: " << filteredModel->rowCount();

    if (filteredModel->rowCount() == 0) {
        QMessageBox::information(this, "No Results", "No employee found with the given ID.");
    }

    ui->searchdepartmenttableview->setModel(filteredModel);
}


void MainWindow::on_pushButton_57_clicked()
{

    if( db.open())
    {
        QSqlTableModel *model = new QSqlTableModel;
        model->setTable("department");

        model->select();
        ui->searchdepartmenttableview->setModel(model);
        ui->searchdepartmenttableview->setVisible(true);
        for (int column = 0; column < model->columnCount(); column++) {
            ui->searchdepartmenttableview->resizeColumnToContents(column);
        }

        ui->searchdepartmenttableview->setEditTriggers(QAbstractItemView::NoEditTriggers);
    }
    else {
        // Handle query execution error
        qDebug() << "Error executing query:";
    }

}


void MainWindow::on_pushButton_34_clicked()
{
    if (!db.open()) {
        QMessageBox::critical(this, "Database Error", "Failed to open the database.");
        return;
    }

    QString id = ui->upprojid->toPlainText().trimmed();

    if (id.isEmpty()) {
        QMessageBox::warning(this, "Input Error", "Please enter an employee ID.");
        return;
    }

    QSqlTableModel *filteredModel = new QSqlTableModel(this, db);
    filteredModel->setTable("project");
    filteredModel->setFilter(QString("LOWER(Proj_ID) = LOWER('%1')").arg(id));
    filteredModel->select();



    // Debugging output
    qDebug() << "Filter applied: " << filteredModel->filter();
    qDebug() << "Number of rows: " << filteredModel->rowCount();

    if (filteredModel->rowCount() == 0) {
        QMessageBox::information(this, "No Results", "No employee found with the given ID.");
    }

    ui->updatetableproject->setModel(filteredModel);

}


void MainWindow::on_pushButton_36_clicked()
{
    if (!db.open()) {
        QMessageBox::critical(this, "Database Error", "Failed to open the database.");
        return;
    }

    QString id = ui->removeprojidsearch->toPlainText().trimmed();

    if (id.isEmpty()) {
        QMessageBox::warning(this, "Input Error", "Please enter an employee ID.");
        return;
    }

    QSqlTableModel *filteredModel = new QSqlTableModel(this, db);
    filteredModel->setTable("project");
    filteredModel->setFilter(QString("LOWER(Proj_ID) = LOWER('%1')").arg(id));
    filteredModel->select();
        ui->removeproject->setEditTriggers(QAbstractItemView::NoEditTriggers);
    for (int column = 0; column < filteredModel->columnCount(); column++) {
        ui->removeproject->resizeColumnToContents(column);
    }

    // Debugging output
    qDebug() << "Filter applied: " << filteredModel->filter();
    qDebug() << "Number of rows: " << filteredModel->rowCount();

    if (filteredModel->rowCount() == 0) {
        QMessageBox::information(this, "No Results", "No employee found with the given ID.");
    }

    ui->removeproject->setModel(filteredModel);

}


void MainWindow::on_pushButton_58_clicked()
{
    if( db.open())
    {
        QSqlTableModel *model = new QSqlTableModel;
        model->setTable("project");
        model->select();
        ui->removeproject->setModel(model);
        ui->removeproject->setVisible(true);
        for (int column = 0; column < model->columnCount(); column++) {
            ui->removeproject->resizeColumnToContents(column);
        }
    }
    else {
        // Handle query execution error
        qDebug() << "Error executing query:";
    }

}


void MainWindow::on_pushButton_35_clicked()
{
    if(db.open())
    {
        QString projectid = ui->removeprojidsearch->toPlainText();

        // Update the employee's status in the database
        QSqlQuery query;
        query.prepare("UPDATE project SET status = 'Complete' WHERE Proj_ID = :id");
        query.bindValue(":id", projectid);

        if(query.exec()){
            QMessageBox::information(this,"Project Status","Project has been Completed successfully");
        }

    }
}


void MainWindow::on_pushButton_38_clicked()
{
    if (!db.open()) {
        QMessageBox::critical(this, "Database Error", "Failed to open the database.");
        return;
    }

    QString id = ui->projectid->toPlainText().trimmed();

    if (id.isEmpty()) {
        QMessageBox::warning(this, "Input Error", "Please enter an employee ID.");
        return;
    }

    QSqlTableModel *filteredModel = new QSqlTableModel(this, db);
    filteredModel->setTable("project");
    filteredModel->setFilter(QString("LOWER(Proj_ID) = LOWER('%1')").arg(id));
    filteredModel->select();
    ui->removeproject->setEditTriggers(QAbstractItemView::NoEditTriggers);
    for (int column = 0; column < filteredModel->columnCount(); column++) {
        ui->searchprojecttable->resizeColumnToContents(column);
    }

    // Debugging output
    qDebug() << "Filter applied: " << filteredModel->filter();
    qDebug() << "Number of rows: " << filteredModel->rowCount();

    if (filteredModel->rowCount() == 0) {
        QMessageBox::information(this, "No Results", "No employee found with the given ID.");
    }

    ui->searchprojecttable->setModel(filteredModel);

}


void MainWindow::on_pushButton_59_clicked()
{

    if( db.open())
    {
        QSqlTableModel *model = new QSqlTableModel;
        model->setTable("project");
        model->select();
        ui->searchprojecttable->setModel(model);
        ui->searchprojecttable->setVisible(true);
        for (int column = 0; column < model->columnCount(); column++) {
            ui->searchprojecttable->resizeColumnToContents(column);
        }
    }
    else {
        // Handle query execution error
        qDebug() << "Error executing query:";
    }


}


void MainWindow::on_updteamdisplay_clicked()
{
    if (!db.open()) {
        QMessageBox::critical(this, "Database Error", "Failed to open the database.");
        return;
    }

    QString id = ui->updateteamid->toPlainText().trimmed();

    if (id.isEmpty()) {
        QMessageBox::warning(this, "Input Error", "Please enter an employee ID.");
        return;
    }

    QSqlTableModel *filteredModel = new QSqlTableModel(this, db);
    filteredModel->setTable("team");
    filteredModel->setFilter(QString("LOWER(TeamID) = LOWER('%1')").arg(id));
    filteredModel->select();


    // Debugging output
    qDebug() << "Filter applied: " << filteredModel->filter();
    qDebug() << "Number of rows: " << filteredModel->rowCount();

    if (filteredModel->rowCount() == 0) {
        QMessageBox::information(this, "No Results", "No employee found with the given ID.");
    }

    ui->updateamview->setModel(filteredModel);
     for (int column = 0; column < filteredModel->columnCount(); column++) {
         ui->updateamview->resizeColumnToContents(column);
     }

     ui->updateamview->horizontalHeader()->setStretchLastSection(true);
}


void MainWindow::on_pushButton_26_clicked()
{

    if( db.open())
    {
        QSqlTableModel *model = new QSqlTableModel;
        model->setTable("team");
        model->select();
        ui->updateamview->setModel(model);
        ui->updateamview->setVisible(true);
        for (int column = 0; column < model->columnCount(); column++) {
            ui->updateamview->resizeColumnToContents(column);
        }

        ui->updateamview->horizontalHeader()->setStretchLastSection(true);    }
    else {
        // Handle query execution error
        qDebug() << "Error executing query:";
    }

}


void MainWindow::on_searchteambut_clicked()
{
    if (!db.open()) {
        QMessageBox::critical(this, "Database Error", "Failed to open the database.");
        return;
    }

    QString id = ui->searchteam->toPlainText().trimmed();

    if (id.isEmpty()) {
        QMessageBox::warning(this, "Input Error", "Please enter an employee ID.");
        return;
    }

    QSqlTableModel *filteredModel = new QSqlTableModel(this, db);
    filteredModel->setTable("team");
    filteredModel->setFilter(QString("LOWER(TeamID) = LOWER('%1')").arg(id));
    filteredModel->select();


    // Debugging output
    qDebug() << "Filter applied: " << filteredModel->filter();
    qDebug() << "Number of rows: " << filteredModel->rowCount();

    if (filteredModel->rowCount() == 0) {
        QMessageBox::information(this, "No Results", "No employee found with the given ID.");
    }

    ui->searchteamtable->setModel(filteredModel);
    for (int column = 0; column < filteredModel->columnCount(); column++) {
        ui->searchteamtable->resizeColumnToContents(column);
    }

    ui->searchteamtable->horizontalHeader()->setStretchLastSection(true);

}


void MainWindow::on_pushButton_60_clicked()
{

    if( db.open())
    {
        QSqlTableModel *model = new QSqlTableModel;
        model->setTable("team");
        model->select();
        ui->searchteamtable->setModel(model);
        ui->searchteamtable->setVisible(true);
        for (int column = 0; column < model->columnCount(); column++) {
            ui->searchteamtable->resizeColumnToContents(column);
        }

        ui->searchteamtable->horizontalHeader()->setStretchLastSection(true);    }
    else {
        // Handle query execution error
        qDebug() << "Error executing query:";
    }

}


void MainWindow::on_pushButton_61_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}


void MainWindow::on_pushButton_63_clicked()
{
    if (!db.open()) {
        QMessageBox::critical(this, "Database Error", "Failed to open the database.");
        return;
    }



    QString id = ui->searupsal->text().trimmed();

    if (id.isEmpty()) {
        QMessageBox::warning(this, "Input Error", "Please enter an employee ID.");
        return;
    }
    //employeeteam
    QSqlTableModel *filteredModel = new QSqlTableModel(this, db);
    filteredModel->setTable("emp_team");
    filteredModel->setFilter(QString("LOWER(emp_id) = LOWER('%1')").arg(id));
    filteredModel->select();


    // Debugging output
    qDebug() << "Filter applied: " << filteredModel->filter();
    qDebug() << "Number of rows: " << filteredModel->rowCount();

    if (filteredModel->rowCount() == 0) {
        QMessageBox::information(this, "No Results", "No employee found with the given ID.");
    }

    ui->empteamtable->setModel(filteredModel);

    //employee salary
    QSqlTableModel *filter = new QSqlTableModel(this, db);
    filter->setTable("salary");
    filter->setFilter(QString("LOWER(employeeID) = LOWER('%1')").arg(id));
    filter->select();


    // Debugging output
    qDebug() << "Filter applied: " << filter->filter();
    qDebug() << "Number of rows: " << filter->rowCount();

    if (filter->rowCount() == 0) {
        QMessageBox::information(this, "No Results", "No employee found with the given ID.");
    }

    ui->empsalarytable->setModel(filter);



    ui->empsalarytable->horizontalHeader()->setStretchLastSection(true);

    //employee supervisor

    QSqlTableModel *filterd = new QSqlTableModel(this, db);
    filterd->setTable("employee_supervisors");
    filterd->setFilter(QString("LOWER(employeeid) = LOWER('%1')").arg(id));
    filterd->select();


    // Debugging output
    qDebug() << "Filter applied: " << filterd->filter();
    qDebug() << "Number of rows: " << filterd->rowCount();

    if (filterd->rowCount() == 0) {
        QMessageBox::information(this, "No Results", "No employee found with the given ID.");
    }

    ui->empsupertable->setModel(filterd);



}


void MainWindow::on_pushButton_62_clicked()
{
    ui->stackedWidget->setCurrentIndex(17);


    if( db.open())
    {

        //employeesalary
        QSqlTableModel *model = new QSqlTableModel;
        model->setTable("salary");

        model->select();
        ui->empsalarytable->setModel(model);
        ui->empsalarytable->setVisible(true);
        for (int column = 0; column < model->columnCount(); column++) {
            ui->empsalarytable->resizeColumnToContents(column);
        }


        QHeaderView *horizontalHeader = ui->empsalarytable->horizontalHeader();
        horizontalHeader->setSectionResizeMode(QHeaderView::Stretch);


        //employee team
        QSqlTableModel *modell = new QSqlTableModel;
        modell->setTable("emp_team");

        modell->select();
        ui->empteamtable->setModel(modell);
        ui->empteamtable->setVisible(true);
        for (int column = 0; column < modell->columnCount(); column++) {
            ui->empteamtable->resizeColumnToContents(column);
        }


        ///employee supervisor

        QSqlTableModel *modelll = new QSqlTableModel;
        modelll->setTable("employee_supervisors");

        modelll->select();
        ui->empsupertable->setModel(modelll);
        ui->empsupertable->setVisible(true);
        for (int column = 0; column < modelll->columnCount(); column++) {
            ui->empsupertable->resizeColumnToContents(column);
        }


    }
    else {
        // Handle query execution error
        qDebug() << "Error executing query:";
    }




}





void MainWindow::on_pushButton_64_clicked()
{

    if( db.open())
    {

        //employeesalary
        QSqlTableModel *model = new QSqlTableModel;
        model->setTable("salary");

        model->select();
        ui->empsalarytable->setModel(model);
        ui->empsalarytable->setVisible(true);
        for (int column = 0; column < model->columnCount(); column++) {
            ui->empsalarytable->resizeColumnToContents(column);
        }


        QHeaderView *horizontalHeader = ui->empsalarytable->horizontalHeader();
        horizontalHeader->setSectionResizeMode(QHeaderView::Stretch);


        //employee team
        QSqlTableModel *modell = new QSqlTableModel;
        modell->setTable("emp_team");

        modell->select();
        ui->empteamtable->setModel(modell);
        ui->empteamtable->setVisible(true);
        for (int column = 0; column < modell->columnCount(); column++) {
            ui->empteamtable->resizeColumnToContents(column);
        }


        ///employee supervisor

        QSqlTableModel *modelll = new QSqlTableModel;
        modelll->setTable("employee_supervisors");

        modelll->select();
        ui->empsupertable->setModel(modelll);
        ui->empsupertable->setVisible(true);
        for (int column = 0; column < modelll->columnCount(); column++) {
            ui->empsupertable->resizeColumnToContents(column);
        }


    }
    else {
        // Handle query execution error
        qDebug() << "Error executing query:";
    }




}


void MainWindow::on_Projclear_clicked()
{
    ui->projID->clear();
    ui->projtitle->clear();
    ui->projcost->clear();
    ui->clientname->clear();
    ui->clientid->clear();
    ui->clientaddress->clear();
    ui->clientinfo->clear();

}

