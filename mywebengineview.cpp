#include "mywebengineview.h"

CMyWebEngineView::CMyWebEngineView(QWidget *parent) : QWebEngineView(parent)
{
    m_pContextMenu = new QMenu;

    m_pBackAct = new QAction(QIcon::fromTheme(QStringLiteral("go-previous")), tr("返回"));
    m_pForwardAct = new QAction(QIcon::fromTheme(QStringLiteral("go-next")), tr("前进"));
    m_pReloadAct = new QAction(QIcon::fromTheme(QStringLiteral("view-refresh")), tr("刷新"));

    m_pContextMenu->addAction(m_pBackAct);
    m_pContextMenu->addAction(m_pForwardAct);
    m_pContextMenu->addAction(m_pReloadAct);
    connect(m_pBackAct, &QAction::triggered, this, &QWebEngineView::back);
    connect(m_pForwardAct, &QAction::triggered, this, &QWebEngineView::forward);
    connect(m_pReloadAct, &QAction::triggered, this, &QWebEngineView::reload);

    setContextMenuPolicy(Qt::DefaultContextMenu);
}

CMyWebEngineView::~CMyWebEngineView()
{

}

void CMyWebEngineView::contextMenuEvent(QContextMenuEvent* event)
{
    m_pBackAct->setEnabled(this->history()->canGoBack());
    m_pForwardAct->setEnabled(this->history()->canGoForward());

    m_pContextMenu->exec(QCursor::pos());
}




















