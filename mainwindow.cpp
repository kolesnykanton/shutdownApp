#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ui_mainwindow.h"
#include "qdialogbuttonbox.h"
#include "QFlags"
#include "QModelIndex"
#include "qlistwidget.h"
#include "string"
#include "qabstractitemview.h"
#include "QSpinBox"
#include <iostream>
#include <QTextStream>
#include <stdio.h>
#include <QProcess>

using namespace std;


string command;
string hiber = " /nobreak & shutdown /h";

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->listWidget,SIGNAL(itemClicked(QListWidgetItem*)),this,SLOT(itemClicked(QListWidgetItem*)));
    connect(ui->spinBox, SIGNAL(valueChanged(int)),this, SLOT(on_spinboxValueChanged(int)));
}

MainWindow::~MainWindow()
{
    delete ui;

}




void MainWindow::on_closeButton_clicked()
{
    close();
}

void MainWindow::on_okButton_clicked()
{
    system(command.c_str());
}

void MainWindow::on_abortButton_clicked()
{
    system("shutdown -a");
}

void MainWindow::on_listWidget_itemClicked(QListWidgetItem *item)
{
    if(item->text()=="Shutdown"){
            command = "shutdown /s /t " + to_string(ui->spinBox->value());
    }
    else if(item->text()=="Hibernate"){
        command = "timeout /t " + to_string(ui->spinBox->value()) + hiber;
    }
}


void MainWindow::on_comboBox_currentIndexChanged(int index)
{
    if(index == 0){
        hourtime = ui->spinBox->value() * 3600;
    }
}


void MainWindow::on_spinBox_valueChanged(int arg1)
{
    timeout = arg1;
}



//void MainWindow::on_checkBoxForce_stateChanged(int arg1)
//{
//    if(arg1 == Qt.Unchecked){
//        force = "";
//    }
//    else {
//        force = " /f";
//    }
//}
