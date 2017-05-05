#ifndef MYMODEL
#define MYMODEL
#include<QAbstractTableModel>

class QTimer;

class MyModel : public QAbstractTableModel
{
    Q_OBJECT
public:
    MyModel(QObject* parents);
    int rowCount(const QModelIndex &parent = QModelIndex()) const Q_DECL_OVERRIDE;
    int columnCount(const QModelIndex &parent = QModelIndex()) const Q_DECL_OVERRIDE;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const Q_DECL_OVERRIDE;

private:
    char m_chData[2][3];

public:
    QTimer* m_pTimer;
public slots:
    void timerHit();
};

#endif // MYMODEL

