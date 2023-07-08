#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Operation/code.cpp"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // 生成菜单栏

    pMenuCode = new QMenu("代码");
    ui -> menubar -> addMenu(pMenuCode);

    pCodeGenerate = new QAction("生成");
    pMenuCode -> addAction(pCodeGenerate);
    pTrainResultGenerate = new QAction("训练");
    pMenuCode -> addAction(pTrainResultGenerate);
    pTestResultGenerate = new QAction("测试");
    pMenuCode -> addAction(pTestResultGenerate);

    pMenuResource = new QMenu("资源");
    ui -> menubar -> addMenu(pMenuResource);

    pModel = new QMenu("模型");
    pMenuResource -> addMenu(pModel);
    pModelAdd = new QAction("添加");
    pModel -> addAction(pModelAdd);
    pModelDel = new QAction("删除");
    pModel -> addAction(pModelDel);
    pModelEdit = new QAction("编辑");
    pModel -> addAction(pModelEdit);
    pModelSearch = new QAction("查找");
    pModel -> addAction(pModelSearch);

    pDataset = new QMenu("数据集");
    pMenuResource -> addMenu(pDataset);
    pDatasetAdd = new QAction("添加");
    pDataset -> addAction(pDatasetAdd);
    pDatasetDel = new QAction("删除");
    pDataset -> addAction(pDatasetDel);
    pDatasetEdit = new QAction("编辑");
    pDataset -> addAction(pDatasetEdit);
    pDatasetSearch = new QAction("查找");
    pDataset -> addAction(pDatasetSearch);

    pOptimizer = new QMenu("优化器");
    pMenuResource -> addMenu(pOptimizer);
    pOptimizerAdd = new QAction("添加");
    pOptimizer -> addAction(pOptimizerAdd);
    pOptimizerDel = new QAction("删除");
    pOptimizer -> addAction(pOptimizerDel);
    pOptimizerEdit = new QAction("编辑");
    pOptimizer -> addAction(pOptimizerEdit);
    pOptimizerSearch = new QAction("查找");
    pOptimizer -> addAction(pOptimizerSearch);

    pLrSchedular = new QMenu("学习率规划器");
    pMenuResource -> addMenu(pLrSchedular);
    pLrSchedularAdd = new QAction("添加");
    pLrSchedular -> addAction(pLrSchedularAdd);
    pLrSchedularDel = new QAction("删除");
    pLrSchedular -> addAction(pLrSchedularDel);
    pLrSchedularEdit = new QAction("编辑");
    pLrSchedular -> addAction(pLrSchedularEdit);
    pLrSchedularSearch = new QAction("查找");
    pLrSchedular -> addAction(pLrSchedularSearch);

    pMetric = new QMenu("指标");
    pMenuResource -> addMenu(pMetric);
    pMetricAdd = new QAction("添加");
    pMetric -> addAction(pMetricAdd);
    pMetricDel = new QAction("删除");
    pMetric -> addAction(pMetricDel);
    pMetricEdit = new QAction("编辑");
    pMetric -> addAction(pMetricEdit);
    pMetricSearch = new QAction("查找");
    pMetric -> addAction(pMetricSearch);

    pLoss = new QMenu("损失函数");
    pMenuResource -> addMenu(pLoss);
    pLossAdd = new QAction("添加");
    pLoss -> addAction(pLossAdd);
    pLossDel = new QAction("删除");
    pLoss -> addAction(pLossDel);
    pLossEdit = new QAction("编辑");
    pLoss -> addAction(pLossEdit);
    pLossSearch = new QAction("查找");
    pLoss -> addAction(pLossSearch);

    // 为菜单栏连接槽函数

    pCodeOperation = new Code();
    connect(pCodeGenerate,&QAction::triggered,pCodeOperation,&Code::code_generate);
    connect(pTrainResultGenerate,&QAction::triggered,pCodeOperation,&Code::train_result_generate);
    connect(pTestResultGenerate,&QAction::triggered,pCodeOperation,&Code::test_result_generate);

    pDatasetOperation = new Dataset();
    connect(pDatasetAdd,&QAction::triggered,pDatasetOperation,&Dataset::add_resource);
    connect(pDatasetDel,&QAction::triggered,pDatasetOperation,&Dataset::del_resource);
    connect(pDatasetEdit,&QAction::triggered,pDatasetOperation,&Dataset::edit_resource);
    connect(pDatasetSearch,&QAction::triggered,pDatasetOperation,&Dataset::search_resource);

    pLossOperation = new Loss();
    connect(pLossAdd,&QAction::triggered,pLossOperation,&Loss::add_resource);
    connect(pLossDel,&QAction::triggered,pLossOperation,&Loss::del_resource);
    connect(pLossEdit,&QAction::triggered,pLossOperation,&Loss::edit_resource);
    connect(pLossSearch,&QAction::triggered,pLossOperation,&Loss::search_resource);

    pLrSchedularOperation = new Lr_schedular();
    connect(pLrSchedularAdd,&QAction::triggered,pLrSchedularOperation,&Lr_schedular::add_resource);
    connect(pLrSchedularDel,&QAction::triggered,pLrSchedularOperation,&Lr_schedular::del_resource);
    connect(pLrSchedularEdit,&QAction::triggered,pLrSchedularOperation,&Lr_schedular::edit_resource);
    connect(pLrSchedularSearch,&QAction::triggered,pLrSchedularOperation,&Lr_schedular::search_resource);

    pMetricOperation = new Metric();
    connect(pMetricAdd,&QAction::triggered,pMetricOperation,&Metric::add_resource);
    connect(pMetricDel,&QAction::triggered,pMetricOperation,&Metric::del_resource);
    connect(pMetricEdit,&QAction::triggered,pMetricOperation,&Metric::edit_resource);
    connect(pMetricSearch,&QAction::triggered,pMetricOperation,&Metric::search_resource);

    pModelOperation = new Model();
    connect(pModelAdd,&QAction::triggered,pModelOperation,&Model::add_resource);
    connect(pModelDel,&QAction::triggered,pModelOperation,&Model::del_resource);
    connect(pModelEdit,&QAction::triggered,pModelOperation,&Model::edit_resource);
    connect(pModelSearch,&QAction::triggered,pModelOperation,&Model::search_resource);

    pOptimizerOperation = new Optimizer();
    connect(pOptimizerAdd,&QAction::triggered,pOptimizerOperation,&Optimizer::add_resource);
    connect(pOptimizerDel,&QAction::triggered,pOptimizerOperation,&Optimizer::del_resource);
    connect(pOptimizerEdit,&QAction::triggered,pOptimizerOperation,&Optimizer::edit_resource);
    connect(pOptimizerSearch,&QAction::triggered,pOptimizerOperation,&Optimizer::search_resource);

}

MainWindow::~MainWindow()
{
    delete ui;
}

