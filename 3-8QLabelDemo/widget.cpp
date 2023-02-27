#include "widget.h"
#include "./ui_widget.h"
#include <QPushButton>
#include <QLayout>


Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    //
    ui->miniontextLabel->move(100,30);

    //Add an image to the second label
    QPixmap minioPixmap("C://Users//PAPPU KUMAR KESHARI//OneDrive//Desktop.png");

    ui->imageLabel->move(0,70);
    ui->imageLabel->setPixmap(minioPixmap.scaled(400,400));

    QWidget *window = new QWidget;
    QPushButton *button1 = new QPushButton("One");
    QPushButton *button2 = new QPushButton("Two");
    QPushButton *button3 = new QPushButton("Three");
    QPushButton *button4 = new QPushButton("Four");
    QPushButton *button5 = new QPushButton("Five");

    QHBoxLayout *layout = new QHBoxLayout;
    layout->addWidget(button1);
    layout->addWidget(button2);
    layout->addWidget(button3);
    layout->addWidget(button4);
    layout->addWidget(button5);

    window->setLayout(layout);
    window->show();


    //
}

Widget::~Widget()
{
    delete ui;
}

