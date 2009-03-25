#ifndef JOHNMAINWINDOW_H
#define JOHNMAINWINDOW_H

#include <QtGui/QMainWindow>
#include <QSettings>

namespace Ui
{
    class JohnMainWindowClass;
}

class JohnMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    JohnMainWindow(QWidget *parent = 0);
    ~JohnMainWindow();

    void restoreWindowState(); // ウィンドウの状態を初期化
    void saveWindowState();

    void loadLinkBar();
    void loadBoardList();
    void loadBookmarks(const QString& fileName);
    void loadSession(const QString& fileName);
    void saveSession(const QString& fileName);

    void getBBSMenu(/*url*/);

    void openThread(/*url*/);
    void openBoard(/*url*/);

    QSettings *settings;

private:
    Ui::JohnMainWindowClass *ui;

private slots:
    void on_action_update_bbsmenu_triggered();
    void on_action_help_triggered();
    void on_action_ChangeSplitDir_triggered();
    void on_action_exit_triggered();
    void on_action_AboutNemo_triggered();
};

#endif // JOHNMAINWINDOW_H
