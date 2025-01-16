#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTabWidget>
#include <QLabel>

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

private:
    void setupUI();
    void createTabs();

    QTabWidget *m_tabWidget;
    QWidget *m_appStoreTab;
    QWidget *m_installedTab;
};

#endif // MAINWINDOW_H 