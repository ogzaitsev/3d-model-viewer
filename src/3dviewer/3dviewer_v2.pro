QT       += core gui opengl concurrent

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets openglwidgets
isEqual(QT_MAJOR_VERSION, 5): LIBS += -lGLU

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    controller/Controller.cc \
    main.cc \
    model/DataBuilder.cc \
    model/Facade.cc \
    model/ObjFileReader.cc \
    model/TransformContext.cc \
    model/strategy/MoveStrategy.cc \
    model/strategy/RotateStrategy.cc \
    model/strategy/ScaleStrategy.cc \
    view/Scene.cc

HEADERS += \
    controller/Controller.h \
    model/Data3D.h \
    model/DataBuilder.h \
    model/Facade.h \
    model/ObjFileReader.h \
    model/TransformContext.h \
    model/strategy/MoveStrategy.h \
    model/strategy/RotateStrategy.h \
    model/strategy/ScaleStrategy.h \
    model/strategy/TransformStrategy.h \
    view/Scene.h

FORMS += \
    view/view.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
