#include "spherewidget.h"
#include <vtkActor.h>
#include <vtkCamera.h>
#include <vtkCellArray.h>
#include <vtkFloatArray.h>
#include <vtkNamedColors.h>
#include <vtkNew.h>
#include <vtkPointData.h>
#include <vtkPoints.h>
#include <vtkPolyData.h>
#include <vtkPolyDataMapper.h>
#include <vtkRenderWindow.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkRenderer.h>
#include <vtkGenericOpenGLRenderWindow.h>
#include <vtkSphereSource.h>
#include <vtkProperty.h>

#include <QSurfaceFormat>
#include <vtkAutoInit.h>

VTK_MODULE_INIT(vtkRenderingOpenGL2);
VTK_MODULE_INIT(vtkRenderingContextOpenGL2); // this is for 2D graphics link
VTK_MODULE_INIT(vtkInteractionStyle);
VTK_MODULE_INIT(vtkRenderingFreeType);


SphereWidget::SphereWidget(QWidget *parent) : QVTKOpenGLWidget(parent) {
//     needed to ensure appropriate OpenGL context is created for VTK rendering.
    QSurfaceFormat::setDefaultFormat(QVTKOpenGLWidget::defaultFormat());

    vtkNew <vtkGenericOpenGLRenderWindow> renderWindow;
    this->SetRenderWindow(renderWindow);
    vtkNew <vtkNamedColors> colors;
    // Sphere
    auto sphereSource = vtkSmartPointer<vtkSphereSource>::New();
    sphereSource->Update();

    auto sphereMapper = vtkSmartPointer<vtkPolyDataMapper>::New();
    sphereMapper->SetInputConnection(sphereSource->GetOutputPort());

    auto sphereActor = vtkSmartPointer<vtkActor>::New();
    sphereActor->SetMapper(sphereMapper);
    sphereActor->GetProperty()->SetColor(colors->GetColor4d("Tomato").GetData());

    // VTK Renderer
    auto renderer = vtkSmartPointer<vtkRenderer>::New();
    renderer->AddActor(sphereActor);
    renderer->SetBackground(colors->GetColor3d("SteelBlue").GetData());

    // VTK/Qt wedded
    this->GetRenderWindow()->AddRenderer(renderer);
    this->GetRenderWindow()->SetWindowName(
            "RenderWindowUIMultipleInheritance");
}
