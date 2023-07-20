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

        cleanSPI(spi);

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

void Configure::generateFolderTree(SPI &spi){

    // Q_ASSUME(SPI_partial_ok(spi));

    QDir root(spi.proj_path);
    if(root.exists()){
        qDebug() << "Warning: folder already exists";
    }
    else if(root.mkpath(spi.proj_path)){

        root.mkpath(spi.proj_path + "\\resource\\dataset");
        root.mkpath(spi.proj_path + "\\resource\\model");
        root.mkpath(spi.proj_path + "\\resource\\optimizer");
        root.mkpath(spi.proj_path + "\\resource\\metric");
        root.mkpath(spi.proj_path + "\\resource\\loss");
        root.mkpath(spi.proj_path + "\\resource\\lrsche");
        root.mkpath(spi.proj_path + "\\train");
        root.mkpath(spi.proj_path + "\\test");

        foreach(QString name, spi.dataset_list){
            root.mkpath(spi.proj_path + "\\resource\\dataset\\" + name);
        }
        foreach(QString name, spi.model_list){
            root.mkpath(spi.proj_path + "\\resource\\model\\" + name);
        }
        foreach(QString name, spi.optimizer_list){
            root.mkpath(spi.proj_path + "\\resource\\optimizer\\" + name);
        }
        foreach(QString name, spi.metric_list){
            root.mkpath(spi.proj_path + "\\resource\\metric\\" + name);
        }
        foreach(QString name, spi.loss_list){
            root.mkpath(spi.proj_path + "\\resource\\loss\\" + name);
        }
        foreach(QString name, spi.lrsche_list){
            root.mkpath(spi.proj_path + "\\resource\\lrsche\\" + name);
        }
        foreach(QString name, spi.train_code_list){
            root.mkpath(spi.proj_path + "\\train\\" + name);
        }
        foreach(QString name, spi.test_code_list){
            root.mkpath(spi.proj_path + "\\test\\" + name);
        }

    }
    else{
        qDebug() << "Warning: Directory create failed";
    }

}

void Configure::refreshSPI(SPI &spi){

    QString proj_path_temp = spi.proj_path;
    generateSPI(spi,proj_path_temp);

}

bool Configure::SPI_path_exist(SPI &spi){

    QDir root(spi.proj_path);
    return root.exists();

}

bool Configure::SPI_proj_name_correct(SPI &spi){

    // Q_ASSUME(SPI_path_exist(spi));

    QString temp_str = spi.proj_path;

    QStringList list_temp = temp_str.split(u'\\', Qt::SkipEmptyParts);
    QString correct_name = list_temp.last();

    return correct_name == spi.proj_name;

}

bool Configure::SPI_dataset_list_empty(SPI &spi){

    return spi.dataset_list.isEmpty();

}

bool Configure::SPI_dataset_list_duplicate(SPI &spi){

    // If this list is empty, we assume that it has no duplicate elements.
    if(SPI_dataset_list_empty(spi)){
        return false;
    }
    else{
        bool isDuplicate = false;

        for (QVector<QString>::Iterator iter=spi.dataset_list.begin();
             iter!=spi.dataset_list.end();iter++){
            for (QVector<QString>::Iterator iter_2=iter+1;
                 iter_2!=spi.dataset_list.end();iter_2++){
                if(*iter_2==*iter){
                    isDuplicate = true;
                }
            }
        }

        return isDuplicate;
    }

}

bool Configure::SPI_model_list_empty(SPI &spi){

    return spi.model_list.isEmpty();

}

bool Configure::SPI_model_list_duplicate(SPI &spi){

    // If this list is empty, we assume that it has no duplicate elements.
    if(SPI_model_list_empty(spi)){
        return false;
    }
    else{
        bool isDuplicate = false;
        for (QVector<QString>::Iterator iter=spi.model_list.begin();
             iter!=spi.model_list.end();iter++){
            for (QVector<QString>::Iterator iter_2=iter+1;
                 iter_2!=spi.model_list.end();iter_2++){
                if(*iter_2==*iter){
                    isDuplicate = true;
                }
            }
        }
        return isDuplicate;
    }

}

