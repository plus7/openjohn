# -------------------------------------------------
# Project created by QtCreator 2009-03-16T15:05:33
# -------------------------------------------------
QT += network \
    script \
    sql \
    webkit \
    xml \
    xmlpatterns
TARGET = John
TEMPLATE = app
SOURCES += main.cpp \
    johnmainwindow.cpp \
    aboutdialog.cpp \
    boardmodel.cpp \
    bbsmenumodel.cpp \
    threadloader.cpp \
    cachemanager.cpp \
    imagecachemanager.cpp \
    bbsmenumgr.cpp \
    treemodel.cpp \
    subjecttxt.cpp \
    boardview.cpp \
    threadview.cpp \
    threadmodel.cpp \
    bbsres.cpp \
    bbsres2ch.cpp \
    configdialog.cpp \
    johnapplication.cpp \
    modelmenu.cpp \
    bookmarks.cpp \
    searchlineedit.cpp \
    edittreeview.cpp \
    urllineedit.cpp \
    xbel.cpp \
    treeproxymodel.cpp \
    threadtabbar.cpp \
    boardtabbar.cpp \
    bbsmenuview.cpp \
    imgviewdialog.cpp \
    bbsmenufetchdialog.cpp
HEADERS += johnmainwindow.h \
    aboutdialog.h \
    boardmodel.h \
    bbsmenumodel.h \
    threadloader.h \
    cachemanager.h \
    imagecachemanager.h \
    bbsmenumgr.h \
    treemodel.h \
    subjecttxt.h \
    boardview.h \
    threadview.h \
    threadmodel.h \
    bbsres.h \
    bbsres2ch.h \
    configdialog.h \
    johnapplication.h \
    modelmenu.h \
    bookmarks.h \
    searchlineedit.h \
    edittreeview.h \
    urllineedit.h \
    xbel.h \
    treeproxymodel.h \
    bookmarksmenu.h \
    threadtabbar.h \
    boardtabbar.h \
    bbsmenuview.h \
    imgviewdialog.h \
    bbsmenufetchdialog.h
FORMS += johnmainwindow.ui \
    aboutdialog.ui \
    aboutdialog.ui \
    configdialog.ui \
    bookmarks.ui \
    addbookmarkdialog.ui \
    imgviewdialog.ui \
    bbsmenufetchdialog.ui
RESOURCES += johnrc.qrc
OTHER_FILES += props/props-common.txt
win32:RC_FILE = john.rc
