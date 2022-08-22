#ifndef ARPHEAD_H
#define ARPHEAD_H

//设置字节对齐为1
#pragma pack(1)
//以太网首部结构
struct ethernet_head
{
    unsigned char dest_mac[6];	//以太网目的地址
    unsigned char src_mac[6];	//以太网源地址
    unsigned short eh_type;		//以太网帧类型
};

struct arp_head
{
    unsigned short hardware_type;	//硬件类型：以太网接口类型为1
    unsigned short protocol_type;	//协议类型：IP协议类型为0x0800
    unsigned char add_len;			//硬件地址长度
    unsigned char pro_len;			//协议地址长度
    unsigned short option;			//操作
    unsigned char sour_addr[6];		//源MAC地址：发送方的MAC地址
    unsigned long sour_ip;			//源IP地址：发送方的IP地址
    unsigned char dest_addr[6];		//目的Mac地址
    unsigned long dest_ip;			//目的IP地址
};

//最终arp包结构
struct arp_packet
{
    ethernet_head eth;	//以太网头部
    arp_head arp;		//arp数据包头部
};
//取消设置的1字节对齐，恢复为默认的4字节对齐
#pragma pack()


#endif // ARPHEAD_H
