#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QMenu>
#include <QMenuBar>
#include <QAction>
#include <QFileDialog>

#include "Operation/code.h"
#include "Operation/dataset.h"
#include "Operation/loss.h"
#include "Operation/lr_schedular.h"
#include "Operation/metric.h"
#include "Operation/model.h"
#include "Operation/optimizer.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    // 菜单栏
    QMenu *pMenuCode;
    QAction *pCodeGenerate;
    QAction *pTrainResultGenerate;
    QAction *pTestResultGenerate;

    QMenu *pMenuResource;

    QMenu *pModel;
    QAction *pModelAdd;
    QAction *pModelDel;
    QAction *pModelEdit;
    QAction *pModelSearch;

    QMenu *pDataset;
    QAction *pDatasetAdd;
    QAction *pDatasetDel;
    QAction *pDatasetEdit;
    QAction *pDatasetSearch;

    QMenu *pOptimizer;
    QAction *pOptimizerAdd;
    QAction *pOptimizerDel;
    QAction *pOptimizerEdit;
    QAction *pOptimizerSearch;

    QMenu *pLrSchedular;
    QAction *pLrSchedularAdd;
    QAction *pLrSchedularDel;
    QAction *pLrSchedularEdit;
    QAction *pLrSchedularSearch;

    QMenu *pMetric;
    QAction *pMetricAdd;
    QAction *pMetricDel;
    QAction *pMetricEdit;
    QAction *pMetricSearch;

    QMenu *pLoss;
    QAction *pLossAdd;
    QAction *pLossDel;
    QAction *pLossEdit;
    QAction *pLossSearch;

    // 点击菜单栏后的动作

    Code *pCodeOperation;
    Dataset *pDatasetOperation;
    Loss *pLossOperation;
    Lr_schedular *pLrSchedularOperation;
    Metric *pMetricOperation;
    Model *pModelOperation;
    Optimizer *pOptimizerOperation;

};
#endif // MAINWINDOW_H
