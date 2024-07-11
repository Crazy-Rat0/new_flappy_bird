#include "../view/mainwindow.h"
#include "app.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    //app c(,&v,&m);
    app c(&w);
    w.show();
    return a.exec();
}
