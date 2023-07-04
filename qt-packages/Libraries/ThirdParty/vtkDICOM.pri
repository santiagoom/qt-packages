#https://github.com/dgobbi/vtk-dicom/
#A set of classes for using DICOM in VTK.

#DEFINES -= UNICODE
#DEFINES += DICOM_USE_DCMTK
include($$PWD/../../SOUPDependency/dcmtk-3.6.4/dcmtk-3.6.4.pri)

INCLUDEPATH += $$PWD/vtkDICOM
LIBS += -L$$PWD/vtkDICOM -lvtkDICOM
