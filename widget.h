#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QDebug>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
    void load_image();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Widget *ui;
};



#endif // WIDGET_H
