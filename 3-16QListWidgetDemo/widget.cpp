#include "widget.h"
#include "./ui_widget.h"
//
#include <QDebug>
//


Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    //
    ui->listWidget->setSelectionMode(QAbstractItemView::MultiSelection);
    //
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_addItemsButton_clicked()
{
    //Add  items in List Widget
    ui->listWidget->addItem("My Item");
}


void Widget::on_deleteItemsButton_clicked()
{
    //Delete item : use take item
    ui->listWidget->takeItem(ui->listWidget->currentRow());
}


void Widget::on_selectedItemButton_clicked()
{
    //Get the list of selected items
    QList<QListWidgetItem *> list=ui->listWidget->selectedItems();

    for(int i=0;i<list.count();i++)
    {
        qDebug() << "selected item :" <<list.at(i)->text() <<", row number id :"
                 <<ui->listWidget->row(list.at(i));
    }
}

