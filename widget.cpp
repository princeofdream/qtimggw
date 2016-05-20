#include "widget.h"
#include "ui_widget.h"
#include <stdlib.h>
#include <stdio.h>

#define S_HIGHT 1280
#define S_WIDTH 720


int point_x;
int point_y;

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->label->setText("by JamesL");

    point_x = 0;
    point_y = 0;
    ui->graphicsView->scale(0.68,0.68);
    //MyThread *m_thread;
    //connect(m_thread,SIGNAL(mmSignal()),this,SLOT(mySlot()));
    //m_thread->start();
}

Widget::~Widget()
{
    delete ui;
}


void Widget::get_android_screen()
{
    QProcess *m_proc = new QProcess();
#if 0
    m_proc->execute("adb shell /system/bin/screencap -p /sdcard/scn.png");
    //m_proc->execute("adb shell sync");
    m_proc->execute("adb pull /sdcard/scn.png F:\\");
#else
#if 0
    m_proc->execute("F:");
    //m_proc->execute("adb shell screencap -p | sed 's/\r$//' > scn.png");

    FILE* fd = freopen("F:\\scn.png", "w", stdout);
    char m_str[256] = "adb shell \"echo screencap -p \|busybox sed \'s/\\\\r$//\' > /data/1.sh\"'";
    char m_str2[128] = "adb shell /data/1.sh";
    m_proc->execute(m_str);
    m_proc->execute(m_str2);
    fclose(fd);
    qDebug()<<m_str;
    //close(fd);
    //m_proc->execute("adb logcat > 1.log");
    //m_proc->execute("adb shell sync");
    //m_proc->execute("adb pull /sdcard/scn.png F:\\");
#else
    m_proc->execute("adb shell su -c \"screencap -p /mnt/obb/scn.png\"");
    m_proc->execute("adb pull /mnt/obb/scn.png F:\\");
#endif
#endif
    delete m_proc;
}

