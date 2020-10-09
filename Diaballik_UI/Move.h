#ifndef MOVE_H
#define MOVE_H
#include "Position.h"
#include <ostream>

class Move{
private:
    Position _start;
    Position _end;
public:
    //CONSTRUCTOR
    Move(Position st,Position end);

    //GETTER
    Position & getStart();
    Position & getEnd();

    friend std::ostream & operator<<(std::ostream & os,Move move){
        os << "Movement to : " << move.getEnd() << std::endl;
        return os;
    }
};

#endif // MOVE_H
