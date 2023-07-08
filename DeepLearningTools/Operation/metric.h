#ifndef METRIC_H
#define METRIC_H

#include "resource.h"

class Metric : public Resource
{
public:
    explicit Metric(QObject *parent = nullptr);

    void add_resource();
    void del_resource();
    void edit_resource();
    void search_resource();

};

#endif // METRIC_H
