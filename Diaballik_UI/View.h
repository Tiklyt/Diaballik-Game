#ifndef VIEW_H
#define VIEW_H
#include "Game.h"
class View : public Observer{
private:
    Game & game;
public:

    //CONSTRUCTOR
    View(Game & g);


    //DISPLAYER
    void welcome();
    void helpShower();
    void quit();
    void displayMove(std::vector<Move> moves);
    void displayName();
    void showMovementLeft();
    void showBoard();
    void showCanSkip(bool skip);
    void showCanAnti(bool anti);
    void showCanSelect(bool select);
    void showGeneralInformation();

    //CHANGER
    std::string askCommand();

    void update(){
        showBoard();
    }
};


#endif // VIEW_H
