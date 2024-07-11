#include "app.h"
#include <QDebug>
app::app(MainWindow* view)
{//
//app(MainWindow* view,viewmodel* viewmodel,map* map)
//   ;
    //command binding

        App_viewmodel =new viewmodel(nullptr);
        App_map= App_viewmodel->map();

    connect(view->son,&graphicsView::clicked,App_viewmodel,&viewmodel::onFly);


    //notifying binding
    connect(App_viewmodel,&viewmodel::birdYChanged,view->son,&graphicsView::redraw_bird);


    //data binding
    view->son->setMap(App_map);

    //debug用，记得删除
    connect(App_viewmodel,&viewmodel::birdY2Changed,this,&app::F_de_bug);



}
