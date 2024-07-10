#include "app.h"
#include <QDebug>
app::app(MainWindow* view,viewmodel* viewmodel,map* map)
{
//   ;
    //command binding
    connect(view->son,&graphicsView::clicked,viewmodel,&viewmodel::onFly);


    //data binding
    connect(viewmodel,&viewmodel::birdYChanged,view->son,&graphicsView::redraw_bird);


    //debug用，记得删除
    connect(viewmodel,&viewmodel::birdY2Changed,this,&app::F_de_bug);



}
