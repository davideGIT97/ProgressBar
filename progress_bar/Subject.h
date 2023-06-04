//
// Created by davide on 15/03/23.
//
#include <list>
#include "Observer.h"

#ifndef PROGRESS_BAR_SUBJECT_H
#define PROGRESS_BAR_SUBJECT_H

class Subject{
public:
    virtual ~Subject() {}
    virtual void attach(Observer* o) = 0;
    virtual void detach(Observer* o) = 0;
    virtual void notify() = 0;
};


#endif //PROGRESS_BAR_SUBJECT_H
