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
#include "johnmainwindow.h"
#include "ui_johnmainwindow.h"

#include "aboutdialog.h"
#include "bbsmenumgr.h"
#include "bbsmenumodel.h"
#include "bookmarks.h"
#include <qsplitter.h>
#include <qcombobox.h>
#include <QDirModel>
#include "treemodel.h"
#include <QProgressDialog>
#include "boardmodel.h"
#include "threadview.h"
#include <QMessageBox>
#include "johnapplication.h"
#include "bookmarks.h"
#include "bbsmenufetchdialog.h"
JohnMainWindow::JohnMainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::JohnMainWindowClass)
{
    loadSettings();
    ui->setupUi(this);
    loadBBSMenu();
    setCorner(Qt::TopLeftCorner, Qt::LeftDockWidgetArea);
    setCorner(Qt::BottomLeftCorner, Qt::LeftDockWidgetArea);
    setCorner(Qt::TopRightCorner, Qt::RightDockWidgetArea);
    setCorner(Qt::BottomRightCorner, Qt::RightDockWidgetArea);
    BookmarksMenu* bmmenu = new BookmarksMenu;
    bmmenu->setTitle(tr("Bookmarks(&M)"));
    ui->menuBar->insertMenu(ui->menuInsert_point_of_BookmarksMenu->menuAction(), bmmenu);
    ui->menuInsert_point_of_BookmarksMenu->hide();
    ui->menuBar->removeAction(ui->menuInsert_point_of_BookmarksMenu->menuAction());

    BookmarksModel *boomarksModel = JohnApplication::bookmarksManager()->bookmarksModel();
    m_bookmarksToolbar = new BookmarksToolBar(boomarksModel, this);

    addToolBarBreak();
    addToolBar(m_bookmarksToolbar);

    ui->threadTabBar->addTab("uniu");
    ui->threadTabBar->addTab("sss");

    restoreWindowLayout();

}

JohnMainWindow::~JohnMainWindow()
{
    saveWindowLayout();
    delete ui;
}

void JohnMainWindow::loadSettings()
{

}

void JohnMainWindow::restoreWindowLayout(){
    // ウィンドウの状態を初期化
    ui->dockWidget_debug->setMaximumHeight(120);
    QFile windowState(JohnApplication::profileDir()+"/settings/window.dat");
    if(!windowState.exists()) return;
    if(!windowState.open(QFile::ReadOnly)) return;
    restoreState(windowState.readAll(), 1);
    windowState.close();
}

void JohnMainWindow::saveWindowLayout(){
    // ウィンドウの状態を保存
    QFile windowState(JohnApplication::profileDir()+"/settings/window.dat");
    if(!windowState.open(QFile::WriteOnly)) return;
    windowState.write(saveState(1));
    windowState.close();
}

void JohnMainWindow::loadLinkBar(){

}

void JohnMainWindow::loadBBSMenu(){
    //bbsmenu
    QFile bbsmenu(JohnApplication::profileDir()+"/bbsmenu.html");
    if(!bbsmenu.exists()){
        QMessageBox::information(NULL, "John",
                                 tr("次に表示されるダイアログで「更新」を押し、２ちゃんねるから最新の板一覧を取得してください"));
        BBSMenuFetchDialog dlg;
        dlg.exec();
    }
    ui->boardTreeView->loadBBSMenu();
}

void JohnMainWindow::loadUri(const QString &uri)
{
}


void JohnMainWindow::on_action_AboutNemo_triggered()
{
    AboutDialog dialog;
    dialog.exec();
}

void JohnMainWindow::on_action_exit_triggered()
{
    this->close();
}

void JohnMainWindow::on_action_ChangeSplitDir_triggered()
{
    if(ui->splitter_central->orientation() == Qt::Horizontal) {
        ui->splitter_central->setOrientation(Qt::Vertical);
    }
    else{
        ui->splitter_central->setOrientation(Qt::Horizontal);
    }
}

void JohnMainWindow::on_action_help_triggered()
{
    QComboBox *cb = new QComboBox(ui->toolBar);
    ui->toolBar->addWidget(cb);
}

void JohnMainWindow::on_action_update_bbsmenu_triggered()
{
    // BBSMenuの更新
    BBSMenuFetchDialog dlg;
    dlg.exec();

    ui->boardTreeView->loadBBSMenu();
}

void JohnMainWindow::on_boardTreeView_clicked(QModelIndex index)
{
    BBSNode * node = (BBSNode *)(index.internalPointer());
    if(node->type() == BBSNode::Board) {
        ui->brdView->loadBoard(node->uri);
    }
}

void JohnMainWindow::on_brdView_clicked(QModelIndex index)
{
    BBSNode * node = (BBSNode *)(index.internalPointer());
    if(!node) return;
    if(node->type() == BBSNode::Thread) {
        ui->threadView->loadThread(node->uri);
    }
}

void JohnMainWindow::on_actionAboutQt_triggered()
{
    QMessageBox::aboutQt(this);
}
