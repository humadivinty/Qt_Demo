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
