#include "testoperation.h"

#include <Operation/configure.h>

TestOperation::TestOperation(QObject *parent)
    : UnitTest{parent}
{

}

void TestOperation::test_generateSPI_generateFolderTree(QString test_field){

    // 测试通过

    // 创建并清空测试路径
    QDir root(test_field);
    if(!root.exists()){
        root.mkpath(test_field);
    }

    QString cmd_temp;
    cmd_temp = "rmdir /s /q " + test_field;    // 删除已有的文件夹并新建一个
    system(cmd_temp.toStdString().c_str());
    cmd_temp = "mkdir " + test_field;
    system(cmd_temp.toStdString().c_str());

    // 任意生成spi，根据spi生成文件树，根据文件树生成spi，比对两个spi
    Configure config;
    QVector<QString> error_catch;
    const int test_example_number = 100;
    int accurate_num = 0;
    Q_ASSUME(test_example_number > 0);
    Q_ASSUME(accurate_num == 0);

    SPI spi_standard;
    SPI spi_result;
    for(int i=0;i<test_example_number;i++){

        qDebug() << "第" << i << "轮测试";

        fast_random_generate_spi(spi_standard, test_field);     // 随机生成spi
        config.generateFolderTree(spi_standard);           // 生成文件树
        config.generateSPI(spi_result,spi_standard.proj_path); // 根据文件树生成新的spi

        if(!spiSame(spi_standard,spi_result)){
            error_catch.append("Error: \n" + spi_standard.proj_name + ":" + show_spi_info(spi_standard) +
                                       spi_result.proj_name + ":" + show_spi_info(spi_result));
        }                                                  // 发现不对劲就把情况记录下来
        else{
            accurate_num += 1;
        }
        cmd_temp = "rmdir /s /q " + test_field;    // 删除已有的文件夹并新建一个
        system(cmd_temp.toStdString().c_str());
        cmd_temp = "mkdir " + test_field;
        system(cmd_temp.toStdString().c_str());
    }

    // 打印测试信息
    qDebug() << "test example number: " << test_example_number;
    qDebug() << "accurate number: " << accurate_num;
    foreach(QString info,error_catch){
        qDebug() << info.toStdString().c_str();
    }
    // qDebug() << "errors" << error_catch;

}

void TestOperation::test_refreshSPI(QString test_field){

    // 测试通过

    qDebug() << "=====现在开始refreshSPI()的测试======";

    // 有个很有趣的关于srand的bug，如果你两次调用的srand的时间间隔小于一秒，那么srand给出的结果是一样的
    // 你可以试试qt的QRandomGenerator
    // 这就是为什么你在debug模式下运行这个代码不会报folder already exists的警告，但是直接运行就会有

    const int test_example_num = 10;
    int accurate_num = 0;
    Q_ASSUME(test_example_num > 0);
    Q_ASSUME(accurate_num == 0);

    Configure config;
    QVector<QString> error_caught;

    for(int i=0;i<test_example_num;i++){

        qDebug() << "现在进行第" << i << "个样例的测试";

        // 随机生成spi
        SPI spi_standard;
        fast_random_generate_spi(spi_standard, test_field);
        // 根据spi生成文件夹树
        config.generateFolderTree(spi_standard);
        // 清空spi中几个list
        SPI spi_regenerate;
        config.copySPI(spi_regenerate, spi_standard);
        spi_regenerate.dataset_list.empty();
        spi_regenerate.model_list.empty();
        spi_regenerate.train_code_list.empty();
        // 看spi和旧的spi是否相同
        if(!(spiSame(spi_standard,spi_regenerate))){
            // 不相同，那就错了
            error_caught.append(QString("Error: \n") + "标准样例: \n" +
                                show_spi_info(spi_standard)
                                + "输出样例: \n" + show_spi_info(spi_regenerate));
        }
        else{
            // 相同，那就对了
            accurate_num += 1;
        }

    }

    qDebug() << "=====测试结果=====";
    qDebug() << "总样例数: " << test_example_num;
    qDebug() << "正确样例数: " << accurate_num;
    qDebug() << "错误样例:";
    foreach(QString temp,error_caught){
        qDebug() << temp.toStdString().c_str();
    }

}

