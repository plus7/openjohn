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
#include "boardview.h"
#include "boardmodel.h"
#include <QUrl>
#include <QFile>
#include <QHttp>
#include <QHttpRequestHeader>
#include <QMessageBox>
BoardView::BoardView(QWidget *parent)
        : QTableView(parent), m_http(NULL), m_subjects(NULL)
{
}

void BoardView::loadBoard(const QUrl& uri)
{
    //QMessageBox::information(NULL, "",uri.toString());
    m_uri = uri;
    if(model()) {
        delete model();
    }
    if(m_subjects) { delete m_subjects; m_subjects = NULL; }
    m_subjects = new QFile("subjects.txt");
    if(!m_subjects->open(QIODevice::ReadWrite)) return;

    if(m_http) { delete m_http; m_http = NULL; }
    m_http = new QHttp(this);

    QUrl remoteSubjects(uri);
    remoteSubjects.setPath(remoteSubjects.path() + tr("subject.txt"));

    connect(m_http, SIGNAL(done(bool)), this, SLOT(httpDone(bool)));
    connect(m_http, SIGNAL(stateChanged(int)), this, SLOT(httpStateChanged(int)));
    connect(m_http, SIGNAL(responseHeaderReceived(const QHttpResponseHeader &)),
            this, SLOT(readResponseHeader(const QHttpResponseHeader &)));

//    QHttpRequestHeader header("GET", remoteSubjects.path());
//    header.setValue("User-Agent", "Monazilla/1.00 (OpenJohn/0.0.1)");
//    header.setValue("Accept-Encoding" , "gzip");
//    header.setValue("Accept", "*/*");
//    header.setValue("Host", "d.tnose.net");//remoteSubjects.host());
//    m_http->setHost("d.tnose.net")+//remoteSubjects.host());
//    m_http->request(header, m_subjects);
    //QMessageBox::information(NULL, remoteSubjects.host(), remoteSubjects.path());
    m_http->setHost(remoteSubjects.host());
    m_http->get(remoteSubjects.path(), m_subjects);
}

void BoardView::httpDone(bool error)
{
    //if(!error) QMessageBox::information(NULL, "",m_http->errorString());
    //else QMessageBox::information(NULL, "","ok");
    m_subjects->close();
    BoardModel *bm = new BoardModel(QList<BBSNode *>(), this);
    bm->loadFromFile(*m_subjects, m_uri);
    setModel(bm);
}

void BoardView::httpStateChanged ( int state )
{
    QString str;
    str.sprintf("%d", state);
    //QMessageBox::information(NULL, "httpstate", str);
    //QMessageBox::information(NULL, "last error", m_http->errorString());
}
void BoardView::readResponseHeader(const QHttpResponseHeader &responseHeader)
{
    //QMessageBox::information(NULL, "", responseHeader.toString());
}
void BoardView::reload()
{

}

QUrl BoardView::uri()
{
    return m_uri;
}
