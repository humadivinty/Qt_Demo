#ifndef MYMODEL
#define MYMODEL
#include<QAbstractTableModel>
#include"camerastatus.h"

class QTimer;

class MyModel : public QAbstractTableModel
{
    Q_OBJECT
public:
    MyModel(QObject* parents);
    int rowCount(const QModelIndex &parent = QModelIndex()) const Q_DECL_OVERRIDE;
    int columnCount(const QModelIndex &parent = QModelIndex()) const Q_DECL_OVERRIDE;
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const Q_DECL_OVERRIDE;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const Q_DECL_OVERRIDE;

    bool AddData(QString ip, QString status);
    void ModifyData(QString ip, QString status);
private:
    char m_chData[2][3];
    CameraStatusList m_CamStatusList;

public:
    QTimer* m_pTimer;
public slots:
    void timerHit();
};

#endif // MYMODEL

