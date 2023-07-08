#ifndef DATASET_H
#define DATASET_H

#include "resource.h"

class Dataset : public Resource
{
public:
    explicit Dataset(QObject *parent = nullptr);

    void add_resource();
    void del_resource();
    void edit_resource();
    void search_resource();

};

#endif // DATASET_H
