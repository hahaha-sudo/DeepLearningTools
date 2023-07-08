#ifndef OPTIMIZER_H
#define OPTIMIZER_H

#include "resource.h"

class Optimizer : public Resource
{
public:
    explicit Optimizer(QObject *parent = nullptr);

    void add_resource();
    void del_resource();
    void edit_resource();
    void search_resource();

};

#endif // OPTIMIZER_H
