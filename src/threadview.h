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
#ifndef THREADVIEW_H
#define THREADVIEW_H

#include <QTextBrowser>
class BBSRes;
class ThreadModel;
class ThreadView : public QTextBrowser
{
    Q_OBJECT
public:
    ThreadView(QWidget * parent=0);
    void loadThread(const QUrl& uri);
    QUrl threadUri();
protected slots:
    void resAdded(BBSRes *res, int pos);
protected:
    QUrl m_threadUri;
    ThreadModel *m_model;
};

#endif // THREADVIEW_H
