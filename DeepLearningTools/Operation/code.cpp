#include "code.h"

Code::Code(QObject *parent)
    : Operation{parent}
{

}

void Code::code_generate(){

    qDebug("代码生成");

}

void Code::train_result_generate(){

    qDebug("开始训练");

}

void Code::test_result_generate(){

    qDebug("开始测试");

}


