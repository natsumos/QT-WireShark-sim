#ifndef SENDPKTTHREAD_H
#define SENDPKTTHREAD_H
#include <QThread>
#include <QMutex>
#define WPCAP
#define HAVE_REMOTE
#include <pcap.h>
#include <remote-ext.h>
#include <winsock.h>
#include <protocol.h>

class SendPktThread: public QThread
{
    Q_OBJECT;
public:
    SendPktThread(pcap_t *adhandle, u_char *currentMac,
                  u_long targetIp, u_char *targetMac,
                  u_long gateIp, u_char *gateMac);
    void stopimmediate();
protected:
    void run();
private:
    QMutex m_lock;
    volatile bool sstopped;
    pcap_t *adhandle;
    struct pcap_pkthdr *header;     //数据包头
    const u_char *pkt_data = NULL;   //网络中收到的字节流数据
    u_char *currentMac;
    u_long targetIp;
    u_char *targetMac;
    u_long gateIp;
    u_char *gateMac;
signals:
    void updateShowInfo(QString msg);
};

#endif // SENDPKTTHREAD_H
