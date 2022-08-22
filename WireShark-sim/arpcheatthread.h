#ifndef ARPCHEATTHREAD_H
#define ARPCHEATTHREAD_H
#include <QThread>
#include <QMutex>
#define WPCAP
#define HAVE_REMOTE
#include <pcap.h>
#include <remote-ext.h>
#include <winsock.h>
#include <protocol.h>

class ArpCheatThread: public QThread
{
    Q_OBJECT
public:
    ArpCheatThread();
    ~ArpCheatThread();
    void stop();
protected:
    void run();
private:
    QMutex m_lock;
    volatile bool stopped;
    u_char *fakeTargetArpPkt;       //发送给目标主机的伪造arp数据包
    u_char *fakeGateArpPkt;         //发送给网关的伪造ARP数据包
    pcap_t *adhandle;
    u_char *currentMac;
    u_long targetIp;
    u_char *targetMac;
    u_long gateIp;
    u_char *gateMac;

    u_char *BuildArpPacket(u_char *srcMac, u_long srcIP, u_char *destMac, u_long destIP);
private slots:
    void getCheatInfo(pcap_t *adhandle, u_char *selfmac, u_long destip, u_char *destmac, u_long gateip, u_char *gatemac);
signals:
    void sendLogMsg(QString msg);
};

#endif // ARPCHEATTHREAD_H
