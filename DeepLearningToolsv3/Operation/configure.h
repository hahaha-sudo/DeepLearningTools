#ifndef CONFIGURE_H
#define CONFIGURE_H

#include "operation.h"

#include <Information/spi.h>
#include <QString>

class Configure : public Operation
{
public:
    explicit Configure(QObject *parent = nullptr);

    // functionality
    void generateSPI(SPI &spi, QString proj_path);
    void generateFolderTree(SPI &spi);
    void refreshSPI(SPI &spi);
    void cleanSPI(SPI &spi);
    void copySPI(SPI &spi_to, SPI &spi_from);  // 从from拷贝到to

    // check
    bool SPI_path_exist(SPI &spi);
    bool SPI_proj_name_correct(SPI &spi);
    bool SPI_dataset_list_empty(SPI &spi);
    bool SPI_dataset_list_duplicate(SPI &spi);
    bool SPI_model_list_empty(SPI &spi);
    bool SPI_model_list_duplicate(SPI &spi);
    bool SPI_optimizer_list_empty(SPI &spi);
    bool SPI_optimizer_list_duplicate(SPI &spi);
    bool SPI_metric_list_empty(SPI &spi);
    bool SPI_metric_list_duplicate(SPI &spi);
    bool SPI_loss_list_empty(SPI &spi);
    bool SPI_loss_list_duplicate(SPI &spi);
    bool SPI_lrsche_list_empty(SPI &spi);
    bool SPI_lrsche_list_duplicate(SPI &spi);
    bool SPI_train_code_list_empty(SPI &spi);
    bool SPI_train_code_list_duplicate(SPI &spi);
    bool SPI_test_code_list_empty(SPI &spi);
    bool SPI_test_code_list_duplicate(SPI &spi);

    bool SPI_ok(SPI &spi);
    bool SPI_partial_ok(SPI &spi);    // Allow some lists to be empty.

};

#endif // CONFIGURE_H
