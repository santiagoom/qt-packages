#ifndef TESTQTVTK_H
#define TESTQTVTK_H

#include <QVTKOpenGLWidget.h>

class TestQtVTK : public QVTKOpenGLWidget
{
    Q_OBJECT
public:
    explicit TestQtVTK(QWidget *parent = nullptr);

signals:

public slots:
};

#endif // TESTQTVTK_H
