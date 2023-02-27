#include "widget.h"
#include "./ui_widget.h"
//
#include <QPushButton>
#include <QDebug>
//

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    //
    QFont buttonFont("Times",20,QFont::Bold);
    QPushButton *button=new QPushButton("Button1",this);
    button->setMinimumSize(200,100);
    button->setFont(buttonFont);
    connect(button,&QPushButton::clicked,[=]()
    {
        qDebug() <<"Button Clicked";
    });

    QPushButton *button2=new QPushButton("Button2",this);
    button2->setMinimumSize(205,100);
    button2->move(200,100);
    button2->setFont(buttonFont);
    connect(button2,&QPushButton::pressed,[=]()
    {
        qDebug() <<"Button Pressed";
    });

    connect(button2,&QPushButton::released,[=]()
    {
        qDebug() <<"Button released";
    });
    //
}

Widget::~Widget()
{
    delete ui;
}

