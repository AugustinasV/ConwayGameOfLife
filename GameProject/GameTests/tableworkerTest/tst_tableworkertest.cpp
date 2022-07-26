#include <QtTest>
#include "tablemodel.h"

class tableworkerTest : public QObject
{
    Q_OBJECT

public:
    tableworkerTest();

private slots:
//    void test_case_valid();
    void test_case_thread_func();

private:
    TableModel *model;
};

tableworkerTest::tableworkerTest()
{
    model = new TableModel;
    model->loadfromfile();
}

void tableworkerTest::test_case_thread_func()
{
    emit model->FileOutputRequest();
    emit model->NextGenerationRequest();
    emit model->FileOutputRequest();
    model->workerThread.wait(200);

    std::string a = ("../../GameApp/exm/" +std::to_string(1) +"th.txt");
    std::ifstream file;
    file.open(a);

    std::string b = ("../../GameApp/exm/" +std::to_string(2) +"th.txt");
    std::ifstream file2;
    file2.open(b);

    QVERIFY(file.is_open());
    QVERIFY(file2.is_open());
}

QTEST_MAIN(tableworkerTest)


#include "tst_tableworkertest.moc"
