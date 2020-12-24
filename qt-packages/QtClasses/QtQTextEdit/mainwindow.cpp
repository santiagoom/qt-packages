#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->logTextEdit->document()->setMaximumBlockCount(5);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
////ui->textBrowser->setText("hhh");
//ui->textBrowser->append("hhh");
//ui->textBrowser->append("hhh");
//ui->textBrowser->append("hhh");
//ui->textBrowser->append("hhh");
//ui->textEdit->setText("aa");
//ui->textEdit->append("hhh");
//ui->plainTextEdit->appendPlainText("ddd");
//// ui->plainTextEdit->verticalScrollBar()->setValue(ui->plainTextEdit->verticalScrollBar()->maximum());
//// ui->plainTextEdit->verticalScrollBar()->
//         ui->plainTextEdit->verticalScrollBar();
    ui->logTextEdit->append("123");
}
