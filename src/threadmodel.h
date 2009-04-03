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
#ifndef THREADMODEL_H
#define THREADMODEL_H

#include <QObject>
#include <QList>
#include <QUrl>
class QFile;
class BBSRes;
class QHttp;
class ThreadModel : public QObject
{
    Q_OBJECT
public:
    ThreadModel(const QString& uri, QObject *parent = 0);
    virtual ~ThreadModel();
    QString title();
    QString uri();
    void load();
    void loadFromFile(QFile& file);
    void mergeDiff();
    int resCount();
    BBSRes *resAt(int num);
signals:
    void resAdded(BBSRes *res, int pos);
protected slots:
    void downloadCompleted(bool error);
protected:
    QHttp *m_http;
    QFile *m_tmpfile;
    QList<BBSRes*> m_reslist;
    QString m_title;
    QUrl m_uri;
};

#endif // THREADMODEL_H
