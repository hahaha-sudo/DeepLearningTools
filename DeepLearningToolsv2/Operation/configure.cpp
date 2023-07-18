#include "configure.h"

#include <QStringList>
#include <QDir>
#include <QFileInfo>
#include <QFileInfoList>


Configure::Configure(QObject *parent)
    : Operation{parent}
{

}

void Configure::generateSPI(SPI &spi, QString proj_path){

    QDir root(proj_path);
    if(!root.exists()){
        qWarning() << "path not exits";
    }
    else{

        spi.proj_path = proj_path;  // 希望这里不要出现不让用拷贝构造函数的bug

        QStringList list_temp = proj_path.split(u'\\', Qt::SkipEmptyParts);
        spi.proj_name = list_temp.last();

        // fill the lists
        QDir dataset_root(proj_path + "/resource/dataset");
        QStringList dataset_info_list_temp = dataset_root.entryList(QDir::Filter::AllDirs | QDir::Filter::NoDotAndDotDot);
        foreach(QString name, dataset_info_list_temp){
            spi.dataset_list.append(name);
        }

        QDir model_root(proj_path + "/resource/model");
        QStringList model_info_list_temp = model_root.entryList(QDir::Filter::AllDirs | QDir::Filter::NoDotAndDotDot);
        foreach(QString name, model_info_list_temp){
            spi.model_list.append(name);
        }

        QDir optimizer_root(proj_path + "/resource/optimizer");
        QStringList optimizer_info_list_temp = optimizer_root.entryList(QDir::Filter::AllDirs | QDir::Filter::NoDotAndDotDot);
        foreach(QString name, optimizer_info_list_temp){
            spi.optimizer_list.append(name);
        }

        QDir metric_root(proj_path + "/resource/metric");
        QStringList metric_info_list_temp = metric_root.entryList(QDir::Filter::AllDirs | QDir::Filter::NoDotAndDotDot);
        foreach(QString name, metric_info_list_temp){
            spi.metric_list.append(name);
        }

        QDir loss_root(proj_path + "/resource/loss");
        QStringList loss_info_list_temp = loss_root.entryList(QDir::Filter::AllDirs | QDir::Filter::NoDotAndDotDot);
        foreach(QString name, loss_info_list_temp){
            spi.loss_list.append(name);
        }

        QDir lrsche_root(proj_path + "/resource/lrsche");
        QStringList lrsche_info_list_temp = lrsche_root.entryList(QDir::Filter::AllDirs | QDir::Filter::NoDotAndDotDot);
        foreach(QString name, lrsche_info_list_temp){
            spi.lrsche_list.append(name);
        }

        QDir train_root(proj_path + "/train");
        QStringList train_info_list_temp = train_root.entryList(QDir::Filter::AllDirs | QDir::Filter::NoDotAndDotDot);
        foreach(QString name, train_info_list_temp){
            spi.train_code_list.append(name);
        }

        QDir test_root(proj_path + "/test");
        QStringList test_info_list_temp = test_root.entryList(QDir::Filter::AllDirs | QDir::Filter::NoDotAndDotDot);
        foreach(QString name, test_info_list_temp){
            spi.test_code_list.append(name);
        }


    }


}

void Configure::test_generateSPI(QString test_field){

    // ongoing

    // test_field means where the test takes place
    // this function generates file trees automatically and delete all of them when ...
    // ... the test process finish

    qDebug() << "===== Testing generateSPI() =====";

    int test_example_total_num = 10;
    int passed_num = 0;

    Q_ASSERT(test_example_total_num > 0);

    for (int i=0;i<test_example_total_num;i++){

        // create standard_spi and generate files
        SPI standard_spi;


        // use generateSPI to generate SPI

        // compare SPI to ideal SPI to determine whether it passed

        // delete all files generated

    }

    float acc_rate = (float)passed_num / test_example_total_num;

    qDebug() << "===== Test result =====";
    qDebug() << "Total test example number " << test_example_total_num;
    qDebug() << "Examples passed " << passed_num;
    qDebug() << "Accuracy is " << acc_rate;

}
