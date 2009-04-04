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
#include "aboutdialog.h"
#include "ui_aboutdialog.h"

AboutDialog::AboutDialog(QWidget *parent) :
    QDialog(parent),
    m_ui(new Ui::AboutDialog)
{
    m_ui->setupUi(this);
    QString html = m_ui->textBrowser_about->toHtml();
    html.replace("%version%", "0.0.1", Qt::CaseSensitive);
    html.replace("%gitcommit%", "Working copy", Qt::CaseSensitive);
    html.replace("%qtversion%", "4.5.0", Qt::CaseSensitive);
    m_ui->textBrowser_about->setHtml(html);

    //バージョン情報の取得方法
    //Windows
    // QSysInfo::WindowsVersion
    //Mac
    // QSysInfo::MacVersion
    //Linux
    // cat /proc/version
}

AboutDialog::~AboutDialog()
{
    delete m_ui;
}

void AboutDialog::changeEvent(QEvent *e)
{
    switch (e->type()) {
    case QEvent::LanguageChange:
        m_ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void AboutDialog::on_buttonBox_accepted()
{

}
