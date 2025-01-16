#include "appgridview.h"
#include <QResizeEvent>
#include <QScrollBar>
#include <QVBoxLayout>

AppGridView::AppGridView(QWidget *parent)
    : QScrollArea(parent)
    , m_container(new QWidget(this))
    , m_gridLayout(new QGridLayout(m_container))
    , m_columnsCount(3)  // 默认每行显示3个卡片
    , m_spacing(20)      // 默认间距20像素
    , m_pagination(new PaginationWidget(this))
{
    setupUI();
}

AppGridView::~AppGridView() = default;

void AppGridView::addAppCard(AppCard *card)
{
    if (!card) return;
    
    m_cards.append(card);
    connectCardSignals(card);
    
    // 更新总页数
    m_pagination->setTotalPages((m_cards.size() + m_pagination->itemsPerPage() - 1) / m_pagination->itemsPerPage());
    
    // 更新显示
    updateVisibleCards();
}

void AppGridView::clearCards()
{
    for (auto card : m_cards) {
        m_gridLayout->removeWidget(card);
        card->deleteLater();
    }
    m_cards.clear();
    m_visibleCards.clear();
    m_pagination->setTotalPages(1);
    m_pagination->setCurrentPage(1);
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

void AppGridView::setCurrentPage(int page)
{
    m_pagination->setCurrentPage(page);
}

void AppGridView::setItemsPerPage(int count)
{
    m_pagination->setItemsPerPage(count);
}

int AppGridView::currentPage() const
{
    return m_pagination->currentPage();
}

int AppGridView::itemsPerPage() const
{
    return m_pagination->itemsPerPage();
}

int AppGridView::totalPages() const
{
    return m_pagination->totalPages();
}

void AppGridView::resizeEvent(QResizeEvent *event)
{
    QScrollArea::resizeEvent(event);
    calculateGrid();
}

void AppGridView::handlePageChanged(int page)
{
    updateVisibleCards();
    emit pageChanged(page);
}

void AppGridView::handleItemsPerPageChanged(int count)
{
    // 更新总页数
    m_pagination->setTotalPages((m_cards.size() + count - 1) / count);
    
    // 更新显示
    updateVisibleCards();
    emit itemsPerPageChanged(count);
}

void AppGridView::setupUI()
{
    // 创建主布局
    QWidget *mainWidget = new QWidget(this);
    QVBoxLayout *mainLayout = new QVBoxLayout(mainWidget);
    mainLayout->setContentsMargins(0, 0, 0, 0);
    mainLayout->setSpacing(20);
    
    // 设置滚动区域的属性
    setWidgetResizable(true);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    setFrameShape(QFrame::NoFrame);
    
    // 设置容器widget
    m_container->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    mainLayout->addWidget(m_container);
    
    // 设置网格布局的属性
    m_gridLayout->setSpacing(m_spacing);
    m_gridLayout->setContentsMargins(m_spacing, m_spacing, m_spacing, m_spacing);
    
    // 添加分页控件
    mainLayout->addWidget(m_pagination);
    
    // 设置主widget
    setWidget(mainWidget);
    
    // 连接分页信号
    connect(m_pagination, &PaginationWidget::pageChanged,
            this, &AppGridView::handlePageChanged);
    connect(m_pagination, &PaginationWidget::itemsPerPageChanged,
            this, &AppGridView::handleItemsPerPageChanged);
    
    // 设置背景色
    setStyleSheet("QScrollArea { background: transparent; }");
    mainWidget->setStyleSheet("QWidget { background: transparent; }");
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
    for (auto card : m_visibleCards) {
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

void AppGridView::updateVisibleCards()
{
    // 隐藏所有卡片
    for (auto card : m_cards) {
        card->hide();
    }
    
    // 清空可见卡片列表
    m_visibleCards.clear();
    
    // 计算当前页的卡片范围
    int startIndex = (currentPage() - 1) * itemsPerPage();
    int endIndex = qMin(startIndex + itemsPerPage(), m_cards.size());
    
    // 添加可见卡片
    for (int i = startIndex; i < endIndex; ++i) {
        AppCard *card = m_cards[i];
        card->show();
        m_visibleCards.append(card);
    }
    
    // 更新布局
    updateLayout();
} 