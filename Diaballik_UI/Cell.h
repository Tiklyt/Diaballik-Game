#ifndef CELL_H
#define CELL_H

#include "Pawn.h"
#include "Observable.h"
#include "Observer.h"
#include <vector>
#include <iostream>
class Cell : public Observable{
private:

    Pawn  _pawn;
    std::vector<Observer *> observers;

public:

    //CONSTRUCTORS
    Cell(Pawn p);
    Cell() = default;
    //GETTER
    Pawn & getPawn();

    //SETTER
    void setBall();
    void resetBall();
    void setColor(Color c);
    void setEmpty();
    void copy(Pawn p);
    //GETTER
    bool isFree();


    //OBSERVABLE
    void notify() override{
        for(unsigned i = 0; i<observers.size();i++){
            observers[i]->update();
            std::cout << "UPDATED";
        }
    }

    void attach(Observer *observer) override{
        observers.push_back(observer);
    }

    //OVERLOAD
    friend std::ostream & operator<<(std::ostream & os,Cell c){
        os << c.getPawn();
        return os;
    }
};

#endif // CELL_H