bool Configure::SPI_optimizer_list_empty(SPI &spi){

    return spi.optimizer_list.isEmpty();

}

bool Configure::SPI_optimizer_list_duplicate(SPI &spi){

    // If this list is empty, we assume that it has no duplicate elements.
    if(SPI_optimizer_list_empty(spi)){
        return false;
    }
    else{
        bool isDuplicate = false;

        for (QVector<QString>::Iterator iter=spi.optimizer_list.begin();
             iter!=spi.optimizer_list.end();iter++){
            for (QVector<QString>::Iterator iter_2=iter+1;
                 iter_2!=spi.optimizer_list.end();iter_2++){
                if(*iter_2==*iter){
                    isDuplicate = true;
                }
            }
        }

        return isDuplicate;
    }

}

bool Configure::SPI_metric_list_empty(SPI &spi){

    return spi.metric_list.isEmpty();

}

bool Configure::SPI_metric_list_duplicate(SPI &spi){

    // If this list is empty, we assume that it has no duplicate elements.
    if(SPI_metric_list_empty(spi)){
        return false;
    }
    else{
        bool isDuplicate = false;

        for (QVector<QString>::Iterator iter=spi.metric_list.begin();
             iter!=spi.metric_list.end();iter++){
            for (QVector<QString>::Iterator iter_2=iter+1;
                 iter_2!=spi.metric_list.end();iter_2++){
                if(*iter_2==*iter){
                    isDuplicate = true;
                }
            }
        }

        return isDuplicate;
    }

}

bool Configure::SPI_loss_list_empty(SPI &spi){

    return spi.loss_list.isEmpty();

}

bool Configure::SPI_loss_list_duplicate(SPI &spi){

    // If this list is empty, we assume that it has no duplicate elements.
    if(SPI_loss_list_empty(spi)){
        return false;
    }
    else{
        bool isDuplicate = false;

        for (QVector<QString>::Iterator iter=spi.loss_list.begin();
             iter!=spi.loss_list.end();iter++){
            for (QVector<QString>::Iterator iter_2=iter+1;
                 iter_2!=spi.loss_list.end();iter_2++){
                if(*iter_2==*iter){
                    isDuplicate = true;
                }
            }
        }

        return isDuplicate;
    }

}

bool Configure::SPI_lrsche_list_empty(SPI &spi){

    return spi.lrsche_list.isEmpty();

}

bool Configure::SPI_lrsche_list_duplicate(SPI &spi){

    // If this list is empty, we assume that it has no duplicate elements.
    if(SPI_lrsche_list_empty(spi)){
        return false;
    }
    else{
        bool isDuplicate = false;

        for (QVector<QString>::Iterator iter=spi.lrsche_list.begin();
             iter!=spi.lrsche_list.end();iter++){
            for (QVector<QString>::Iterator iter_2=iter+1;
                 iter_2!=spi.lrsche_list.end();iter_2++){
                if(*iter_2==*iter){
                    isDuplicate = true;
                }
            }
        }

        return isDuplicate;
    }

}

bool Configure::SPI_train_code_list_empty(SPI &spi){

    return spi.train_code_list.isEmpty();

}

bool Configure::SPI_train_code_list_duplicate(SPI &spi){

    // If this list is empty, we assume that it has no duplicate elements.
    if(SPI_train_code_list_empty(spi)){
        return false;
    }
    else{
        bool isDuplicate = false;

        for (QVector<QString>::Iterator iter=spi.train_code_list.begin();
             iter!=spi.train_code_list.end();iter++){
            for (QVector<QString>::Iterator iter_2=iter+1;
                 iter_2!=spi.train_code_list.end();iter_2++){
                if(*iter_2==*iter){
                    isDuplicate = true;
                }
            }
        }

        return isDuplicate;
    }

}

