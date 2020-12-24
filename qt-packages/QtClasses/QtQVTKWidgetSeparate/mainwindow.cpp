#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"cubewidget.h"
#include"spherewidget.h"
#include"qdebug.h"
#include"myvtkwidget.h"

#include <vtkSTLReader.h>

MainWindow::MainWindow(QWidget *parent) :
        QMainWindow(parent),
        ui(new Ui::MainWindow) {
    ui->setupUi(this);
    ui->cubeGridLayout->removeWidget(ui->cubeWidget);
    ui->cubeGridLayout->addWidget(new CubeWidget);
    ui->cubeGridLayout->removeWidget(ui->cubeWidget);

    initPolyData();
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::initPolyData() {

    double color[3] = {0, 1, 0};
    double color1[3] = {1, 0, 0};

    std::string filename1 = "F:\\data\\esdata\\esdata\\experiment\\stl\\CTA20140728_DENGXILIAN\\AT_6_CTA20140728_DENGXILIAN_predictionv1.stl";
    std::string filename2 = "F:\\data\\esdata\\esdata\\experiment\\stl\\CTA20140728_DENGXILIAN\\CM_1_CTA20140728_DENGXILIAN_predictionv1.stl";
    std::string filename3 = "F:\\data\\esdata\\esdata\\experiment\\stl\\CTA20140728_DENGXILIAN\\LA_2_CTA20140728_DENGXILIAN_predictionv1.stl";
    std::string filename4 = "F:\\data\\esdata\\esdata\\experiment\\stl\\CTA20140728_DENGXILIAN\\levelset_1_CTA20140728_DENGXILIAN_predictionv1.stl";
    std::string filename5 = "F:\\data\\esdata\\esdata\\experiment\\stl\\CTA20140728_DENGXILIAN\\LV_3_CTA20140728_DENGXILIAN_predictionv1.stl";
    std::string filename6 = "F:\\data\\esdata\\esdata\\experiment\\stl\\CTA20140728_DENGXILIAN\\PA_7_CTA20140728_DENGXILIAN_predictionv1.stl";
    std::string filename7 = "F:\\data\\esdata\\esdata\\experiment\\stl\\CTA20140728_DENGXILIAN\\RA_4_CTA20140728_DENGXILIAN_predictionv1.stl";
    std::string filename8 = "F:\\data\\esdata\\esdata\\experiment\\stl\\CTA20140728_DENGXILIAN\\RV_5_CTA20140728_DENGXILIAN_predictionv1.stl";

    {
        vtkSmartPointer<vtkSTLReader> reader = vtkSmartPointer<vtkSTLReader>::New();

        reader->SetFileName(filename1.c_str());
        reader->Update();
        ui->myVTKWidget->addPolyData("1", reader->GetOutput(), color);
    }

    {
        vtkSmartPointer<vtkSTLReader> reader = vtkSmartPointer<vtkSTLReader>::New();
        reader->SetFileName(filename2.c_str());
        reader->Update();
        ui->myVTKWidget->addPolyData("2", reader->GetOutput(), color1);
    }


}

void MainWindow::on_pushButton_toggled(bool checked) {
    if (checked)
        qDebug() << "checked";
    else
        qDebug() << "un checked";
}

void MainWindow::on_pushButton_clicked() {
    qDebug() << "b1";
    ui->myVTKWidget->showPolyData("at", false);

}


void MainWindow::on_pushButton_2_clicked() {
    qDebug() << "b2";
    ui->myVTKWidget->hidePolyData("at", true);
}


