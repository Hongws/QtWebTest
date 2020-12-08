#ifndef SETDIALOG_H
#define SETDIALOG_H

#include <QDialog>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include <QGridLayout>
#include <QSystemTrayIcon>
#include <QApplication>
#include <QAction>
#include <QMenu>
#include <QRegExpValidator>
#include <QMessageBox>
#include <QSettings>

#pragma execution_character_set("utf-8")

class SetDialog : public QDialog
{
    Q_OBJECT
public:
    explicit SetDialog(QWidget *parent = nullptr);

    void createActions();
    void createMenu();

signals:
    void refresh_url(QString);

public slots:
   // void on_activatedSysTrayIcon(QSystemTrayIcon::ActivationReason reason);
    void on_showMainAction();
    void on_exitAppAction();
    void OnClickedOK();

protected:
    void closeEvent(QCloseEvent *event);

private:
    QLabel          *m_label_url;
    QLineEdit       *m_ledit_url;
    QPushButton     *m_pbtn_ok;
    //QPushButton     *m_pbtn_quit;
    QSystemTrayIcon *m_SysTrayIcon;
    QMenu           *m_Menu;
    QAction         *m_ShowMainAction;
    QAction         *m_ExitAppAction;


};

#endif // SETDIALOG_H
