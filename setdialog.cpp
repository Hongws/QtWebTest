#include "setdialog.h"

SetDialog::SetDialog(QWidget *parent) : QDialog(parent)
{

    // 去掉问号，只保留关闭
    //setWindowFlags(Qt::CustomizeWindowHint | Qt::WindowCloseButtonHint);

    //setWindowTitle("Configuration");
    setWindowTitle(tr("配置"));

    Qt::WindowFlags flags= this->windowFlags();
    setWindowFlags(flags&~Qt::WindowContextHelpButtonHint);


    setFixedSize(300, 200);

    m_label_url = new QLabel;
    m_label_url->setText(tr("IP地址："));
    m_label_url->setFixedSize(40, 30);

    m_ledit_url = new QLineEdit;
    m_ledit_url->setFixedSize(180, 30);

    m_pbtn_ok = new QPushButton;
    m_pbtn_ok->setFixedSize(240, 30);
    m_pbtn_ok->setText(tr("确认"));

    QGridLayout *layout = new QGridLayout;
    layout->addWidget(m_label_url, 0, 0, 1, 1);
    layout->addWidget(m_ledit_url, 0, 1, 1, 1);
    layout->addWidget(m_pbtn_ok, 1, 0, 1, 2);
    // 设置水平间距
    layout->setHorizontalSpacing(20);
    // 设置垂直间距
    layout->setVerticalSpacing(30);

    layout->setContentsMargins(30, 50, 30, 60);
    setLayout(layout);

    connect(m_pbtn_ok, SIGNAL(clicked()), this, SLOT(OnClickedOK()));

//    m_pbtn_quit = new QPushButton;
//    m_pbtn_quit->setFixedSize(100, 30);

    //setStyleSheet("background-color:#000000;");

    //connect(m_pbtn_ok, SIGNAL(clicked()), this, SIGNAL(refresh_url()));

//    m_SysTrayIcon = nullptr;
//    m_Menu = nullptr;
//    m_ShowMainAction = nullptr;
//    m_ExitAppAction = nullptr;

    this->hide();
    //新建QSystemTrayIcon对象
    m_SysTrayIcon = new QSystemTrayIcon(this);
    //新建托盘要显示的icon
    QString strIcon = QString("%1/Resources/images/myicon.ico").arg(qApp->applicationDirPath());
    QIcon icon = QIcon(strIcon);
    //QIcon icon = QIcon("../IMClient/Resources/GG64.png");
    //将icon设到QSystemTrayIcon对象中
    m_SysTrayIcon->setIcon(icon);
    //当鼠标移动到托盘上的图标时，会显示此处设置的内容
    //m_SysTrayIcon->setToolTip("Equipment");
    m_SysTrayIcon->setToolTip(tr("网页测试"));
    //在系统托盘显示此对象
    m_SysTrayIcon->show();
    //connect(m_SysTrayIcon, SIGNAL(activated(QSystemTrayIcon::ActivationReason)), this, SLOT(on_activatedSysTrayIcon(QSystemTrayIcon::ActivationReason)));
    //建立托盘操作的菜单
    createActions();
    createMenu();

}
//#include <qstring.h>
void SetDialog::OnClickedOK()
{
    QString url = m_ledit_url->text();

    if( url.isEmpty())
    {
        QMessageBox::about(this, tr("提示"), tr("ip地址不能为空"));
        return;
    }
    //正则表达式控制
//    QRegExp regExpAdd("\\b(?:(?:25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\\.){3}(?:25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\\:([0-9]|[1-9]\\d|[1-9]\\d{2}|[1-9]\\d{3}|[1-5]\\d{4}|6[0-4]\\d{3}|65[0-4]\\d{2}|655[0-2]\\d|6553[0-5])\\b");
//    QRegExpValidator *patternAddr= new QRegExpValidator(regExpAdd, this);

//    QValidator::State res;
//    int pos = 0;
//    res = patternAddr->validate(url, pos);
//    if(QValidator::Acceptable == res)
//    {
     emit refresh_url(url);
//        emit close();
//    }
//    else
//        QMessageBox::about(this, tr("提示"), tr("请输入正确的ip地址"));

    emit close();

//    //m_ledit_url->setValidator(patternAddr);
//    //bool n = url.contains(patternAddr);

//    int pos = url.indexOf(patternAddr);              // 0, position of the first match.
//                                            // Returns -1 if str is not found.
//                                            // You can also use rx.indexIn(str);
//    qDebug() << pos;



}


//#include <QDebug>
void SetDialog::closeEvent(QCloseEvent *event)
{
    //隐藏程序主窗口
//     this->hide();
//     //新建QSystemTrayIcon对象
//     m_SysTrayIcon = new QSystemTrayIcon(this);
//     //新建托盘要显示的icon
//     QString strIcon = QString("%1/Resources/images/myicon.ico").arg(qApp->applicationDirPath());
//     QIcon icon = QIcon(strIcon);
//     //QIcon icon = QIcon("../IMClient/Resources/GG64.png");
//     //将icon设到QSystemTrayIcon对象中
//     m_SysTrayIcon->setIcon(icon);
//     //当鼠标移动到托盘上的图标时，会显示此处设置的内容
//     m_SysTrayIcon->setToolTip(tr("装备柜 "));
//     //在系统托盘显示此对象
//     //m_SysTrayIcon->show();
//    //return;

//     //connect(m_SysTrayIcon, SIGNAL(activated(QSystemTrayIcon::ActivationReason)), this, SLOT(on_activatedSysTrayIcon(QSystemTrayIcon::ActivationReason)));

//     //建立托盘操作的菜单
//     createActions();
//     createMenu();
}


void SetDialog::createActions()
{
    //m_ShowMainAction = new QAction("Open Configuration",this);
    m_ShowMainAction = new QAction(tr("配置"),this);
    connect(m_ShowMainAction, SIGNAL(triggered()), this, SLOT(on_showMainAction()));

    //m_ExitAppAction = new QAction("Quit",this);
    m_ExitAppAction = new QAction(tr("退出"),this);
    connect(m_ExitAppAction, SIGNAL(triggered()), this, SLOT(on_exitAppAction()));
}

void SetDialog::createMenu()
{
    m_Menu = new QMenu(this);
    m_Menu->addAction(m_ShowMainAction);
    m_Menu->addSeparator();
    m_Menu->addAction(m_ExitAppAction);
    m_SysTrayIcon->setContextMenu(m_Menu);
}

void SetDialog::on_showMainAction()
{
    QString iniFilePath = qApp->applicationDirPath() + "/Config.ini";
    QSettings *configIniRead = new QSettings(iniFilePath, QSettings::IniFormat);

    QString strIP   = configIniRead->value("/Config/IP", "0.0.0.0").toString();

    m_ledit_url->setText(strIP);

    this->show();
}

void SetDialog::on_exitAppAction()
{
    //exit(0);
    QCoreApplication::exit();
}

//void SetDialog::on_activatedSysTrayIcon(QSystemTrayIcon::ActivationReason reason)
//{
//    switch(reason){
//    case QSystemTrayIcon::Trigger:
//        m_SysTrayIcon->showMessage(tr("123"), tr("345"), QSystemTrayIcon::Information, 1000);
//        break;
//    case QSystemTrayIcon::DoubleClick:
//        this->show();
//        break;
//    default:
//        break;
//    }
//}










