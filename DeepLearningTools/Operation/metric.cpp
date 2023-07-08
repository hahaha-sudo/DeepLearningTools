#include "metric.h"

Metric::Metric(QObject *parent)
    : Resource{parent}
{

}

void Metric::add_resource(){

    qDebug("添加指标");

}

void Metric::del_resource(){

    qDebug("删除指标");

}

void Metric::edit_resource(){

    qDebug("编辑指标");

}

void Metric::search_resource(){

    qDebug("查找指标");

}
