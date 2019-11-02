#ifndef CREATECHESS_H
#define CREATECHESS_H

class MainWindow;
class QString;

class createChess
{
public:
    createChess(QString s,bool (&isChess)[13][13][2],MainWindow * const &parent,bool &isFirst);
    createChess(QString s,bool (&isChess)[13][13][2],MainWindow * const &parent,int &x,int &y);
    createChess(const createChess&) = delete;
    createChess& operator=(const createChess&) = delete;
};

#endif // CREATECHESS_H
