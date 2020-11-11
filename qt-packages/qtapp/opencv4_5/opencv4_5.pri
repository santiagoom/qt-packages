#win32{

#    INCLUDEPATH += $$PWD/./build/include/
#    DEPENDPATH += $$PWD/./build/include/

#    CONFIG(debug, debug|release){
#        LIBS += -L$$PWD/./build\x64\vc15\lib
#    }
#    CONFIG(release, debug|release) {
#        LIBS += -L$$PWD/./build\x64\vc15\lib
#    }

#    LIBS += \
#        -lopencv_world411
#}

win32{

    INCLUDEPATH += D:\lib\opencv4.5.0\opencv\build\include
    DEPENDPATH += D:\lib\opencv4.5.0\opencv\build\include

    CONFIG(debug, debug|release){
        LIBS += -LD:\lib\opencv4.5.0\opencv\build\x64\vc15\lib
    }
    CONFIG(release, debug|release) {
        LIBS += -LD:\lib\opencv4.5.0\opencv\build\x64\vc15\lib
    }

    LIBS += \
        -lopencv_world450d
}


#win32{

#    INCLUDEPATH += D:\lib\opencv4.5.0\opencv\build\include
#    DEPENDPATH += D:\lib\opencv4.5.0\opencv\build\include

#    CONFIG(debug, debug|release){
#        LIBS += -LD:\lib\opencv4.5.0\opencv\build\x64\vc15\lib
#    }
#    CONFIG(release, debug|release) {
#        LIBS += -LD:\lib\opencv4.5.0\opencv\build\x64\vc15\lib
#    }

#    LIBS += \
#        -lopencv_world450d
#}



#LIBS += -L$$(OPENCV_SDK_DIR)/x86/mingw/lib \
#        -lopencv_core320        \
#        -lopencv_highgui320     \
#        -lopencv_imgcodecs320   \
#        -lopencv_imgproc320     \
#        -lopencv_features2d320  \
#        -lopencv_calib3d320

#INCLUDEPATH += D:\lib\opencv4.5.0\opencv\build\include
#DEPENDPATH += D:\lib\opencv4.5.0\opencv\build\include
#LIBS += -LD:\lib\opencv4.5.0\opencv\build\x64\vc15\lib

#LIBS += -LD:\lib\opencv4.5.0\opencv\build\x64\vc15\lib -lopencv_core410d -lopencv_imgproc410d -lopencv_highgui410d -lopencv_imgcodecs410d -lopencv_videoio410d -lopencv_video410d -lopencv_calib3d410d -lopencv_photo410d -lopencv_features2d410d
#INCLUDEPATH += D:\lib\opencv4.5.0\opencv\build\include
#DEPENDPATH += D:\lib\opencv4.5.0\opencv\build\include

#win32{

#    INCLUDEPATH += D:\lib\opencv4.5.0\opencv\build\include
#    DEPENDPATH += D:\lib\opencv4.5.0\opencv\build\include

#    CONFIG(debug, debug|release){
#        LIBS += -LD:\lib\opencv4.5.0\opencv\build\x64\vc15\lib
#    }
#    CONFIG(release, debug|release) {
#        LIBS += -LD:\lib\opencv4.5.0\opencv\build\x64\vc15\lib
#    }

#    LIBS += \
#        -lopencv_world450d
#}


#win32{

#    INCLUDEPATH += $$PWD/./include/
#    DEPENDPATH += $$PWD/./include/

#    CONFIG(debug, debug|release){
#        LIBS += -L$$PWD/./lib/Debug
#    }
#    CONFIG(release, debug|release) {
#        LIBS += -L$$PWD/./lib/Release
#    }

#    LIBS += \
#        -lopencv_world411
#}

#DISTFILES += \
#    opencv4_5.pri




