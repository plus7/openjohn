#ifndef BBSMENUVIEW_H
#define BBSMENUVIEW_H

#include <QTreeView>
class QUrl;
class BBSMenuModel;
class BBSMenuView : public QTreeView
{
    Q_OBJECT
public:
    BBSMenuView(QWidget *parent = 0);
    void loadBBSMenu();
signals:
    void openBoard(const QUrl& url);
private:
    BBSMenuModel *m_model;
};

#endif // BBSMENUVIEW_H
