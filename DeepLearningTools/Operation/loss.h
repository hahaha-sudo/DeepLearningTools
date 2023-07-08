#ifndef LOSS_H
#define LOSS_H

#include "resource.h"

class Loss : public Resource
{
public:
    explicit Loss(QObject *parent = nullptr);

    void add_resource();
    void del_resource();
    void edit_resource();
    void search_resource();

};

#endif // LOSS_H
