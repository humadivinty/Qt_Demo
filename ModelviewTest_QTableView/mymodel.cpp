#include"mymodel.h"
#include<QVariant>
#include<QDebug>
#include<QFont>
#include<QBrush>
#include<QTime>
#include<QTimer>

MyModel::MyModel(QObject *parents)
    :QAbstractTableModel(parents)
{
    m_pTimer = new QTimer(this);
    m_pTimer->setInterval(1000);
    //connect(m_pTimer, SIGNAL(timeout()), this, SLOT(timerHit()));
    connect(m_pTimer, SIGNAL(timeout()) , this, SLOT(timerHit()));


    m_pTimer->start();
}

int MyModel::rowCount(const QModelIndex &parent) const
{
    return 2;
}

int MyModel::columnCount(const QModelIndex &parent) const
{
    return 3;
}

QVariant MyModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role == Qt::DisplayRole)
    {
        if (orientation == Qt::Horizontal) {
            switch (section)
            {
            case 0:
                return QString("first");
            case 1:
                return QString("second");
            case 2:
                return QString("third");
            }
        }
        if (orientation == Qt::Vertical) {
            switch (section)
            {
            case 0:
                return QString("Ver-first");
            case 1:
                return QString("Ver-second");
            case 2:
                return QString("Ver-third");
            }
        }
    }
    return QVariant();
}

QVariant MyModel::data(const QModelIndex &index, int role) const
{
    int row = index.row();
    int col = index.column();
    qDebug()<<QString("row %1, col%2, role %3").arg(row).arg(col).arg(role);

    if(role == Qt::DisplayRole)
    {
        if(row == 0 && col == 0)
        {
            return QTime::currentTime().toString();
        }
    }

    return QVariant();
}

void MyModel::timerHit()
{
    QModelIndex topLeft = createIndex(0, 0);
    emit dataChanged(topLeft, topLeft);
}
