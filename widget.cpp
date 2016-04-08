#include "widget.h"
#include "ui_widget.h"
#include <QFileDialog>
#include <QProcess>
#include <QCursor>
#include <QPoint>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->label->setText("100333993");
    //"E:/My_Documents/James/Pictures/20160310093319.jpg"
    ui->graphicsView->scale(0.73,0.73);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::get_android_screen()
{
    QProcess *m_proc = new QProcess();
    m_proc->execute("adb shell /system/bin/screencap -p /sdcard/scn.png");
    m_proc->execute("adb shell sync");
    m_proc->execute("adb pull /sdcard/scn.png F:\\");
    delete m_proc;
}

void Widget::reflash_android_screen()
{
    QImage *image= new QImage();

    get_android_screen();
#if 0
    QString fileName = QFileDialog::getOpenFileName(
                this, "open image file",
                ".",
                "Image files (*.bmp *.jpg *.pbm *.pgm *.png *.ppm *.xbm *.xpm);;All files (*.*)");
#else
    QString fileName="F:/scn.png";
    //QString fileName="E:/My_Documents/James/Pictures/2000.jpg";
#endif
    if(fileName != "")
    {
        if(image->load(fileName))
        {
            //image->scaledToWidth(300);
            QGraphicsScene *scene = new QGraphicsScene;
            scene->addPixmap(QPixmap::fromImage(*image));
            ui->graphicsView->setScene(scene);
            //             ui->graphicsView->scale(0.5,0.5);
            //ui->graphicsView->resize(image->width() + 10, image->height() + 10);
            ui->graphicsView->show();
            qDebug()<<"------->>"<<fileName<<"<<-----"<<scene->height()<<"-------";
        }
    }

    QPoint p = this->mapFromGlobal(QCursor::pos());

    QString p_to_str = "-->x:"+QString("%1").arg(p.x())+"-->y:"+QString("%1").arg(p.y());
    ui->label->setText(p_to_str);

    delete image;
}

void Widget::on_pushButton_clicked()
{
    reflash_android_screen();
}

void Widget::on_pushButton_2_clicked()
{
    QProcess *m_proc = new QProcess();
    m_proc->execute("adb shell input touchscreen swipe 360 900 360 200");
    reflash_android_screen();
}

void Widget::on_Btn_home_clicked()
{
    QProcess *m_proc = new QProcess();
    m_proc->execute("adb shell input keyevent 3");
    reflash_android_screen();
}

void Widget::on_Btn_return_clicked()
{
    QProcess *m_proc = new QProcess();
    m_proc->execute("adb shell input keyevent 4");
    reflash_android_screen();
}