bool Configure::SPI_test_code_list_empty(SPI &spi){

    return spi.test_code_list.isEmpty();

}

bool Configure::SPI_test_code_list_duplicate(SPI &spi){

    // If this list is empty, we assume that it has no duplicate elements.
    if(SPI_test_code_list_empty(spi)){
        return false;
    }
    else{
        bool isDuplicate = false;

        for (QVector<QString>::Iterator iter=spi.test_code_list.begin();
             iter!=spi.test_code_list.end();iter++){
            for (QVector<QString>::Iterator iter_2=iter+1;
                 iter_2!=spi.test_code_list.end();iter_2++){
                if(*iter_2==*iter){
                    isDuplicate = true;
                }
            }
        }

        return isDuplicate;
    }

}

bool Configure::SPI_ok(SPI &spi){

    bool ok = true;

    if (!SPI_path_exist(spi))
        ok=false;
    else if(!SPI_proj_name_correct(spi))
        ok=false;
    else if(SPI_dataset_list_empty(spi))
        ok=false;
    else if(SPI_dataset_list_duplicate(spi))
        ok=false;
    else if(SPI_model_list_empty(spi))
        ok=false;
    else if(SPI_model_list_duplicate(spi))
        ok=false;
    else if(SPI_optimizer_list_empty(spi))
        ok=false;
    else if(SPI_optimizer_list_duplicate(spi))
        ok=false;
    else if(SPI_metric_list_empty(spi))
        ok=false;
    else if(SPI_metric_list_duplicate(spi))
        ok=false;
    else if(SPI_loss_list_empty(spi))
        ok=false;
    else if(SPI_loss_list_duplicate(spi))
        ok=false;
    else if(SPI_lrsche_list_empty(spi))
        ok=false;
    else if(SPI_lrsche_list_duplicate(spi))
        ok=false;
    else if(SPI_train_code_list_empty(spi))
        ok=false;
    else if(SPI_train_code_list_duplicate(spi))
        ok=false;
    else if(SPI_test_code_list_empty(spi))
        ok=false;
    else if(SPI_test_code_list_duplicate(spi))
        ok=false;

    return ok;

}

bool Configure::SPI_partial_ok(SPI &spi){

    bool ok = true;

    if (!SPI_path_exist(spi))
        ok=false;
    else if(!SPI_proj_name_correct(spi))
        ok=false;

    else if(SPI_dataset_list_duplicate(spi))
        ok=false;

    else if(SPI_model_list_duplicate(spi))
        ok=false;

    else if(SPI_optimizer_list_duplicate(spi))
        ok=false;

    else if(SPI_metric_list_duplicate(spi))
        ok=false;

    else if(SPI_loss_list_duplicate(spi))
        ok=false;

    else if(SPI_lrsche_list_duplicate(spi))
        ok=false;

    else if(SPI_train_code_list_duplicate(spi))
        ok=false;

    else if(SPI_test_code_list_duplicate(spi))
        ok=false;

    return ok;

}

void Configure::cleanSPI(SPI &spi){

    spi.proj_name="";
    spi.proj_path="";
    spi.dataset_list.clear();
    spi.model_list.clear();
    spi.optimizer_list.clear();
    spi.metric_list.clear();
    spi.loss_list.clear();
    spi.lrsche_list.clear();
    spi.train_code_list.clear();
    spi.test_code_list.clear();

}

void Configure::copySPI(SPI &spi_to, SPI &spi_from){

    spi_to.proj_name = spi_from.proj_name;
    spi_to.proj_path = spi_from.proj_path;
    spi_to.dataset_list = spi_from.dataset_list;
    spi_to.model_list = spi_from.model_list;
    spi_to.optimizer_list = spi_from.optimizer_list;
    spi_to.metric_list = spi_from.metric_list;
    spi_to.loss_list = spi_from.loss_list;
    spi_to.lrsche_list = spi_from.lrsche_list;
    spi_to.train_code_list = spi_from.train_code_list;
    spi_to.test_code_list = spi_from.test_code_list;

}
