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
#ifndef BOARDVIEW_H
#define BOARDVIEW_H

#include <QTableView>
#include <QUrl>
class QFile;
class QHttp;
class QUrl;
class QHttpResponseHeader;
class BoardView : public QTableView
{
    Q_OBJECT
public:
    BoardView(QWidget * parent=0);

    void loadBoard(const QUrl& uri);
    void reload();
    QUrl uri();
protected slots:
    void httpDone(bool error);
    void httpStateChanged ( int state );
    void readResponseHeader(const QHttpResponseHeader &responseHeader);
signals:
    void openThread(QUrl url);
protected:
    QUrl m_uri;
    QFile *m_subjects;
    QHttp *m_http;
};

#endif // BOARDVIEW_H
