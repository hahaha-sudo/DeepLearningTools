#ifndef CODE_H
#define CODE_H

#include "operation.h"

class Code : public Operation
{

    //Q_OBJECT

public:
    explicit Code(QObject *parent = nullptr);

    void code_generate();
    void train_result_generate();
    void test_result_generate();

};

#endif // CODE_H
