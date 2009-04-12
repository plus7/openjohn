#include "boardtabbar.h"
#include <QUrl>
BoardTabBar::BoardTabBar()
{
}

int BoardTabBar::addTab(const QString& text,
                        BoardView* bv)
{
}
int BoardTabBar::addTab(const QString& text,
                        const QUrl& url)
{
}
int BoardTabBar::insertTab(int index,
                           const QString& text,
                           BoardView* bv)
{
}
int BoardTabBar::insertTab(int index,
                           const QString& text,
                           const QUrl& url)
{
}

void BoardTabBar::openBoard(const QUrl& url)
{
    //タブの中から該当する板を検索
    //すでに存在すればアクティブにする
    //存在していなければ新規作成する
}
