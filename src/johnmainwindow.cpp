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
#include <qsplitter.h>
#include <qcombobox.h>
#include <QDirModel>
#include "treemodel.h"
#include <QProgressDialog>
#include "boardmodel.h"
#include "threadview.h"
#include <QMessageBox>
JohnMainWindow::JohnMainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::JohnMainWindowClass)
{
    settings = new QSettings("John2ch.ini", QSettings::IniFormat);
    ui->setupUi(this);
}

JohnMainWindow::~JohnMainWindow()
{
    delete ui;
    delete settings;
}

void JohnMainWindow::restoreWindowState(){
    // ウィンドウの状態を初期化
    // ウィンドウの大きさ, Dock, 分割方向, Pane数, etc.
}

void JohnMainWindow::loadLinkBar(){

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
    bbsMenuMgr = new BBSMenuManager(this);
    bbsMenuMgr->loadFromFile("C:\\cygwin\\home\\Administrator\\bbsmenu.html");
    TreeModel *model = new TreeModel(bbsMenuMgr);
    ui->boardTreeView->setModel(model);
    //ui->brdView->loadBoard(QUrl(tr("http://pc12.2ch.net/software/")));
//    QList<BBSNode *> thl;
//    BBSThread *th2 = new BBSThread(NULL);
//    th2->title = tr("IETF");
//    th2->uri = tr("http://www.ietf.org/");
//    thl.append(th2);
//    BBSThread *th = new BBSThread(NULL);
//    th->title = tr("ssss");
//    th->uri = tr("http://www.w3.org/");
//    thl.append(th);
//    BoardModel *bm = new BoardModel(thl);
//    ui->brdView->setModel(bm);
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
    //QMessageBox::information(NULL, "", "sswu");
    if(!node) return;
    if(node->type() == BBSNode::Thread) {
        //QMessageBox::information(NULL,"","poi");
        ui->threadView->loadThread(node->uri);
    }
}
