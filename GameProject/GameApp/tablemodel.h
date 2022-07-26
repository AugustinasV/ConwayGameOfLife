#ifndef TABLEMODEL_H
#define TABLEMODEL_H

#include <QMainWindow>
#include <QAbstractTableModel>
#include <QThread>

#include <iostream>
#include <sstream>
#include <string>
#include <unistd.h>
#include <vector>
#include <fstream>

class Node
{
public:
    Node(int , int , int);
    void setNeighb(int);  // write neighbour count
    void setLive(int);    // write live

    int xy[2];      // grid coord
    int liveneighb; // live neighbour count
    int live;       // 1 = live; 0 = dead
};

class TableModel : public QAbstractTableModel
{
    Q_OBJECT

public:

    ~TableModel();
    TableModel(QObject *parent = nullptr);
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;


    void insertRow(int row, const QModelIndex &parent= QModelIndex()) ;
    void insertColumn(int column, const QModelIndex &parent= QModelIndex()) ;
    void removeRow();
    void removeColumn();


    std::vector<std::string> lineread;
    std::string startfile = "../../GameApp/exm/";          // path to start file
    std::string target = startfile+"0th.txt";

    void loadfromfile();
    void readLine();
    void readstr(int);


    int row_size =0;           // TODO: add counter; set_rowcol based on file
    int col_size =0;
    int iter =1;


    QThread workerThread;
    std::vector<std::vector<Node>> grid;
    std::vector<Node> gridrow;

signals:
    void NextGenerationRequest();
    void FileOutputRequest();

public slots:
    void sendNextGenerationRequestReceived();
    void sendOutputRequestReceived();

    void addcolbut_clicked();
    void addrowbut_clicked();
    void removecolbut_clicked();
    void removerowbut_clicked();

    void cellclickupdate(QModelIndex);
};

#endif // TABLEMODEL_H
