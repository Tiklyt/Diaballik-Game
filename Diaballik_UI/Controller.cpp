#include <Controller.h>
#include "Position.h"
#include <cstring>
#include <sstream>
#include <string>


//==========================================================================CONSTRUCTOR
/**
 * @brief Allow to construct a Controller
 * that will be used to make the relation with the game
 * and the view
 * @param game the game of the controller
 * @param view the view of the controller
 */
Controller::Controller(Game & game,View & view):g(game),v(view){}

//==========================================================================INITIALIZER


/**
 * @brief Allow to initialize the game from
 * the Controller
 */
void Controller::initialize(){
    g.initializer();
}

//==========================================================================EXECUTER

/**
 * @brief Allow to split a String like the method
 * strtok() in C
 * @param strToSplit the String to tokenize
 * @param delimeter the delimeter
 * @return return the delimited string
 */
std::vector<std::string> Controller::split(std::string strToSplit, char delimeter)
{
    std::stringstream ss(strToSplit);
    std::string item;
    std::vector<std::string> splittedStrings;
    while (std::getline(ss, item, delimeter))
    {
        splittedStrings.push_back(item);
    }
    return splittedStrings;
}
//==========================================================================GETTER

/**
 * @brief Allow to get the game from the Controller
 * @return the Game
 */
Game & Controller::getGame(){
    return g;
}
//==========================================================================EXECUTER

/**
 * @brief Allow to start the game Diaballik
 */
void Controller::startGame(){
    v.welcome();
    v.helpShower();
    v.showGeneralInformation();
    v.showBoard();
    std::string command = v.askCommand();
    while(g.isNotOver() && command != "quit" && !g.thereIsWinner()){
        selectChecker(command);
        applyChecker(command);
        movesChecker(command);
        skipChecker(command);
        antiChecker(command);
        v.showGeneralInformation();
        v.showBoard();
        command =v.askCommand();
    }

    std::cout << "Good bye, have a nice day !" << std::endl;
}

//==========================================================================CHECKER

/**
 * @brief command checker
 * @param command the command that will be checked
 */
void Controller::selectChecker(std::string command){
    std::vector<std::string> spl = split(command,' ');
    try {
        if(spl[0] == "select" && spl.size() == 3 && is_number(spl[1]) && is_number(spl[2])){
            std::string x = spl[1];
            std::string y = spl[2];
            Position p(std::stoi(x),std::stoi(y));
            v.showCanSelect(g.select(p));
        }
    } catch (...) {
        std::cout << "Out of bound Position" << std::endl;
    }
}

//==========================================================================CHECKER

/**
 * @brief command checker
 * @param command the command that will be checked
 */
void Controller::applyChecker(std::string command){
    std::vector<std::string> spl = split(command,' ');
    try {
        if(spl[0] == "apply" && spl.size() == 2 && is_number(spl[1])){
            std::string x = spl[1];
            if(static_cast<unsigned>(std::stoi(x)) < g.getMoves().size()){
                g.mov(g.getMoves()[static_cast<unsigned>(std::stoi(x))]);
            }
        }
    } catch (...) {
        std::cout << "Out of bound Position" << std::endl;
    }
}

//==========================================================================CHECKER

/**
 * @brief command checker
 * @param command the command that will be checked
 */
void Controller::movesChecker(std::string command){
    if(command == "moves"){
        v.displayMove(g.getMoves());
    }
}

//==========================================================================CHECKER

/**
 * @brief command checker
 * @param command the command that will be checked
 */
void Controller::skipChecker(std::string command){
    if(command == "skip"){
        v.showCanSkip(g.askSkipTurn());
    }
}

//==========================================================================CHECKER

/**
 * @brief command checker
 * @param command the command that will be checked
 */
void Controller::antiChecker(std::string command){
    if(command == "anti"){
        v.showCanAnti(g.askAntiGame());
        if(g.askAntiGame()){
            //exit(0);
        }
    }
}

//==========================================================================CHECKER


/**
 * @brief command checker
 * @param command the command that will be checked
 */
bool Controller::is_number(const std::string& s)
{
    std::string::const_iterator it = s.begin();
    while (it != s.end() && std::isdigit(*it)) ++it;
    return !s.empty() && it == s.end();
}

//==========================================================================
