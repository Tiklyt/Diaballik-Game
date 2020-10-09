#ifndef PAWN_H
#define PAWN_H
#include <utility>
#include <string>
#include "Color.h"
class Pawn{
private:
    std::pair<bool,Color> _pawn;
public:

    //CONSTRUCTORS
    Pawn(Color color);
    Pawn();
    //GETTER
    Color & getColor();
    bool & containBall();

    //CHANGER
    void putBall();
    void setEmpty();
    void setColor(Color c);
    void removeBall();
    void copy(Pawn p);
    //CHECKERS
    bool isEmpty();
    bool isMovable();


    //OVERLOAD
    friend std::ostream & operator<<(std::ostream & os,Pawn p){
        std::string value;
        if(p.containBall()){
            if(p.getColor() == Color::BROWN){
                value+=" (X) ";
            } else {
                value+=" (O) ";
            }
        } else {
            if(p.getColor() == Color::BROWN){
                value+="  X  ";
            } else if(p.getColor() == Color::BLACK){
                value+="  O  ";
            } else {
                value+="  -  ";
            }
        }
        os << value;
        return os;
    }
};

#endif // PAWN_H
