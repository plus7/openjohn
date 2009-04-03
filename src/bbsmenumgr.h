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
#ifndef BBSMENUMANAGER_H
#define BBSMENUMANAGER_H
#include <QObject>
#include <QList>
#include <QString>
class BBSNode;
class BBSMenuManager : public QObject
{
    Q_OBJECT

public:
    BBSMenuManager(QObject *parent = 0);
    BBSNode *root() const;
    bool loadFromFile(const QString& fileName);
signals:
    void itemAdded(BBSNode *item);
    void itemRemoved(BBSNode *parent, int row, BBSNode *item);
    void itemChanged(BBSNode *item);
private:
    BBSNode *m_root;
};

class BBSNode
{
public:
    enum Type{
        Root,
        Folder,
        Board,
        Thread,
        Separator
    };

    BBSNode(BBSNode *parent, BBSNode::Type type);
    virtual ~BBSNode();

    Type type() const;
    void setType(Type type) {m_type = type;}

    QList<BBSNode *> children() const{ return m_children; }
    BBSNode *parent() const{ return m_parent; }

    void addNode(BBSNode *child, int offset = -1);
    void removeNode(BBSNode *child);
    int row();

    QString title;
    QString uri;
    QString misc;
    bool expanded;
private:
    BBSNode *m_parent;
    Type m_type;
    QList<BBSNode *> m_children;
};

class BBSThread : public BBSNode
{
public:
    BBSThread(BBSNode *parent);
};

#endif // BBSMENUMANAGER_H
