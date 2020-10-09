#ifndef GAME_H
#define GAME_H
#include <Board.h>
#include <Move.h>
#include <Player.h>
#include <Observer.h>
#include <Observable.h>
class Game : public Observable{

private:

    Board _board;
    std::pair<Player,Player>  _players;
    Position _selectedPawn = Position(0,0);
    bool _antiGame;
    std::vector<Observer *> observers;

public:

    //CONSTRUCTORS
    Game(unsigned side,std::string name1,std::string name2);

    //GETTERS
    Board & getBoard();
    std::vector<Move> getMoves();
    Pawn & getSelected();
    Player & getCurrentPlayer();


    //Observers
    void attach(Observer *observer) override{
        observers.push_back(observer);
    }

    void notify() override{
        for(unsigned i =0;i < observers.size();i++){
            observers[i]->update();
        }
    }
    //CHECKERS // GETTER
    bool isNotOver();
    bool haveMoves();
    bool askAntiGame();
    bool thereIsWinner();
    bool askSkipTurn();
    bool canSkipTurn();


    //CHANGER
    void initializer();
    void mov(Move & move);
    void swapPlayers();
    bool select(Position pos);
    void resize(unsigned size);
    void resetTable();
};

#endif // GAME_H
