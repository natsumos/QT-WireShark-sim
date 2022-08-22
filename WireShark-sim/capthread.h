#ifndef CAPTHREAD_H
#define CAPTHREAD_H
#include <QThread>
#include <QMutex>
#define WPCAP
#define HAVE_REMOTE
#include <pcap.h>
#include <remote-ext.h>
#include <winsock.h>
#include <protocol.h>

class CapThread: public QThread
{
    Q_OBJECT
public:
    CapThread(pcap_t *adhandle, pktCount *npacket, datapktVec &datapktLLink, dataVec &dataCharLLink, pcap_dumper_t *dumpfile);
    void stop();
protected:
    void run();
private:
    QMutex m_lock;
    volatile bool stopped;
    pcap_t *adhandle;
    pktCount *npacket;
    datapktVec &datapktLink;
    dataVec &dataCharLink;
    pcap_dumper_t *dumpfile;

signals:
    void addOneCaptureLine(QString timestr, QString srcMac, QString destMac, QString len, QString protoType, QString srcIP, QString dstIP);
    void updatePktCount();
};

#endif // CAPTHREAD_H
