#ifndef TRAIN_H
#define TRAIN_H

#include "operation.h"

#include <Information/spi.h>
#include <Information/stri.h>

class Train : public Operation
{
public:
    explicit Train(QObject *parent = nullptr);

    // del_train_code: delete train script and refresh the spi
    // gene_train_code: generate new train script accoring to the stri given by
    // the user. It has the name given by the user.
    // run_code: run the train script with name given by the user.
    void del_train_code(SPI &spi,QString name);
    void gene_train_code(SPI &spi, STrI &stri, QString name);
    void run_code(QString name);

};

#endif // TRAIN_H
