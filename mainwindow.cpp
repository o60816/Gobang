#include <QPixmap>
#include <qevent.h>
#include <QLabel>
#include <QMessageBox>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "createchess.h"
#include "time.h"
#include "stdlib.h"
#include <iostream>
clock_t start_time , end_time;
float total_time=0;
MainWindow::MainWindow(QWidget *parent, int color) :
    QMainWindow(parent),colorSelect(color),isFirst(true),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    label = new QLabel(this);
    QPixmap pixmap1(":new/prefix1/desk.jpg");
    label->setPixmap(pixmap1);
    label->setGeometry(50,65,600,600);
    label->show();
    connect(this,SIGNAL(clicked()),this,SLOT(mousePressEventSlot()));
    connect(ui->action,SIGNAL(triggered()),SLOT(newFile()));
    connect(ui->action_2,SIGNAL(triggered()),SLOT(closeWindow()));
    if(colorSelect){
        createChess ch("black",isChess,this,isFirst);
    }
}

void MainWindow::mousePressEvent(QMouseEvent* e)
{
    start_time = clock();
    int x = e->x();
    int y = e->y();
    x=x-120;
    y=y-132;
    if(x<0||y<0||x>460||y>472)
        return;
    else{
        if(x%37>20||y%37>20)
            return;
        else{
            x=x/36;
            y=y/37;
        }
    }
    if(isChess[x][y][0]||isChess[x][y][1]){
        QMessageBox::warning(this,"Warning!!","請勿重複下棋!!",QMessageBox::Ok);
        return;
    }else{
        if(!colorSelect){
            createChess ch("black",isChess,this,x,y);
        }else{
            createChess ch("white",isChess,this,x,y);
        }
    }
    emit clicked();
}

void MainWindow::mousePressEventSlot()
{
    isFirst=false;
    if(colorSelect){
        createChess ch("black",isChess,this,isFirst);
    }else{
        createChess ch("white",isChess,this,isFirst);
    }
    end_time = clock();
        total_time = (float)(end_time - start_time)/CLOCKS_PER_SEC;
        std::cout<<total_time<<" sec ";
}

void MainWindow::newFile()
{
    MainWindow *w=0;
    if(!colorSelect){
        w = new MainWindow(0,0);

    }else{
        w = new MainWindow(0,1);
    }
    w->show();
    this->deleteLater();
}

void MainWindow::closeWindow()
{
    this->deleteLater();
}

MainWindow::~MainWindow()
{
    delete ui;
}
