#include "mainwindow.h"
#include <QApplication>
#include <QScreen>
#include <QCloseEvent>
#include <QVBoxLayout>
#include <QStyle>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , m_tabWidget(new QTabWidget(this))
    , m_appStoreTab(new QWidget(this))
    , m_installedTab(new QWidget(this))
{
    setupUI();
    createTabs();
}

MainWindow::~MainWindow() = default;

void MainWindow::setupUI()
{
    // 设置窗口标志，保留关闭按钮
    setWindowFlags(Qt::Window);
    
    // 设置窗口属性
    setAttribute(Qt::WA_TranslucentBackground);
    
    // 在macOS上启用原生全屏
    #ifdef Q_OS_MAC
        setUnifiedTitleAndToolBarOnMac(true);
    #endif
    
    // 设置全屏
    QScreen *screen = QApplication::primaryScreen();
    if (screen) {
        setGeometry(screen->availableGeometry());
    }
    
    // 设置中央部件
    setCentralWidget(m_tabWidget);
    
    // 设置样式
    setStyleSheet(
        "QMainWindow { background: white; }"
        "QTabWidget::pane { border: none; }"
        "QTabWidget::tab-bar { alignment: center; }"
        "QTabBar::tab { background: #f0f0f0; padding: 8px 20px; margin: 0 2px; }"
        "QTabBar::tab:selected { background: #ffffff; border-bottom: 2px solid #007AFF; }"
    );
}

void MainWindow::createTabs()
{
    // 设置应用商城标签页
    QVBoxLayout *storeLayout = new QVBoxLayout(m_appStoreTab);
    storeLayout->setContentsMargins(20, 20, 20, 20);
    m_tabWidget->addTab(m_appStoreTab, "应用商城");

    // 设置已安装标签页
    QVBoxLayout *installedLayout = new QVBoxLayout(m_installedTab);
    installedLayout->setContentsMargins(20, 20, 20, 20);
    m_tabWidget->addTab(m_installedTab, "已安装");
    
    // 设置标签页的样式
    m_tabWidget->setDocumentMode(true);
    m_tabWidget->setElideMode(Qt::ElideNone);
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    // 允许关闭窗口
    event->accept();
}

void MainWindow::changeEvent(QEvent *event)
{
    if (event->type() == QEvent::WindowStateChange) {
        if (windowState() != Qt::WindowFullScreen) {
            QScreen *screen = QApplication::primaryScreen();
            if (screen) {
                setGeometry(screen->availableGeometry());
            }
        }
    }
    QMainWindow::changeEvent(event);
}