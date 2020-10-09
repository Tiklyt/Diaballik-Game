#include "Player.h"
#include <iostream>

//==========================================================================CONSTRUCTOR

/**
 * @brief Create a player with her name
 * @param the name of the player
 */
Player::Player(std::string name,Color c) : _namePlayer(name),color(c){ _attribuedMovement = 0 ; _attribuedBallMovement = 0;
                                                                     _gaveUp = false;}

//==========================================================================GETTER

/**
 * @brief get the name of the player
 * @return the name of the player
 */
std::string & Player::getName(){
    return _namePlayer;
}

//==========================================================================GETTER

/**
 * @brief get the color of the player
 * @return the Color
 */
Color Player::getColor(){
    return this->color;
}

//==========================================================================GETTER

/**
 * @brief get the movement done
 */
unsigned Player::getMovementDone(){
    return _attribuedMovement;
}

//==========================================================================GETTER

/**
 * @brief get ball movement done
 */
unsigned Player::getBallMovementDone(){
    return _attribuedBallMovement;
}

//==========================================================================SETTER

/**
 * @brief reset all movement of the player
 * a player have to do a least one movement
 */
void Player::resetAllMovement(){
 _attribuedMovement = 0;
 _attribuedBallMovement = 0;
}

//==========================================================================SETTER

/**
 * @brief increment the ball movement of 1 unit
 * @return true if the increment suceed, false
 * if not
 */
bool Player::incBallMovement(){
    if(_attribuedBallMovement == 1){
        return false;
    }
    _attribuedBallMovement++;
    return true;
}

//==========================================================================SETTER

/**
 * @brief increment the pawn movement of 1 unit
 * @return true if the increment suceed, false
 * if not
 */
bool Player::incMovement(){
    if(_attribuedMovement == 2){
        return false;
    }
    _attribuedMovement++;
    return true;
}

//==========================================================================CHECKER

/**
 * @brief check if the player have done the mininum
 * of movement.
 * @return true he have, false if not.
 */
bool Player::haveDoneMinDisp(){
    return _attribuedMovement >= 1 || _attribuedBallMovement == 1;
}

//==========================================================================EXECUTER

/**
 * @brief Allow to a player to give up.
 */
void Player::giveUp(){
    _gaveUp = true;
}

//==========================================================================EXECUTER

/**
 * @brief Check if the player have give up
 * @return true if gave up, false if not.
 */
bool & Player::haveGiveUp(){
    return _gaveUp;
}

//==========================================================================SETTER

/**
 * @brief Allow to set the name of the player.
 * @param name the name of the player.
 */
void Player::setName(std::string name){
    this->_namePlayer = name;
}

//==========================================================================
