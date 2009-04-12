/*
* Copyright 2009 NOSE Takafumi <ahya365@gmail.com>
*
* This program is free software; you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation; either version 3 of the License, or
* (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program; if not, write to the Free Software
* Foundation, Inc., 51 Franklin Street, Fifth Floor,
* Boston, MA 02110-1301 USA
*/
#ifndef JOHNMAINWINDOW_H
#define JOHNMAINWINDOW_H

#include <QtGui/QMainWindow>
#include <QSettings>
#include "bbsmenumgr.h"
#include "bbsmenumodel.h"
namespace Ui
{
    class JohnMainWindowClass;
}
class BookmarksToolBar;
class JohnMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    JohnMainWindow(QWidget *parent = 0);
    ~JohnMainWindow();

    void restoreWindowLayout(); // ウィンドウの状態を初期化
    void saveWindowLayout();

    void loadSettings();
    void loadLinkBar();
    void loadBBSMenu();
    void loadBookmarks(const QString& fileName);
    void loadSession(const QString& fileName);
    void saveSession(const QString& fileName);

    void getBBSMenu(const QString &uri);

    void loadThread(const QString &uri);
    void loadBoard(const QString &uri);

    BBSMenuModel *bbsMenuModel;
private:
    Ui::JohnMainWindowClass *ui;
    BookmarksToolBar *m_bookmarksToolbar;

public slots:
    void loadUri(const QString &uri);

private slots:
    void on_actionAboutQt_triggered();
    void on_brdView_clicked(QModelIndex index);
    void on_boardTreeView_clicked(QModelIndex index);
    void on_action_update_bbsmenu_triggered();
    void on_action_help_triggered();
    void on_action_ChangeSplitDir_triggered();
    void on_action_exit_triggered();
    void on_action_AboutNemo_triggered();
};

#endif // JOHNMAINWINDOW_H
