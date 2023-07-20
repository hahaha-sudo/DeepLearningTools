#include "unittest.h"

UnitTest::UnitTest(QObject *parent)
    : QObject{parent}
{

}

bool UnitTest::pathExist(QString path){

    QDir root(path);
    return root.exists();

}

QString UnitTest::random_string_generate(int length){

    Q_ASSUME(length >= 0);

    QString possibleCharacters = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*()-=_+[]{};':\",.<>/?\\|~`";

    QString temp = "";
    for (int i=0;i<length;i++){
        temp += possibleCharacters.at(rand()%possibleCharacters.length());
    }

    return temp;

}

QString UnitTest::random_string_generate_with_limit(int length){

    Q_ASSUME(length >= 0);

    QString possibleCharacters = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";

    QString temp = "";
    for (int i=0;i<length;i++){
        temp += possibleCharacters.at(rand()%possibleCharacters.length());
    }

    return temp;

}

QString UnitTest::random_string_generate(int minimum, int maximum){

    Q_ASSUME(minimum >= 0);
    Q_ASSUME(maximum >= minimum);

    int length = rand() % (maximum-minimum+1) + minimum;

    QString possibleCharacters = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*()-=_+[]{};':\",.<>/?\\|~`";

    QString temp = "";
    for (int i=0;i<length;i++){
        temp += possibleCharacters.at(rand()%possibleCharacters.length());
    }

    return temp;

}

QString UnitTest::random_string_generate_with_limit(int minimum, int maximum){

    Q_ASSUME(minimum >= 0);
    Q_ASSUME(maximum >= minimum);

    int length = rand() % (maximum-minimum+1) + minimum;

    QString possibleCharacters = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";

    QString temp = "";
    for (int i=0;i<length;i++){
        temp += possibleCharacters.at(rand()%possibleCharacters.length());
    }

    return temp;

}

QStringList UnitTest::random_string_list_generate(int element_num){

    Q_ASSUME(element_num >= 0);

    return random_string_list_generate(element_num,1,5);

}

QStringList UnitTest::random_string_list_generate(int element_num, int minimum, int maximum){

    Q_ASSUME(element_num >= 0);

    QStringList list_temp;

    for(int i=0;i<element_num;i++){

        list_temp.append(random_string_generate(minimum,maximum));  // 字符串的长度在1~5之间

    }

    return list_temp;

}

QStringList UnitTest::random_string_list_generate_with_limit(int element_num, int minimum, int maximum){

    Q_ASSUME(element_num >= 0);

    QStringList list_temp;

    for(int i=0;i<element_num;i++){

        list_temp.append(random_string_generate_with_limit(minimum,maximum));

    }

    return list_temp;

}

QStringList UnitTest::random_string_list_generate_with_limit(int element_num){

    Q_ASSUME(element_num >= 0);

    return random_string_list_generate_with_limit(element_num,1,5);

}

QStringList UnitTest::random_string_list_generate_with_limit_without_duplicate(int element_num, int minimum, int maximum){

    Q_ASSUME(element_num >= 0);

    QStringList list_temp;

    for(int i=0;i<element_num;i++){

        QString temp = random_string_generate_with_limit(minimum,maximum);
        while(list_temp.contains(temp)){
            temp = random_string_generate_with_limit(minimum,maximum);
        }
        list_temp.append(temp);

    }

    return list_temp;

}

QStringList UnitTest::random_string_list_generate_with_limit_without_duplicate(int element_num){

    Q_ASSUME(element_num >= 0);

    return random_string_list_generate_with_limit_without_duplicate(element_num,1,5);

}

bool UnitTest::spiSame(SPI &spi_a, SPI &spi_b){

    if(spi_a.proj_name!=spi_b.proj_name)
        return false;
    if(spi_a.proj_path!=spi_b.proj_path)
        return false;
    if(!vectorSameElement(spi_a.dataset_list,spi_b.dataset_list))
        return false;
    if(!vectorSameElement(spi_a.model_list,spi_b.model_list))
        return false;
    if(!vectorSameElement(spi_a.optimizer_list,spi_b.optimizer_list))
        return false;
    if(!vectorSameElement(spi_a.metric_list,spi_b.metric_list))
        return false;
    if(!vectorSameElement(spi_a.loss_list,spi_b.loss_list))
        return false;
    if(!vectorSameElement(spi_a.lrsche_list,spi_b.lrsche_list))
        return false;
    if(!vectorSameElement(spi_a.train_code_list,spi_b.train_code_list))
        return false;
    if(!vectorSameElement(spi_a.test_code_list,spi_b.test_code_list))
        return false;

    return true;

}

