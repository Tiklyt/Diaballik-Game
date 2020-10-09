#include <iostream>
#include "View.h"

//NO DOCUMENTATION FOR THE VIEW
View::View(Game & g):game(g){}


//==========================================================================CONSTRUCTOR

void View::welcome(){
    std::cout << "Welcome to Diaballik of Bilal Brarou !" << std::endl;
}

//==========================================================================
void View::helpShower(){
    std::cout << "COMMAND  :" << std::endl;
    std::cout << "==========================================" <<std::endl;
    std::cout << "select X Y // apply X // moves " << std::endl;
    std::cout << "==========================================" <<std::endl;
    std::cout << "antigame // skip // quit " << std::endl;
    std::cout << "==========================================" <<std::endl;

}

//==========================================================================DISPLAYER

void View::quit(){
    std::cout << "good bye" << std::endl;
}

//==========================================================================DISPLAYER

void View::displayMove(std::vector<Move> moves){
    if(moves.empty()){
        std::cout << "==========================================" <<std::endl;
        std::cout << "No displacement (left) or pass possible (left) ! " << std::endl;
        std::cout << "==========================================" <<std::endl;
        std::cout << "Please skip turn if you have no displacement or pass left !" << std::endl;
    }
    for(std::size_t i = 0;i < moves.size();i++){
        std::cout << i << ": " << moves[i];
    }
}

//==========================================================================DISPLAYER

void View::showMovementLeft(){
    std::cout << "==========================================" <<std::endl;
    std::cout << "Pawn Displacement Left :" << 2 -game.getCurrentPlayer().getMovementDone() << std::endl;
    std::cout << "==========================================" <<std::endl;
    std::cout << "Ball Pass Left :" << 1 - game.getCurrentPlayer().getBallMovementDone() << std::endl;
    std::cout << "==========================================" <<std::endl;
}

//==========================================================================DISPLAYER

void View::showBoard(){
    std::cout << game.getBoard();
}

//==========================================================================DISPLAYER

void View::showCanSkip(bool skip){
    if(!skip){
        std::cout << "You can't skip your turn now !" << std::endl;
    } else {
        std::cout << "skip succeed !" << std::endl;
    }
}

//==========================================================================DISPLAYER

void View::showCanSelect(bool select){
    if(select){
        std::cout << "select success !" << std::endl;
    } else {
        std::cout << "select failed" << std::endl;
    }
}

//==========================================================================DISPLAYER

void View::showCanAnti(bool anti){
    if(anti){
        std::cout << "Anti Game success !" << std::endl;
    } else {
        std::cout << "you can't antigame !" << std::endl;
    }
}

//==========================================================================DISPLAYER

void View::showGeneralInformation(){
    Pawn p(game.getCurrentPlayer().getColor());
    std::cout<< "==========================================" << std::endl;
    std::cout << "Current Player : " << game.getCurrentPlayer().getName() << std::endl;
    std::cout << "=========================================" << std::endl;
    std::cout << "Player Logo : " << p << std::endl;
    showMovementLeft();
}

//==========================================================================DISPLAYER

std::string View::askCommand(){
    std::string command;
    std::getline(std::cin,command);
    return std::string(command);
}


//==========================================================================
