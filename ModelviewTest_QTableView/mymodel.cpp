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

}

int MyModel::rowCount(const QModelIndex &parent) const
{
    return ROWS;
}

int MyModel::columnCount(const QModelIndex &parent) const
{
    return COLS;
}

QVariant MyModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role == Qt::DisplayRole)
    {
        if (orientation == Qt::Horizontal)
        {
            return QString("Col%1").arg(section);
        }
        if (orientation == Qt::Vertical)
        {
             return QString("Line%1").arg(section);
        }
    }
    return QVariant();
}

QVariant MyModel::data(const QModelIndex &index, int role) const
{
    int row = index.row();
    int col = index.column();
    //qDebug()<<QString("row %1, col%2, role %3").arg(row).arg(col).arg(role);

    if(role == Qt::DisplayRole)
    {
        return m_gridData[row][col];
    }
    return QVariant();
}

bool MyModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if(role == Qt::EditRole)
    {
        m_gridData[index.row()][index.column()] = value.toString();
        QString result;
        for(int row = 0; row < ROWS; row++)
        {
            for(int col = 0; col < COLS; col ++ )
            {
                result +=m_gridData[row][col] + " ";
            }
        }
        qDebug()<<result;
        emit editCompleted(result);         //这里发送信号是否是为以后的实现做准备？
    }
    return true;
}

Qt::ItemFlags MyModel::flags(const QModelIndex &index) const
{
    //设置单元格的"可编辑"属性,当属性为“可编辑”时才能对其进行修改
    return Qt::ItemIsEnabled | QAbstractTableModel::flags(index);
}
