#ifndef STEI_H
#define STEI_H

#include "information.h"

#include <QString>
#include <QVector>

class STeI : public Information
{
public:
    explicit STeI(QObject *parent = nullptr);

    QString test_code_name;
    QString dataset_name;
    QString model_name;
    QString model_pkl_path;
    int batch_size = 0;
    QVector<QString> metric_name_list;

};

#endif // STEI_H
