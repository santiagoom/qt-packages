#ifndef MYVTKWIDGET_H
#define MYVTKWIDGET_H

#include <QMap>
#include <QMultiMap>

#include <QVTKOpenGLWidget.h>
#include <vtkSmartPointer.h>
#include "vtkAutoInit.h"
VTK_MODULE_INIT(vtkRenderingOpenGL2);
VTK_MODULE_INIT(vtkInteractionStyle);
VTK_MODULE_INIT(vtkRenderingFreeType)
VTK_MODULE_INIT(vtkRenderingVolumeOpenGL2)


class vtkMetaImageReader;
class vtkRenderer;
class vtkVolume;
class vtkActor;
class vtkPolyData;
class vtkPolyDataMapper;
class vtkImageImport;
class vtkSmartVolumeMapper;
class vtkVolumeProperty;
class vtkPiecewiseFunction;
class vtkColorTransferFunction;
class vtkRenderWindowInteractor;
class vtkImagePlaneWidget;
class vtkOrientationMarkerWidget;
class vtkImplicitPlaneWidget2;
class vtkImplicitPlaneRepresentation;
class vtkTextActor;


class MyVTKWidget : public QVTKOpenGLWidget
{
    Q_OBJECT
public:
    explicit MyVTKWidget(QWidget *parent = nullptr);
//    ~MyVTKWidget();

    void updateWindow();

    bool addPolyData(const QString &name, const vtkSmartPointer<vtkPolyData> &polyData, double *rgbColor, double opacity = 1.0);
    void hidePolyData(const QString &name,bool reset = true);
    void showPolyData(const QString &name, bool reset = true);


signals:

private:
    void backupCamera(bool reset=true);

public slots:


protected:
    vtkSmartPointer<vtkRenderer> renderer;
    QMap<QString,vtkActor*> polyDataActorMap;
    double oriViewUp[3];
    double oriPos[3];
    double oriFocal[3];

};

#endif // MYVTKWIDGET_H
