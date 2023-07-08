#include "optimizer.h"

Optimizer::Optimizer(QObject *parent)
    : Resource{parent}
{

}

void Optimizer::add_resource(){

    qDebug("添加优化器");

}

void Optimizer::del_resource(){

    qDebug("删除优化器");

}

void Optimizer::edit_resource(){

    qDebug("编辑优化器");

}

void Optimizer::search_resource(){

    qDebug("查找优化器");

}
