#ifndef OPERATION_H
#define OPERATION_H

#include <QObject>

class Operation : public QObject
{
    Q_OBJECT
public:
    explicit Operation(QObject *parent = nullptr);

signals:

};

#endif // OPERATION_H
