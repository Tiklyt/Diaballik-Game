#include <iostream>
#include "Board.h"
#include <exception>
//==========================================================================CONSTRUCTOR
/**
     * @brief Constructor for creating a Board
     * @param side the size of the board
     *
     */
Board::Board(unsigned side){

        _board.resize(side);
        for (unsigned i = 0; i < side; ++i)
            _board[i].resize(side);

}

void Board::resize(int size){
    _board.resize(size);
    for (unsigned i = 0; i < size; ++i)
        _board[i].resize(size);
}


//==========================================================================SETTER

/**
     * @brief Allow to put a Pawn in a specific Position
     * @param pawn The pawn that will be put
     * @param pos the position where to position the Pawn will be placed
     */
void Board::putPawn(Pawn pawn, Position pos){
    if(!isInside(pos)){
        throw std::invalid_argument("Invalid position");
    }
    unsigned x = static_cast<unsigned int>(pos.getRow());
    unsigned y = static_cast<unsigned int>(pos.getCol());
    _board[x][y] = Cell(pawn);
}

//==========================================================================SETTER

/**
     * @brief set the Ball in a specific Position
     * @param pos the Position where the Ball will be set.
     */
void Board::setBall(Position pos){
    if(!isInside(pos)){
        throw std::invalid_argument("Invalid position");
    }
    unsigned x = static_cast<unsigned int>(pos.getRow());
    unsigned y = static_cast<unsigned int>(pos.getCol());
    if(!_board[x][y].getPawn().isEmpty())
        _board[x][y].setBall();
}

//==========================================================================GETTER

/**
     * @brief get the 2D vector from the class board
     * @return a 2D vector
     */
std::vector<std::vector<Cell>> & Board::getBoard(){
    return _board;
}

//==========================================================================GETTER

/**
     * @brief Allow to get a cell from the plate
     * in a specific position
     * @param pos the position
     * @return a Cell
     */
Cell & Board::getCell(Position pos){
    if(!isInside(pos)){
        throw std::invalid_argument("Invalid position");
    }
    unsigned x = static_cast<unsigned int>(pos.getRow());
    unsigned y = static_cast<unsigned int>(pos.getCol());
    return _board[x][y];
}

//==========================================================================GETTER

/**
     * @brief return the size of a side of the plate
     */
unsigned Board::getSize(){
    return _board.size();
}

//==========================================================================CHECKER

/**
     * @brief check in a specific position if the Cell
     * is Free.
     * @param pos the position where we will check if it's free or not
     * @return true or false
     */
bool Board::isFree(Position & pos){
    if(!isInside(pos)){
        throw std::invalid_argument("Invalid position");
    }
    unsigned x = static_cast<unsigned int>(pos.getRow());
    unsigned y = static_cast<unsigned int>(pos.getCol());
    return _board[x][y].isFree();
}

//==========================================================================CHECKER

/**
     * @brief Check the Position in parameter is inside
     * the plate
     * @param pos the Position where the position will be checked
     * @return true or false
     */
bool Board::isInside(Position & pos){
    int size = static_cast<int>(getSize());
    return pos.getCol() >= 0 && pos.getCol() < size
            && pos.getRow() >= 0 && pos.getRow() < size;
}

//==========================================================================CHECKER

/**
     * @brief Check if the Pawn in a specific
     * Position is the same color of the color passed
     * in parameter
     * @param pos the Position where we will get the Pawn
     * @param color the Color with we will checked the equality
     * @return true or false
     */
bool Board::isMyOwn(Position &  pos,Color color){
    if(!isInside(pos)){
        throw std::invalid_argument("Invalid position");
    }
    unsigned x = static_cast<unsigned int>(pos.getRow());
    unsigned y = static_cast<unsigned int>(pos.getCol());
    return _board[x][y].getPawn().getColor() == color;
}
