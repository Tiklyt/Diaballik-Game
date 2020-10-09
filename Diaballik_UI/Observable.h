#ifndef SUBJECT_H
#define SUBJECT_H
#include "Observer.h"



class Observable {

public:



    virtual void attach(Observer *observer)    = 0;    // VP
    virtual void notify()                       = 0;    // VP

};

#endif // SUBJECT_H
