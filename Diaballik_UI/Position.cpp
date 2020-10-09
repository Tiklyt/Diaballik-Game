#include "Position.h"

//==========================================================================CONSTRUCTOR

/**
 * @brief Allow to create a Position(row,column)
 * @param the row in a 2 dimensional surface.
 * @param the column in a 2 dimensional surface.
 */
Position::Position(int row,int  column){
    this->_row = row; this->_column = column;
}

//==========================================================================GETTER

/**
 * @brief get the column of the Position(row,column)
 * @return return column.
 */
int Position::getCol(){
    return _column;
}

//==========================================================================GETTER

/**
 * @brief get the column of the Position(row,column)
 * @return return row.
 */
int Position::getRow(){
    return _row;
}

//==========================================================================OVERLOADING

/**
 * @brief the method overload the + operator
 * like this a Direction can be added to a Position
 * @param d the direction
 * @return the new Position
 */
Position  Position::operator+(Direction d){
    return Position(this->getRow()+d.getRow(),this->getCol()+getCol());

}

//==========================================================================
