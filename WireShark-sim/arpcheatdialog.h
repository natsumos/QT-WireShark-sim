#ifndef ARPCHEATDIALOG_H
#define ARPCHEATDIALOG_H

#include <QDialog>
#define WPCAP
#define HAVE_REMOTE
#include <pcap.h>
#include <remote-ext.h>
#include <winsock2.h>
#include <Packet32.h>
#include <ntddndis.h>
#include <protocol.h>
#include <arpcheatthread.h>
#include <sendpktthread.h>

namespace Ui {
class ArpCheatDialog;
}

class ArpCheatDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ArpCheatDialog(QWidget *parent = 0);
    ~ArpCheatDialog();
    int initDev(int interface_index);      //打开指定的设备
    u_char* GetSelfMac(char *pDevName);        //获得本机网卡的MAC地址
    void transMac(const char source[], u_char *dest);

private slots:
    void on_startBtn_clicked();

    void on_stopBtn_clicked();

    void slotUpdateEdit(QString msg);

    void slotUpdateEdit1(QString msg);

private:
    Ui::ArpCheatDialog *ui;
    int interface_index;        //主界面中选择的网卡序号
    pcap_if_t *alldevs;         //全部网卡列表
    pcap_if_t *dev;             //设备指针
    pcap_t *adhandle;           //打开设备指针
    u_char *selfmac;
    QString destip;           //被欺骗主机IP地址
    QString destmac;          //被欺骗主机Mac地址
    QString gateip;
    QString gatemac;
    //作为信号传递的欺骗信息
    u_long deli_destip;
    u_char *deli_destmac;
    u_long deli_gateip;
    u_char *deli_gatemac;
    u_long netmask;
    char filters[50] = "not arp";
    struct bpf_program fcode;

    ArpCheatThread *arpcheatthread;
    SendPktThread *sendpktthread;

    char errbuf[PCAP_ERRBUF_SIZE];
signals:
    void setCheatInfo(pcap_t *adhandle, u_char *selfmac, u_long deli_destip, u_char *deli_destmac, u_long deli_gateip, u_char *deli_gatemac);

};

#endif // ARPCHEATDIALOG_H
