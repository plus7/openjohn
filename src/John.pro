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
    bookmarksmodel.cpp \
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
    configdialog.cpp
HEADERS += johnmainwindow.h \
    aboutdialog.h \
    bookmarksmodel.h \
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
    configdialog.h
FORMS += johnmainwindow.ui \
    aboutdialog.ui \
    aboutdialog.ui \
    configdialog.ui
RESOURCES += johnrc.qrc
OTHER_FILES += props/props-common.txt
