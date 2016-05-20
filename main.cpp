#include "widget.h"
#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
#if 1
    Widget w;
    w.show();
#else
    QGraphicsScene *scene = new QGraphicsScene;
    scene->addLine(10, 10, 150, 300);
    QGraphicsView *view = new QGraphicsView(scene);
    view->resize(500, 500);
    view->setWindowTitle("Graphics View");
    view->show();
#endif
    MyThread m_thread;

    m_thread.start();
    //m_thread.wait();
    //connect(m_thread,SIGNAL(mySignal()),w,SLOT(mySlot()));
    return a.exec();
}
