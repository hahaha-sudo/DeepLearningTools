#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <UnitTest/testoperation.h>
#include <UnitTest/unittest.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    srand(QTime(0,0,0).secsTo(QTime::currentTime()));

    TestOperation t;
    t.test_refreshSPI("G:\\ceshi");
    // t.test_generateSPI_generateFolderTree("G:\\ceshi");
    // t.test_random_generate_spi();
    // t.test_fast_string_list();
    // UnitTest t;
    // t.test_vectorSameElement();

}

MainWindow::~MainWindow()
{
    delete ui;
}

