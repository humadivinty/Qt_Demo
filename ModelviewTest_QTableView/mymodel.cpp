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
//    m_pTimer = new QTimer(this);
//    m_pTimer->setInterval(1000);
//    connect(m_pTimer, SIGNAL(timeout()) , this, SLOT(timerHit()));
//    m_pTimer->start();

    m_CamStatusList.addStatus(new CameraStatus("127.0.0.2", "connect"));
//    m_CamStatusList.addStatus(new CameraStatus("172.18.0.11", "connect"));
//    m_CamStatusList.addStatus(new CameraStatus("127.0.0.3", "disconnect"));
//    m_CamStatusList.addStatus(new CameraStatus("172.18.0.56", "connect"));


}

int MyModel::rowCount(const QModelIndex &parent) const
{
    return m_CamStatusList.GetListLenth();
}

int MyModel::columnCount(const QModelIndex &parent) const
{
    return 2;
}

QVariant MyModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role == Qt::DisplayRole)
    {
        if (orientation == Qt::Horizontal) {
            switch (section)
            {
            case 0:
                return QString("IpAddress");
            case 1:
                return QString("Status");
            case 2:
                return QString("third");
            }
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
//        if(row == 0 && col == 0)
//        {
//            return QTime::currentTime().toString();
//        }
        CameraStatus tempStatus = m_CamStatusList.getStatus(row);
        if(col ==0)
        {
            return tempStatus.GetCamIp();
        }
        else
        {
            return tempStatus.GetCamStat();
        }
    }

    return QVariant();
}

bool MyModel::AddData(QString ip, QString status)
{
    beginResetModel();   //在更新数据时，需要使用这个begin 和end 把修改代码包裹起来?
    m_CamStatusList.addStatus(new CameraStatus(ip, status));

//    QModelIndex topLeft = createIndex(m_CamStatusList.GetListLenth()-1, 0);
//    QModelIndex bottomRight = createIndex(m_CamStatusList.GetListLenth()-1, 1);
//    QModelIndex topLeft = createIndex(1, 0);
//    QModelIndex bottomRight = createIndex(1, 1);
//    emit dataChanged(topLeft, bottomRight);


    endResetModel();

    return true;
}

void MyModel::ModifyData(QString ip, QString status)
{
    //beginResetModel();
    int iRet = m_CamStatusList.modifyStatus("172.18.0.2", "haha");
    //endResetModel();
    if(iRet != -1)
    {
        qDebug()<<iRet<<"was modify";
        QModelIndex topLeft = createIndex(iRet, 0);
        QModelIndex bottomRight = createIndex(iRet, 1);
        emit dataChanged(topLeft, bottomRight);
    }
}

void MyModel::timerHit()
{
    QModelIndex topLeft = createIndex(0, 0);
    emit dataChanged(topLeft, topLeft);
}
