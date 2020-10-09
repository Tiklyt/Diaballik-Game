#ifndef POSITION_H
#define POSITION_H
#include "Direction.h"
#include <ostream>
class Position{
private:

    int _row;
    int _column;

public:


    //CONSTRUCTORS
    Position(int row,int  column);
    Position() = default;

    //GETTER
    int getRow();
    int getCol();

    bool equals(Position p){
        if(p.getCol() == _column && p.getRow() == _row){
            return true;
        }
        return false;
    }

    //OVERLOAD
    Position operator+(Direction d);
    friend std::ostream & operator<<(std::ostream & os,Position pos){
    os << "[" << pos.getRow()<< "," << pos.getCol() << "]";
    return os;
    }
};

#endif // POSITION_H
