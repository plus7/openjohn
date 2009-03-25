#include "johnmainwindow.h"
#include "ui_johnmainwindow.h"

#include "aboutdialog.h"

#include <qsplitter.h>
#include <qcombobox.h>

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
}
