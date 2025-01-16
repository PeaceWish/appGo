#include "mainwindow.h"
#include "widgets/appcard.h"
#include "widgets/appgridview.h"
#include <QVBoxLayout>
#include <QTabWidget>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setupUI();
}

MainWindow::~MainWindow() = default;

void MainWindow::setupUI()
{
    // 设置窗口属性
    resize(1200, 800);
    setWindowTitle("应用商城");
    setAttribute(Qt::WA_TranslucentBackground, false);
    
    // 创建中央部件
    QWidget *centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);
    
    // 创建主布局
    QVBoxLayout *mainLayout = new QVBoxLayout(centralWidget);
    mainLayout->setContentsMargins(0, 0, 0, 0);
    mainLayout->setSpacing(0);
    
    // 创建标签页
    QTabWidget *tabWidget = new QTabWidget(this);
    mainLayout->addWidget(tabWidget);
    
    // 设置标签页样式
    tabWidget->setStyleSheet(
        "QTabWidget::pane {"
        "  border: none;"
        "  background: white;"
        "}"
        "QTabBar::tab {"
        "  padding: 8px 20px;"
        "  background: #f0f0f0;"
        "  border: none;"
        "  border-top-left-radius: 4px;"
        "  border-top-right-radius: 4px;"
        "  margin-right: 2px;"
        "}"
        "QTabBar::tab:selected {"
        "  background: white;"
        "  color: #007bff;"
        "}"
    );
    
    // 创建应用商城标签页
    QWidget *storeTab = new QWidget();
    QVBoxLayout *storeLayout = new QVBoxLayout(storeTab);
    AppGridView *storeGrid = new AppGridView(storeTab);
    storeLayout->addWidget(storeGrid);
    
    // 添加测试卡片到应用商城
    QStringList storeApps = {
        "微信", "QQ", "钉钉", "企业微信", "腾讯会议",
        "网易云音乐", "QQ音乐", "酷狗音乐", "酷我音乐", "虾米音乐",
        "Chrome", "Firefox", "Edge", "Opera", "Safari",
        "VSCode", "Sublime Text", "Atom", "WebStorm", "PyCharm",
        "PhotoShop", "Illustrator", "Premiere", "After Effects", "Lightroom"
    };
    
    for (const QString &appName : storeApps) {
        AppCard *card = new AppCard(storeGrid);
        card->setAppName(appName);
        card->setInstalled(false);
        storeGrid->addAppCard(card);
    }
    
    // 创建已安装标签页
    QWidget *installedTab = new QWidget();
    QVBoxLayout *installedLayout = new QVBoxLayout(installedTab);
    AppGridView *installedGrid = new AppGridView(installedTab);
    installedLayout->addWidget(installedGrid);
    
    // 添加测试卡片到已安装
    QStringList installedApps = {
        "微信", "QQ", "Chrome", "VSCode", "PhotoShop",
        "网易云音乐", "钉钉", "企业微信", "Firefox", "Sublime Text",
        "QQ音乐", "腾讯会议", "Edge", "Atom", "Illustrator"
    };
    
    for (const QString &appName : installedApps) {
        AppCard *card = new AppCard(installedGrid);
        card->setAppName(appName);
        card->setInstalled(true);
        installedGrid->addAppCard(card);
    }
    
    // 添加标签页到QTabWidget
    tabWidget->addTab(storeTab, "应用商城");
    tabWidget->addTab(installedTab, "已安装");
    
    // 连接信号
    connect(storeGrid, &AppGridView::cardClicked, this, &MainWindow::handleCardClicked);
    connect(storeGrid, &AppGridView::cardDoubleClicked, this, &MainWindow::handleCardDoubleClicked);
    connect(storeGrid, &AppGridView::cardInstallClicked, this, &MainWindow::handleCardInstall);
    connect(storeGrid, &AppGridView::cardUninstallClicked, this, &MainWindow::handleCardUninstall);
    connect(storeGrid, &AppGridView::cardStartClicked, this, &MainWindow::handleCardStart);
    
    connect(installedGrid, &AppGridView::cardClicked, this, &MainWindow::handleCardClicked);
    connect(installedGrid, &AppGridView::cardDoubleClicked, this, &MainWindow::handleCardDoubleClicked);
    connect(installedGrid, &AppGridView::cardInstallClicked, this, &MainWindow::handleCardInstall);
    connect(installedGrid, &AppGridView::cardUninstallClicked, this, &MainWindow::handleCardUninstall);
    connect(installedGrid, &AppGridView::cardStartClicked, this, &MainWindow::handleCardStart);
}

void MainWindow::handleCardClicked(AppCard *card)
{
    qDebug() << "Card clicked:" << card->appName();
}

void MainWindow::handleCardDoubleClicked(AppCard *card)
{
    qDebug() << "Card double clicked:" << card->appName();
}

void MainWindow::handleCardInstall(AppCard *card)
{
    qDebug() << "Installing:" << card->appName();
}

void MainWindow::handleCardUninstall(AppCard *card)
{
    qDebug() << "Uninstalling:" << card->appName();
}

void MainWindow::handleCardStart(AppCard *card)
{
    qDebug() << "Starting:" << card->appName();
}