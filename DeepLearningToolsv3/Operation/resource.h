#ifndef RESOURCE_H
#define RESOURCE_H

#include "operation.h"
#include <Information/spi.h>

class Resource : public Operation
{
public:
    explicit Resource(QObject *parent = nullptr);

    // add_resource: add resource to a category and refresh spi
    // del_resource: delete resource of a category and refresh spi

    void add_resource(SPI &spi, QString file_path, QString name, QString category);
    void del_resource(SPI &spi, QString name, QString category);

    bool isInside(SPI &spi, QString name, QString category);
    // 确定某个类别的东西里面有没有名字为name的对象

};

#endif // RESOURCE_H
