#include "model.h"

Model::Model(QObject *parent)
    : Resource{parent}
{

}

void Model::add_resource(){

    qDebug("添加模型");

}

void Model::del_resource(){

    qDebug("删除模型");

}

void Model::edit_resource(){

    qDebug("编辑模型");

}

void Model::search_resource(){

    qDebug("查找模型");

}
