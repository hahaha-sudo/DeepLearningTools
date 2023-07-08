#include "resource.h"

Resource::Resource(QObject *parent)
    : Operation{parent}
{
    this -> source_file_path = NULL;
    this -> target_file_path = NULL;
}

void Resource::edit_source_file_path(QString input){

    this -> source_file_path = input;

}

void Resource::edit_target_file_path(QString input){

    this -> target_file_path = input;

}

QString Resource::get_source_file_path(){

    return this -> source_file_path;

}

QString Resource::get_target_file_path(){

    return this -> target_file_path;

}

void Resource::add_resource(){

    qDebug("添加资源");

}

void Resource::del_resource(){

    qDebug("删除资源");

}

void Resource::edit_resource(){

    qDebug("编辑资源");

}

void Resource::search_resource(){

    qDebug("搜索资源");

}
