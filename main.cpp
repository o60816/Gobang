#include "mainwindow.h"
#include "dialog.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
#ifdef ANDROID
    MainWindow *w = new MainWindow(0,0);
    w->show();
#else
    Dialog *d = new Dialog();
    d->show();
#endif

    return a.exec();
}
