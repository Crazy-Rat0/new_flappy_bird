#include "../view/mainwindow.h"
#include "app.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    map m;
    viewmodel v(nullptr,&m);
    app c(&w,&v,&m);
    w.show();
    return a.exec();
}
