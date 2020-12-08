#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
//    SetDialog *SetDlg = new SetDialog(this);
//    SetDlg->show();

    QDesktopWidget* desktopWidget = QApplication::desktop();
    //获取可用桌面大小
    QRect deskRect = desktopWidget->availableGeometry();
    int  ndeskRectX = deskRect.width();
    int  ndeskRectY = deskRect.height();
    resize(ndeskRectX, ndeskRectY);

    //setWindowFlags(Qt::FramelessWindowHint);
    setWindowFlags(Qt::FramelessWindowHint|Qt::WindowStaysOnTopHint|Qt::Popup|Qt::Tool);

    //QString strurl = "www.baidu.com";
    QString iniFilePath = qApp->applicationDirPath() + "/Config.ini";
    QSettings *configIniRead = new QSettings(iniFilePath, QSettings::IniFormat);

    QString strIP   = configIniRead->value("/Config/IP", "0.0.0.0").toString();

    QString strurl = "https://www.baidu.com";
    //QString strurl = /*"http://" +*/ strIP;
    m_web_view = new CMyWebEngineView(this);
    m_web_view->setAttribute(Qt::WA_DeleteOnClose);
    m_web_view->settings()->setFontFamily(QWebEngineSettings::StandardFont, "Microsoft YaHei");

//   m_web_view->settings()->setAttribute(QWebEngineSettings::PluginsEnabled, true);



//    m_web_view->settings();
//    QWebEngineSettings
    //m_web_view->setAttribute(Qt::WA_SetFont);
//    QFont font;
//    font.setFamily("Microsoft YaHei");
//    //a.setFont(font);
//    m_web_view->setFont(font);

    m_web_view->load(QUrl(strurl));

    QGridLayout *layout = new QGridLayout();
    layout->addWidget(m_web_view);
    layout->setContentsMargins(0, 0, 0, 0);
    setLayout(layout);

    SetDialog *SetDlg = new SetDialog(this);
    //SetDlg->show();

//    Qt::WindowFlags flags = Qt::Dialog;
//    flags |= Qt::WindowCloseButtonHint;
//    SetDlg->setWindowFlags(flags);

    connect(SetDlg, SIGNAL(refresh_url(QString)), this, SLOT(OnRefreshUrl(QString)));
}

Widget::~Widget()
{
}

//void Widget::resizeEvent(QResizeEvent *)
//{
//    m_web_view->resize(this->size());
//}
void Widget::OnRefreshUrl(QString ip)
{

    //QString strurl = "https://www.baidu.com";
    QString strurl = ip;
    m_web_view->load(QUrl(strurl));

    QString iniFilePath = qApp->applicationDirPath() + "/Config.ini";
    QSettings *configIniWrite = new QSettings(iniFilePath, QSettings::IniFormat);

    configIniWrite->setValue("/Config/IP", ip);
}
