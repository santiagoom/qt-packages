unix:!macx{
    INCLUDEPATH += ../third_party/onnxruntime/1.13.1/include

    LIBS += -L../third_party/onnxruntime/1.13.1/lib/

    LIBS += -lonnxruntime
}
mac*{

    INCLUDEPATH += ../third_party/onnxruntime/1.13.1/include

    LIBS += -L../third_party/onnxruntime/1.13.1/lib/

    LIBS += -lonnxruntime

}

win32{
    INCLUDEPATH += ../ThirdParty/onnxruntime/1.13.1-tensorrt/include

    LIBS += -L$$PWD/ThirdParty/onnxruntime/1.13.1-tensorrt/lib/

    LIBS += -lonnxruntime -ld3d12 -lonnxruntime_providers_cuda -lonnxruntime_providers_shared -lonnxruntime_providers_tensorrt
}



