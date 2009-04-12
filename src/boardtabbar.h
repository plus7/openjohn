#ifndef BOARDTABBAR_H
#define BOARDTABBAR_H

#include <QTabBar>
class QStackedWidget;
class BoardView;
class QUrl;
class ThreadTabBar;
class BoardTabBar : public QTabBar
{
    Q_OBJECT
public:
    BoardTabBar();
    void setStackedWidget(QStackedWidget *widget);
    void setThreadTabBar(ThreadTabBar *tabbar);
    int addTab(const QString& text,
               BoardView* bv);
    int addTab(const QString& text,
               const QUrl& url);
    int insertTab(int index,
                  const QString& text,
                  BoardView* bv);
    int insertTab(int index,
                  const QString& text,
                  const QUrl& url);
public slots:
    void openBoard(const QUrl& url);
    //void tabChanged(const QUrl& url);
private:
    QStackedWidget *m_sw;
    ThreadTabBar *m_thtab;

};

#endif // BOARDTABBAR_H
