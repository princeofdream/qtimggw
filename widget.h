#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QDebug>
#include <QFileDialog>
#include <QProcess>
#include <QCursor>
#include <QPoint>
#include <QGraphicsItem>
#include <QPainter>
#include <QRectF>
#include <QPixmap>
#include <QtGui>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QtGui/QPainter>
#include <QThread>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_Btn_home_clicked();

    void on_Btn_return_clicked();

    void get_android_screen();

    void reflash_android_screen();

    void on_tap_clicked();

    void on_swip_left_clicked();

    void on_swip_right_clicked();

private:
    QThread thr_label;
    Ui::Widget *ui;
};



#endif // WIDGET_H
