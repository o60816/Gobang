#include <memory>
#include "createchess.h"
#include "blackchess.h"
#include "whitechess.h"
#include "chess.h"

createChess::createChess(QString s,bool (&isChess)[13][13][2], MainWindow * const &parent, bool &isFirst)
{
    if(s=="black")
        std::shared_ptr<chess> c(new blackChess(isChess,parent,isFirst));
    else
        std::shared_ptr<chess> c(new whiteChess(isChess,parent));
}

createChess::createChess(QString s, bool (&isChess)[13][13][2], MainWindow * const &parent, int &x, int &y)
{
    if(s=="black")
        std::shared_ptr<chess> c(new blackChess(isChess,parent,x,y));
    else
        std::shared_ptr<chess> c(new whiteChess(isChess,parent,x,y));
}
