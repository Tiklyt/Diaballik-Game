#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include <Cell.h>
#include <Position.h>

class Board{
private:


    std::vector<std::vector<Cell>> _board;
    std::size_t _size;


public:

    //CONSTRUCTOR
    Board(unsigned side);

    //GETTERS
    Cell & getCell(Position pos);
    std::vector<std::vector<Cell>> & getBoard();
    std::size_t getSize();

    //SETTER
    void putPawn(Pawn pawn,Position pos);
    void setBall(Position pos);
    void resize(int size);


    //CHECKERS
    bool isInside(Position & pos);
    bool isFree(Position & pos);
    bool isMyOwn(Position & pos,Color color);

    //OVERLOAD
    friend std::ostream & operator<<(std::ostream & os,Board b){
        std::string board = " ";
        for(unsigned i = 0;i < b.getSize();i++){
            for(unsigned j=0;j < b.getSize();j++){
                os << b.getBoard()[i][j];
            }
            os << "\n";
        }
        return os;
    }






};


#endif // BOARD_H
