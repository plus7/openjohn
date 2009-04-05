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
#include "threadview.h"
#include "threadmodel.h"
#include <QWebFrame>
#include "bbsres.h"
#include <QMessageBox>
ThreadView::ThreadView(QWidget * parent)
        : QTextBrowser(parent)
{
}

void ThreadView::loadThread(const QUrl& uri)
{
    this->setHtml("<html><body style=\"font-family:'MS P Gothic';font-size:14px;\"></body></html>");
    m_threadUri = uri;
    m_model = new ThreadModel(uri.toString(), this);
    connect(m_model, SIGNAL(resAdded(BBSRes*,int)), this, SLOT(resAdded(BBSRes*,int)));
    m_model->load();
}

void ThreadView::resAdded(BBSRes *res, int pos)
{
    QString rescnt;
    rescnt.sprintf("%d", m_model->resCount());
    this->textCursor().movePosition(QTextCursor::End);
    this->textCursor().insertHtml("<dt>"+rescnt+": <b><a href=\"" + res->mail + "\">" + res->name+"</a></b> "+res->info+"</dt><dd>"+res->body+"</dd><br>");
}

QUrl ThreadView::threadUri()
{
    return m_threadUri;
}
