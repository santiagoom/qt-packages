#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QPushButton>
#include <qdebug.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    qtQMessageBox();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::qtQMessageBox()
{
//    // 1
//    QMessageBox msgBox;
//    msgBox.setText("The document has been modified.");
//    msgBox.exec();

////    2
//    QMessageBox msgBox;
//    msgBox.setText("The document has been modified.");
//    msgBox.setInformativeText("Do you want to save your changes?");
//    msgBox.setStandardButtons(QMessageBox::Save | QMessageBox::Discard | QMessageBox::Cancel);
//    msgBox.setDefaultButton(QMessageBox::Save);
//    int ret = msgBox.exec();
//    qDebug() <<ret;
//    switch (ret) {
//      case QMessageBox::Save:
//          // Save was clicked
//          break;
//      case QMessageBox::Discard:
//          // Don't Save was clicked
//          break;
//      case QMessageBox::Cancel:
//          // Cancel was clicked
//          break;
//      default:
//          // should never be reached
//          break;
//    }

    int ret = QMessageBox::warning(this, tr("My Application"),
                                   tr("The document has been modified.\n"
                                      "Do you want to save your changes?"),
                                   QMessageBox::Save | QMessageBox::Discard
                                   | QMessageBox::Cancel,
                                   QMessageBox::Save);

    QMessageBox msgBox;
    QPushButton *connectButton = msgBox.addButton(tr("Connect"), QMessageBox::ActionRole);
    QPushButton *abortButton = msgBox.addButton(QMessageBox::Abort);

    msgBox.exec();

    if (msgBox.clickedButton() == connectButton) {
        // connect
    } else if (msgBox.clickedButton() == abortButton) {
        // abort
    }
}
