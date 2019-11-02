#include <QLabel>
#include <QPixmap>
#include <QMessageBox>
#include <dialog.h>
#include "blackchess.h"

blackChess::blackChess(bool (&isChess)[13][13][2], MainWindow * const &parent,int x,int y)
    :chess(isChess)
{
    QPixmap pixmap(":new/prefix1/black.jpg");
    QLabel *label = new QLabel(parent);
    label->setPixmap(pixmap);
    label->setGeometry((120+x*37),(132+y*37),20,21);
    label->show();
    isChess[x][y][0]=true;
    setPoint(x,y);
    if(checkWin(isChess,0)){
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

blackChess::blackChess(bool (&isChess)[13][13][2], MainWindow * const &parent,bool isFirst)
    :chess(isChess)
{
    if(isFirst){
        QPixmap pixmap(":new/prefix1/black.jpg");
        QLabel *label = new QLabel(parent);
        label->setPixmap(pixmap);
        label->setGeometry((120+6*37),(132+6*37),20,21);
        label->show();
        isChess[6][6][0]=true;
    }else{
        QPoint point(countScore(isChess));
        QPixmap pixmap(":new/prefix1/black.jpg");
        QLabel *label = new QLabel(parent);
        label->setPixmap(pixmap);
        label->setGeometry((120+point.x()*37),(132+point.y()*37),20,21);
        label->show();
        isChess[point.x()][point.y()][0]=true;
        if(checkWin(isChess,0)){
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
}

