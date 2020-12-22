#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"cubewidget.h"
#include"spherewidget.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->cubeGridLayout->removeWidget(ui->cubeWidget);
    ui->cubeGridLayout->addWidget(new CubeWidget);

    ui->cubeGridLayout->removeWidget(ui->cubeWidget);
    ui->sphereGridLayout->addWidget(new SphereWidget);

}

MainWindow::~MainWindow()
{
    delete ui;
}
