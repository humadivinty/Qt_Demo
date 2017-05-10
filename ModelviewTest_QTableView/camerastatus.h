#ifndef CAMERASTATUS
#define CAMERASTATUS

#include<list>
#include<QMutex>
#include<QString>

class CameraStatus
{
public:
    CameraStatus();
    CameraStatus(QString ip, QString status);

private:
    QString strCamIp;
    QString strStatus;

public:
    QString GetCamIp() const;
    QString GetCamStat()const;
    void SetStatus(QString strStatus);
};

class  CameraStatusList
{
public:
     CameraStatusList();
     ~CameraStatusList();

     bool addStatus(CameraStatus*);
     int modifyStatus(QString ip, QString status);
     CameraStatus getStatus(int inDex) const;
     int GetListLenth()const;
private:
     std::list<CameraStatus*> m_pStatusList;
     QMutex m_mutex;
};

#endif // CAMERASTATUS

