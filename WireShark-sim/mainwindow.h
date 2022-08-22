#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#define WPCAP
#define HAVE_REMOTE
#include <pcap.h>
#include <remote-ext.h>
#include <winsock.h>
#include <protocol.h>
#include <capthread.h>
#include <QAction>
#include <QMenu>
#include <QIcon>
#include <QFileDialog>
#include <QFile>
#include <QCloseEvent>
#include <arpcheatdialog.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    //my function
    int sniff_initCap();       //初始化
    int sniff_startCap();      //开始捕获数据
    void showHexData(u_char*, int len);     //显示数据包中的十六进制内容
    void createActions();
    void createMenus();
    bool saveFile(const QString &filename);     //将临时数据包文件拷贝到指定文件中
    void closeEvent(QCloseEvent *event);

    //my data
    int devCount;
    char errbuf[PCAP_ERRBUF_SIZE];
    char filepath[512];     //临时数据包保存路径
    pcap_if_t *alldevs;
    pcap_if_t *dev;
    pcap_t *adhandle;
    pcap_dumper_t *dumpfile;

    pktCount *npacket;
    CapThread *capthread;

    datapktVec datapktLink;
    dataVec dataCharLink;
    int RowCount;
    bool isFileSaved;

private slots:
    void on_startBtn_clicked();
    void updateTableWidget(QString timestr, QString srcMac, QString destMac, QString len, QString protoType, QString srcIP, QString dstIP);
    void updateCapCalculate();
    void on_finishBtn_clicked();
    void showProtoTree(int row, int column);
    void slotopen();
    void slotsave();
    void slotCheat();

    void on_clearBtn_clicked();

private:
    Ui::MainWindow *ui;
    QAction *openAction;
    QAction *saveAction;
    QAction *exitAction;
    QAction *bootCheatAction;
    QMenu *fileMenu;
    QMenu *cheatMenu;

};

#endif // MAINWINDOW_H
