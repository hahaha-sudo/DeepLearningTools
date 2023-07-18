#include "test.h"

Test::Test(QObject *parent)
    : Operation{parent}
{

}

void Test::del_test_code(SPI &spi, QString name){

    QString cmd_temp = "rmdir /s /q " + spi.proj_path + "\\" + "test" + "\\" + name;
    system(cmd_temp.toStdString().c_str());

    spi.test_code_list.removeAll(name);

}

void Test::gene_test_code(SPI &spi, STeI &stei, QString name){

    // generate and paste



    // refresh list
    spi.test_code_list.append(name);

}

void Test::run_code(QString name){

    // use system cmd to run

}
