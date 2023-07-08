QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Operation/code.cpp \
    Operation/dataset.cpp \
    Operation/loss.cpp \
    Operation/lr_schedular.cpp \
    Operation/metric.cpp \
    Operation/model.cpp \
    Operation/operation.cpp \
    Operation/optimizer.cpp \
    Operation/resource.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    Operation/code.h \
    Operation/dataset.h \
    Operation/loss.h \
    Operation/lr_schedular.h \
    Operation/metric.h \
    Operation/model.h \
    Operation/operation.h \
    Operation/optimizer.h \
    Operation/resource.h \
    mainwindow.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

