#ifndef TEST_H
#define TEST_H

#include "operation.h"

#include <Information/spi.h>
#include <Information/stei.h>

class Test : public Operation
{
public:
    explicit Test(QObject *parent = nullptr);

    void del_test_code(SPI &spi, QString name);
    void gene_test_code(SPI &spi, STeI &stei, QString name);
    void run_code(QString name);

};

#endif // TEST_H
