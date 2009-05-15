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
#include "boardmodel.h"
#include "bbsmenumgr.h"
#include <QFile>
#include <QTextStream>
#include <QRegExp>
#include <QUrl>
#include <QMessageBox>
BoardModel::BoardModel(const QList<BBSNode *> &threads, QObject *parent)
        : QAbstractListModel(parent)
{
    m_threadlist = threads;
}

int BoardModel::rowCount(const QModelIndex &parent) const
{
    return m_threadlist.size();
}

int BoardModel::columnCount(const QModelIndex &parent) const
{
    return 2;
}

QVariant BoardModel::data(const QModelIndex &index, int role) const
{
    if(!index.isValid()) return QVariant();
    if(index.row() >= m_threadlist.size()) return QVariant();
    if(role == Qt::DisplayRole){
        BBSNode * th = m_threadlist.at(index.row());
        switch(index.column()){
        case 0:
            return th->title;
        case 1:
            return th->uri;
        }
    }
    return QVariant();
}

QVariant BoardModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if(role == Qt::DisplayRole){
    switch(section){
    case 0:
        return tr("title");
        break;
    case 1:
        return tr("uri");
        break;
    }
    }
    return QAbstractListModel::headerData(section, orientation, role);
}

 QModelIndex BoardModel::index(int row, int column, const QModelIndex &parent)
             const
 {
     if (!hasIndex(row, column, parent))
         return QModelIndex();
     return createIndex(row, column, m_threadlist.at(row));
//     BBSNode *parentNode;
//     if (!parent.isValid())
//         parentNode = m_manager->root();
//     else
//         parentNode = static_cast<BBSNode*>(parent.internalPointer());
//     BBSNode *childNode = parentNode->children().at(row);//parentNode->child(row);
//     if (childNode)
//         return createIndex(row, column, childNode);
//     else
//         return QModelIndex();
 }

void BoardModel::loadFromFile(QFile& file, const QUrl& base)
{
    while(!m_threadlist.empty()){
        BBSNode *node = m_threadlist.takeFirst();
        m_threadlist.removeFirst();
        delete node;
    }
    //QMessageBox::information(NULL, "", "ww");
    if(!file.open(QIODevice::ReadOnly)) return;
    //QMessageBox::information(NULL, "", "wwss");
    QTextStream in(&file);
    in.setCodec("Shift-JIS");
    QRegExp subjectexp("(\\d+)\\.dat<>(.+)\\((\\d+)\\)");
    while (!in.atEnd())
    {
        int pos = 0;
        QString line = in.readLine();
        //QMessageBox::information(NULL, "", line);
        if (subjectexp.indexIn(line, pos) >= 0)
        {
            BBSNode *node = new BBSNode(NULL, BBSNode::Thread);
            node->title = subjectexp.cap(2);
            QString baseStr = base.toString() + "dat/";
            //baseStr.insert(baseStr.indexOf('/', 8, Qt::CaseSensitive)+1, "test/read.cgi/");
            node->uri = baseStr + subjectexp.cap(1) + ".dat";//"/";
            m_threadlist.append(node);
        }
    }
    file.close();
}
