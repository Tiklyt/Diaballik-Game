#ifndef CONTROLLER_H
#define CONTROLLER_H
#include "View.h"
#include "Game.h"
class Controller{

private:

    Game & g;
    View & v;

public:
    Controller(Game & game,View & view);
    std::vector<std::string> split(std::string strToSplit, char delimeter);
    void initialize();
    void startGame();
    void selectChecker(std::string command);
    void applyChecker(std::string command);
    void movesChecker(std::string command);
    void skipChecker(std::string command);
    void antiChecker(std::string command);
    bool is_number(const std::string& s);
    Game & getGame();
};

#endif // CONTROLLER_H
