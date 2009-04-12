#ifndef JOHNAPPLICATION_H
#define JOHNAPPLICATION_H

#include <QtGui/QApplication>
class BookmarksManager;
class BBSMenuManager;
class QSettings;
class JohnApplication : public QApplication
{
public:
    JohnApplication( int & argc, char ** argv );
    virtual ~JohnApplication();
    void setupDB();
    static QString profileDir();
    static QSettings *settings();
    static BookmarksManager *bookmarksManager();
    static BBSMenuManager *bbsMenuManager();
private:
    static QSettings *m_settings;
    static BookmarksManager *m_bookmarkMgr;
    static BBSMenuManager *m_bbsMenuMgr;
};

#endif // JOHNAPPLICATION_H
