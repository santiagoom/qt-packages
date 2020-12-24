#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"qdebug.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_checkBox_toggled(bool checked)
{
    if(checked)
        qDebug()<<"aa";
    else
        qDebug()<<"bb";
}
