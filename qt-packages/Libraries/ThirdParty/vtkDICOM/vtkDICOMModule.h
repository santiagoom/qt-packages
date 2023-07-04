/* Export macros for shared libraries */

#ifndef vtkDICOMModule_h
#define vtkDICOMModule_h

#include "vtkABI.h"
#include "vtkDICOMConfig.h"

#if defined(DICOM_BUILD_SHARED_LIBS)
# if defined(vtkDICOM_EXPORTS)
#  define VTKDICOM_EXPORT VTK_ABI_EXPORT
# else
#  define VTKDICOM_EXPORT VTK_ABI_IMPORT
# endif
#else
# define VTKDICOM_EXPORT
#endif

#endif
