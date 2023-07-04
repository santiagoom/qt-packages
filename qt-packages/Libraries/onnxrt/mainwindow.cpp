#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "onnxruntime_cxx_api.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

