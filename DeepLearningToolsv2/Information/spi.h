#ifndef SPI_H
#define SPI_H

#include "information.h"

#include <QString>
#include <QVector>

class SPI : public Information
{
public:
    explicit SPI(QObject *parent = nullptr);

    QString proj_name;
    QString proj_path;
    QVector<QString> dataset_list;
    QVector<QString> model_list;
    QVector<QString> optimizer_list;
    QVector<QString> metric_list;
    QVector<QString> loss_list;
    QVector<QString> lrsche_list;
    QVector<QString> train_code_list;
    QVector<QString> test_code_list;

};

#endif // SPI_H
