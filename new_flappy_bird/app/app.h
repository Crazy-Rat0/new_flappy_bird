#ifndef APP_H
#define APP_H

#include "../view/mainwindow.h"
#include "../viewmodel/viewmodel.h"
#include "../common/map.h"
#include <QObject>
class app:QObject
{
    Q_OBJECT
public:
    app(MainWindow* view,viewmodel* viewmodel,map* map);
};

#endif // APP_H
