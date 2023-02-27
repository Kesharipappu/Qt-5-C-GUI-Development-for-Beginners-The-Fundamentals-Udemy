#include "mainwindow.h"
#include "./ui_mainwindow.h"
//
#include <QPushButton>
#include <QDebug>
#include <QMenuBar>
#include <QStatusBar>
#include <QAction>
#include <QApplication>

//

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //
    //Add central widget
    QPushButton *button=new QPushButton("Pappu",this);
    setCentralWidget(button);

    //Declare Quit Action
    QAction *quitAction=new QAction("Quit");
    connect(quitAction,&QAction::triggered,[=](){
        QApplication::quit();
     });


    //Add menus
   QMenu *fileMenu= menuBar()->addMenu("File");
   fileMenu->addAction(quitAction);
    menuBar()->addMenu("Edit");
    menuBar()->addMenu("Window");
    menuBar()->addMenu("Setting");
    menuBar()->addMenu("Help");


    //Add status bar message
    statusBar()->showMessage("Uploading file...",3000);
    //
}

MainWindow::~MainWindow()
{
    delete ui;
}

QSize MainWindow::sizeHint() const
{
    return QSize(800,500);
}

