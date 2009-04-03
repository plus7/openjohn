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
/****************************************************************************
 **
 ** Copyright (C) 2009 Nokia Corporation and/or its subsidiary(-ies).
 ** Contact: Qt Software Information (qt-info@nokia.com)
 **
 ** This file is part of the documentation of the Qt Toolkit.
 **
 ** $QT_BEGIN_LICENSE:LGPL$
 ** Commercial Usage
 ** Licensees holding valid Qt Commercial licenses may use this file in
 ** accordance with the Qt Commercial License Agreement provided with the
 ** Software or, alternatively, in accordance with the terms contained in
 ** a written agreement between you and Nokia.
 **
 ** GNU Lesser General Public License Usage
 ** Alternatively, this file may be used under the terms of the GNU Lesser
 ** General Public License version 2.1 as published by the Free Software
 ** Foundation and appearing in the file LICENSE.LGPL included in the
 ** packaging of this file.  Please review the following information to
 ** ensure the GNU Lesser General Public License version 2.1 requirements
 ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
 **
 ** In addition, as a special exception, Nokia gives you certain
 ** additional rights. These rights are described in the Nokia Qt LGPL
 ** Exception version 1.0, included in the file LGPL_EXCEPTION.txt in this
 ** package.
 **
 ** GNU General Public License Usage
 ** Alternatively, this file may be used under the terms of the GNU
 ** General Public License version 3.0 as published by the Free Software
 ** Foundation and appearing in the file LICENSE.GPL included in the
 ** packaging of this file.  Please review the following information to
 ** ensure the GNU General Public License version 3.0 requirements will be
 ** met: http://www.gnu.org/copyleft/gpl.html.
 **
 ** If you are unsure which license is appropriate for your use, please
 ** contact the sales department at qt-sales@nokia.com.
 ** $QT_END_LICENSE$
 **
 ****************************************************************************/

#include <QtGui>
#include "treemodel.h"
#include "bbsmenumgr.h"
 TreeModel::TreeModel(BBSMenuManager *manager, QObject *parent)
     : QAbstractItemModel(parent)
 {
     setupModelData(manager);
 }
 TreeModel::~TreeModel()
 {
     //delete rootItem;
 }
 int TreeModel::columnCount(const QModelIndex &parent) const
 {
     return 1;
 }
 QVariant TreeModel::data(const QModelIndex &index, int role) const
 {
     if (!index.isValid())
         return QVariant();
     if (role != Qt::DisplayRole)
         return QVariant();
     BBSNode *node = static_cast<BBSNode*>(index.internalPointer());
     return node->title;
 }
 Qt::ItemFlags TreeModel::flags(const QModelIndex &index) const
 {
     if (!index.isValid())
         return 0;
     return Qt::ItemIsEnabled | Qt::ItemIsSelectable;
 }
 QVariant TreeModel::headerData(int section, Qt::Orientation orientation,
                                int role) const
 {
     if (orientation == Qt::Horizontal && role == Qt::DisplayRole)
         return QString("title");
     return QVariant();
 }
 QModelIndex TreeModel::index(int row, int column, const QModelIndex &parent)
             const
 {
     if (!hasIndex(row, column, parent))
         return QModelIndex();
     BBSNode *parentNode;
     if (!parent.isValid())
         parentNode = m_manager->root();
     else
         parentNode = static_cast<BBSNode*>(parent.internalPointer());
     BBSNode *childNode = parentNode->children().at(row);//parentNode->child(row);
     if (childNode)
         return createIndex(row, column, childNode);
     else
         return QModelIndex();
 }

 QModelIndex TreeModel::parent(const QModelIndex &index) const
 {
     if (!index.isValid())
         return QModelIndex();
     BBSNode *childNode = static_cast<BBSNode*>(index.internalPointer());
     BBSNode *parentNode = childNode->parent();
     if (parentNode == m_manager->root())
         return QModelIndex();
     return createIndex(parentNode->row(), 0, parentNode);
 }

 int TreeModel::rowCount(const QModelIndex &parent) const
 {
     BBSNode *parentNode;
     if (parent.column() > 0)
         return 0;
     if (!parent.isValid())
         parentNode = m_manager->root();
     else
         parentNode = static_cast<BBSNode*>(parent.internalPointer());
     return parentNode->children().size();
 }
 void TreeModel::setupModelData(BBSMenuManager *manager)
 {
     m_manager = manager;
 }
