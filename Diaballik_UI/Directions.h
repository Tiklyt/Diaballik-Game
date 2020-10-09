#ifndef DIRECTIONS_H
#define DIRECTIONS_H
#include "Direction.h"

class Directions{

   const std::vector<Direction> directions = {Direction(-1,0),Direction(1,0),Direction(0,-1),Direction(0,1)};
   const std::vector<Direction> diagonals = {Direction(-1,-1),Direction(-1,1),Direction(1,1),Direction(1,-1)};
public:
    Directions(){}
    const std::vector<Direction> getDirections(){return directions;}
    const std::vector<Direction> getDiagonals(){return diagonals;}
};

#endif // DIRECTIONS_H
