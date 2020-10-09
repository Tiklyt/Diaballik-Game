#include "Move.h"


//==========================================================================CONSTRUCTOR
/**
 * @brief Create a Move, a move is represented
 * by a displacement of a start Position and a
 * end Position
 * @param st the start Position of the Move
 * @param end the end Position of the Move
 */
Move::Move(Position st,Position end) : _start(st), _end(end){}

//==========================================================================GETTER

/**
 * @brief get the start position of the Move
 * @return the Position start.
 */
Position & Move::getStart(){
    return _start;
}

//==========================================================================GETTER

/**
 * @brief get the end position of the Move
 * @return the End Position.
 */
Position & Move::getEnd(){
    return _end;
}

//==========================================================================
