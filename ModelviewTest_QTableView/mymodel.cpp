#include"mymodel.h"
#include<QVariant>

MyModel::MyModel(QObject *parents)
    :QAbstractTableModel(parents)
{
    m_chData[0][0] ='0';
    m_chData[0][1] ='1';
    m_chData[0][2] ='2';
    m_chData[1][0] ='3';
    m_chData[1][1] ='4';
    m_chData[1][2] ='5';
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
    if(role == Qt::DisplayRole)
    {
        //return QString("Row%1 , Column%2").arg(index.row()+1).arg(index.column()+1);
        return QString("%1").arg(m_chData[index.row()][index.column()]);
    }
    return QVariant();
}
