#include "unittest.h"

UnitTest::UnitTest(QObject *parent)
    : QObject{parent}
{

}

void UnitTest::test_generateSPI(){

    // passed

    qDebug() << "===== Testing Configure::generateSPI() =====";

    QString proj_path = "G:\\cao\\ni\\ma\\proj\\";
    SPI spi;
    Configure config;
    config.generateSPI(spi,proj_path);
    qDebug() << "proj_path" << spi.proj_path;
    qDebug() << "proj_name" << spi.proj_name;  // This is wrong. It displayed the path.
    qDebug() << "dataset_list" << spi.dataset_list;
    qDebug() << "loss_list" << spi.loss_list;
    qDebug() << "model_list" <<spi.model_list;
    qDebug() << "lrsche_list" <<spi.lrsche_list;
    qDebug() << "metric_list" <<spi.metric_list;
    qDebug() << "optimizer_list" <<spi.optimizer_list;
    qDebug() << "train_code_list" << spi.train_code_list;
    qDebug() << "test_code_list" << spi.test_code_list;
}

void UnitTest::test_del_resource(){

    // passed

    qDebug() << "=====Testing Resource::del_resource()=====";

    QString proj_path = "G:\\cao\\ni\\ma\\proj\\";
    SPI spi;
    Configure config;
    config.generateSPI(spi,proj_path);

    qDebug() << "+++++Orinigial spi content+++++";
    qDebug() << "proj_path" << spi.proj_path;
    qDebug() << "proj_name" << spi.proj_name;  // This is wrong. It displayed the path.
    qDebug() << "dataset_list" << spi.dataset_list;
    qDebug() << "loss_list" << spi.loss_list;
    qDebug() << "model_list" <<spi.model_list;
    qDebug() << "lrsche_list" <<spi.lrsche_list;
    qDebug() << "metric_list" <<spi.metric_list;
    qDebug() << "optimizer_list" <<spi.optimizer_list;
    qDebug() << "train_code_list" << spi.train_code_list;
    qDebug() << "test_code_list" << spi.test_code_list;

    Resource res;
    res.del_resource(spi, "zhangsan", "model");
    qDebug() << "+++++removed zhangsan from model+++++";
    qDebug() << "proj_path" << spi.proj_path;
    qDebug() << "proj_name" << spi.proj_name;  // This is wrong. It displayed the path.
    qDebug() << "dataset_list" << spi.dataset_list;
    qDebug() << "loss_list" << spi.loss_list;
    qDebug() << "model_list" <<spi.model_list;
    qDebug() << "lrsche_list" <<spi.lrsche_list;
    qDebug() << "metric_list" <<spi.metric_list;
    qDebug() << "optimizer_list" <<spi.optimizer_list;
    qDebug() << "train_code_list" << spi.train_code_list;
    qDebug() << "test_code_list" << spi.test_code_list;


}

void UnitTest::test_add_resource(){

    // passed

    qDebug()<<"=====Testing Resource::add_resource()=====";

    QString proj_path = "G:\\cao\\ni\\ma\\proj\\";
    SPI spi;
    Configure config;
    config.generateSPI(spi,proj_path);

    qDebug() << "+++++Orinigial spi content+++++";
    qDebug() << "proj_path" << spi.proj_path;
    qDebug() << "proj_name" << spi.proj_name;  // This is wrong. It displayed the path.
    qDebug() << "dataset_list" << spi.dataset_list;
    qDebug() << "loss_list" << spi.loss_list;
    qDebug() << "model_list" <<spi.model_list;
    qDebug() << "lrsche_list" <<spi.lrsche_list;
    qDebug() << "metric_list" <<spi.metric_list;
    qDebug() << "optimizer_list" <<spi.optimizer_list;
    qDebug() << "train_code_list" << spi.train_code_list;
    qDebug() << "test_code_list" << spi.test_code_list;

    Resource res;
    res.add_resource(spi, "G:\\shabi", "happy", "dataset");

    qDebug() << "+++++added happy to dataset+++++";
    qDebug() << "proj_path" << spi.proj_path;
    qDebug() << "proj_name" << spi.proj_name;  // This is wrong. It displayed the path.
    qDebug() << "dataset_list" << spi.dataset_list;
    qDebug() << "loss_list" << spi.loss_list;
    qDebug() << "model_list" <<spi.model_list;
    qDebug() << "lrsche_list" <<spi.lrsche_list;
    qDebug() << "metric_list" <<spi.metric_list;
    qDebug() << "optimizer_list" <<spi.optimizer_list;
    qDebug() << "train_code_list" << spi.train_code_list;
    qDebug() << "test_code_list" << spi.test_code_list;

}