bool UnitTest::vectorSameElement(QVector<QString> &vec_a, QVector<QString> &vec_b){

    QSet<QString> set_a;
    QSet<QString> set_b;

    foreach(QString temp, vec_a){
        set_a.insert(temp);
    }
    foreach(QString temp, vec_b){
        set_b.insert(temp);
    }
    return set_a == set_b;

}

void UnitTest::random_generate_spi(SPI &spi, QString test_field){

    spi.proj_name="";
    spi.proj_path="";
    spi.dataset_list.clear();
    spi.model_list.clear();
    spi.optimizer_list.clear();
    spi.metric_list.clear();
    spi.loss_list.clear();
    spi.lrsche_list.clear();
    spi.train_code_list.clear();
    spi.test_code_list.clear();

    QString proj_name_temp = random_string_generate_with_limit(1,5);
    spi.proj_name = proj_name_temp;
    spi.proj_path = test_field + "\\" + proj_name_temp;

    QStringList name_list_temp = random_string_list_generate_with_limit_without_duplicate(5,1,5);
    foreach(QString name, name_list_temp){
        spi.dataset_list.append(name);
    }
    name_list_temp = random_string_list_generate_with_limit_without_duplicate(5,1,5);
    foreach(QString name, name_list_temp){
        spi.model_list.append(name);
    }
    name_list_temp = random_string_list_generate_with_limit_without_duplicate(5,1,5);
    foreach(QString name, name_list_temp){
        spi.optimizer_list.append(name);
    }
    name_list_temp = random_string_list_generate_with_limit_without_duplicate(5,1,5);
    foreach(QString name, name_list_temp){
        spi.metric_list.append(name);
    }
    name_list_temp = random_string_list_generate_with_limit_without_duplicate(5,1,5);
    foreach(QString name, name_list_temp){
        spi.loss_list.append(name);
    }
    name_list_temp = random_string_list_generate_with_limit_without_duplicate(5,1,5);
    foreach(QString name, name_list_temp){
        spi.lrsche_list.append(name);
    }
    name_list_temp = random_string_list_generate_with_limit_without_duplicate(5,1,5);
    foreach(QString name, name_list_temp){
        spi.train_code_list.append(name);
    }
    name_list_temp = random_string_list_generate_with_limit_without_duplicate(5,1,5);
    foreach(QString name, name_list_temp){
        spi.test_code_list.append(name);
    }

}

QString UnitTest::show_spi_info(SPI &spi){

    QString output_result = "";

    output_result += "proj name: " + spi.proj_name + "\n";
    output_result += "proj path: " + spi.proj_path + "\n";

    output_result += "datasets: ";
    foreach(QString name, spi.dataset_list){
        output_result += name + ";";
    }
    output_result += "\n";

    output_result += "models: ";
    foreach(QString name, spi.model_list){
        output_result += name + ";";
    }
    output_result += "\n";

    output_result += "optimizers: ";
    foreach(QString name, spi.optimizer_list){
        output_result += name + ";";
    }
    output_result += "\n";

    output_result += "metrics: ";
    foreach(QString name, spi.metric_list){
        output_result += name + ";";
    }
    output_result += "\n";

    output_result += "losses: ";
    foreach(QString name, spi.loss_list){
        output_result += name + ";";
    }
    output_result += "\n";

    output_result += "lrsche: ";
    foreach(QString name, spi.lrsche_list){
        output_result += name + ";";
    }
    output_result += "\n";

    output_result += "train codes: ";
    foreach(QString name, spi.train_code_list){
        output_result += name + ";";
    }
    output_result += "\n";

    output_result += "test codes: ";
    foreach(QString name, spi.test_code_list){
        output_result += name + ";";
    }
    output_result += "\n";

    return output_result;

}

