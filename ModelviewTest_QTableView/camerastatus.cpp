#include"camerastatus.h"
#include<QMutexLocker>
#include<QDebug>

CameraStatusList::CameraStatusList()
{

}

CameraStatusList::~CameraStatusList()
{
    static int iTimes = 0;
    CameraStatus* pTemp = NULL;
    m_mutex.lock();
    while(m_pStatusList.size() > 0)
    {
        pTemp = m_pStatusList.front();
        if(pTemp)
        {
            m_pStatusList.pop_front();
            delete pTemp;
            pTemp = NULL;
        }
        qDebug()<<++iTimes;
    }

    m_mutex.unlock();
}

int CameraStatusList::GetListLenth() const
{
    return m_pStatusList.size();
}

bool CameraStatusList::addStatus(CameraStatus *status)
{
    if(!status) return false;

    m_mutex.lock();
    m_pStatusList.push_back(status);
    m_mutex.unlock();

    return true;
}

int  CameraStatusList::modifyStatus(QString ip, QString status)
{
    int i_index = -1, index=0;
    std::list<CameraStatus*>::iterator itor;
    CameraStatus* pTemp = NULL;
    for(itor= m_pStatusList.begin(); itor !=  m_pStatusList.end(); itor++)
    {
        pTemp = *itor;
        if(pTemp && pTemp->GetCamIp() == ip)
        {
            i_index = index;
            pTemp->SetStatus(status);
            break;
        }
        ++index;
    }
    pTemp = NULL;
    return i_index;
}

CameraStatus CameraStatusList::getStatus(int index)const
{
    //m_mutex.lock();
    CameraStatus tempStatus;
    if(m_pStatusList.size() < index)
    {
        //m_mutex.unlock();
        return tempStatus;
    }
    else
    {
        std::list<CameraStatus*>::const_iterator itor;
        CameraStatus* pTemp = NULL;
        int iDex = 0;
        for(itor = m_pStatusList.begin(); itor !=  m_pStatusList.end(); itor++)
        {
            if(iDex == index)
            {
                pTemp = *itor;
                break;
            }
            iDex++;
        }
        //m_mutex.unlock();
        return *pTemp;

        //return tempStatus;
    }
}


CameraStatus::CameraStatus()
{
    strCamIp = QString("127.0.0.1");
    strStatus = QString("connect");
}

CameraStatus::CameraStatus(QString ip, QString status)
    :strCamIp(ip), strStatus(status)
{

}

QString CameraStatus::GetCamIp() const
{
    return strCamIp;
}

QString CameraStatus::GetCamStat() const
{
    return strStatus;
}

void CameraStatus::SetStatus(QString Status)
{
   strStatus = Status;
}
