#include <QMessageBox>
#include <QByteArray>
#include <QIcon>
#include "arpcheatdialog.h"
#include "ui_arpcheatdialog.h"
ArpCheatDialog::ArpCheatDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ArpCheatDialog)
{
    ui->setupUi(this);
    this->setWindowTitle("ARP虚假包");
    this->interface_index = netDeviceNum;
    adhandle = NULL;
    alldevs = NULL;
    arpcheatthread = NULL;
    sendpktthread = NULL;
    ui->targetIp->setPlaceholderText(tr("输入目标IP地址"));// 背景提示文字
    ui->targetIp->setStyleSheet("border-radius: 3px"); // 设置圆角
    ui->targetMac->setPlaceholderText(tr("输入目标MAC地址"));// 背景提示文字
    ui->targetMac->setStyleSheet("border-radius: 3px"); // 设置圆角
    ui->gateIp->setPlaceholderText(tr("输入网关IP地址"));//背景提示文字
    ui->gateIp->setStyleSheet("border-radius: 3px"); // 设置圆角
    ui->gateMac->setPlaceholderText(tr("输入网关MAC地址"));//背景提示文字
    ui->gateMac->setStyleSheet("border-radius: 3px"); // 设置圆角
    ui->stopBtn->setEnabled(false);
}

ArpCheatDialog::~ArpCheatDialog()
{
    delete ui;
}

void ArpCheatDialog::on_startBtn_clicked()
{
    ui->startBtn->setEnabled(false);
    ui->stopBtn->setEnabled(true);
    ui->textBrowser->clear();
    initDev(interface_index);
    //获取当前网卡MAC地址
    selfmac = GetSelfMac(dev->name + 8);	//+8以去掉"rpcap://"
    destip = ui->targetIp->text();
    destmac = ui->targetMac->text();
    gateip = ui->gateIp->text();
    gatemac = ui->gateMac->text();
    if(!(destip != NULL && destmac != NULL && gateip != NULL && gatemac != NULL)){
        QMessageBox::warning(this, "Error", tr("请输入完整信息，MAC地址可以通过arp缓存表获得"), QMessageBox::Ok);
        return;
    }
    if(arpcheatthread != NULL){
        delete arpcheatthread;
        arpcheatthread = NULL;
    }
    arpcheatthread = new ArpCheatThread();
    connect(this, SIGNAL(setCheatInfo(pcap_t*, u_char*,u_long,u_char*,u_long,u_char*)), arpcheatthread, SLOT(getCheatInfo(pcap_t*, u_char*,u_long,u_char*,u_long,u_char*)));
    connect(arpcheatthread, SIGNAL(sendLogMsg(QString)), this, SLOT(slotUpdateEdit(QString)));
    //对输入IP进行转换
    const char *destipStr;
    QByteArray ba = destip.toLatin1();
    destipStr = ba.data();
    deli_destip = inet_addr(destipStr);
    if(deli_destip == INADDR_NONE){
        QMessageBox::warning(this, "Error", tr("目标IP为无效输入!"), QMessageBox::Ok);
        return;
    }
    const char *gateipStr;
    ba = gateip.toLatin1();
    gateipStr = ba.data();
    deli_gateip = inet_addr(gateipStr);
    if(deli_gateip == INADDR_NONE){
        QMessageBox::warning(this, "Error", tr("网关IP为无效输入!"), QMessageBox::Ok);
        return;
    }
    //对输入MAC地址进行转换
    const char *destMacStr;
    ba = destmac.toLatin1();
    destMacStr = ba.data();
    deli_destmac = (u_char *)malloc(6 * sizeof(u_char));        //注意释放malloc内存
    transMac(destMacStr, deli_destmac);
    const char *gateMacStr;
    ba = gatemac.toLatin1();
    gateMacStr = ba.data();
    deli_gatemac = (u_char *)malloc(6 * sizeof(u_char));        //注意释放malloc内存
    transMac(gateMacStr, deli_gatemac);

    emit setCheatInfo(adhandle, selfmac, deli_destip, deli_destmac, deli_gateip, deli_gatemac);

    arpcheatthread->start();

    //重新开一个线程用于转发数据包
    if (dev->addresses != NULL)
        /* 获取接口第一个地址的掩码 */
        netmask=((struct sockaddr_in *)(dev->addresses->netmask))->sin_addr.S_un.S_addr;
    else
        netmask=0xffffff;
    //设置过滤规则，只捕获非arp数据包
    if (pcap_compile(adhandle, &fcode, filters, 1, netmask) < 0)
    {
        QMessageBox::warning(this, "Error!", tr("过滤规则编译失败"), QMessageBox::Ok);
        pcap_freealldevs(alldevs);
        return;
    }
    // set the filter
    if (pcap_setfilter(adhandle, &fcode) < 0)
    {
        QMessageBox::warning(this, "Error!", tr("过滤规则编译失败"), QMessageBox::Ok);
        pcap_freealldevs(alldevs);
        return;
    }

    pcap_freealldevs(alldevs);

    if(sendpktthread != NULL){
        delete sendpktthread;
        sendpktthread = NULL;
    }
    sendpktthread = new SendPktThread(adhandle, selfmac, deli_destip, deli_destmac, deli_gateip, deli_gatemac);
    connect(sendpktthread, SIGNAL(updateShowInfo(QString)), this, SLOT(slotUpdateEdit1(QString)));

    sendpktthread->start();
}

