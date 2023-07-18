#include "train.h"

Train::Train(QObject *parent)
    : Operation{parent}
{

}

void Train::del_train_code(SPI &spi, QString name){

    QString cmd_temp = "rmdir /s /q " + spi.proj_path + "\\" + "train" + "\\" + name;
    system(cmd_temp.toStdString().c_str());

    spi.train_code_list.removeAll(name);

}

void Train::gene_train_code(SPI &spi, STrI &stri, QString name){

    // generate and paste



    // refresh list
    spi.train_code_list.append(name);

}

void Train::run_code(QString name){

    // use system cmd to run

}