void Widget::reflash_android_screen()
{
    QImage *image= new QImage();


#if 0
    QString fileName = QFileDialog::getOpenFileName(
                this, "open image file",
                ".",
                "Image files (*.bmp *.jpg *.pbm *.pgm *.png *.ppm *.xbm *.xpm);;All files (*.*)");
#else
    QString fileName="F:/scn.png";
#endif

#if 1
    get_android_screen();
    if(fileName != "")
    {
        if(image->load(fileName))
        {
            //image->scaledToWidth(300);
            QGraphicsScene *scene = new QGraphicsScene;;
            scene->addPixmap(QPixmap::fromImage(*image));

            double scal_number = 1;

            scene->addLine(0, 0, 0, S_HIGHT);
            scene->addLine(100*scal_number, 0, 100*scal_number, S_HIGHT);
            scene->addLine(200*scal_number, 0, 200*scal_number, S_HIGHT);
            scene->addLine(300*scal_number, 0, 300*scal_number, S_HIGHT);
            scene->addLine(400*scal_number, 0, 400*scal_number, S_HIGHT);
            scene->addLine(500*scal_number, 0, 500*scal_number, S_HIGHT);
            scene->addLine(600*scal_number, 0, 600*scal_number, S_HIGHT);
            scene->addLine(700*scal_number, 0, 700*scal_number, S_HIGHT);
            scene->addLine(720*scal_number, 0, 720*scal_number, S_HIGHT);

            scene->addLine(0, 0, 600, 0);
            scene->addLine(0, 100*scal_number, S_WIDTH, 100*scal_number);
            scene->addLine(0, 200*scal_number, S_WIDTH, 200*scal_number);
            scene->addLine(0, 300*scal_number, S_WIDTH, 300*scal_number);
            scene->addLine(0, 400*scal_number, S_WIDTH, 400*scal_number);
            scene->addLine(0, 500*scal_number, S_WIDTH, 500*scal_number);
            scene->addLine(0, 600*scal_number, S_WIDTH, 600*scal_number);
            scene->addLine(0, 700*scal_number, S_WIDTH, 700*scal_number);
            scene->addLine(0, 800*scal_number, S_WIDTH, 800*scal_number);
            scene->addLine(0, 900*scal_number, S_WIDTH, 900*scal_number);
            scene->addLine(0, 1000*scal_number, S_WIDTH, 1000*scal_number);
            scene->addLine(0, 1100*scal_number, S_WIDTH, 1100*scal_number);
            scene->addLine(0, 1200*scal_number, S_WIDTH, 1200*scal_number);
            scene->addLine(0, 1280*scal_number, S_WIDTH, 1280*scal_number);

            ui->graphicsView->setScene(scene);
            //ui->graphicsView->resize(image->width() + 10, image->height() + 10);
            ui->graphicsView->show();
            //ui->graphicsView->drawItems();
            qDebug()<<"------->>"<<fileName<<"<<-----"<<scene->width()<<"x"<<scene->height()<<"-------";
        }
    }
#endif

#if 0
    QGraphicsScene *scene2 = new QGraphicsScene;
    //scene2->addRect(10,10,20,890);
    scene2->addLine(0, 0, 0, 960);
    scene2->addLine(100, 0, 100, 960);
    scene2->addLine(200, 0, 200, 960);
    scene2->addLine(300, 0, 300, 960);
    scene2->addLine(400, 0, 400, 960);
    scene2->addLine(500, 0, 500, 960);
    scene2->addLine(600, 0, 600, 960);

    ui->graphicsView->setScene(scene2);
    ui->graphicsView->show();
#endif


    QPoint p = this->mapFromGlobal(QCursor::pos());

    QString p_to_str = "x:"+QString("%1").arg(p.x())+"y:"+QString("%1").arg(p.y());
    ui->label->setText(p_to_str);
    point_x = p.x();
    point_y = p.y();

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



void Widget::on_Btn_return_clicked()
{
    QProcess *m_proc = new QProcess();
    m_proc->execute("adb shell input keyevent 4");
    reflash_android_screen();
}

void Widget::on_tap_clicked()
{
    QString get_y = ui->lineEdit->text();
    QString get_x = ui->lineEdit_2->text();

    //get_x.number()
    get_x.toInt();
    get_y.toInt();
    QProcess *m_proc = new QProcess();

    qDebug()<<"------->>adb shell input touchscreen tap "+get_x+" " + get_y + "<<-------";
    m_proc->execute("adb shell input touchscreen tap "+get_x+" " + get_y);
    reflash_android_screen();
}

void Widget::on_swip_left_clicked()
{
    QProcess *m_proc = new QProcess();
    m_proc->execute("adb shell input touchscreen swipe 60 500 400 500");
    reflash_android_screen();
}

void Widget::on_swip_right_clicked()
{
    QProcess *m_proc = new QProcess();
    m_proc->execute("adb shell input touchscreen swipe 400 500 60 500");
    reflash_android_screen();
}

void Widget::on_Swip_clicked()
{
    QString get_y = ui->Y1->text();
    QString get_x = ui->X1->text();

    QString get_y2 = ui->Y2->text();
    QString get_x2 = ui->X2->text();

    //get_x.number()
    get_x.toInt();
    get_y.toInt();
    QProcess *m_proc = new QProcess();

    qDebug()<<"------->>adb shell input touchscreen swip "+get_x+" " + get_y + " --> "+get_x2+" " + get_y2 +"<<-------";
    m_proc->execute("adb shell input touchscreen swipe "+get_x+" " + get_y+ " "+get_x2+" " + get_y2);
    reflash_android_screen();
    qDebug()<<"test by JamesL";
}

int Widget::get_current_point()
{
    QPoint p = this->mapFromGlobal(QCursor::pos());

    QString p_to_str = "x:"+QString("%1").arg(p.x())+"y:"+QString("%1").arg(p.y());
    ui->label->setText(p_to_str);
}

void Widget::mySlot()
{
    qDebug()<<"Loo";
}

//void MyThread::mmSignal()
//{
//    qDebug()<<"PP";
//}

void MyThread::run()
{
    int i0 = 0;
    while(1)
    {
        qDebug()<<"Loop ================="+QString("%1").arg(point_x)+":"+QString("%1").arg(point_y);
        //point_x = 65533;
        sleep(1);
        i0++;
        //if (i0 > 100)
        //    break;
    }
    return;
}

void Widget::on_btn_home_clicked()
{
    QProcess *m_proc = new QProcess();
    m_proc->execute("adb shell input keyevent 3");
    reflash_android_screen();
}
