#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTabWidget>
#include "widgets/appcard.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;

protected:
    // 禁用关闭、最小化、最大化按钮
    void closeEvent(QCloseEvent *event) override;
    void changeEvent(QEvent *event) override;

private slots:
    // 处理卡片事件
    void handleCardClicked(AppCard *card);
    void handleCardDoubleClicked(AppCard *card);
    void handleCardInstall(AppCard *card);
    void handleCardUninstall(AppCard *card);
    void handleCardStart(AppCard *card);

private:
    void setupUI();
    void createTabs();

    QTabWidget *m_tabWidget;
    QWidget *m_appStoreTab;
    QWidget *m_installedTab;
};

#endif // MAINWINDOW_H 