#include "widget.h"
#include "ui_widget.h"
#include <QFileDialog>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->label->setText("100333993");
    //"E:/My_Documents/James/Pictures/20160310093319.jpg"
    load_image();
}

Widget::~Widget()
{
    delete ui;
}



void Widget::load_image()
{
    QString filename="E:/My_Documents/James/Pictures/20160310093319.jpg";
    QImage newImage;

    newImage.load(filename);
}

void Widget::on_pushButton_clicked()
{
    QImage *image= new QImage();
#if 0
    QString fileName = QFileDialog::getOpenFileName(
                this, "open image file",
                ".",
                "Image files (*.bmp *.jpg *.pbm *.pgm *.png *.ppm *.xbm *.xpm);;All files (*.*)");
#else
    //QString fileName="E:/My_Documents/James/Pictures/20160310093319.jpg";
     QString fileName="E:/My_Documents/James/Pictures/2000.jpg";
#endif
     if(fileName != "")
     {
         if(image->load(fileName))
         {
             QGraphicsScene *scene = new QGraphicsScene;
             scene->addPixmap(QPixmap::fromImage(*image));
             ui->graphicsView->setScene(scene);
             ui->graphicsView->resize(image->width() + 10, image->height() + 10);
             ui->graphicsView->show();
         }
     }

    qDebug()<<"------->>"<<fileName<<"<<------------";
    //QGraphicsScene
    //ui->graphicsView->setScene();
    delete image;
}
