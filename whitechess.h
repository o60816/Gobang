#ifndef WHITECHESS_H
#define WHITECHESS_H

#include "chess.h"

class MainWindow;

class whiteChess : public chess
{
    friend class createChess;
    explicit whiteChess(bool (&isChess)[13][13][2], MainWindow * const &parent);
    explicit whiteChess(bool (&isChess)[13][13][2], MainWindow * const &parent,int x,int y);
    whiteChess(const whiteChess& rhs)=delete;
    whiteChess& operator=(const whiteChess& rhs)=delete;
public:
    ~whiteChess()=default;
};

#endif // WHITECHESS_H
