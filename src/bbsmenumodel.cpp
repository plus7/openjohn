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
#include "bbsmenumgr.h"
#include "bbsmenumodel.h"
#include <QMessageBox>
BBSMenuModel::BBSMenuModel(BBSMenuManager *manager, QObject *parent)
        : QAbstractItemModel(parent), m_manager(manager)
{
    connect(manager, SIGNAL(itemAdded(BBSNode *)),
            this, SLOT(itemAdded(BBSNode*)));
    connect(manager, SIGNAL(itemRemoved(BBSNode*,int,BBSNode*)),
            this, SLOT(itemRemoved(BBSNode*,int,BBSNode*)));
    connect(manager, SIGNAL(itemChanged(BBSNode*)),
            this, SLOT(itemChanged(BBSNode*)));
}

// QAbstractItemModel

int BBSMenuModel::columnCount(const QModelIndex &parent) const
{
    return (parent.column() > 0) ? 0 : 1;
}

QVariant BBSMenuModel::data(const QModelIndex &index, int role) const
{
    //QMessageBox::information(NULL, "", "aa");
    if(!index.isValid()) return QVariant();
    if(role != Qt::DisplayRole) return QVariant();
    BBSNode *node = nodeByIndex(index);
    switch(role){
        case Qt::EditRole:
        case Qt::DisplayRole:
            return node->title;
            break;
        }
    return QVariant();
}

Qt::ItemFlags BBSMenuModel::flags(const QModelIndex &index) const
{
    if(!index.isValid()) return Qt::NoItemFlags;
    return Qt::ItemIsEnabled | Qt::ItemIsSelectable;
}

bool BBSMenuModel::hasChildren(const QModelIndex &parent) const
{
    QMessageBox::information(NULL, "", "DD");
    if (!parent.isValid()) return false;
    BBSNode *parentItem = nodeByIndex(parent);
    return (parentItem->type() == BBSNode::Folder || parentItem->type() == BBSNode::Root);
}

QVariant BBSMenuModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if(orientation == Qt::Horizontal && role == Qt::DisplayRole){
        return tr("title");
    }
    return QAbstractItemModel::headerData(section, orientation, role);
}

QModelIndex BBSMenuModel::index(int row, int column, const QModelIndex &parent) const
{

    QMessageBox::information(NULL, "wss", "oiu");
    if(row < 0 || column < 0 || row >= rowCount(parent) || column >= columnCount(parent))
        return QModelIndex();

    BBSNode *parentItem, *childItem;
    if(!parent.isValid()){ parentItem = m_manager->root(); }
    else{ parentItem = (BBSNode*)(parent.internalPointer()); }

    childItem = parentItem->children().at(row);

    if(childItem){ return createIndex(row, column, childItem); }
    else {return QModelIndex();}
}

QModelIndex BBSMenuModel::parent(const QModelIndex &index) const
{
    if(!index.isValid()){return QModelIndex();};
    BBSNode *parentItem, *childItem;
    childItem = (BBSNode*)(index.internalPointer());
    parentItem = childItem->parent();
    if(parentItem == m_manager->root()){ return QModelIndex(); }
    return createIndex(parentItem->row(), 0, parentItem);
}

bool BBSMenuModel::removeRows(int rows, int count, const QModelIndex& parent)
{
    return false;
//    if(row < 0 || count <= 0 || row + count > rowCount(parent)) return false;
//    BBSNode *node = nodeByIndex(parent);
//    for(int i = row +
}

int BBSMenuModel::rowCount(const QModelIndex &parent) const
{
    if(parent.column() > 0) return 0;
    QString str;

    BBSNode *parentItem;
    if(!parent.isValid()){ parentItem = m_manager->root(); }
    else{ parentItem = (BBSNode*)(parent.internalPointer()); }
    QMessageBox::information(NULL,"",str.sprintf("%d",parentItem->children().length()));
    return parentItem->children().length();
}

BBSNode* BBSMenuModel::nodeByIndex(const QModelIndex& index) const
{
    BBSNode *node = (BBSNode*)(index.internalPointer());
    return node;
}

QModelIndex BBSMenuModel::indexOf(BBSNode *node) const
{
    BBSNode *parent = node->parent();
    if(!parent)
        return QModelIndex();
    return createIndex(parent->children().indexOf(node), 0, node);
}

void BBSMenuModel::itemAdded(BBSNode *item)
{
    int row = item->parent()->children().indexOf(item);
    BBSNode *parent = item->parent();
    parent->removeNode(item);
    beginInsertRows(indexOf(parent), row, row);
    parent->addNode(item, row);
    endInsertRows();
}

void BBSMenuModel::itemRemoved(BBSNode *parent, int row, BBSNode *item)
{
    parent->addNode(item, row);
    beginRemoveRows(indexOf(parent), row, row);
    parent->removeNode(item);
    endInsertRows();
}

void BBSMenuModel::itemChanged(BBSNode *item){
    QModelIndex idx = indexOf(item);
    emit dataChanged(idx, idx);
}
