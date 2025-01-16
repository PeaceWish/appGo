#ifndef APPCARD_H
#define APPCARD_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QEnterEvent>

class AppCard : public QWidget
{
    Q_OBJECT

public:
    explicit AppCard(QWidget *parent = nullptr);
    ~AppCard() override;

    // 设置应用信息
    void setAppName(const QString &name);
    void setAppDescription(const QString &description);
    void setAppIcon(const QString &iconPath);
    void setInstalled(bool installed);
    
    // 获取应用信息
    QString appName() const { return m_nameLabel->text(); }
    bool isInstalled() const { return m_isInstalled; }

signals:
    void installClicked();
    void uninstallClicked();
    void startClicked();
    void cardClicked();         // 整个卡片被点击时发出
    void cardDoubleClicked();   // 卡片被双击时发出

protected:
    void enterEvent(QEnterEvent *event) override;
    void leaveEvent(QEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseDoubleClickEvent(QMouseEvent *event) override;

private:
    void setupUI();
    void updateStyle();

private:
    QLabel *m_iconLabel;      // 应用图标
    QLabel *m_nameLabel;      // 应用名称
    QLabel *m_descLabel;      // 应用描述
    QPushButton *m_actionBtn; // 操作按钮（安装/卸载/启动）
    
    bool m_isInstalled;       // 是否已安装
    bool m_isHovered;         // 是否鼠标悬停
    bool m_isPressed;         // 是否被按下
};

#endif // APPCARD_H 