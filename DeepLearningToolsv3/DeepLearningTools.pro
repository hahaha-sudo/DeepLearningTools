QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Information/information.cpp \
    Information/spi.cpp \
    Information/stei.cpp \
    Information/stri.cpp \
    Operation/configure.cpp \
    Operation/operation.cpp \
    Operation/resource.cpp \
    Operation/test.cpp \
    Operation/train.cpp \
    UnitTest/testoperation.cpp \
    UnitTest/unittest.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    Information/information.h \
    Information/spi.h \
    Information/stei.h \
    Information/stri.h \
    Operation/configure.h \
    Operation/operation.h \
    Operation/resource.h \
    Operation/test.h \
    Operation/train.h \
    UnitTest/testoperation.h \
    UnitTest/unittest.h \
    mainwindow.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
