#include "cubewidget.h"
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
#include <array>

#include <QSurfaceFormat>
#include <vtkAutoInit.h>

VTK_MODULE_INIT(vtkRenderingOpenGL2);
VTK_MODULE_INIT(vtkRenderingContextOpenGL2); // this is for 2D graphics link
VTK_MODULE_INIT(vtkInteractionStyle);
VTK_MODULE_INIT(vtkRenderingFreeType);


CubeWidget::CubeWidget(QWidget *parent) : QVTKOpenGLWidget(parent) {
    // needed to ensure appropriate OpenGL context is created for VTK rendering.
    QSurfaceFormat::setDefaultFormat(QVTKOpenGLWidget::defaultFormat());
    vtkNew <vtkGenericOpenGLRenderWindow> renderWindow;
    this->SetRenderWindow(renderWindow);

    vtkNew <vtkNamedColors> colors;
    std::array<std::array<double, 3>, 8> pts = {{{{0, 0, 0}},
                                                        {{1, 0, 0}},
                                                        {{1, 1, 0}},
                                                        {{0, 1, 0}},
                                                        {{0, 0, 1}},
                                                        {{1, 0, 1}},
                                                        {{1, 1, 1}},
                                                        {{0, 1, 1}}}};
    // The ordering of the corner points on each face.
    std::array<std::array<vtkIdType, 4>, 6> ordering = {{{{0, 1, 2, 3}},
                                                                {{4, 5, 6, 7}},
                                                                {{0, 1, 5, 4}},
                                                                {{1, 2, 6, 5}},
                                                                {{2, 3, 7, 6}},
                                                                {{3, 0, 4, 7}}}};

    // We'll create the building blocks of polydata including data attributes.
    vtkNew <vtkPolyData> cube;
    vtkNew <vtkPoints> points;
    vtkNew <vtkCellArray> polys;
    vtkNew <vtkFloatArray> scalars;

    // Load the point, cell, and data attributes.
    for (auto i = 0ul; i < pts.size(); ++i) {
        points->InsertPoint(i, pts[i].data());
        scalars->InsertTuple1(i, i);
        //        scalars->InsertTuple1(i, 1);
    }
    for (auto &&i : ordering) {
        cout << i.size() << endl;
        cout << i.data() << endl;
        polys->InsertNextCell(vtkIdType(i.size()), i.data());
    }

    float value;
    for (int i = 0; i < scalars->GetNumberOfTuples(); i++) {
        value = scalars->GetValue(i);
        std::cout << value << std::endl;
    }

    // We now assign the pieces to the vtkPolyData.
    cube->SetPoints(points);
    cube->SetPolys(polys);
    cube->GetPointData()->SetScalars(scalars);

    // Now we'll look at it.
    vtkNew <vtkPolyDataMapper> cubeMapper;
    cubeMapper->SetInputData(cube);
    cout << cube->GetScalarRange() << endl;
    cubeMapper->SetScalarRange(cube->GetScalarRange());
    vtkNew <vtkActor> cubeActor;
    cubeActor->SetMapper(cubeMapper);

    // VTK Renderer
    auto renderer = vtkSmartPointer<vtkRenderer>::New();
    renderer->AddActor(cubeActor);
    renderer->SetBackground(colors->GetColor3d("SteelBlue").GetData());

    // VTK/Qt wedded
    this->GetRenderWindow()->AddRenderer(renderer);
    this->GetRenderWindow()->SetWindowName(
            "RenderWindowUIMultipleInheritance");

}
