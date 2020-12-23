#ifndef SPHEREWIDGET_H
#define SPHEREWIDGET_H

#include <QVTKOpenGLWidget.h>

class SphereWidget : public QVTKOpenGLWidget
{
    Q_OBJECT
public:
    explicit SphereWidget(QWidget *parent = nullptr);

signals:

public slots:
};

#endif // SPHEREWIDGET_H
