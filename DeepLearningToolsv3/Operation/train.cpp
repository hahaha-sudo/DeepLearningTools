#include "train.h"

#include <QDebug>
#include <Operation/configure.h>

Train::Train(QObject *parent)
    : Operation{parent}
{

}

void Train::del_train_code(SPI &spi, QString name){

    if(!spi.train_code_list.contains(name)){
        qDebug() << "Warning: this name not exist in train";
    }
    else{
        QString cmd_temp = "rmdir /s /q " + spi.proj_path + "\\" + "train" + "\\" + name;
        system(cmd_temp.toStdString().c_str());

        Configure config;
        config.refreshSPI(spi);
    }



}

void Train::gene_train_code(SPI &spi, STrI &stri, QString name){

    // generate and paste



    // refresh list
    spi.train_code_list.append(name);

}

void Train::run_code(QString name){

    // use system cmd to run

}