void ArpCheatDialog::on_stopBtn_clicked()
{
    ui->startBtn->setEnabled(true);
    ui->stopBtn->setEnabled(false);

    sendpktthread->stopimmediate();
    if(sendpktthread->isRunning() != true){
        delete sendpktthread;
        sendpktthread = NULL;
    }

    arpcheatthread->stop();
    if(arpcheatthread->isRunning() != true){
        delete arpcheatthread;
        arpcheatthread = NULL;
    }

    pcap_close(adhandle);
    free(deli_destmac);
    free(deli_gatemac);
    deli_destmac = NULL;
    deli_gatemac = NULL;

}

//获取设备列表并打开设备
int ArpCheatDialog::initDev(int interface_index)
{
    //获取本机网卡列表
    if(pcap_findalldevs_ex((char*)PCAP_SRC_IF_STRING, NULL, &alldevs, errbuf) == -1){
        QMessageBox::warning(this, "Error", tr("获取本机网卡列表失败"), QMessageBox::Ok);
        return -1;
    }
    //移动指针到用户选择的网卡
    int i;
    for(dev = alldevs, i = 0; i < interface_index - 1; dev = dev->next, i++);
    //打开网卡
    if((adhandle = pcap_open_live(dev->name,    //设备名
                                  65536,    //捕获数据包长度
                                  1,    //设置成混杂模式
                                  1000,    //读超时设置
                                  errbuf  //错误信息缓冲
                                  )) == NULL)
    {
        QMessageBox::warning(this, "Error", tr("网卡接口打开失败"), QMessageBox::Ok);
        pcap_freealldevs(alldevs);
        alldevs = NULL;
        return -1;
    }
    //此处不能先释放掉设备信息列表
    //pcap_freealldevs(alldevs);
    return 0;
}

u_char* ArpCheatDialog::GetSelfMac(char *pDevName)
{
    static u_char mac[6];

    memset(mac, 0, sizeof(mac));

    LPADAPTER lpAdapter = PacketOpenAdapter(pDevName);

    if (!lpAdapter || (lpAdapter->hFile == INVALID_HANDLE_VALUE))
    {
        return NULL;
    }
    //allocate a buffer to get the MAC address
    PPACKET_OID_DATA OidData = (PPACKET_OID_DATA)malloc(6 + sizeof(PACKET_OID_DATA));
    if (OidData == NULL)
    {
        printf("内存分配错误!\n");
        PacketCloseAdapter(lpAdapter);
        return NULL;
    }

    //retrive the adapter MAC querying the NIC driver
    OidData->Oid = OID_802_3_CURRENT_ADDRESS;

    OidData->Length = 6;
    memset(OidData->Data, 0, 6);
    BOOLEAN Status = PacketRequest(lpAdapter, false, OidData);
    if (Status)
    {
        memcpy(mac, (u_char *)(OidData->Data), 6);
    }
    free(OidData);
    PacketCloseAdapter(lpAdapter);
    return mac;
}

//将mac字符串转换成6位MAC地址
void ArpCheatDialog::transMac(const char source[], u_char *dest)
{
    short i;
    int sourceLen = strlen(source);
    unsigned char highByte, lowByte;
    for (i = 0; i < sourceLen; i += 3)
    {
        highByte = toupper(source[i]);
        lowByte  = toupper(source[i + 1]);
        if(highByte > 0x39)
            highByte -= 0x37;
        else
            highByte -= 0x30;
        if(lowByte > 0x39)
            lowByte -= 0x37;
        else
            lowByte -= 0x30;
        dest[i/3] = (highByte << 4) | lowByte;
    }
}

void ArpCheatDialog::slotUpdateEdit(QString msg)
{
    ui->textBrowser->append(msg);
}

void ArpCheatDialog::slotUpdateEdit1(QString msg)
{
    ui->textBrowser->append(msg);
}
