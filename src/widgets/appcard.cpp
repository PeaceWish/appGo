#include "appcard.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPixmap>
#include <QEvent>

AppCard::AppCard(QWidget *parent)
    : QWidget(parent)
    , m_iconLabel(new QLabel(this))
    , m_nameLabel(new QLabel(this))
    , m_descLabel(new QLabel(this))
    , m_actionBtn(new QPushButton(this))
    , m_isInstalled(false)
    , m_isHovered(false)
{
    setupUI();
    updateStyle();
}

AppCard::~AppCard() = default;

void AppCard::setAppName(const QString &name)
{
    m_nameLabel->setText(name);
}

void AppCard::setAppDescription(const QString &description)
{
    m_descLabel->setText(description);
}

void AppCard::setAppIcon(const QString &iconPath)
{
    QPixmap pixmap(iconPath);
    if (!pixmap.isNull()) {
        pixmap = pixmap.scaled(48, 48, Qt::KeepAspectRatio, Qt::SmoothTransformation);
        m_iconLabel->setPixmap(pixmap);
    }
}

void AppCard::setInstalled(bool installed)
{
    m_isInstalled = installed;
    m_actionBtn->setText(installed ? "启动" : "安装");
    
    // 更新按钮点击信号连接
    disconnect(m_actionBtn, &QPushButton::clicked, this, nullptr);
    if (installed) {
        connect(m_actionBtn, &QPushButton::clicked, this, &AppCard::startClicked);
    } else {
        connect(m_actionBtn, &QPushButton::clicked, this, &AppCard::installClicked);
    }
    
    updateStyle();
}

void AppCard::enterEvent(QEnterEvent *event)
{
    m_isHovered = true;
    updateStyle();
    QWidget::enterEvent(event);
}

void AppCard::leaveEvent(QEvent *event)
{
    m_isHovered = false;
    updateStyle();
    QWidget::leaveEvent(event);
}

void AppCard::setupUI()
{
    // 设置固定大小
    setFixedSize(280, 100);
    
    // 创建布局
    QHBoxLayout *mainLayout = new QHBoxLayout(this);
    mainLayout->setContentsMargins(12, 12, 12, 12);
    mainLayout->setSpacing(12);
    
    // 添加图标
    m_iconLabel->setFixedSize(48, 48);
    mainLayout->addWidget(m_iconLabel);
    
    // 创建中间的文本布局
    QVBoxLayout *textLayout = new QVBoxLayout();
    textLayout->setSpacing(4);
    
    // 设置名称标签
    QFont nameFont = m_nameLabel->font();
    nameFont.setPointSize(12);
    nameFont.setBold(true);
    m_nameLabel->setFont(nameFont);
    textLayout->addWidget(m_nameLabel);
    
    // 设置描述标签
    m_descLabel->setWordWrap(true);
    QFont descFont = m_descLabel->font();
    descFont.setPointSize(10);
    m_descLabel->setFont(descFont);
    textLayout->addWidget(m_descLabel);
    
    mainLayout->addLayout(textLayout, 1);
    
    // 添加操作按钮
    m_actionBtn->setFixedSize(80, 32);
    mainLayout->addWidget(m_actionBtn);
    
    // 设置默认文本
    m_nameLabel->setText("应用名称");
    m_descLabel->setText("应用描述");
    m_actionBtn->setText("安装");
}

void AppCard::updateStyle()
{
    QString cardStyle = QString(
        "QWidget {"
        "  background-color: %1;"
        "  border: 1px solid %2;"
        "  border-radius: 8px;"
        "}"
        "QLabel {"
        "  background: transparent;"
        "  border: none;"
        "}"
        "QPushButton {"
        "  background-color: %3;"
        "  color: white;"
        "  border: none;"
        "  border-radius: 4px;"
        "  padding: 4px 12px;"
        "}"
        "QPushButton:hover {"
        "  background-color: %4;"
        "}"
    )
    .arg(m_isHovered ? "#f5f5f5" : "#ffffff")
    .arg(m_isHovered ? "#e0e0e0" : "#f0f0f0")
    .arg(m_isInstalled ? "#28a745" : "#007AFF")
    .arg(m_isInstalled ? "#218838" : "#0056b3");
    
    setStyleSheet(cardStyle);
} 