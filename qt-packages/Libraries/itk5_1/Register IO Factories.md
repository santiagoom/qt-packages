# Register IO Factories



## Synopsis

When CMake is not used to build an executable or library against ITK, the Image and Transform IO format objects are not automatically registered to ITK’s object factory system, so they must be manually registered. There is not a static list of IO classes because the classes available depend on which modules are enabled when ITK is configured. This examples shows how to register the ImageIOBase objects so the ImageFileReader can read the formats corresponding to the registered objects.

## Results

```
When CMake is not used to register the IO classes, there are
0 IO objects available to the ImageFileReader.

When we try to read a MetaImage, we will fail.

After registering the MetaImageIO object, there are
1 IO objects available to the ImageFileReader.

Now, when we try to read a MetaImage, we will succeed.

Every format desired to be supported by the reader
must be registered.
```

## Code     All     C++     Python   

### C++

```cpp
#include "itkImageFileReader.h"
#include "itkMetaImageIOFactory.h"
#include "itkPNGImageIOFactory.h"

int
main(int argc, char * argv[])
{
  if (argc != 3)
  {
    std::cerr << "Usage: " << std::endl;
    std::cerr << argv[0];
    std::cerr << " <MetaImageFileName> <PNGFileName>";
    std::cerr << std::endl;
    return EXIT_FAILURE;
  }

  const char * metaImageFileName = argv[1];
  const char * pngFileName = argv[2];

  constexpr unsigned int Dimension = 2;

  using PixelType = unsigned char;
  using ImageType = itk::Image<PixelType, Dimension>;

  using ReaderType = itk::ImageFileReader<ImageType>;
  ReaderType::Pointer reader = ReaderType::New();

  using RegisteredObjectsContainerType = std::list<itk::LightObject::Pointer>;


  RegisteredObjectsContainerType registeredIOs = itk::ObjectFactoryBase::CreateAllInstance("itkImageIOBase");
  std::cout << "When CMake is not used to register the IO classes, there are\n"
            << registeredIOs.size() << " IO objects available to the ImageFileReader.\n"
            << std::endl;


  std::cout << "When we try to read a MetaImage, we will ";
  reader->SetFileName(metaImageFileName);
  try
  {
    reader->Update();
  }
  catch (itk::ImageFileReaderException &)
  {
    std::cout << "fail.\n" << std::endl;
  }


  std::cout << "After registering the MetaImageIO object, ";
  itk::MetaImageIOFactory::RegisterOneFactory();

  std::cout << "there are\n";
  registeredIOs = itk::ObjectFactoryBase::CreateAllInstance("itkImageIOBase");
  std::cout << registeredIOs.size() << " IO objects available to the ImageFileReader.\n" << std::endl;

  std::cout << "Now, when we try to read a MetaImage, we will ";
  try
  {
    reader->Update();
    std::cout << "succeed.\n" << std::endl;
  }
  catch (itk::ImageFileReaderException & error)
  {
    std::cerr << "Error: " << error << std::endl;
    return EXIT_FAILURE;
  }


  std::cout << "Every format desired to be supported by the reader\n"
            << "must be registered." << std::endl;
  itk::PNGImageIOFactory::RegisterOneFactory();
  reader->SetFileName(pngFileName);
  try
  {
    reader->Update();
  }
  catch (itk::ExceptionObject & error)
  {
    std::cerr << "Error: " << error << std::endl;
    return EXIT_FAILURE;
  }


  return EXIT_SUCCESS;
}
```

## Classes demonstrated

- template<typename `TOutputImage`, typename `ConvertPixelTraits` = DefaultConvertPixelTraits<*typename* [TOutputImage](https://itk.org/ITKExamples/src/IO/ImageBase/ConvertFileFormats/Documentation.html#_CPPv4I00EN3itk15ImageFileReaderE)::IOPixelType>> *class* `ImageFileReader` : *public* itk::[ImageSource](https://itk.org/ITKExamples/src/Core/Common/ProduceImageProgrammatically/Documentation.html#_CPPv4I0EN3itk11ImageSourceE)<[TOutputImage](https://itk.org/ITKExamples/src/IO/ImageBase/ConvertFileFormats/Documentation.html#_CPPv4I00EN3itk15ImageFileReaderE)> 

  Data source that reads image data from a single file.This source object is a general filter to read data from a variety of file formats. It works with a ImageIOBase subclass to actually do the reading of the data. Object factory machinery can be used to automatically create the ImageIOBase, or the ImageIOBase can be manually created and set. Note that this class reads data from a single file; if you wish to read data from a series of files use ImageSeriesReader.TOutputImage is the type expected by the external users of the filter. If data stored in the file is stored in a different format then specified by TOutputImage, than this filter converts data between the file type and the external expected type. The