#include "myvtkwidget.h"

#include <vtkInteractorStyleTrackballCamera.h>
#include <vtkRenderer.h>
#include <vtkRenderWindow.h>
#include <vtkMetaImageReader.h>
#include <vtkSmartVolumeMapper.h>
#include <vtkPiecewiseFunction.h>
#include <vtkColorTransferFunction.h>
#include <vtkVolumeProperty.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkObjectFactory.h>
#include <vtkStripper.h>
#include <vtkProperty.h>
#include <vtkActor.h>
#include <vtkPolyDataMapper.h>
#include <vtkMarchingCubes.h>
#include <vtkNIFTIImageReader.h>
#include <vtkPolyData.h>
#include <vtkImageImport.h>
#include <vtkNew.h>
#include <vtkImagePlaneWidget.h>
#include <vtkImageData.h>
#include <vtkLinearTransform.h>
#include <vtkAnnotatedCubeActor.h>
#include <vtkOrientationMarkerWidget.h>
#include <vtkPropPicker.h>
#include <vtkCamera.h>
#include <vtkTextMapper.h>
#include <vtkTextActor.h>
#include <vtkTextProperty.h>
#include <vtkCommand.h>
#include <vtkImplicitPlaneWidget2.h>
#include <vtkImplicitPlaneRepresentation.h>
#include <vtkPlane.h>
#include <vtkClipVolume.h>
#include <vtkVolumePicker.h>
#include <vtkRendererCollection.h>

#include <QResizeEvent>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QJsonValue>
#include <QStringList>
#include <QString>


MyVTKWidget::MyVTKWidget(QWidget *parent) : QVTKOpenGLWidget(parent)
{
    renderer = vtkSmartPointer<vtkRenderer>::New();
    GetRenderWindow()->AddRenderer(renderer);
}

void MyVTKWidget::updateWindow()
{
    GetRenderWindow()->Render();
}

bool MyVTKWidget::addPolyData(const QString &name, const vtkSmartPointer<vtkPolyData> &polyData, double *rgbColor, double opacity)
{
    if(name.isEmpty())
           return false;
       vtkNew<vtkPolyDataMapper> baseDataMapper;
       baseDataMapper->SetInputData(polyData);
       baseDataMapper->Update();
       // proactively manage pointer
       vtkActor* baseDataActor = vtkActor::New();
       baseDataActor->SetMapper(baseDataMapper);
       baseDataActor->GetProperty()->SetColor(rgbColor);
       baseDataActor->GetProperty()->SetOpacity(opacity);
       renderer->AddActor(baseDataActor);
       polyDataActorMap.insert(name,baseDataActor);
       backupCamera();
       updateWindow();
       return true;
}

void MyVTKWidget::hidePolyData(const QString &name, bool reset)
{
    if(polyDataActorMap.contains(name))
    {
        renderer->RemoveActor(polyDataActorMap.value(name));
        backupCamera(reset);
        updateWindow();
    }

}

void MyVTKWidget::showPolyData(const QString &name, bool reset)
{
    if(polyDataActorMap.contains(name))
       {
           renderer->AddActor(polyDataActorMap.value(name));
           backupCamera(reset);
           updateWindow();
       }

}

void MyVTKWidget::backupCamera(bool reset)
{
    if(reset)
           renderer->ResetCamera();
       oriViewUp[0] = renderer->GetActiveCamera()->GetViewUp()[0];
       oriViewUp[1] = renderer->GetActiveCamera()->GetViewUp()[1];
       oriViewUp[2] = renderer->GetActiveCamera()->GetViewUp()[2];
       oriPos[0] = renderer->GetActiveCamera()->GetPosition()[0];
       oriPos[1] = renderer->GetActiveCamera()->GetPosition()[1];
       oriPos[2] = renderer->GetActiveCamera()->GetPosition()[2];
       oriFocal[0] = renderer->GetActiveCamera()->GetFocalPoint()[0];
       oriFocal[1] = renderer->GetActiveCamera()->GetFocalPoint()[1];
       oriFocal[2] = renderer->GetActiveCamera()->GetFocalPoint()[2];

}
