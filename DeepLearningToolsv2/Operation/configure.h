#ifndef CONFIGURE_H
#define CONFIGURE_H

#include "operation.h"

#include <Information/spi.h>
#include <QString>

class Configure : public Operation
{
public:
    explicit Configure(QObject *parent = nullptr);

    // functions for usage
    void generateSPI(SPI &spi, QString proj_path);

    // test the above functions
    void test_generateSPI(QString test_field);

};

#endif // CONFIGURE_H
