#ifndef APPGRIDVIEW_H
#define APPGRIDVIEW_H

#include <QWidget>
#include <QScrollArea>
#include <QGridLayout>
#include "appcard.h"

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

protected:
    void resizeEvent(QResizeEvent *event) override;

private:
    void setupUI();
    void updateLayout();
    void calculateGrid();

private:
    QWidget *m_container;       // 容器widget
    QGridLayout *m_gridLayout;  // 网格布局
    QList<AppCard*> m_cards;    // 卡片列表
    int m_columnsCount;         // 每行显示的卡片数量
    int m_spacing;              // 卡片之间的间距
};

#endif // APPGRIDVIEW_H 