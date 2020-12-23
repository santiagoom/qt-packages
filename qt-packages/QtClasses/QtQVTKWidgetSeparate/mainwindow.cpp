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

//    QString name = QFileDialog::getOpenFileName(this,tr("Open centerline file"),
//                                                m_exchangeDatDir,tr("*.ctl"));
//    if(name.isEmpty())
//        return;
//    clear(m_groundTruthList);
//    ESLabelIO::loadCenterline(name,m_groundTruthList);
//    vtkSmartPointer<vtkPolyData> polydata = createPolyLine(m_groundTruthList);
    double color[3] = {0, 1, 0};
//    ui->containerWidget->addPolyData(groundTruthName,polydata,color);
//    ui->groundTruthCtl->setChecked(true);

    std::string filename = "F:\\data\\esdata\\esdata\\experiment\\stls\\CTA20140728_DENGXILIAN\\stl\\AT_6_CTA20140728_DENGXILIAN_prediction.stl";
//    std::string filename = "D:\\gitrepoe\\vtk-examples\\code\\cpp\\cmake-build-release\\vtk-examples\\cpp-examples\\working-with-3d-data\\medical\\Label2.vtp";

    vtkSmartPointer<vtkSTLReader> reader = vtkSmartPointer<vtkSTLReader>::New();
    reader->SetFileName(filename.c_str());
    reader->Update();
    ui->myVTKWidget->addPolyData("at", reader->GetOutput(), color);


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


