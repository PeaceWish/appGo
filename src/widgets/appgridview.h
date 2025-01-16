#ifndef APPGRIDVIEW_H
#define APPGRIDVIEW_H

#include <QWidget>
#include <QScrollArea>
#include <QGridLayout>
#include "appcard.h"
#include "paginationwidget.h"

class AppGridView : public QScrollArea
{
    Q_OBJECT

public:
    explicit AppGridView(QWidget *parent = nullptr);
    ~AppGridView() override;

    // 添加应用卡片
    void addAppCard(AppCard *card);
    // 清空所有卡片
    void clearCards();
    // 设置每行显示的卡片数量
    void setColumnsCount(int count);
    // 获取当前显示的卡片数量
    int cardsCount() const;
    
    // 分页相关
    void setCurrentPage(int page);
    void setItemsPerPage(int count);
    int currentPage() const;
    int itemsPerPage() const;
    int totalPages() const;

signals:
    // 转发卡片的信号
    void cardClicked(AppCard *card);
    void cardDoubleClicked(AppCard *card);
    void cardInstallClicked(AppCard *card);
    void cardUninstallClicked(AppCard *card);
    void cardStartClicked(AppCard *card);
    
    // 分页信号
    void pageChanged(int page);
    void itemsPerPageChanged(int count);

protected:
    void resizeEvent(QResizeEvent *event) override;

private slots:
    void handlePageChanged(int page);
    void handleItemsPerPageChanged(int count);

private:
    void setupUI();
    void updateLayout();
    void calculateGrid();
    void connectCardSignals(AppCard *card);
    void updateVisibleCards();

private:
    QWidget *m_container;       // 容器widget
    QGridLayout *m_gridLayout;  // 网格布局
    QList<AppCard*> m_cards;    // 所有卡片列表
    QList<AppCard*> m_visibleCards; // 当前页显示的卡片
    int m_columnsCount;         // 每行显示的卡片数量
    int m_spacing;              // 卡片之间的间距
    
    PaginationWidget *m_pagination;  // 分页控件
};

#endif // APPGRIDVIEW_H 