#ifndef CMYWEBENGINEVIEW_H
#define CMYWEBENGINEVIEW_H

#include <QWebEngineView>
#include <QMenu>
#include <QAction>
#include <QIcon>
#include <QWebEngineHistory>

class CMyWebEngineView : public QWebEngineView
{
    Q_OBJECT
public:
    CMyWebEngineView(QWidget* parent = nullptr);
    ~CMyWebEngineView();
protected:
    void contextMenuEvent(QContextMenuEvent* event);
private:
    QMenu*      m_pContextMenu;
    QAction*    m_pBackAct;
    QAction*    m_pForwardAct;
    QAction*    m_pReloadAct;
};

#endif // CMYWEBENGINEVIEW_H
