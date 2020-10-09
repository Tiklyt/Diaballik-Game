#include "Pawn.h"

//==========================================================================CONSTRUCTOR
/**
 * @brief Allow to create a Pawn with his characteristics
 * (Color : Color of the Pawn) (bool : if there is a ball)
 * default value : bool is false at the creation of object Pawn
 * @param color the color of the pawn
 */
Pawn::Pawn (Color color){
    _pawn.first = false;
    _pawn.second = color;
}

Pawn::Pawn(){
    setEmpty();
}

//==========================================================================CHECKER

/**
 * @brief Check if the Pawn is Empty
 * This method return true if the Pawn
 * has created with the zero constructor
 */
bool Pawn::isEmpty(){
    return _pawn.second == Color::NUL;
}

//==========================================================================SETTER

void Pawn::copy(Pawn p){
    this->_pawn.first = p.containBall();
    this->_pawn.second = p.getColor();
}


void Pawn::setEmpty(){
    _pawn.first = false;
    _pawn.second = Color::NUL;
}

/**
 * @brief put the ball in the surface of the Pawn
 * Then the first element of the std::pair will
 * be true.
 */
void Pawn::putBall(){
    _pawn.first = true;
}

//==========================================================================SETTER

/**
 * @brief remove the Ball from the Pawn
 * Then the second element of the std::pair will
 * be false.
 */
void Pawn::removeBall(){
    _pawn.first = false;
}

//==========================================================================CHECKER

/**
 * @brief check if the Pawn contain the ball
 * @return true if there is the ball, false if not
 */
bool & Pawn::containBall(){
    return _pawn.first;
}

//==========================================================================CHECKER

/**
 * @brief check if the Pawn can move
 * @return true if the pawn can, false if cannot
 */
bool Pawn::isMovable(){
    return !containBall();
}

//==========================================================================CHECKER

/**
 * @brief get the color of the Pawn
 * @return it's return color of the Pawn
 */
Color & Pawn::getColor(){
    return _pawn.second;
}

//==========================================================================SETTER

/**
 * @brief set the Color of the Pawn
 * @param c the color that will be modified
 * to the Pawn
 */
void Pawn::setColor(Color c){
    _pawn.second = c;
}

//==========================================================================