void UnitTest::test_vectorSameElement(){

    // ongoing
    qDebug() << "=====Test starts=====";

    int test_example_num = 10;
    int accurate_num = 0;
    int list_length = 10;
    Q_ASSUME(test_example_num > 0);
    Q_ASSUME(accurate_num == 0);
    Q_ASSUME(list_length > 0);

    qDebug() << "同样的内容，顺序不同";

    for(int i=0;i<test_example_num;i++){

        qDebug() << "第" << i << "/" << test_example_num << "次测试";

        QVector<QString> temp;
        for(int j=0;j<list_length;j++){
            temp.append(QString::number(rand()%10,10));
        }
        QVector<QString> temp_a;
        QVector<QString> temp_b;
        foreach(QString temp_temp, temp){
            temp_a.append(temp_temp);
        }
        for(int j=list_length-1;j>=0;j--){
            temp_b.append(temp.at(j));
        }

        qDebug() << "用例a" << temp_a;
        qDebug() << "用例b" << temp_b;
        qDebug() << "程序认为是否相同："<<vectorSameElement(temp_a,temp_b);

    }

    qDebug() << "不同的内容";
    for(int i=0;i<test_example_num;i++){

        qDebug() << "第" << i << "/" << test_example_num << "次测试";

        QVector<QString> temp_a;
        QVector<QString> temp_b;

        for(int j=0;j<list_length;j++){
            temp_a.append(QString::number(rand()%10,10));
            temp_b.append(QString::number(rand()%10,10));
        }

        qDebug() << "用例a" << temp_a;
        qDebug() << "用例b" << temp_b;
        qDebug() << "程序认为是否相同："<<vectorSameElement(temp_a,temp_b);

    }

}

void UnitTest::test_random_generate_spi(){

    qDebug() << "=====Now testing random_generate_spi=====";

    SPI spi;
    random_generate_spi(spi, "G:\\ceshi");
    QString info = show_spi_info(spi);
    qDebug() << info.toStdString().c_str();

}

QStringList UnitTest::fast_string_list(){

    // 这个函数保证生成非空、无重复元素、仅含数字和字母的字符串列表，使用时记得在外部加上srand

    QVector<QString> list_sample = {"AAUc3","1m5","Nu","jWICX","aeP",
                                    "wH","JPclX","91D","V",
                                    "slwLX","iNX","5","R8GR"};

    const int length_max = list_sample.length();
    const int length_min = 1;

    int length = 0;
    while(!(length>=length_min&&length<=length_max)){
        length = rand()%length_max;
    }

    // qDebug() << "length是" << length;

    QStringList result;

    for(int i=0;i<length;i++){

        // qDebug() << "放进去第" << i << "个元素";

        QString temp;
        do{
           temp = list_sample.at(rand()%length_max);
        }while(result.contains(temp));   // 保证不重复
        result.append(temp);
    }

    return result;

}

void UnitTest::test_fast_string_list(){

    qDebug() << "=====Testing fast_string_list=====";

    const int test_example_number = 10;

    for(int i=0;i<test_example_number;i++){
        qDebug() << "第" << i << "个用例";
        qDebug() << fast_string_list();
    }

}

void UnitTest::fast_random_generate_spi(SPI &spi, QString test_field){

    spi.proj_name="";
    spi.proj_path="";
    spi.dataset_list.clear();
    spi.model_list.clear();
    spi.optimizer_list.clear();
    spi.metric_list.clear();
    spi.loss_list.clear();
    spi.lrsche_list.clear();
    spi.train_code_list.clear();
    spi.test_code_list.clear();

    QString proj_name_temp = random_string_generate_with_limit(1,5);
    spi.proj_name = proj_name_temp;
    spi.proj_path = test_field + "\\" + proj_name_temp;

    QStringList name_list_temp = fast_string_list();
    foreach(QString name, name_list_temp){
        spi.dataset_list.append(name);
    }
    name_list_temp = fast_string_list();
    foreach(QString name, name_list_temp){
        spi.model_list.append(name);
    }
    name_list_temp = fast_string_list();
    foreach(QString name, name_list_temp){
        spi.optimizer_list.append(name);
    }
    name_list_temp = fast_string_list();
    foreach(QString name, name_list_temp){
        spi.metric_list.append(name);
    }
    name_list_temp = fast_string_list();
    foreach(QString name, name_list_temp){
        spi.loss_list.append(name);
    }
    name_list_temp = fast_string_list();
    foreach(QString name, name_list_temp){
        spi.lrsche_list.append(name);
    }
    name_list_temp = fast_string_list();
    foreach(QString name, name_list_temp){
        spi.train_code_list.append(name);
    }
    name_list_temp = fast_string_list();
    foreach(QString name, name_list_temp){
        spi.test_code_list.append(name);
    }

}
