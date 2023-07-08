#include "dataset.h"

Dataset::Dataset(QObject *parent)
    : Resource{parent}
{

}

void Dataset::add_resource(){

    qDebug("添加数据集");

}

void Dataset::del_resource(){

    qDebug("删除数据集");

}

void Dataset::edit_resource(){

    qDebug("编辑数据集");

}

void Dataset::search_resource(){

    qDebug("查找数据集");

}
