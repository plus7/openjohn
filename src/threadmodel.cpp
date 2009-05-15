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
#include "threadmodel.h"
#include "bbsres.h"
#include <QHttp>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QApplication>
ThreadModel::ThreadModel(const QString& uri, QObject *parent)
        : QObject(parent), m_http(NULL), m_tmpfile(NULL)
{
    m_uri = QUrl(uri);
}

ThreadModel::~ThreadModel()
{
    /*while(!m_reslist.empty()){
        BBSRes *res = m_reslist.takeFirst();
        m_reslist.removeFirst();
        delete res;
    }*/
}

QString ThreadModel::title()
{
    return m_title;
}

QString ThreadModel::uri()
{
    return m_uri.toString();
}

void ThreadModel::load()
{
    m_tmpfile = new QFile("tmp.dat");
    if(m_tmpfile->exists()) m_tmpfile->remove();
    if(!m_tmpfile->open(QIODevice::ReadWrite)) return;
    //http://gimpo.2ch.net/namazuplus/dat/1230058090.dat
    m_http = new QHttp(this);

    connect(m_http, SIGNAL(done(bool)), this, SLOT(downloadCompleted(bool)));

    m_http->setHost(m_uri.host());
    m_http->get(m_uri.path(), m_tmpfile);
}

void ThreadModel::downloadCompleted(bool error)
{
    delete m_http;
    m_http = NULL;
    m_tmpfile->close();
    loadFromFile(*m_tmpfile);
}

void ThreadModel::loadFromFile(QFile& file)
{
    if(!file.open(QIODevice::ReadOnly)) return;
    QTextStream in(&file);
    in.setCodec("Shift-JIS");

     //[名前]<>[メール]<>[日付] [ID] [BE-ID]<>[本文]<>[スレッドタイトル]
    QRegExp resexp("(.*)<>(.*)<>(.*)<>(.*)<>(.*)");

    int count = 0;
    while (!in.atEnd())
    {

        int pos = 0;
        QString line = in.readLine();
        //QMessageBox::information(NULL, "", line);
        if (resexp.indexIn(line, pos) >= 0)
        {
            if(count == 0) m_title = resexp.cap(5);
            BBSRes *res = new BBSRes();
            res->name = resexp.cap(1);
            res->mail = resexp.cap(2);
            res->info = resexp.cap(3);
            res->body = resexp.cap(4);
            m_reslist.append(res);
            count++;
            emit resAdded(res, count);
        }
        QApplication::processEvents();
    }
    file.close();
}

void ThreadModel::mergeDiff()
{
}

int ThreadModel::resCount()
{
    return m_reslist.size();
}

BBSRes *ThreadModel::resAt(int num)
{
    return m_reslist.at(num);
}
