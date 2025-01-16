#include "mainwindow.h"
#include <QApplication>
#include <QScreen>
#include <QCloseEvent>
#include <QVBoxLayout>
#include <QStyle>
#include <QMessageBox>
#include "widgets/appcard.h"
#include "widgets/appgridview.h"

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
    setAttribute(Qt::WA_TranslucentBackground, false);
    
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
        "QTabWidget::pane { border: none; background: white; }"
        "QTabWidget::tab-bar { alignment: center; }"
        "QTabBar::tab { background: #f0f0f0; padding: 8px 20px; margin: 0 2px; min-width: 100px; }"
        "QTabBar::tab:selected { background: #ffffff; border-bottom: 2px solid #007AFF; }"
    );
}

void MainWindow::createTabs()
{
    // 设置应用商城标签页
    QVBoxLayout *storeLayout = new QVBoxLayout(m_appStoreTab);
    storeLayout->setContentsMargins(0, 0, 0, 0);
    
    // 创建应用网格视图
    AppGridView *storeGridView = new AppGridView(m_appStoreTab);
    storeLayout->addWidget(storeGridView);
    
    // 连接信号
    connect(storeGridView, &AppGridView::cardClicked, this, &MainWindow::handleCardClicked);
    connect(storeGridView, &AppGridView::cardDoubleClicked, this, &MainWindow::handleCardDoubleClicked);
    connect(storeGridView, &AppGridView::cardInstallClicked, this, &MainWindow::handleCardInstall);
    connect(storeGridView, &AppGridView::cardUninstallClicked, this, &MainWindow::handleCardUninstall);
    connect(storeGridView, &AppGridView::cardStartClicked, this, &MainWindow::handleCardStart);
    
    // 添加测试卡片
    for (int i = 1; i <= 10; ++i) {
        AppCard *card = new AppCard();
        card->setAppName(QString("测试应用 %1").arg(i));
        card->setAppDescription(QString("这是第 %1 个测试应用，用于验证网格布局的显示效果。").arg(i));
        storeGridView->addAppCard(card);
    }
    
    m_tabWidget->addTab(m_appStoreTab, "应用商城");

    // 设置已安装标签页
    QVBoxLayout *installedLayout = new QVBoxLayout(m_installedTab);
    installedLayout->setContentsMargins(0, 0, 0, 0);
    
    // 创建已安装应用的网格视图
    AppGridView *installedGridView = new AppGridView(m_installedTab);
    installedLayout->addWidget(installedGridView);
    
    // 连接信号
    connect(installedGridView, &AppGridView::cardClicked, this, &MainWindow::handleCardClicked);
    connect(installedGridView, &AppGridView::cardDoubleClicked, this, &MainWindow::handleCardDoubleClicked);
    connect(installedGridView, &AppGridView::cardInstallClicked, this, &MainWindow::handleCardInstall);
    connect(installedGridView, &AppGridView::cardUninstallClicked, this, &MainWindow::handleCardUninstall);
    connect(installedGridView, &AppGridView::cardStartClicked, this, &MainWindow::handleCardStart);
    
    // 添加测试卡片（已安装状态）
    for (int i = 1; i <= 5; ++i) {
        AppCard *card = new AppCard();
        card->setAppName(QString("已安装应用 %1").arg(i));
        card->setAppDescription(QString("这是第 %1 个已安装的应用，点击启动按钮运行。").arg(i));
        card->setInstalled(true);
        installedGridView->addAppCard(card);
    }
    
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

void MainWindow::handleCardClicked(AppCard *card)
{
    if (card) {
        QMessageBox::information(this, "卡片点击",
            QString("点击了应用：%1").arg(card->appName()));
    }
}

void MainWindow::handleCardDoubleClicked(AppCard *card)
{
    if (card) {
        QMessageBox::information(this, "卡片双击",
            QString("双击了应用：%1").arg(card->appName()));
    }
}

void MainWindow::handleCardInstall(AppCard *card)
{
    if (card) {
        QMessageBox::information(this, "安装应用",
            QString("正在安装应用：%1").arg(card->appName()));
    }
}

void MainWindow::handleCardUninstall(AppCard *card)
{
    if (card) {
        QMessageBox::information(this, "卸载应用",
            QString("正在卸载应用：%1").arg(card->appName()));
    }
}

void MainWindow::handleCardStart(AppCard *card)
{
    if (card) {
        QMessageBox::information(this, "启动应用",
            QString("正在启动应用：%1").arg(card->appName()));
    }
}