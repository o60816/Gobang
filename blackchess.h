#ifndef BLACKCHESS_H
#define BLACKCHESS_H

#include "chess.h"

class MainWindow;

class blackChess : public chess
{
    friend class createChess;
    explicit blackChess(bool (&isChess)[13][13][2], MainWindow * const &parent,bool isFirst);
    explicit blackChess(bool (&isChess)[13][13][2], MainWindow * const &parent,int x,int y);
    blackChess(const blackChess& rhs)=delete;
    blackChess& operator=(const blackChess& rhs)=delete;
public:
    ~blackChess()=default;
};

#endif // BLACKCHESS_H
