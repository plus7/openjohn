#include "johnapplication.h"
#include <QDir>
#include <QSettings>
#include "bbsmenumgr.h"
#include "bookmarks.h"
#include <QTextCodec>

BBSMenuManager *JohnApplication::m_bbsMenuMgr = 0;
BookmarksManager *JohnApplication::m_bookmarkMgr = 0;
QSettings *JohnApplication::m_settings = 0;

JohnApplication::JohnApplication(int & argc, char ** argv)
        : QApplication(argc, argv)
{
    QTextCodec::setCodecForTr(QTextCodec::codecForName("UTF-8"));
    QDir dir(JohnApplication::profileDir() + "/settings");
    if(!dir.exists())
        dir.mkpath(dir.path());
    m_settings = new QSettings(
                JohnApplication::profileDir() +
                    "/settings/John2ch.ini",
                QSettings::IniFormat);
}

JohnApplication::~JohnApplication()
{
    delete m_settings;
}

BookmarksManager *JohnApplication::bookmarksManager()
{
    if (!m_bookmarkMgr) {
        m_bookmarkMgr = new BookmarksManager;
    }
    return m_bookmarkMgr;
}

BBSMenuManager *JohnApplication::bbsMenuManager()
{
    if (!m_bbsMenuMgr) {
        m_bbsMenuMgr = new BBSMenuManager;
    }
    return m_bbsMenuMgr;
}

QString JohnApplication::profileDir()
{
    return QDir::homePath() + "/John";
}
