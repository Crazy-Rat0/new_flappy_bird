#ifndef APP_H
#define APP_H

#include "../view/mainwindow.h"
#include "../viewmodel/viewmodel.h"
#include "../common/map.h"
#include <QObject>
#include <QDebug>
class app:public QObject
{
    Q_OBJECT
public:
    //app(MainWindow* view,viewmodel* viewmodel,map* map);
    app(MainWindow* view);
    viewmodel* App_viewmodel;
   // map* App_map;
};

#endif // APP_H
