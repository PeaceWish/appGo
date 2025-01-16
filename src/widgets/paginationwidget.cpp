#include "paginationwidget.h"
#include <QHBoxLayout>
#include <QStyle>

PaginationWidget::PaginationWidget(QWidget *parent)
    : QWidget(parent)
    , m_prevBtn(new QPushButton("上一页", this))
    , m_nextBtn(new QPushButton("下一页", this))
    , m_totalLabel(new QLabel(this))
    , m_currentPage(1)
    , m_totalPages(1)
    , m_itemsPerPage(10)
    , m_maxVisiblePages(5)
{
    setupUI();
    updateButtons();
}

PaginationWidget::~PaginationWidget()
{
    qDeleteAll(m_pageButtons);
    m_pageButtons.clear();
}

void PaginationWidget::setTotalPages(int total)
{
    if (total < 1) total = 1;
    if (m_totalPages != total) {
        m_totalPages = total;
        if (m_currentPage > m_totalPages) {
            setCurrentPage(m_totalPages);
        }
        updatePageNumbers();
        updateButtons();
    }
}

void PaginationWidget::setCurrentPage(int page)
{
    if (page < 1) page = 1;
    if (page > m_totalPages) page = m_totalPages;
    
    if (m_currentPage != page) {
        m_currentPage = page;
        updatePageNumbers();
        updateButtons();
        emit pageChanged(page);
    }
}

void PaginationWidget::setItemsPerPage(int count)
{
    if (count > 0 && m_itemsPerPage != count) {
        m_itemsPerPage = count;
        emit itemsPerPageChanged(count);
    }
}

void PaginationWidget::handlePrevClicked()
{
    if (m_currentPage > 1) {
        setCurrentPage(m_currentPage - 1);
    }
}

void PaginationWidget::handleNextClicked()
{
    if (m_currentPage < m_totalPages) {
        setCurrentPage(m_currentPage + 1);
    }
}

void PaginationWidget::handlePageNumberClicked()
{
    QPushButton *button = qobject_cast<QPushButton*>(sender());
    if (button) {
        bool ok;
        int page = button->property("page").toInt(&ok);
        if (ok) {
            setCurrentPage(page);
        }
    }
}

void PaginationWidget::setupUI()
{
    QHBoxLayout *layout = new QHBoxLayout(this);
    layout->setContentsMargins(0, 0, 0, 0);
    layout->setSpacing(8);
    
    // 添加上一页按钮
    m_prevBtn->setFixedSize(80, 32);
    layout->addWidget(m_prevBtn);
    
    // 添加页码按钮的占位符
    layout->addStretch();
    
    // 添加下一页按钮
    m_nextBtn->setFixedSize(80, 32);
    layout->addWidget(m_nextBtn);
    
    // 添加总页数标签
    m_totalLabel->setFixedHeight(32);
    layout->addWidget(m_totalLabel);
    
    // 连接信号
    connect(m_prevBtn, &QPushButton::clicked, this, &PaginationWidget::handlePrevClicked);
    connect(m_nextBtn, &QPushButton::clicked, this, &PaginationWidget::handleNextClicked);
    
    // 设置样式
    QString btnStyle = 
        "QPushButton {"
        "  background-color: #f8f9fa;"
        "  border: 1px solid #dee2e6;"
        "  border-radius: 4px;"
        "  color: #007bff;"
        "  padding: 4px 12px;"
        "}"
        "QPushButton:hover {"
        "  background-color: #e9ecef;"
        "  border-color: #dee2e6;"
        "  color: #0056b3;"
        "}"
        "QPushButton:disabled {"
        "  background-color: #e9ecef;"
        "  border-color: #dee2e6;"
        "  color: #6c757d;"
        "}";
    
    setStyleSheet(btnStyle);
}

