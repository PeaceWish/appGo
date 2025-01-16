#ifndef PAGINATIONWIDGET_H
#define PAGINATIONWIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>

class PaginationWidget : public QWidget
{
    Q_OBJECT

public:
    explicit PaginationWidget(QWidget *parent = nullptr);
    ~PaginationWidget() override;

    // 设置总页数和当前页
    void setTotalPages(int total);
    void setCurrentPage(int page);
    
    // 获取当前页和每页显示数量
    int currentPage() const { return m_currentPage; }
    int itemsPerPage() const { return m_itemsPerPage; }
    int totalPages() const { return m_totalPages; }
    
    // 设置每页显示数量
    void setItemsPerPage(int count);

signals:
    void pageChanged(int page);
    void itemsPerPageChanged(int count);

private slots:
    void handlePrevClicked();
    void handleNextClicked();
    void handlePageNumberClicked();

private:
    void setupUI();
    void updateButtons();
    void updatePageNumbers();
    QPushButton* createPageButton(int pageNum);

private:
    QPushButton *m_prevBtn;     // 上一页按钮
    QPushButton *m_nextBtn;     // 下一页按钮
    QList<QPushButton*> m_pageButtons;  // 页码按钮列表
    QLabel *m_totalLabel;       // 总页数标签
    
    int m_currentPage;          // 当前页码
    int m_totalPages;           // 总页数
    int m_itemsPerPage;         // 每页显示数量
    int m_maxVisiblePages;      // 最大可见页码数
};

#endif // PAGINATIONWIDGET_H 