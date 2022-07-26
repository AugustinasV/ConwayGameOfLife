#include "tableworker.h"

Node::Node(int x, int y, int val)
{
    xy[0] = x;
    xy[1] = y;
    liveneighb = 0;
    live = val;
}

void Node::setNeighb(int neigh)
{
    liveneighb = neigh;
}

void Node::setLive(int alive)
{
    live = alive;
}


TableModel::~TableModel()
{
    workerThread.exit();
}

TableModel::TableModel(QObject *parent) : QAbstractTableModel(parent)
{
    workerThread.start();
    TableWorker *worker = new TableWorker(this);
    worker->moveToThread(&workerThread);

    connect(this, SIGNAL(NextGenerationRequest()), worker, SLOT(getNextGeneration()));
    connect(this, SIGNAL(FileOutputRequest()), worker, SLOT(getFileOutput()));
};


int TableModel::rowCount(const QModelIndex &parent) const
{
    return row_size;
}

int TableModel::columnCount(const QModelIndex &parent) const
{
    return col_size;
}

QVariant TableModel::data(const QModelIndex &index, int role) const
{
    if (index.isValid())
    {
        if (role == Qt::BackgroundRole)
        {
            if (grid.at(index.row()).at(index.column()).live==1)
            {
                return QVariant(QColor(Qt::black));
            }
            else
            {
                return QVariant(QColor(Qt::white));
            }
        }
        return QVariant();
    }
    return QVariant();
}



void TableModel::insertRow(int row,const  QModelIndex &parent)
{
    beginInsertRows(parent, row, row);
    for (int x=0;x<columnCount();x++)
    {
        gridrow.push_back(Node(row, x, 0));
    }
    grid.push_back(gridrow);
    gridrow.clear();
    row_size++;
    endInsertRows();
}
void TableModel::insertColumn(int column, const  QModelIndex &parent)
{
    beginInsertColumns(parent, column, column);
    for (int x=0;x<rowCount();x++)
    {
        grid[x].push_back(Node(x, column, 0));
    }
    col_size++;
    endInsertColumns();

}
void TableModel::removeRow()
{
    beginResetModel();
    if (row_size>0)
    {
        grid.pop_back();
        row_size = row_size-1;
    }
    endResetModel();
}
void TableModel::removeColumn()
{
    beginResetModel();
    if (col_size>0)
    {
        for (int x=0;x<rowCount();x++)
            {
                grid[x].pop_back();
            }
        col_size = col_size-1;
    }
    endResetModel();
}


void TableModel::readstr(int a)  /// 'a' -> index of lineread
{
    int k = 0;
    std::string word;
    std::stringstream str(lineread[a]);
    while (str >> word) {
        gridrow.push_back(Node(a, k, stoi(word)));
        k++;
        col_size ++;
    }
    grid.push_back(gridrow);
    gridrow.clear();
}

void TableModel::readLine()     // read data file;
{
    std::string qwer;
    std::ifstream file;
    file.open(target);
    if (!file.is_open()) {
        std::cout << "Neranda tokio failo" << std::endl;
    }
    while (getline(file, qwer)) {
        if (qwer == "") {                 /// check for empty lines, skip to next line if empty found
            continue;
        }
        lineread.push_back(qwer);
        row_size++;
    }
    file.close();
}

void TableModel::loadfromfile()
{
    std::vector<std::string> lineread;
    readLine();
    for (int x=0;x<this->row_size;x++)
    {
        this->readstr(x);
    }
    col_size = col_size/row_size;
}


void TableModel::sendNextGenerationRequestReceived()    // rename
{
    beginResetModel();
    emit NextGenerationRequest();
    endResetModel();
}

void TableModel::sendOutputRequestReceived()            // rename
{
    emit FileOutputRequest();
}

void TableModel::cellclickupdate(QModelIndex index)
{
    if (grid.at(index.row()).at(index.column()).live==1)
    {
        grid.at(index.row()).at(index.column()).live=0;
    }
    else if (grid.at(index.row()).at(index.column()).live==0)
    {
        grid.at(index.row()).at(index.column()).live=1;
    }
}

void TableModel::addcolbut_clicked()
{
    insertColumn(columnCount());
}
void TableModel::addrowbut_clicked()
{
    insertRow(rowCount());
}
void TableModel::removecolbut_clicked()
{
    removeColumn();
}
void TableModel::removerowbut_clicked()
{
    removeRow();
}