void PaginationWidget::updateButtons()
{
    m_prevBtn->setEnabled(m_currentPage > 1);
    m_nextBtn->setEnabled(m_currentPage < m_totalPages);
    m_totalLabel->setText(QString("共 %1 页").arg(m_totalPages));
    
    // 更新页码按钮状态
    for (auto btn : m_pageButtons) {
        bool ok;
        int page = btn->property("page").toInt(&ok);
        if (ok) {
            btn->setProperty("current", page == m_currentPage);
            btn->style()->unpolish(btn);
            btn->style()->polish(btn);
        }
    }
}

void PaginationWidget::updatePageNumbers()
{
    // 清除现有的页码按钮
    qDeleteAll(m_pageButtons);
    m_pageButtons.clear();
    
    // 计算显示的页码范围
    int start = qMax(1, m_currentPage - m_maxVisiblePages / 2);
    int end = qMin(m_totalPages, start + m_maxVisiblePages - 1);
    
    // 调整起始页码，确保显示足够的页码
    if (end - start + 1 < m_maxVisiblePages) {
        start = qMax(1, end - m_maxVisiblePages + 1);
    }
    
    // 获取布局
    QHBoxLayout *layout = qobject_cast<QHBoxLayout*>(this->layout());
    if (!layout) return;
    
    // 移除旧的页码按钮
    while (layout->count() > 4) {  // 4是固定的部件数量（前一页、弹簧、后一页、总页数）
        QLayoutItem *item = layout->takeAt(1);  // 1是页码按钮的起始位置
        delete item;
    }
    
    // 添加新的页码按钮
    int insertIndex = 1;  // 在"上一页"按钮后插入
    
    // 添加第一页和省略号
    if (start > 1) {
        auto firstBtn = createPageButton(1);
        layout->insertWidget(insertIndex++, firstBtn);
        m_pageButtons.append(firstBtn);
        
        if (start > 2) {
            auto ellipsisLabel = new QLabel("...");
            ellipsisLabel->setAlignment(Qt::AlignCenter);
            ellipsisLabel->setFixedSize(32, 32);
            layout->insertWidget(insertIndex++, ellipsisLabel);
        }
    }
    
    // 添加中间的页码
    for (int i = start; i <= end; ++i) {
        auto btn = createPageButton(i);
        layout->insertWidget(insertIndex++, btn);
        m_pageButtons.append(btn);
    }
    
    // 添加最后一页和省略号
    if (end < m_totalPages) {
        if (end < m_totalPages - 1) {
            auto ellipsisLabel = new QLabel("...");
            ellipsisLabel->setAlignment(Qt::AlignCenter);
            ellipsisLabel->setFixedSize(32, 32);
            layout->insertWidget(insertIndex++, ellipsisLabel);
        }
        
        auto lastBtn = createPageButton(m_totalPages);
        layout->insertWidget(insertIndex++, lastBtn);
        m_pageButtons.append(lastBtn);
    }
}

QPushButton* PaginationWidget::createPageButton(int pageNum)
{
    QPushButton *btn = new QPushButton(QString::number(pageNum));
    btn->setFixedSize(32, 32);
    btn->setProperty("page", pageNum);
    btn->setProperty("current", pageNum == m_currentPage);
    
    // 设置页码按钮的样式
    QString numBtnStyle = 
        "QPushButton {"
        "  background-color: #ffffff;"
        "  border: 1px solid #dee2e6;"
        "  border-radius: 4px;"
        "  color: #007bff;"
        "}"
        "QPushButton:hover {"
        "  background-color: #e9ecef;"
        "  border-color: #dee2e6;"
        "  color: #0056b3;"
        "}"
        "QPushButton[current=\"true\"] {"
        "  background-color: #007bff;"
        "  border-color: #007bff;"
        "  color: #ffffff;"
        "}";
    
    btn->setStyleSheet(numBtnStyle);
    
    connect(btn, &QPushButton::clicked, this, &PaginationWidget::handlePageNumberClicked);
    return btn;
} 