#ifndef UNITTEST_H
#define UNITTEST_H

#include <QObject>

#include <QDir>

#include <Information/information.h>
#include <Information/spi.h>
#include <Information/stei.h>
#include <Information/stri.h>
#include <Operation/operation.h>
#include <Operation/configure.h>
#include <Operation/resource.h>
#include <Operation/test.h>
#include <Operation/train.h>

#include <QDebug>

// This class is used for testing of unit blocks.
// You can add this into the mainwindow.cpp before release.
// Remember to report which function you are testing when you call the test func.

class UnitTest : public QObject
{
    Q_OBJECT
public:
    explicit UnitTest(QObject *parent = nullptr);

    // auxiliary functions
    QString random_string_generate(int length);                           // 生成定长的字符串
    QString random_string_generate_with_limit(int length);                // 生成定长的、字符有限制的字符串
    QString random_string_generate(int minimum, int maximum);             // 生成长度在一定范围内的字符串
    QString random_string_generate_with_limit(int minimum, int maximum);  // 生成长度在一定范围内、字符有限制的字符串
    QStringList random_string_list_generate(int element_num);
    QStringList random_string_list_generate(int element_num, int minimum, int maximum);
    QStringList random_string_list_generate_with_limit(int element_num);
    QStringList random_string_list_generate_with_limit(int element_num, int minimum, int maximum);
    QStringList random_string_list_generate_with_limit_without_duplicate(int element_num, int minimum, int maximum);
    QStringList random_string_list_generate_with_limit_without_duplicate(int element_num);   // 保证不重复
    // 这些生成QStringList的函数太慢了，可以弄个快速的版本，从用户定义的“备选字符串中随便选一个就行”
    QStringList fast_string_list();

    void random_generate_spi(SPI &spi, QString test_field);    // 生成随机的spi
    void fast_random_generate_spi(SPI &spi, QString test_field); // 快速生成spi
    QString show_spi_info(SPI &spi);       // 将spi的内容以字符串的形式打印出来

    bool pathExist(QString path);          // 判断某路径是否存在
    bool spiSame(SPI &spi_a, SPI &spi_b);  // 判断两个spi是否相等
    bool vectorSameElement(QVector<QString> &vec_a, QVector<QString> &vec_b);  // 判断两个vector容器内元素是否相同（无先后顺序）

    // test auxiliary functions
    void test_vectorSameElement();
    void test_random_generate_spi();
    void test_fast_string_list();


signals:

};

#endif // UNITTEST_H
