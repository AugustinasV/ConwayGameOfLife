#include <QtTest>

#include "tablemodel.h"

class tablemodelTest : public QObject
{
    Q_OBJECT

public:
    tablemodelTest();

private slots:
    void test_init_rowcol_size();
    void test_add_row_col();
    void test_remove_row_col();
    void test_cell_click();

private:
    TableModel *model;
};

tablemodelTest::tablemodelTest()
{
    model = new TableModel;
    model->loadfromfile();
}

void tablemodelTest::test_init_rowcol_size()
{
    QVERIFY(model->rowCount() == 45);
    QVERIFY(model->columnCount() == 40);
}

void tablemodelTest::test_add_row_col()
{
    model->addcolbut_clicked();
    model->addrowbut_clicked();
    QVERIFY(model->rowCount() == 46);
    QVERIFY(model->columnCount() == 41);
}

void tablemodelTest::test_remove_row_col()
{
    model->removecolbut_clicked();
    model->removerowbut_clicked();
    QVERIFY(model->rowCount() == 45);
    QVERIFY(model->columnCount() == 40);
}

void tablemodelTest::test_cell_click()
{
    QVERIFY(model->grid[0][0].live == 0);
    model->cellclickupdate(model->index(0,0));
    QVERIFY(model->grid[0][0].live == 1);
    model->cellclickupdate(model->index(0,0));
    QVERIFY(model->grid[0][0].live == 0);
}

QTEST_MAIN(tablemodelTest)

#include "tst_tablemodeltest.moc"
