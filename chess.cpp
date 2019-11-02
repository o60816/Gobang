#include <QPoint>
#include "chess.h"

using namespace std;
using P = pair<int,int>;
int direction[4][2][2]={{{1,0},{-1,0}},{{0,1},{0,-1}},{{1,1},{-1,-1}},{{-1,1},{1,-1}}};


chess::chess(bool (&isChess)[13][13][2])
{
    std::pair<int,int> p;
    for(int i=0;i!=13;++i){
        for(int j=0;j!=13;++j){
            if(!isChess[j][i][0]&&!isChess[j][i][1]){
                p.first=j;
                p.second=i;
                emptyBoard.push_back(p);
            }
        }
    }
}

QPoint chess::countScore(bool (&isChess)[13][13][2])
{
    int nx,ny;
    for(int color=0;color<2;++color){
        for(auto &a : emptyBoard){
            for(int i=0;i<4;++i){
                int count(0);
                int lisLive(0);
                int risLive(0);
                for(int j=0;j<2;++j){
                    nx=a.first+direction[i][j][0];
                    ny=a.second+direction[i][j][1];
                    while(0<=nx&&nx<12&&0<=ny&&ny<12){
                        if(j&&isChess[nx][ny][color]){
                            risLive=0;
                            break;
                        }else if(j&&!isChess[nx][ny][0]&&!isChess[nx][ny][1]){
                            risLive=1;
                            break;
                        }else if(!j&&isChess[nx][ny][color]){
                            lisLive=0;
                            break;
                        }else if(!j&&!isChess[nx][ny][0]&&!isChess[nx][ny][1]){
                            lisLive=1;
                            break;
                        }
                        nx+=direction[i][j][0];
                        ny+=direction[i][j][1];
                        ++count;
                    }
                }
                if(risLive&&lisLive)
                    lisLive=1;
                else
                    lisLive=0;
                if(color){
                    if(lisLive==0&&count==1){
                        blackSituation[a.first][a.second][i+1]=1;
                    }
                    else if(lisLive==1&&count==1){
                        blackSituation[a.first][a.second][i+1]=4;
                    }
                    else if(lisLive==0&&count==2){
                        blackSituation[a.first][a.second][i+1]=16;
                    }
                    else if(lisLive==1&&count==2){
                        blackSituation[a.first][a.second][i+1]=64;
                    }
                    else if(lisLive==0&&count==3){
                        blackSituation[a.first][a.second][i+1]=256;
                    }
                    else if(lisLive==1&&count==3){
                        blackSituation[a.first][a.second][i+1]=1024;
                    }
                    else if(lisLive==0&&count==4){
                        blackSituation[a.first][a.second][i+1]=4096;
                    }
                    else if(lisLive==1&&count==4){
                        blackSituation[a.first][a.second][i+1]=16384;
                    }
                    else if(lisLive==0&&count==5){
                    blackSituation[a.first][a.second][i+1]=65536;
                    }
                    else if(lisLive==1&&count==5){
                        blackSituation[a.first][a.second][i+1]=262144;
                    }
                } else{
                    if(lisLive==0&&count==1){
                        whiteSituation[a.first][a.second][i+1]=1;
                    }
                    else if(lisLive==1&&count==1){
                        whiteSituation[a.first][a.second][i+1]=4;
                    }
                    else if(lisLive==0&&count==2){
                        whiteSituation[a.first][a.second][i+1]=16;
                    }
                    else if(lisLive==1&&count==2){
                        whiteSituation[a.first][a.second][i+1]=64;
                    }
                    else if(lisLive==0&&count==3){
                        whiteSituation[a.first][a.second][i+1]=256;
                    }
                    else if(lisLive==1&&count==3){
                        whiteSituation[a.first][a.second][i+1]=1024;
                    }
                    else if(lisLive==0&&count==4){
                        whiteSituation[a.first][a.second][i+1]=4096;
                    }
                    else if(lisLive==1&&count==4){
                        whiteSituation[a.first][a.second][i+1]=16384;
                    }
                    else if(lisLive==0&&count==5){
                    whiteSituation[a.first][a.second][i+1]=65536;
                    }
                    else if(lisLive==1&&count==5){
                        whiteSituation[a.first][a.second][i+1]=262144;
                    }
                }
            }

        }
    }
    for(int i=0;i!=13;++i){
        for(int j=0;j!=13;++j){
            if(blackSituation[i][j][1]==1024&&blackSituation[i][j][2]==1024)
                blackSituation[i][j][0]+=10000;
            else if(blackSituation[i][j][1]==1024&&blackSituation[i][j][3]==1024)
                blackSituation[i][j][0]+=10000;
            else if(blackSituation[i][j][1]==1024&&blackSituation[i][j][4]==1024)
                blackSituation[i][j][0]+=10000;
            else if(blackSituation[i][j][2]==1024&&blackSituation[i][j][3]==1024)
                blackSituation[i][j][0]+=10000;
            else if(blackSituation[i][j][2]==1024&&blackSituation[i][j][4]==1024)
                blackSituation[i][j][0]+=10000;
            else if(blackSituation[i][j][3]==1024&&blackSituation[i][j][4]==1024)
                blackSituation[i][j][0]+=10000;
            else if(whiteSituation[i][j][1]==1024&&whiteSituation[i][j][2]==1024)
                whiteSituation[i][j][0]+=10000;
            else if(whiteSituation[i][j][1]==1024&&whiteSituation[i][j][3]==1024)
                whiteSituation[i][j][0]+=10000;
            else if(whiteSituation[i][j][1]==1024&&whiteSituation[i][j][4]==1024)
                whiteSituation[i][j][0]+=10000;
            else if(whiteSituation[i][j][2]==1024&&whiteSituation[i][j][3]==1024)
                whiteSituation[i][j][0]+=10000;
            else if(whiteSituation[i][j][2]==1024&&whiteSituation[i][j][4]==1024)
                whiteSituation[i][j][0]+=10000;
            else if(whiteSituation[i][j][3]==1024&&whiteSituation[i][j][4]==1024)
                whiteSituation[i][j][0]+=10000;
        }
    }

    for(int i=0;i!=13;++i){
        for(int j=0;j!=13;++j){
            for(int x=1;x!=5;++x){
                blackSituation[i][j][0] += blackSituation[i][j][x];
                whiteSituation[i][j][0] += whiteSituation[i][j][x];
            }
            blackSituation[i][j][0] += whiteSituation[i][j][0];
        }
    }
    int max=blackSituation[0][0][0];
    for(int i=0;i!=13;++i){
        for(int j=0;j!=13;++j){
            if(blackSituation[i][j][0]>max){
                max=blackSituation[i][j][0];
                point.setX(i);
                point.setY(j);
            }
        }
    }
    return point;
}


bool chess::checkWin(bool (&isChess)[13][13][2],int color)
{
    int count=0,nx=0,ny=0;
    for(int i=0;i<4;++i){
        for(int j=0;j<2;++j){
            nx=point.x();
            ny=point.y();
            while(0<=nx&&nx<12&&0<=ny&&ny<12&&isChess[nx][ny][color]){
                nx+=direction[i][j][0];
                ny+=direction[i][j][1];
                ++count;
            }
        }
        if(count>=6)
            return true;
        count=0;
    }
    return false;
}
