//
// Created by davide on 15/03/23.
//

#ifndef PROGRESS_BAR_OBSERVER_H
#define PROGRESS_BAR_OBSERVER_H

class Observer{
public:
    Observer() {}
    virtual ~Observer(){}
    virtual void update() = 0;
};




#endif //PROGRESS_BAR_OBSERVER_H
