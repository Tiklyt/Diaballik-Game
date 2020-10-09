#ifndef DIRECTION_H
#define DIRECTION_H
#include <vector>
#include <ostream>



class Direction{
private:
    const int _row;
    const int _column;

public:

    //CONSTRUCTOR
    Direction(int row,int column) : _row(row),_column(column){}


    //GETTER
    inline int getRow(){
        return _row;
    }
    inline int getColumn(){
        return _column;
    }


    friend std::ostream & operator<<(std::ostream & os,Direction pos){
    os << "[" << pos.getRow()<< "," << pos.getColumn() << "]";
    return os;
    }

};

#endif // DIRECTION_H
