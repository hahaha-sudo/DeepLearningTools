#ifndef STRI_H
#define STRI_H

#include "information.h"

#include <QString>
#include <QVector>

class STrI : public Information
{
public:
    explicit STrI(QObject *parent = nullptr);

    QString train_code_name;
    QString dataset_name;
    QString model_name;
    QString optimizer_name;
    QString metric_name;
    QString loss_name;
    QVector<QString> metric_name_list;
    int epoch_number = 0;
    int batch_size = 0;
    float learning_rate = 0;

};

#endif // STRI_H
