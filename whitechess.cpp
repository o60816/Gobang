#include <QPixmap>
#include <QLabel>
#include <QMessageBox>
#include <dialog.h>
#include "whitechess.h"
#include "mainwindow.h"

whiteChess::whiteChess(bool (&isChess)[13][13][2], MainWindow * const &parent, int x,int y)
:chess(isChess)
{
    QPixmap pixmap(":new/prefix1/white.jpg");
    QLabel *label = new QLabel(parent);
    label->setPixmap(pixmap);
    label->setGeometry((120+x*37),(132+y*37),20,21);
    label->show();
    isChess[x][y][1]=true;
    setPoint(x,y);
    if(checkWin(isChess,1)){
        if(QMessageBox::Ok == QMessageBox::information(parent,"You Win!!","恭喜你贏了,點擊OK再來ㄧ場,點擊Cancel離開?"
            ,QMessageBox::Ok|QMessageBox::Cancel,QMessageBox::Ok)){
            #ifdef ANDROID
                    MainWindow *w = new MainWindow(0,0);
                    w->show();
                    parent->deleteLater();
            #else
                    Dialog *d = new Dialog();
                    d->show();
                    parent->deleteLater();
            #endif
        }else{
            parent->deleteLater();
        }
    }
}

whiteChess::whiteChess(bool (&isChess)[13][13][2], MainWindow *const &parent)
:chess(isChess)
{
    QPoint point(countScore(isChess));
    QPixmap pixmap(":new/prefix1/white.jpg");
    QLabel *label = new QLabel(parent);
    label->setPixmap(pixmap);
    label->setGeometry((120+point.x()*37),(132+point.y()*37),20,21);
    label->show();
    isChess[point.x()][point.y()][1]=true;
    if(checkWin(isChess,1)){
        if(QMessageBox::Ok == QMessageBox::information(parent,"You lose!!","你輸了,再接再厲!!點擊OK再來ㄧ場,點擊Cancel離開?"
            ,QMessageBox::Ok|QMessageBox::Cancel,QMessageBox::Ok)){
            #ifdef ANDROID
                    MainWindow *w = new MainWindow(0,0);
                    w->show();
                    parent->deleteLater();
            #else
                    Dialog *d = new Dialog();
                    d->show();
                    parent->deleteLater();
            #endif
        }else{
            parent->deleteLater();
        }
    }
}
