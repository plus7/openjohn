#include <QtGui/QApplication>
#include "johnmainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    JohnMainWindow w;
    w.show();
    return a.exec();
}
