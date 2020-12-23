#ifndef CUBEWIDGET_H
#define CUBEWIDGET_H

#include <QVTKOpenGLWidget.h>


class CubeWidget : public QVTKOpenGLWidget
{
    Q_OBJECT
public:
    explicit CubeWidget(QWidget *parent = nullptr);

signals:

public slots:
};

#endif // CUBEWIDGET_H
