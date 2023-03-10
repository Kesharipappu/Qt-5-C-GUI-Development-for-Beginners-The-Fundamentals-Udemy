#include "widget.h"
#include "./ui_widget.h"
//
#include <QFileDialog>
#include <QMessageBox>
//

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_chooseDirButton_clicked()
{
    QString filename = QFileDialog::getExistingDirectory(this,"Choose Folder");
    if (filename.isEmpty())
        return;
    ui->lineEdit->setText(filename);
}


void Widget::on_createDirButton_clicked()
{
    //create a dir if it doesn't exist already
    QString dirPath = ui->lineEdit->text();
    if (dirPath.isEmpty())
        return;
    QDir dir(dirPath);
    if (!dir.exists()) {
        //create it
        if (dir.mkpath(dirPath)) {
            QMessageBox::information(this,"Message","Directory Created");
        }
    }
    else {
        QMessageBox::information(this,"Message","Directory already exists");
    }
}


void Widget::on_dirExistButton_clicked()
{
    //check if a directory exists
    QString dirPath = ui->lineEdit->text();
    if (dirPath.isEmpty())
        return;

    QDir dir(dirPath);
    if (dir.exists()) {
        QMessageBox::information(this,"Message","Directory already exists");
    }
    else {
        QMessageBox::information(this,"Message","Directory doesn't exist");
    }
}


void Widget::on_dirOrFileButton_clicked()
{
   QFileInfo fileInfo(ui->listWidget->currentItem()->text());
   if (fileInfo.isDir()) {
       QMessageBox::information(this,"Message","This  is a Dir");
   }
   else if (fileInfo.isFile()) {
       QMessageBox::information(this,"Message","This is a File");
   }
   else {
       QMessageBox::information(this,"Message","Something else");
   }
}


void Widget::on_folderContentsButton_clicked()
{
    ui->listWidget->clear();
    QString dirPath = ui->lineEdit->text();
    if (dirPath.isEmpty())
        return;
    QDir dir(dirPath);

    //Get the list of files and directories in the folder

    QList<QFileInfo> fileList = dir.entryInfoList();
    for (int i = 0; i < fileList.size(); i++) {
//        QString prefix;
//        if (fileList.at(i).isFile()) {
//            prefix = "FILE : ";
//        }
//        if (fileList.at(i).isDir()) {
//            prefix = "DIRECTORY :" ;
//        }
         ui->listWidget->addItem(fileList.at(i).absoluteFilePath());
    }
}

