#include "widget.h"
#include "./ui_widget.h"
//
#include <QGridLayout>
//

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    //
    QGridLayout *layout=new QGridLayout(this);

    //First row
    layout->addWidget(ui->button1,0,0);
    layout->addWidget(ui->button2,0,1);
    layout->addWidget(ui->button3,0,2);

    //Second row
    layout->addWidget(ui->button4,1,0);
    layout->addWidget(ui->button5,1,1);
    layout->addWidget(ui->button6,1,2);

    //Third row
    layout->addWidget(ui->button7,2,0);
    layout->addWidget(ui->button8,2,1);
    layout->addWidget(ui->button9,2,2);
    //
}

Widget::~Widget()
{
    delete ui;
}

