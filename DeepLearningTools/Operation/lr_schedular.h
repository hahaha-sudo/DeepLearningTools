#ifndef LR_SCHEDULAR_H
#define LR_SCHEDULAR_H

#include "resource.h"

class Lr_schedular : public Resource
{
public:
    explicit Lr_schedular(QObject *parent = nullptr);

    void add_resource();
    void del_resource();
    void edit_resource();
    void search_resource();

};

#endif // LR_SCHEDULAR_H
