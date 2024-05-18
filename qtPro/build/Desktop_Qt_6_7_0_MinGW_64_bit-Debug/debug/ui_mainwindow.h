/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QStackedWidget *stackedWidget;
    QWidget *login;
    QLabel *label;
    QFrame *frame;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QTextEdit *textEdit;
    QLabel *label_5;
    QTextEdit *textEdit_2;
    QLabel *label_6;
    QPushButton *pushButton_2;
    QWidget *manager;
    QFrame *frame_2;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QPushButton *pushButton;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QLabel *label_10;
    QFrame *frame_3;
    QFrame *frame_4;
    QLabel *label_13;
    QLabel *label_16;
    QFrame *frame_5;
    QLabel *label_12;
    QLabel *label_15;
    QFrame *frame_6;
    QLabel *label_11;
    QLabel *label_14;
    QFrame *frame_7;
    QLabel *label_17;
    QLabel *label_18;
    QPushButton *pushButton_7;
    QLabel *label_35;
    QWidget *Department;
    QFrame *frame_8;
    QFrame *frame_9;
    QLabel *label_19;
    QLabel *label_20;
    QLabel *label_21;
    QLabel *label_22;
    QPushButton *pushButton_6;
    QPushButton *pushButton_9;
    QPushButton *pushButton_10;
    QTableWidget *tableWidget;
    QLabel *label_36;
    QWidget *project;
    QFrame *frame_10;
    QLabel *label_23;
    QLabel *label_24;
    QLabel *label_25;
    QLabel *label_26;
    QPushButton *pushButton_12;
    QPushButton *pushButton_13;
    QPushButton *pushButton_14;
    QFrame *frame_11;
    QTableWidget *tableWidget_2;
    QLabel *label_37;
    QWidget *teams;
    QFrame *frame_12;
    QLabel *label_27;
    QLabel *label_28;
    QLabel *label_29;
    QPushButton *pushButton_15;
    QLabel *label_30;
    QPushButton *pushButton_16;
    QPushButton *pushButton_17;
    QPushButton *pushButton_18;
    QFrame *frame_13;
    QLabel *label_38;
    QWidget *employee;
    QFrame *frame_14;
    QLabel *label_31;
    QLabel *label_32;
    QLabel *label_33;
    QLabel *label_34;
    QPushButton *pushButton_19;
    QPushButton *pushButton_20;
    QPushButton *pushButton_21;
    QPushButton *pushButton_22;
    QFrame *frame_15;
    QFrame *frame_16;
    QLabel *label_39;
    QLabel *label_40;
    QFrame *frame_18;
    QLabel *label_43;
    QLabel *label_44;
    QWidget *insertemp;
    QFrame *frame_19;
    QLabel *label_41;
    QLabel *label_42;
    QLabel *label_45;
    QLabel *label_46;
    QPushButton *pushButton_23;
    QPushButton *pushButton_24;
    QPushButton *pushButton_25;
    QPushButton *pushButton_26;
    QFrame *frame_17;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1056, 682);
        MainWindow->setStyleSheet(QString::fromUtf8(""));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName("stackedWidget");
        stackedWidget->setGeometry(QRect(0, 0, 1061, 681));
        stackedWidget->setStyleSheet(QString::fromUtf8("background-color:rgba(45,45,45,255);"));
        login = new QWidget();
        login->setObjectName("login");
        label = new QLabel(login);
        label->setObjectName("label");
        label->setGeometry(QRect(0, 0, 1061, 681));
        label->setPixmap(QPixmap(QString::fromUtf8(":/pics/picture/d.jpg")));
        label->setScaledContents(true);
        frame = new QFrame(login);
        frame->setObjectName("frame");
        frame->setGeometry(QRect(300, 70, 461, 541));
        frame->setStyleSheet(QString::fromUtf8("border-radius:22px;\n"
" background-color:rgba(87, 106, 177, 128);\n"
"opacity:0.5;"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        label_2 = new QLabel(frame);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(190, 30, 111, 81));
        label_2->setPixmap(QPixmap(QString::fromUtf8(":/pics/picture/person.png")));
        label_2->setScaledContents(true);
        label_3 = new QLabel(frame);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(190, 110, 121, 41));
        label_3->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"font: 700 16pt \"Tahoma\";"));
        label_4 = new QLabel(frame);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(120, 150, 241, 41));
        label_4->setStyleSheet(QString::fromUtf8("color:  white;\n"
"font: 11pt \"Tahoma\";"));
        textEdit = new QTextEdit(frame);
        textEdit->setObjectName("textEdit");
        textEdit->setGeometry(QRect(160, 230, 241, 31));
        textEdit->setStyleSheet(QString::fromUtf8("background-color: rgb(177, 177, 177);\n"
"border-radius: 12px;\n"
"font: 11pt \"Tahoma\";\n"
"color:white;"));
        label_5 = new QLabel(frame);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(60, 230, 91, 31));
        label_5->setStyleSheet(QString::fromUtf8("color:white;\n"
"font: 700 11pt \"Tahoma\";"));
        textEdit_2 = new QTextEdit(frame);
        textEdit_2->setObjectName("textEdit_2");
        textEdit_2->setGeometry(QRect(160, 290, 241, 31));
        textEdit_2->setStyleSheet(QString::fromUtf8("background-color: rgb(177, 177, 177);\n"
"border-radius: 12px;\n"
"font: 11pt \"Tahoma\";\n"
"color:white;"));
        label_6 = new QLabel(frame);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(60, 290, 91, 31));
        label_6->setStyleSheet(QString::fromUtf8("color:white;\n"
"font: 700 11pt \"Tahoma\";"));
        pushButton_2 = new QPushButton(frame);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(200, 360, 83, 29));
        pushButton_2->setStyleSheet(QString::fromUtf8("font: 12pt \"Tahoma\";\n"
"color:white;\n"
"background-color: rgb(0, 157, 255);\n"
" border: 1px solid #ccc;\n"
"    border-radius: 10px;"));
        stackedWidget->addWidget(login);
        manager = new QWidget();
        manager->setObjectName("manager");
        frame_2 = new QFrame(manager);
        frame_2->setObjectName("frame_2");
        frame_2->setGeometry(QRect(0, 0, 281, 681));
        frame_2->setStyleSheet(QString::fromUtf8("background-color:rgba(27,27,27,255);"));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        label_7 = new QLabel(frame_2);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(10, 10, 261, 151));
        label_7->setPixmap(QPixmap(QString::fromUtf8(":/pics/picture/people.png")));
        label_7->setScaledContents(true);
        label_8 = new QLabel(frame_2);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(40, 140, 211, 51));
        label_8->setStyleSheet(QString::fromUtf8("color: rgb(254, 251, 255);\n"
"font: 700 11pt \"Arial\";"));
        label_9 = new QLabel(frame_2);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(50, 180, 201, 21));
        label_9->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"font: italic 9pt \"Segoe UI\";"));
        pushButton = new QPushButton(frame_2);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(0, 240, 281, 61));
        pushButton->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"font: 11pt \"Arial\";"));
        pushButton_3 = new QPushButton(frame_2);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(0, 300, 281, 61));
        pushButton_3->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"font: 11pt \"Arial\";"));
        pushButton_4 = new QPushButton(frame_2);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setGeometry(QRect(0, 360, 281, 61));
        pushButton_4->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"font: 11pt \"Arial\";"));
        pushButton_5 = new QPushButton(frame_2);
        pushButton_5->setObjectName("pushButton_5");
        pushButton_5->setGeometry(QRect(0, 420, 281, 61));
        pushButton_5->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"font: 11pt \"Arial\";"));
        label_10 = new QLabel(frame_2);
        label_10->setObjectName("label_10");
        label_10->setGeometry(QRect(90, 640, 121, 31));
        label_10->setStyleSheet(QString::fromUtf8("color:white;"));
        frame_3 = new QFrame(manager);
        frame_3->setObjectName("frame_3");
        frame_3->setGeometry(QRect(280, 0, 781, 41));
        frame_3->setStyleSheet(QString::fromUtf8("background-color:rgba(27,27,27,255);"));
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        frame_4 = new QFrame(manager);
        frame_4->setObjectName("frame_4");
        frame_4->setGeometry(QRect(820, 120, 211, 181));
        frame_4->setStyleSheet(QString::fromUtf8("border-radius:12px;\n"
"background-color:rgba(58,162,238,255);"));
        frame_4->setFrameShape(QFrame::StyledPanel);
        frame_4->setFrameShadow(QFrame::Raised);
        label_13 = new QLabel(frame_4);
        label_13->setObjectName("label_13");
        label_13->setGeometry(QRect(10, 50, 201, 31));
        label_13->setStyleSheet(QString::fromUtf8("font: 12pt \"Arial\";\n"
"color:white;"));
        label_13->setScaledContents(true);
        label_13->setWordWrap(false);
        label_16 = new QLabel(frame_4);
        label_16->setObjectName("label_16");
        label_16->setGeometry(QRect(90, 90, 41, 41));
        label_16->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"font: 700 12pt \"Arial\";"));
        frame_5 = new QFrame(manager);
        frame_5->setObjectName("frame_5");
        frame_5->setGeometry(QRect(570, 120, 211, 181));
        frame_5->setStyleSheet(QString::fromUtf8("border-radius:12px;\n"
"background-color:rgba(210,82,88,255);"));
        frame_5->setFrameShape(QFrame::StyledPanel);
        frame_5->setFrameShadow(QFrame::Raised);
        label_12 = new QLabel(frame_5);
        label_12->setObjectName("label_12");
        label_12->setGeometry(QRect(30, 50, 171, 31));
        label_12->setStyleSheet(QString::fromUtf8("font: 12pt \"Arial\";\n"
"color:white;"));
        label_15 = new QLabel(frame_5);
        label_15->setObjectName("label_15");
        label_15->setGeometry(QRect(90, 90, 41, 41));
        label_15->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"font: 700 12pt \"Arial\";"));
        frame_6 = new QFrame(manager);
        frame_6->setObjectName("frame_6");
        frame_6->setGeometry(QRect(310, 120, 211, 181));
        frame_6->setStyleSheet(QString::fromUtf8("border-radius:12px;\n"
"background-color:rgba(0,133,104,255);"));
        frame_6->setFrameShape(QFrame::StyledPanel);
        frame_6->setFrameShadow(QFrame::Raised);
        label_11 = new QLabel(frame_6);
        label_11->setObjectName("label_11");
        label_11->setGeometry(QRect(30, 50, 151, 31));
        label_11->setStyleSheet(QString::fromUtf8("font: 12pt \"Arial\";\n"
"color:white;"));
        label_14 = new QLabel(frame_6);
        label_14->setObjectName("label_14");
        label_14->setGeometry(QRect(80, 90, 41, 41));
        label_14->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"font: 700 12pt \"Arial\";"));
        frame_7 = new QFrame(manager);
        frame_7->setObjectName("frame_7");
        frame_7->setGeometry(QRect(490, 360, 381, 181));
        frame_7->setStyleSheet(QString::fromUtf8("border-radius:12px;\n"
"background-color: rgb(134, 156, 170);"));
        frame_7->setFrameShape(QFrame::StyledPanel);
        frame_7->setFrameShadow(QFrame::Raised);
        label_17 = new QLabel(frame_7);
        label_17->setObjectName("label_17");
        label_17->setGeometry(QRect(90, 40, 231, 41));
        label_17->setStyleSheet(QString::fromUtf8("font: 12pt \"Arial\";\n"
"color:white;"));
        label_18 = new QLabel(frame_7);
        label_18->setObjectName("label_18");
        label_18->setGeometry(QRect(170, 80, 41, 41));
        label_18->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"font: 700 12pt \"Arial\";"));
        pushButton_7 = new QPushButton(manager);
        pushButton_7->setObjectName("pushButton_7");
        pushButton_7->setGeometry(QRect(920, 50, 111, 51));
        pushButton_7->setStyleSheet(QString::fromUtf8("color:white;\n"
"background-color: rgb(191, 18, 35);\n"
"font: 11pt \"Arial\";"));
        label_35 = new QLabel(manager);
        label_35->setObjectName("label_35");
        label_35->setGeometry(QRect(320, 50, 191, 20));
        label_35->setStyleSheet(QString::fromUtf8("color:white;"));
        stackedWidget->addWidget(manager);
        Department = new QWidget();
        Department->setObjectName("Department");
        frame_8 = new QFrame(Department);
        frame_8->setObjectName("frame_8");
        frame_8->setGeometry(QRect(280, 0, 781, 41));
        frame_8->setStyleSheet(QString::fromUtf8("background-color:rgba(27,27,27,255);"));
        frame_8->setFrameShape(QFrame::StyledPanel);
        frame_8->setFrameShadow(QFrame::Raised);
        frame_9 = new QFrame(Department);
        frame_9->setObjectName("frame_9");
        frame_9->setGeometry(QRect(0, 0, 281, 681));
        frame_9->setStyleSheet(QString::fromUtf8("background-color:rgba(27,27,27,255);"));
        frame_9->setFrameShape(QFrame::StyledPanel);
        frame_9->setFrameShadow(QFrame::Raised);
        label_19 = new QLabel(frame_9);
        label_19->setObjectName("label_19");
        label_19->setGeometry(QRect(10, 10, 261, 151));
        label_19->setPixmap(QPixmap(QString::fromUtf8(":/pics/picture/people.png")));
        label_19->setScaledContents(true);
        label_20 = new QLabel(frame_9);
        label_20->setObjectName("label_20");
        label_20->setGeometry(QRect(50, 140, 211, 51));
        label_20->setStyleSheet(QString::fromUtf8("color: rgb(254, 251, 255);\n"
"font: 700 11pt \"Arial\";"));
        label_21 = new QLabel(frame_9);
        label_21->setObjectName("label_21");
        label_21->setGeometry(QRect(50, 180, 201, 21));
        label_21->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"font: italic 9pt \"Segoe UI\";"));
        label_22 = new QLabel(frame_9);
        label_22->setObjectName("label_22");
        label_22->setGeometry(QRect(90, 640, 121, 31));
        label_22->setStyleSheet(QString::fromUtf8("color:white;"));
        pushButton_6 = new QPushButton(frame_9);
        pushButton_6->setObjectName("pushButton_6");
        pushButton_6->setGeometry(QRect(0, 370, 281, 61));
        pushButton_6->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"font: 11pt \"Arial\";"));
        pushButton_9 = new QPushButton(frame_9);
        pushButton_9->setObjectName("pushButton_9");
        pushButton_9->setGeometry(QRect(0, 250, 281, 61));
        pushButton_9->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"font: 11pt \"Arial\";"));
        pushButton_10 = new QPushButton(frame_9);
        pushButton_10->setObjectName("pushButton_10");
        pushButton_10->setGeometry(QRect(0, 310, 281, 61));
        pushButton_10->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"font: 11pt \"Arial\";"));
        tableWidget = new QTableWidget(Department);
        tableWidget->setObjectName("tableWidget");
        tableWidget->setGeometry(QRect(350, 160, 651, 441));
        label_36 = new QLabel(Department);
        label_36->setObjectName("label_36");
        label_36->setGeometry(QRect(320, 50, 191, 20));
        label_36->setStyleSheet(QString::fromUtf8("color:white;"));
        stackedWidget->addWidget(Department);
        project = new QWidget();
        project->setObjectName("project");
        frame_10 = new QFrame(project);
        frame_10->setObjectName("frame_10");
        frame_10->setGeometry(QRect(0, 0, 281, 681));
        frame_10->setStyleSheet(QString::fromUtf8("background-color:rgba(27,27,27,255);"));
        frame_10->setFrameShape(QFrame::StyledPanel);
        frame_10->setFrameShadow(QFrame::Raised);
        label_23 = new QLabel(frame_10);
        label_23->setObjectName("label_23");
        label_23->setGeometry(QRect(10, 10, 261, 151));
        label_23->setPixmap(QPixmap(QString::fromUtf8(":/pics/picture/people.png")));
        label_23->setScaledContents(true);
        label_24 = new QLabel(frame_10);
        label_24->setObjectName("label_24");
        label_24->setGeometry(QRect(50, 140, 211, 51));
        label_24->setStyleSheet(QString::fromUtf8("color: rgb(254, 251, 255);\n"
"font: 700 11pt \"Arial\";"));
        label_25 = new QLabel(frame_10);
        label_25->setObjectName("label_25");
        label_25->setGeometry(QRect(50, 180, 201, 21));
        label_25->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"font: italic 9pt \"Segoe UI\";"));
        label_26 = new QLabel(frame_10);
        label_26->setObjectName("label_26");
        label_26->setGeometry(QRect(90, 640, 121, 31));
        label_26->setStyleSheet(QString::fromUtf8("color:white;"));
        pushButton_12 = new QPushButton(frame_10);
        pushButton_12->setObjectName("pushButton_12");
        pushButton_12->setGeometry(QRect(0, 360, 281, 61));
        pushButton_12->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"font: 11pt \"Arial\";"));
        pushButton_13 = new QPushButton(frame_10);
        pushButton_13->setObjectName("pushButton_13");
        pushButton_13->setGeometry(QRect(0, 240, 281, 61));
        pushButton_13->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"font: 11pt \"Arial\";"));
        pushButton_14 = new QPushButton(frame_10);
        pushButton_14->setObjectName("pushButton_14");
        pushButton_14->setGeometry(QRect(0, 300, 281, 61));
        pushButton_14->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"font: 11pt \"Arial\";"));
        frame_11 = new QFrame(project);
        frame_11->setObjectName("frame_11");
        frame_11->setGeometry(QRect(280, 0, 781, 41));
        frame_11->setStyleSheet(QString::fromUtf8("background-color:rgba(27,27,27,255);"));
        frame_11->setFrameShape(QFrame::StyledPanel);
        frame_11->setFrameShadow(QFrame::Raised);
        tableWidget_2 = new QTableWidget(project);
        tableWidget_2->setObjectName("tableWidget_2");
        tableWidget_2->setGeometry(QRect(320, 120, 691, 511));
        label_37 = new QLabel(project);
        label_37->setObjectName("label_37");
        label_37->setGeometry(QRect(320, 50, 191, 20));
        label_37->setStyleSheet(QString::fromUtf8("color:white;"));
        stackedWidget->addWidget(project);
        teams = new QWidget();
        teams->setObjectName("teams");
        frame_12 = new QFrame(teams);
        frame_12->setObjectName("frame_12");
        frame_12->setGeometry(QRect(0, 0, 281, 681));
        frame_12->setStyleSheet(QString::fromUtf8("background-color:rgba(27,27,27,255);"));
        frame_12->setFrameShape(QFrame::StyledPanel);
        frame_12->setFrameShadow(QFrame::Raised);
        label_27 = new QLabel(frame_12);
        label_27->setObjectName("label_27");
        label_27->setGeometry(QRect(10, 10, 261, 151));
        label_27->setPixmap(QPixmap(QString::fromUtf8(":/pics/picture/people.png")));
        label_27->setScaledContents(true);
        label_28 = new QLabel(frame_12);
        label_28->setObjectName("label_28");
        label_28->setGeometry(QRect(50, 140, 211, 51));
        label_28->setStyleSheet(QString::fromUtf8("color: rgb(254, 251, 255);\n"
"font: 700 11pt \"Arial\";"));
        label_29 = new QLabel(frame_12);
        label_29->setObjectName("label_29");
        label_29->setGeometry(QRect(50, 180, 201, 21));
        label_29->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"font: italic 9pt \"Segoe UI\";"));
        pushButton_15 = new QPushButton(frame_12);
        pushButton_15->setObjectName("pushButton_15");
        pushButton_15->setGeometry(QRect(0, 240, 281, 61));
        pushButton_15->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"font: 11pt \"Arial\";"));
        label_30 = new QLabel(frame_12);
        label_30->setObjectName("label_30");
        label_30->setGeometry(QRect(90, 640, 121, 31));
        label_30->setStyleSheet(QString::fromUtf8("color:white;"));
        pushButton_16 = new QPushButton(frame_12);
        pushButton_16->setObjectName("pushButton_16");
        pushButton_16->setGeometry(QRect(0, 420, 281, 61));
        pushButton_16->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"font: 11pt \"Arial\";"));
        pushButton_17 = new QPushButton(frame_12);
        pushButton_17->setObjectName("pushButton_17");
        pushButton_17->setGeometry(QRect(0, 300, 281, 61));
        pushButton_17->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"font: 11pt \"Arial\";"));
        pushButton_18 = new QPushButton(frame_12);
        pushButton_18->setObjectName("pushButton_18");
        pushButton_18->setGeometry(QRect(0, 360, 281, 61));
        pushButton_18->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"font: 11pt \"Arial\";"));
        frame_13 = new QFrame(teams);
        frame_13->setObjectName("frame_13");
        frame_13->setGeometry(QRect(280, 0, 781, 41));
        frame_13->setStyleSheet(QString::fromUtf8("background-color:rgba(27,27,27,255);"));
        frame_13->setFrameShape(QFrame::StyledPanel);
        frame_13->setFrameShadow(QFrame::Raised);
        label_38 = new QLabel(teams);
        label_38->setObjectName("label_38");
        label_38->setGeometry(QRect(320, 50, 191, 20));
        label_38->setStyleSheet(QString::fromUtf8("color:white;"));
        stackedWidget->addWidget(teams);
        employee = new QWidget();
        employee->setObjectName("employee");
        frame_14 = new QFrame(employee);
        frame_14->setObjectName("frame_14");
        frame_14->setGeometry(QRect(0, 0, 281, 681));
        frame_14->setStyleSheet(QString::fromUtf8("background-color:rgba(27,27,27,255);"));
        frame_14->setFrameShape(QFrame::StyledPanel);
        frame_14->setFrameShadow(QFrame::Raised);
        label_31 = new QLabel(frame_14);
        label_31->setObjectName("label_31");
        label_31->setGeometry(QRect(10, 10, 261, 151));
        label_31->setPixmap(QPixmap(QString::fromUtf8(":/pics/picture/people.png")));
        label_31->setScaledContents(true);
        label_32 = new QLabel(frame_14);
        label_32->setObjectName("label_32");
        label_32->setGeometry(QRect(50, 140, 211, 51));
        label_32->setStyleSheet(QString::fromUtf8("color: rgb(254, 251, 255);\n"
"font: 700 11pt \"Arial\";"));
        label_33 = new QLabel(frame_14);
        label_33->setObjectName("label_33");
        label_33->setGeometry(QRect(50, 180, 201, 21));
        label_33->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"font: italic 9pt \"Segoe UI\";"));
        label_34 = new QLabel(frame_14);
        label_34->setObjectName("label_34");
        label_34->setGeometry(QRect(90, 640, 121, 31));
        label_34->setStyleSheet(QString::fromUtf8("color:white;"));
        pushButton_19 = new QPushButton(frame_14);
        pushButton_19->setObjectName("pushButton_19");
        pushButton_19->setGeometry(QRect(0, 240, 281, 61));
        pushButton_19->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"font: 11pt \"Arial\";"));
        pushButton_20 = new QPushButton(frame_14);
        pushButton_20->setObjectName("pushButton_20");
        pushButton_20->setGeometry(QRect(0, 300, 281, 61));
        pushButton_20->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"font: 11pt \"Arial\";"));
        pushButton_21 = new QPushButton(frame_14);
        pushButton_21->setObjectName("pushButton_21");
        pushButton_21->setGeometry(QRect(0, 360, 281, 61));
        pushButton_21->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"font: 11pt \"Arial\";"));
        pushButton_22 = new QPushButton(frame_14);
        pushButton_22->setObjectName("pushButton_22");
        pushButton_22->setGeometry(QRect(0, 420, 281, 61));
        pushButton_22->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"font: 11pt \"Arial\";"));
        frame_15 = new QFrame(employee);
        frame_15->setObjectName("frame_15");
        frame_15->setGeometry(QRect(280, 0, 781, 41));
        frame_15->setStyleSheet(QString::fromUtf8("background-color:rgba(27,27,27,255);"));
        frame_15->setFrameShape(QFrame::StyledPanel);
        frame_15->setFrameShadow(QFrame::Raised);
        frame_16 = new QFrame(employee);
        frame_16->setObjectName("frame_16");
        frame_16->setGeometry(QRect(340, 120, 291, 181));
        frame_16->setStyleSheet(QString::fromUtf8("border-radius:12px;\n"
"background-color:rgba(0,133,104,255);"));
        frame_16->setFrameShape(QFrame::StyledPanel);
        frame_16->setFrameShadow(QFrame::Raised);
        label_39 = new QLabel(frame_16);
        label_39->setObjectName("label_39");
        label_39->setGeometry(QRect(80, 50, 151, 31));
        label_39->setStyleSheet(QString::fromUtf8("font: 12pt \"Arial\";\n"
"color:white;"));
        label_40 = new QLabel(frame_16);
        label_40->setObjectName("label_40");
        label_40->setGeometry(QRect(130, 90, 41, 41));
        label_40->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"font: 700 12pt \"Arial\";"));
        frame_18 = new QFrame(employee);
        frame_18->setObjectName("frame_18");
        frame_18->setGeometry(QRect(670, 120, 291, 181));
        frame_18->setStyleSheet(QString::fromUtf8("border-radius:12px;\n"
"background-color:rgba(210,82,88,255);"));
        frame_18->setFrameShape(QFrame::StyledPanel);
        frame_18->setFrameShadow(QFrame::Raised);
        label_43 = new QLabel(frame_18);
        label_43->setObjectName("label_43");
        label_43->setGeometry(QRect(70, 50, 171, 31));
        label_43->setStyleSheet(QString::fromUtf8("font: 12pt \"Arial\";\n"
"color:white;"));
        label_44 = new QLabel(frame_18);
        label_44->setObjectName("label_44");
        label_44->setGeometry(QRect(130, 90, 41, 41));
        label_44->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"font: 700 12pt \"Arial\";"));
        stackedWidget->addWidget(employee);
        insertemp = new QWidget();
        insertemp->setObjectName("insertemp");
        frame_19 = new QFrame(insertemp);
        frame_19->setObjectName("frame_19");
        frame_19->setGeometry(QRect(0, 0, 281, 681));
        frame_19->setStyleSheet(QString::fromUtf8("background-color:rgba(27,27,27,255);"));
        frame_19->setFrameShape(QFrame::StyledPanel);
        frame_19->setFrameShadow(QFrame::Raised);
        label_41 = new QLabel(frame_19);
        label_41->setObjectName("label_41");
        label_41->setGeometry(QRect(10, 10, 261, 151));
        label_41->setPixmap(QPixmap(QString::fromUtf8(":/pics/picture/people.png")));
        label_41->setScaledContents(true);
        label_42 = new QLabel(frame_19);
        label_42->setObjectName("label_42");
        label_42->setGeometry(QRect(50, 140, 211, 51));
        label_42->setStyleSheet(QString::fromUtf8("color: rgb(254, 251, 255);\n"
"font: 700 11pt \"Arial\";"));
        label_45 = new QLabel(frame_19);
        label_45->setObjectName("label_45");
        label_45->setGeometry(QRect(50, 180, 201, 21));
        label_45->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"font: italic 9pt \"Segoe UI\";"));
        label_46 = new QLabel(frame_19);
        label_46->setObjectName("label_46");
        label_46->setGeometry(QRect(90, 640, 121, 31));
        label_46->setStyleSheet(QString::fromUtf8("color:white;"));
        pushButton_23 = new QPushButton(frame_19);
        pushButton_23->setObjectName("pushButton_23");
        pushButton_23->setGeometry(QRect(0, 240, 281, 61));
        pushButton_23->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"font: 11pt \"Arial\";"));
        pushButton_24 = new QPushButton(frame_19);
        pushButton_24->setObjectName("pushButton_24");
        pushButton_24->setGeometry(QRect(0, 300, 281, 61));
        pushButton_24->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"font: 11pt \"Arial\";"));
        pushButton_25 = new QPushButton(frame_19);
        pushButton_25->setObjectName("pushButton_25");
        pushButton_25->setGeometry(QRect(0, 360, 281, 61));
        pushButton_25->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"font: 11pt \"Arial\";"));
        pushButton_26 = new QPushButton(frame_19);
        pushButton_26->setObjectName("pushButton_26");
        pushButton_26->setGeometry(QRect(0, 420, 281, 61));
        pushButton_26->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"font: 11pt \"Arial\";"));
        frame_17 = new QFrame(insertemp);
        frame_17->setObjectName("frame_17");
        frame_17->setGeometry(QRect(280, 0, 781, 41));
        frame_17->setStyleSheet(QString::fromUtf8("background-color:rgba(27,27,27,255);"));
        frame_17->setFrameShape(QFrame::StyledPanel);
        frame_17->setFrameShadow(QFrame::Raised);
        stackedWidget->addWidget(insertemp);
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QString());
        label_2->setText(QString());
        label_3->setText(QCoreApplication::translate("MainWindow", "Login In", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Enter Your Information Below", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Username:", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "Password:", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "Login", nullptr));
        label_7->setText(QString());
        label_8->setText(QCoreApplication::translate("MainWindow", "Employee Management", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "Optimizing Work Productivity", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "        Department", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainWindow", "Teams", nullptr));
        pushButton_4->setText(QCoreApplication::translate("MainWindow", "       Employees", nullptr));
        pushButton_5->setText(QCoreApplication::translate("MainWindow", "   Projects", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "App Version v1.0", nullptr));
        label_13->setText(QCoreApplication::translate("MainWindow", "No of Projects Pending", nullptr));
        label_16->setText(QCoreApplication::translate("MainWindow", "300", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", "No of Departments", nullptr));
        label_15->setText(QCoreApplication::translate("MainWindow", "300", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "No of Employees", nullptr));
        label_14->setText(QCoreApplication::translate("MainWindow", "300", nullptr));
        label_17->setText(QCoreApplication::translate("MainWindow", "No of Incoming Deadlines", nullptr));
        label_18->setText(QCoreApplication::translate("MainWindow", "12", nullptr));
        pushButton_7->setText(QCoreApplication::translate("MainWindow", "Log Out", nullptr));
        label_35->setText(QCoreApplication::translate("MainWindow", "Dashboard", nullptr));
        label_19->setText(QString());
        label_20->setText(QCoreApplication::translate("MainWindow", "Employee Management", nullptr));
        label_21->setText(QCoreApplication::translate("MainWindow", "Optimizing Work Productivity", nullptr));
        label_22->setText(QCoreApplication::translate("MainWindow", "App Version v1.0", nullptr));
        pushButton_6->setText(QCoreApplication::translate("MainWindow", "       Employees", nullptr));
        pushButton_9->setText(QCoreApplication::translate("MainWindow", " Project", nullptr));
        pushButton_10->setText(QCoreApplication::translate("MainWindow", "Teams", nullptr));
        label_36->setText(QCoreApplication::translate("MainWindow", "Department", nullptr));
        label_23->setText(QString());
        label_24->setText(QCoreApplication::translate("MainWindow", "Employee Management", nullptr));
        label_25->setText(QCoreApplication::translate("MainWindow", "Optimizing Work Productivity", nullptr));
        label_26->setText(QCoreApplication::translate("MainWindow", "App Version v1.0", nullptr));
        pushButton_12->setText(QCoreApplication::translate("MainWindow", "       Employees", nullptr));
        pushButton_13->setText(QCoreApplication::translate("MainWindow", "        Department", nullptr));
        pushButton_14->setText(QCoreApplication::translate("MainWindow", "Teams", nullptr));
        label_37->setText(QCoreApplication::translate("MainWindow", "Project", nullptr));
        label_27->setText(QString());
        label_28->setText(QCoreApplication::translate("MainWindow", "Employee Management", nullptr));
        label_29->setText(QCoreApplication::translate("MainWindow", "Optimizing Work Productivity", nullptr));
        pushButton_15->setText(QCoreApplication::translate("MainWindow", "Search", nullptr));
        label_30->setText(QCoreApplication::translate("MainWindow", "App Version v1.0", nullptr));
        pushButton_16->setText(QCoreApplication::translate("MainWindow", "       Employees", nullptr));
        pushButton_17->setText(QCoreApplication::translate("MainWindow", " Project", nullptr));
        pushButton_18->setText(QCoreApplication::translate("MainWindow", "Teams", nullptr));
        label_38->setText(QCoreApplication::translate("MainWindow", "Teams", nullptr));
        label_31->setText(QString());
        label_32->setText(QCoreApplication::translate("MainWindow", "Employee Management", nullptr));
        label_33->setText(QCoreApplication::translate("MainWindow", "Optimizing Work Productivity", nullptr));
        label_34->setText(QCoreApplication::translate("MainWindow", "App Version v1.0", nullptr));
        pushButton_19->setText(QCoreApplication::translate("MainWindow", "      Insert Employees", nullptr));
        pushButton_20->setText(QCoreApplication::translate("MainWindow", "            Remove Employees", nullptr));
        pushButton_21->setText(QCoreApplication::translate("MainWindow", "      Update Records", nullptr));
        pushButton_22->setText(QCoreApplication::translate("MainWindow", "      Retrieve Records", nullptr));
        label_39->setText(QCoreApplication::translate("MainWindow", "No of Employees", nullptr));
        label_40->setText(QCoreApplication::translate("MainWindow", "300", nullptr));
        label_43->setText(QCoreApplication::translate("MainWindow", "Active Employees", nullptr));
        label_44->setText(QCoreApplication::translate("MainWindow", "300", nullptr));
        label_41->setText(QString());
        label_42->setText(QCoreApplication::translate("MainWindow", "Employee Management", nullptr));
        label_45->setText(QCoreApplication::translate("MainWindow", "Optimizing Work Productivity", nullptr));
        label_46->setText(QCoreApplication::translate("MainWindow", "App Version v1.0", nullptr));
        pushButton_23->setText(QCoreApplication::translate("MainWindow", "      Insert Employees", nullptr));
        pushButton_24->setText(QCoreApplication::translate("MainWindow", "            Remove Employees", nullptr));
        pushButton_25->setText(QCoreApplication::translate("MainWindow", "      Update Records", nullptr));
        pushButton_26->setText(QCoreApplication::translate("MainWindow", "      Retrieve Records", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
