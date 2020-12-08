#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QWebEngineView>
#include <QDesktopWidget>
#include <QApplication>
#include <QGridLayout>
#include <QSettings>
#include "setdialog.h"
#include <QWebEngineSettings>
#include "mywebengineview.h"

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

//protected:
//    void resizeEvent(QResizeEvent *);
public slots:
    void OnRefreshUrl(QString);

private:
     CMyWebEngineView *m_web_view;
};
#endif // WIDGET_H
