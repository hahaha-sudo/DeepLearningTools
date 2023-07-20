#ifndef TESTOPERATION_H
#define TESTOPERATION_H

#include "unittest.h"

class TestOperation : public UnitTest
{

    // This class is specially used for test of class Operation.
    // This class has methods of class UnitTest.

public:
    explicit TestOperation(QObject *parent = nullptr);

    // Configure class
    void test_generateSPI_generateFolderTree(QString test_field);
    void test_refreshSPI(QString test_field);
    // Resource class
    void test_add_resource(QString test_field);  // ongoing
    void test_del_resource(QString test_field);  // ongoing
    // Test class

    // Train class


};

#endif // TESTOPERATION_H
