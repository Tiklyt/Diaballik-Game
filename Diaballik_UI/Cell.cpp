#include "Cell.h"
#include "iostream"

//==========================================================================CONSTRUCTOR
/**
 * @brief Create a cell with a Pawn
 * the Cell is one "square" of the plate,
 * a cell can have one or no Pawn in him
 * @param p the Pawn that will be added.
 */
Cell::Cell(Pawn  p) : _pawn(p){}

//==========================================================================GETTER
/**
 * @brief get the pawn of the cell
 * All cells have pawn but the difference
 * with real pawn and invisible pawn is that
 * color of the pawn is NUL.
 * @return the Pawn in Cell
 */
Pawn & Cell::getPawn(){
    return _pawn;
}

//==========================================================================SETTER
/**
 * @brief put the ball in the surface of the Pawn
 * Then the first element of the std::pair will
 * be true.
 */
void Cell::setBall(){
    _pawn.putBall();
    notify();
}

//==========================================================================SETTER
/**
 * @brief set the Color of the Pawn
 * @param c the color that will be modified
 * to the Pawn
 */
void Cell::setColor(Color c){
    _pawn.setColor(c);
    notify();
}

void Cell::copy(Pawn p){
    _pawn.copy(p);
    notify();
}

//==========================================================================SETTER
/**
 * @brief remove the Ball from the Pawn
 * Then the second element of the std::pair will
 * be false.
 */
void Cell::resetBall(){
  _pawn.removeBall();
  notify();
}

void Cell::setEmpty(){
    _pawn.setEmpty();
    notify();
}

//==========================================================================CHECKER
/**
 * @brief check if the cell contains a
 * "visible" Pawn.
 * @return the method return true if the cell
 * contains a "visible" Pawn, false if not.
 */
bool Cell::isFree(){
    return _pawn.isEmpty();
}
//==========================================================================
