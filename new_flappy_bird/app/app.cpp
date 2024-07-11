#include "app.h"
#include <QDebug>
app::app(MainWindow* view)
{//
//app(MainWindow* view,viewmodel* viewmodel,map* map)
//   ;
    //command binding

        App_viewmodel =new viewmodel(nullptr);

    connect(view->son,&graphicsView::clicked,App_viewmodel,&viewmodel::onFly);


    //notifying binding
    connect(App_viewmodel,&viewmodel::birdYChanged,view->son,&graphicsView::redraw);


    //data binding
    view->son->setMap(App_viewmodel->map());

    //set timer
    view->son->drop_timer = new QTimer(view->son);
    view->son->drop_timer->start(25);

    connect(view->son->drop_timer,&QTimer::timeout,App_viewmodel,&viewmodel::onDrop);






}
