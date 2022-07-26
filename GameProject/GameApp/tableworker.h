#ifndef TABLEWORKER_H
#define TABLEWORKER_H

#include <QObject>
#include <QThread>

#include "tablemodel.h"

class TableWorker : public QObject
{
    Q_OBJECT

public:
    TableWorker(TableModel*);

signals:
    void getNextGenerationFinished();
    void getFileOutputFinished();

public slots:
    void getNextGeneration();       // tested
    void getFileOutput();           // tested

private:
    TableModel* model;
};

#endif // TABLEWORKER_H

