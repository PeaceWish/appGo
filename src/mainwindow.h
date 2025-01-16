#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class AppCard;
class QTabWidget;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;

private slots:
    void handleCardClicked(AppCard *card);
    void handleCardDoubleClicked(AppCard *card);
    void handleCardInstall(AppCard *card);
    void handleCardUninstall(AppCard *card);
    void handleCardStart(AppCard *card);

private:
    void setupUI();
};

#endif // MAINWINDOW_H 