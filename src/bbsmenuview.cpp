#include "bbsmenuview.h"
#include "bbsmenumgr.h"
#include "johnapplication.h"
#include "treemodel.h"
BBSMenuView::BBSMenuView(QWidget *parent)
        :QTreeView(parent)
{
}


void BBSMenuView::loadBBSMenu()
{
    BBSMenuManager *bbsMenuMgr = JohnApplication::bbsMenuManager();
    bbsMenuMgr->loadFromFile(JohnApplication::profileDir() + "/bbsmenu.html");
    TreeModel *model = new TreeModel(bbsMenuMgr);
    setModel(model);
}
