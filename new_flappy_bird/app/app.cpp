#include "app.h"

app::app(MainWindow* view)
{
    App_viewmodel = new viewmodel(nullptr);

    // command binding
    connect(view->son, &graphicsView::clicked, App_viewmodel, &viewmodel::onFly);
    connect(view->son->ResetBtn,&QPushButton::clicked,App_viewmodel,&viewmodel::onReset);

    // notifying binding
    connect(App_viewmodel, &viewmodel::birdYChanged, view->son, &graphicsView::redrawBird);
    connect(App_viewmodel, &viewmodel::gameOver, view->son, &graphicsView::gameOver);
    connect(App_viewmodel, &viewmodel::pipesMoved, view->son, &graphicsView::redrawPipes);

    // data binding
    view->son->setMap(App_viewmodel->getMap());

    // set timer
    view->son->drop_timer = new QTimer(view->son);
    view->son->drop_timer->start(25);
    connect(view->son->drop_timer, &QTimer::timeout, App_viewmodel, &viewmodel::updateGame);
}
