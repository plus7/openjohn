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

#include <QClipboard>
#include <QtGui/QApplication>
#include <QWebView>
#include <QWebFrame>
#include <QSysInfo>
#include "aboutdialog.h"
#include "ui_aboutdialog.h"

AboutDialog::AboutDialog(QWidget *parent) :
    QDialog(parent),
    m_ui(new Ui::AboutDialog)
{
    m_ui->setupUi(this);
    QString html = m_ui->textBrowser_about->toHtml();
    html.replace("%version%", QApplication::applicationVersion(), Qt::CaseSensitive);
    html.replace("%gitcommit%", "Working copy", Qt::CaseSensitive);
    html.replace("%qtversion%", QT_VERSION_STR, Qt::CaseSensitive);
    m_ui->textBrowser_about->setHtml(html);

    QString html2 = m_ui->textBrowser_sysinfo->toHtml();
    html2.replace("%version%", QApplication::applicationVersion(), Qt::CaseSensitive);
    html2.replace("%gitcommit%", "Working copy", Qt::CaseSensitive);
    html2.replace("%qtversion%", QT_VERSION_STR, Qt::CaseSensitive);
    QWebView *wview = new QWebView(0);
    QString wkUA =wview->page()->mainFrame()->
                  evaluateJavaScript("navigator.userAgent;").toString();
    delete wview;
    html2.replace("%webkitversion%", wkUA, Qt::CaseSensitive);
    QString OSName;
#if defined Q_OS_WIN32
    switch(QSysInfo::WindowsVersion) {
        case QSysInfo::WV_32s:
            OSName = "Windows 3.1";
            break;
        case QSysInfo::WV_95:
            OSName = "Windows 95";
            break;
        case QSysInfo::WV_98:
            OSName = "Windows 98";
            break;
        case QSysInfo::WV_Me:
            OSName = "Windows Me";
            break;
        case QSysInfo::WV_NT:
            OSName = "Windows NT 4.0";
            break;
        case QSysInfo::WV_2000:
            OSName = "Windows 2000";
            break;
        case QSysInfo::WV_XP:
            OSName = "Windows XP";
            break;
        case QSysInfo::WV_2003:
            OSName = "Windows Server 2003";
            break;
        case QSysInfo::WV_VISTA:
            OSName = "Windows Vista/Server 2008";
            break;
        default:
            OSName = "Windows";
            break;
        }
#elif defined Q_OS_LINUX
    OSName = "Linux"
#elif defined Q_OS_DARWIN
#ifdef __i386__ || __x86_64__
    OSName = "Intel Mac OS X";
#else
    OSName = "PPC Mac OS X";
#endif
     switch(QSysInfo::MacintoshVersion){
         case QSysInfo::MV_10_3:
                OSName += " 10.3";
                break;
         case QSysInfo::MV_10_4:
                OSName += " 10.4";
                break;
         case QSysInfo::MV_10_5:
                OSName += " 10.5";
                break;
         default:
                break;
            }
#else
    OSName = "Unknown";
#endif
    html2.replace("%os%", OSName, Qt::CaseSensitive);
    m_ui->textBrowser_sysinfo->setHtml(html2);

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

void AboutDialog::on_copySysInfoButton_clicked()
{
    QClipboard *clipboard = QApplication::clipboard();
    clipboard->setText(m_ui->textBrowser_sysinfo->toPlainText());
}
