#include "test.h"

#include <Operation/configure.h>
#include <QDebug>

Test::Test(QObject *parent)
    : Operation{parent}
{

}

void Test::del_test_code(SPI &spi, QString name){

    if(!spi.test_code_list.contains(name)){
        qDebug() << "Warning: this name not exist in test";
    }
    else{
        QString cmd_temp = "rmdir /s /q " + spi.proj_path + "\\" + "test" + "\\" + name;
        system(cmd_temp.toStdString().c_str());

        Configure config;
        config.refreshSPI(spi);
    }

}

void Test::gene_test_code(SPI &spi, STeI &stei, QString name){

    // generate and paste



    // refresh list
    spi.test_code_list.append(name);

}

void Test::run_code(QString name){

    // use system cmd to run

}
