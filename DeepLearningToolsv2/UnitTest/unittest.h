#ifndef UNITTEST_H
#define UNITTEST_H

#include <QObject>

#include <Information/information.h>
#include <Information/spi.h>
#include <Information/stei.h>
#include <Information/stri.h>
#include <Operation/operation.h>
#include <Operation/configure.h>
#include <Operation/resource.h>
#include <Operation/test.h>
#include <Operation/train.h>

#include <QDebug>

// This class is used for testing of unit blocks.
// You can add this into the mainwindow.cpp before release.
// Remember to report which function you are testing when you call the test func.

class UnitTest : public QObject
{
    Q_OBJECT
public:
    explicit UnitTest(QObject *parent = nullptr);

    void test_generateSPI();
    void test_add_resource();
    void test_del_resource();

signals:

};

#endif // UNITTEST_H
