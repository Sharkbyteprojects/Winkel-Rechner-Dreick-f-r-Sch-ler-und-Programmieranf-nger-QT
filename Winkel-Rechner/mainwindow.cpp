/*
 * WRITTEN BY:
 *
 * SHARKBYTEPROJECTS
 *
 * http://services.sharkbyte.bplaced.net/
 */
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
int num1;
int neud;
int num2;
int numlock1;
int numlock2;
//180 - (x+y)
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->progressBar->setValue(0);
    ui->progressBar->setMaximum(180);
    ui->dial->setMinimum(0);
    ui->dial->setMaximum(180);
    ui->dial->setValue(0);
    ui->dial_2->setMinimum(0);
    ui->dial_2->setMaximum(180);
    ui->dial_2->setValue(0);
    ui->spinBox->setMaximum(180);
    ui->spinBox_2->setMaximum(180);
    ui->spinBox->setMinimum(0);
    ui->spinBox_2->setMinimum(0);

    this->setFixedSize(this->width(),this->height());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_dial_valueChanged(int value)
{
   num1= value;
   ui->spinBox_2->setValue(value);
   neud = 180 - (value + num2);
   if (neud < 0){
       QString warn;
       warn = "Fehler, diese eingabe ist leider nicht möglich!";
       QMessageBox mb;
       mb.setText(warn);
       mb.exec();
       ui->dial->setValue(numlock1);
   }else{
      ui->lcdNumber_3->display(neud);
      ui->progressBar->setValue(value+num2);
      numlock1 = value;
   }
}

void MainWindow::on_dial_2_valueChanged(int value)
{
    num2=value;
    ui->spinBox->setValue(value);
    neud = 180-(value + num1);
    if (neud < 0){
        QString warn;
        warn = ("Fehler, diese eingabe ist leider nicht möglich!");
        QMessageBox mb;
        mb.setText(warn);
        mb.exec();
        ui->dial_2->setValue(numlock2);
    }else{
       ui->lcdNumber_3->display(neud);
       ui->progressBar->setValue(value+num1);
       numlock2 = value;
    }
}

void MainWindow::on_spinBox_valueChanged(int arg1)
{
    ui->dial_2->setValue(arg1);
}

void MainWindow::on_spinBox_2_valueChanged(int arg1)
{
    ui->dial->setValue(arg1);
}
