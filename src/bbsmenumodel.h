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
#ifndef BBSMENUMODEL_H
#define BBSMENUMODEL_H

#include <QAbstractItemModel>
class BBSMenuManager;
class BBSNode;
class BBSMenuModel : public QAbstractItemModel
{
    Q_OBJECT
public:
    BBSMenuModel(BBSMenuManager *manager, QObject *parent = 0);
    BBSMenuManager *bbsMenuManager() const { return m_manager; }

    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
    int columnCount(const QModelIndex &parent = QModelIndex()) const;
    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    QModelIndex index(int, int, const QModelIndex &parent = QModelIndex()) const;
    QModelIndex parent(const QModelIndex &index = QModelIndex()) const;
    Qt::ItemFlags flags(const QModelIndex &index) const;
//    Qt::DropActions supportedDropActions() const;
    bool removeRows(int row, int count, const QModelIndex &parent = QModelIndex());
//    bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole);
//    QMimeData *mimeData(const QModelIndexList &indexes) const;
//    QStringList mimeTypes() const;
//    bool dropMimeData(const QMimeData *data,
//                      Qt::DropAction action, int row, int column, const QModelIndex &parent);
    bool hasChildren(const QModelIndex &parent = QModelIndex()) const;

    BBSNode* nodeByIndex(const QModelIndex& index) const;
    QModelIndex indexOf(BBSNode *node) const;

public slots:
    void itemAdded(BBSNode *item);
    void itemRemoved(BBSNode *parent, int row, BBSNode *item);
    void itemChanged(BBSNode *item);
private:
    BBSMenuManager *m_manager;
};

#endif // BBSMENUMODEL_H
