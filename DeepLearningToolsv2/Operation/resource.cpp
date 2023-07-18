#include "resource.h"

#include <QDir>

Resource::Resource(QObject *parent)
    : Operation{parent}
{

}

void Resource::add_resource(SPI &spi, QString file_path, QString name, QString category){

    // I dont wanna talk about the defensive coding
    // make a new dir
    QString cmd_temp = "mkdir " + spi.proj_path + "\\resource\\" + category +"\\" +name;
    system(cmd_temp.toStdString().c_str());

    // copy
    cmd_temp = "xcopy " + file_path + " " + spi.proj_path + "\\resource\\" + category + "\\" + name + " /e";
    system(cmd_temp.toStdString().c_str());

    // refresh spi info
    if(category == "dataset"){
        spi.dataset_list.append(name);
    }
    else if(category == "model"){
        spi.model_list.append(name);
    }
    else if(category == "optimizer"){
        spi.optimizer_list.append(name);
    }
    else if(category == "metric"){
        spi.metric_list.append(name);
    }
    else if(category == "loss"){
        spi.loss_list.append(name);
    }
    else if(category == "lrsche"){
        spi.lrsche_list.append(name);
    }
    else{
        qDebug() << "没有这个类别，你输入的不对";
    }

}

void Resource::del_resource(SPI &spi, QString name, QString category){

    QString cmd_temp = "rmdir /s /q " + spi.proj_path + "\\resource\\" + category + "\\" + name;
    system(cmd_temp.toStdString().c_str());

    if(category == "dataset"){
        spi.dataset_list.removeAll(name);
    }
    else if(category == "model"){
        spi.model_list.removeAll(name);
    }
    else if(category == "optimizer"){
        spi.optimizer_list.removeAll(name);
    }
    else if(category == "metric"){
        spi.metric_list.removeAll(name);
    }
    else if(category == "loss"){
        spi.loss_list.removeAll(name);
    }
    else if(category == "lrsche"){
        spi.lrsche_list.removeAll(name);
    }
    else{
        qDebug() << "没有这个类别，你输入的不对";
    }

}
