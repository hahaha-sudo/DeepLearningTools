#ifndef RESOURCE_H
#define RESOURCE_H

#include "operation.h"

class Resource : public Operation
{


public:
    explicit Resource(QObject *parent = nullptr);

    QString source_file_path;
    QString target_file_path;

    void edit_source_file_path(QString input);
    void edit_target_file_path(QString input);
    QString get_source_file_path();
    QString get_target_file_path();

    void add_resource();
    void del_resource();
    void edit_resource();
    void search_resource();

};

#endif // RESOURCE_H
