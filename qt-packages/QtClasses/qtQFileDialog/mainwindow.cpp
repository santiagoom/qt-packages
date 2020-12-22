#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include<qdebug.h>

MainWindow::MainWindow(QWidget *parent) :
        QMainWindow(parent),
        ui(new Ui::MainWindow) {
    ui->setupUi(this);
    qtQFileDialog();
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::qtQFileDialog() {
//    QString fileName = QFileDialog::getOpenFileName(this,
//                                                    tr("Open Image"), "/home/jana",
//                                                    tr("Image Files (*.png *.jpg *.bmp)"));

//    qDebug() << fileName;

//    QFileDialog dialog(this);
//    dialog.setFileMode(QFileDialog::AnyFile);

//    QStringList fileNames;
//    if (dialog.exec()) {
//        fileNames = dialog.selectedFiles();
//        qDebug() << fileNames;
//    }

//    QString dir = QFileDialog::getExistingDirectory(this, tr("Open Directory"),
//                                                    "/home",
//                                                    QFileDialog::ShowDirsOnly
//                                                    | QFileDialog::DontResolveSymlinks);
//    qDebug() << dir;

//    QString fileName1 = QFileDialog::getSaveFileName(this, tr("Save File"),
//                               "/home/jana/untitled.png",
//                               tr("Images (*.png *.xpm *.jpg)"));
//    qDebug() << fileName1;

    QStringList mimeTypeFilters({"image/jpeg", // will show "JPEG image (*.jpeg *.jpg *.jpe)
                                 "image/png",  // will show "PNG image (*.png)"
                                 "application/octet-stream" // will show "All files (*)"
                                });

    QFileDialog dialog(this);
    dialog.setMimeTypeFilters(mimeTypeFilters);
    dialog.exec();

}
