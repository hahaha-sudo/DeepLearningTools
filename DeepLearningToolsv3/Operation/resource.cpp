#include "resource.h"

#include <QDir>

#include <Operation/configure.h>

Resource::Resource(QObject *parent)
    : Operation{parent}
{

}

void Resource::add_resource(SPI &spi, QString file_path, QString name, QString category){

    if(isInside(spi,name,category)){
        qDebug() << "Warning: already exists!";
    }
    else{

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

}

void Resource::del_resource(SPI &spi, QString name, QString category){

    if(!isInside(spi,name,category)){
        qDebug() << "Warning: not exist";
    }
    else{
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
            qDebug() << "Warning: 没有这个类别，你输入的不对";
        }
    }

}

bool Resource::isInside(SPI &spi, QString name, QString category){

    Configure config;
    Q_ASSUME(config.SPI_partial_ok(spi));

    if(category == "dataset")
        return spi.dataset_list.contains(name);
    else if(category=="model")
        return spi.model_list.contains(name);
    else if(category=="optimizer")
        return spi.optimizer_list.contains(name);
    else if(category=="metric")
        return spi.metric_list.contains(name);
    else if(category=="loss")
        return spi.loss_list.contains(name);
    else if(category=="lrsche")
        return spi.lrsche_list.contains(name);
    else{
        qDebug() << "Warning: category exceeded";
        return false;
    }

}
