#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#pragma comment(lib,"rpcrt4.lib")
#pragma comment(lib,"WS2_32.lib")

#include "itkGDCMImageIO.h"
#include "itkGDCMSeriesFileNames.h"
#include "itkImageSeriesReader.h"
#include "itkImageSeriesWriter.h"
#include "itkImageFileReader.h"
#include "itkMetaImageIOFactory.h"
#include "itkPNGImageIOFactory.h"
#include<qdebug.h>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    int itk_test_std();
    int itk_test_simple();
    void dicom_mhd();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
