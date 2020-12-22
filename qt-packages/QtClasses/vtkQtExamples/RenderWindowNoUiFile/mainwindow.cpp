#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QVTKOpenGLWidget.h>
#include <vtkActor.h>
#include <vtkGenericOpenGLRenderWindow.h>
#include <vtkNamedColors.h>
#include <vtkNew.h>
#include <vtkPolyDataMapper.h>
#include <vtkProperty.h>
#include <vtkRenderWindow.h>
#include <vtkRenderer.h>
#include <vtkSphereSource.h>
#include <vtkVersion.h>

#if VTK_VERSION_NUMBER >= 89000000000ULL
#define VTK890 1
#endif

#include <QSurfaceFormat>
#include <QVTKOpenGLNativeWidget.h>

#include <vtkAutoInit.h>
VTK_MODULE_INIT(vtkRenderingOpenGL2);
VTK_MODULE_INIT(vtkRenderingContextOpenGL2); // this is for 2D graphics link
VTK_MODULE_INIT(vtkInteractionStyle);
VTK_MODULE_INIT(vtkRenderingFreeType);


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    RenderWindowNoUiFile();
//    ui->gridLayout->removeWidget(ui->widget);
//    ui->gridLayout->addWidget(new TestQtVTK);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::RenderWindowNoUiFile()
{
    // needed to ensure appropriate OpenGL context is created for VTK rendering.
//      QSurfaceFormat::setDefaultFormat(QVTKOpenGLNativeWidget::defaultFormat());

      // needed to ensure appropriate OpenGL context is created for VTK rendering.
      QSurfaceFormat::setDefaultFormat(QVTKOpenGLWidget::defaultFormat());

      QVTKOpenGLNativeWidget widget;
//      QVTKOpenGLWidget widget;


      vtkNew <vtkGenericOpenGLRenderWindow> renderWindow;
         widget.SetRenderWindow(renderWindow);
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
         widget.GetRenderWindow()->AddRenderer(renderer);
         widget.GetRenderWindow()->SetWindowName(
                 "RenderWindowUIMultipleInheritance");



//      QVTKOpenGLNativeWidget widget;
////      QVTKOpenGLWidget widget;
////      vtkNew<QVTKOpenGLNativeWidget> widget;

//        vtkNew<vtkNamedColors> colors;

//        vtkNew<vtkGenericOpenGLRenderWindow> renderWindow;
////      #if VTK890
//        widget.SetRenderWindow(renderWindow);
////        widget.GetRenderWindow()
////      #else
////        widget.SetRenderWindow(renderWindow);
////      #endif

//        widget.resize(600, 600);

//        vtkNew<vtkSphereSource> sphereSource;

//        vtkNew<vtkPolyDataMapper> sphereMapper;
//        sphereMapper->SetInputConnection(sphereSource->GetOutputPort());

//        vtkNew<vtkActor> sphereActor;
//        sphereActor->SetMapper(sphereMapper);
//        sphereActor->GetProperty()->SetColor(colors->GetColor4d("Tomato").GetData());

//        vtkNew<vtkRenderer> renderer;
//        renderer->AddActor(sphereActor);
//        renderer->SetBackground(colors->GetColor3d("SteelBlue").GetData());

////      #if VTK890
////        widget.renderWindow()->AddRenderer(renderer);
////        widget.renderWindow()->SetWindowName("RenderWindowNoUIFile");
////      #else
//        widget.GetRenderWindow()->AddRenderer(renderer);
//        widget.GetRenderWindow()->SetWindowName("RenderWindowNoUIFile");
////      #endif
//        widget.show();




}
