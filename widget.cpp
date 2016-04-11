#include "widget.h"
#include "ui_widget.h"


Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->label->setText("100333993");

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

            scene->addLine(0, 0, 0, 960);
            scene->addLine(100*scal_number, 0, 100*scal_number, 960);
            scene->addLine(200*scal_number, 0, 200*scal_number, 960);
            scene->addLine(300*scal_number, 0, 300*scal_number, 960);
            scene->addLine(400*scal_number, 0, 400*scal_number, 960);
            scene->addLine(500*scal_number, 0, 500*scal_number, 960);
            scene->addLine(600*scal_number, 0, 600*scal_number, 960);
            //scene->addLine(700*scal_number, 0, 700*scal_number, 960);
            //scene->addLine(720*scal_number, 0, 720*scal_number, 960);

            scene->addLine(0, 0, 600, 0);
            scene->addLine(0, 100*scal_number, 600, 100*scal_number);
            scene->addLine(0, 200*scal_number, 600, 200*scal_number);
            scene->addLine(0, 300*scal_number, 600, 300*scal_number);
            scene->addLine(0, 400*scal_number, 600, 400*scal_number);
            scene->addLine(0, 500*scal_number, 600, 500*scal_number);
            scene->addLine(0, 600*scal_number, 600, 600*scal_number);
            scene->addLine(0, 700*scal_number, 600, 700*scal_number);
            scene->addLine(0, 800*scal_number, 600, 800*scal_number);
            scene->addLine(0, 900*scal_number, 600, 900*scal_number);
            scene->addLine(0, 1000*scal_number, 600, 1000*scal_number);
            //scene->addLine(0, 1100*scal_number, 600, 1100*scal_number);
            //scene->addLine(0, 1200*scal_number, 600, 1200*scal_number);
            //scene->addLine(0, 1280*scal_number, 600, 1280*scal_number);

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
