#ifndef MODEL_H
#define MODEL_H

#include "resource.h"

class Model : public Resource
{
public:
    explicit Model(QObject *parent = nullptr);

    void add_resource();
    void del_resource();
    void edit_resource();
    void search_resource();

};

#endif // MODEL_H
