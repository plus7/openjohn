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
#include <QFile>
#include <QRegExp>
#include <QTextStream>
#include <QMessageBox>
#include <QTextCodec>

BBSMenuManager::BBSMenuManager(QObject *parent)
        : QObject(parent),
        m_root(NULL)
{

}

bool BBSMenuManager::loadFromFile(const QString& fileName)
{
    if(m_root) delete m_root;
    m_root = new BBSNode(NULL, BBSNode::Root);
    //int state = 0;
    QFile file(fileName);
    if(!file.open(QFile::ReadOnly | QFile::Text)) return false;
    QTextStream in(&file);
    in.setCodec("Shift-JIS");
    QRegExp btag(tr("<br><br><b>(.+)</b>"),Qt::CaseInsensitive,QRegExp::RegExp);
    QRegExp atag(tr("<a href=\"?([^\"]*)\"?>(.+)</a>"),Qt::CaseInsensitive,QRegExp::RegExp);
    int pos;
    QString category, brdName, brdUri;
    BBSNode *currentParent = NULL;
    BBSNode *newNode;

    while (!in.atEnd())
    {
        pos = 0;
        QString line = in.readLine();
        if (btag.indexIn(line, pos) >= 0)
        {
            //pos = btag.indexIn(line, pos);
            category = btag.cap(1);
//            if(currentParent){
//                QString str;
//                QMessageBox::information(NULL, "", str.sprintf("%d", currentParent->children().size()));
//            }
            currentParent = new BBSNode(root(), BBSNode::Folder);
            currentParent->title = category;
            //root()->addNode(currentParent);
            //emit itemAdded(currentParent);
        }
        else if(atag.indexIn(line, pos) >= 0 )
        {
            pos = atag.indexIn(line, pos);
            brdUri = atag.cap(1);
            brdName = atag.cap(2);
            if(currentParent){
                newNode = new BBSNode(currentParent, BBSNode::Board);
                newNode->title = brdName;
                newNode->uri = brdUri;
                //currentParent->addNode(newNode);
                //emit itemAdded(newNode);
            }
        }

    }
    file.close();
    return true;
}

BBSNode *BBSMenuManager::root() const
{
    return m_root;
}

BBSNode::BBSNode(BBSNode *parent, BBSNode::Type type)
        : expanded(false),
        m_parent(parent),
        m_type(type)
{
    if(parent) parent->addNode(this);
}

BBSNode::~BBSNode()
{
    if(m_parent) m_parent->removeNode(this);
    qDeleteAll(m_children);
}

BBSNode::Type BBSNode::type() const
{ return m_type; }

void BBSNode::addNode(BBSNode *child, int offset)
{
    if(child->m_parent) child->m_parent->removeNode(child);
    child->m_parent = this;
    if(offset == -1) offset = m_children.size();
    m_children.insert(offset, child);
}

void BBSNode::removeNode(BBSNode *child)
{
    child->m_parent = NULL;
    m_children.removeAll(child);
}

int BBSNode::row()
{
    if(parent()) return parent()->children().indexOf(this);
    else return 0;
}

BBSThread::BBSThread(BBSNode *parent)
        : BBSNode(parent, BBSNode::Thread)
{
}
