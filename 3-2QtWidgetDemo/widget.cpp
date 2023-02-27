#include "widget.h"
#include "./ui_widget.h"
#include <QLabel>

Widget::Widget(QWidget *parent):
    QWidget(parent),
    ui(new Ui::Widget)
{
    //Add label to the widget
    ui->setupUi(this);
    ui->pushButton->setText("Changed Text");
    setWindowTitle("Pappu Kumar Keshari");
    QLabel *label=new QLabel("This is Label of Pappu",this);

    //Add a styled widget and move it around
    QPalette label1Palette;
    label1Palette.setColor(QPalette::Window,Qt::yellow);
    label1Palette.setColor(QPalette::WindowText,Qt::blue);

    QFont label1Font("Times",20,QFont::Bold);

    QLabel *label1=new QLabel(this);
    label1->setAutoFillBackground(true);
    label1->setText("My coloured label");
    label1->setFont(label1Font);
    label1->setPalette(label1Palette);
    label1->move(50,50);

    //Add a button and connect to slot
    QFont buttonFont("Times",30,QFont::Bold);
    QPushButton *button=new QPushButton(this);
    button->setText("Click Me");
    button->setFont(buttonFont);
    button->move(100,250);
}

Widget::~Widget()
{
    delete ui;
}

