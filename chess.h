#ifndef CHESS_H
#define CHESS_H

#include <vector>
#include <QPoint>
#include "mainwindow.h"

using std::vector;
using std::pair;
class QPoint;

class chess
{
    friend class createChess;
protected:
    explicit chess(bool (&isChess)[13][13][2]);
    virtual ~chess()=default;
    QPoint countScore(bool (&isChess)[13][13][2]);
    bool checkWin(bool (&isChess)[13][13][2],int color);
    void setPoint(int x,int y){point.setX(x);point.setY(y);};
private:
    QPoint point = QPoint(0,0);
    vector<pair<int,int> > emptyBoard=vector<pair<int,int> >(0);
    int blackSituation[13][13][5]={{{0}}};
    int whiteSituation[13][13][5]={{{0}}};
    int times=1;
    bool copyisChess[13][13][2];
    void bTransScore(bool (&isChess)[13][13][2]);
    void bStraiScore(bool (&isChess)[13][13][2]);
    void bSlashScore(bool (&isChess)[13][13][2]);
    void bBackSlashScore(bool (&isChess)[13][13][2]);
    void wTransScore(bool (&isChess)[13][13][2]);
    void wStraiScore(bool (&isChess)[13][13][2]);
    void wSlashScore(bool (&isChess)[13][13][2]);
    void wBackSlashScore(bool (&isChess)[13][13][2]);
    bool isTransWin(bool (&isChess)[13][13][2],int color);
    bool isStraiWin(bool (&isChess)[13][13][2],int color);
    bool isSlashWin(bool (&isChess)[13][13][2],int color);
    bool isBackSlashWin(bool (&isChess)[13][13][2],int color);

};

#endif // CHESS_H
