#ifndef PLAYER_H
#define PLAYER_H
#include "Pawn.h"
#include <ostream>
#include <vector>

class Player
{
private:
    std::string _namePlayer;
    Color color;
    unsigned _attribuedMovement;
    unsigned _attribuedBallMovement;
    bool _gaveUp;

public:

    //CONSTRUCTORS
    Player(std::string name,Color c);
    Player() = default;

    //GETTER
    Color getColor();
    bool & haveGiveUp();
    std::string & getName();
    unsigned getMovementDone();
    unsigned getBallMovementDone();

    //SETTER
    void setName(std::string name);


    //CHANGER
    void addPawns(Pawn p);
    void resetAllMovement();
    bool incMovement();
    bool incBallMovement();
    bool haveDoneMinDisp();
    void giveUp();

    friend std::ostream & operator<<(std::ostream & os,Player player){
        os << "name : " << player.getName() << " Can skip : "<< player.haveDoneMinDisp();
        return os;
    }
};

#endif // PLAYER_H
