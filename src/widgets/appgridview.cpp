#include "appgridview.h"
#include <QResizeEvent>
#include <QScrollBar>

AppGridView::AppGridView(QWidget *parent)
    : QScrollArea(parent)
    , m_container(new QWidget(this))
    , m_gridLayout(new QGridLayout(m_container))
    , m_columnsCount(3)  // 默认每行显示3个卡片
    , m_spacing(20)      // 默认间距20像素
{
    setupUI();
}

AppGridView::~AppGridView() = default;

void AppGridView::addAppCard(AppCard *card)
{
    if (!card) return;
    
    m_cards.append(card);
    connectCardSignals(card);
    updateLayout();
}

void AppGridView::clearCards()
{
    for (auto card : m_cards) {
        m_gridLayout->removeWidget(card);
        card->deleteLater();
    }
    m_cards.clear();
}

void AppGridView::setColumnsCount(int count)
{
    if (count > 0 && count != m_columnsCount) {
        m_columnsCount = count;
        updateLayout();
    }
}

int AppGridView::cardsCount() const
{
    return m_cards.count();
}

void AppGridView::resizeEvent(QResizeEvent *event)
{
    QScrollArea::resizeEvent(event);
    calculateGrid();
}

void AppGridView::setupUI()
{
    // 设置滚动区域的属性
    setWidgetResizable(true);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    setFrameShape(QFrame::NoFrame);
    
    // 设置容器widget
    setWidget(m_container);
    
    // 设置网格布局的属性
    m_gridLayout->setSpacing(m_spacing);
    m_gridLayout->setContentsMargins(m_spacing, m_spacing, m_spacing, m_spacing);
    
    // 设置背景色
    setStyleSheet("QScrollArea { background: transparent; }");
    m_container->setStyleSheet("QWidget { background: transparent; }");
}

void AppGridView::updateLayout()
{
    // 清空现有布局
    while (m_gridLayout->count() > 0) {
        m_gridLayout->takeAt(0);
    }
    
    // 重新添加卡片到网格布局
    int row = 0;
    int col = 0;
    for (auto card : m_cards) {
        m_gridLayout->addWidget(card, row, col);
        col++;
        if (col >= m_columnsCount) {
            col = 0;
            row++;
        }
    }
}

void AppGridView::calculateGrid()
{
    // 获取可用宽度
    int availableWidth = width() - (m_spacing * 2) - verticalScrollBar()->sizeHint().width();
    
    // 计算合适的列数
    int cardWidth = 280; // AppCard的固定宽度
    int possibleColumns = (availableWidth + m_spacing) / (cardWidth + m_spacing);
    
    // 确保至少显示一列
    possibleColumns = qMax(1, possibleColumns);
    
    // 如果列数发生变化，更新布局
    if (possibleColumns != m_columnsCount) {
        setColumnsCount(possibleColumns);
    }
}

void AppGridView::connectCardSignals(AppCard *card)
{
    // 连接卡片的所有信号
    connect(card, &AppCard::cardClicked, this, [this, card]() {
        emit cardClicked(card);
    });
    
    connect(card, &AppCard::cardDoubleClicked, this, [this, card]() {
        emit cardDoubleClicked(card);
    });
    
    connect(card, &AppCard::installClicked, this, [this, card]() {
        emit cardInstallClicked(card);
    });
    
    connect(card, &AppCard::uninstallClicked, this, [this, card]() {
        emit cardUninstallClicked(card);
    });
    
    connect(card, &AppCard::startClicked, this, [this, card]() {
        emit cardStartClicked(card);
    });
} 