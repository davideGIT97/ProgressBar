//
// Created by davide on 19/03/23.
//

#ifndef PROGRESS_BAR_VIEWER_H
#define PROGRESS_BAR_VIEWER_H
#include <iostream>
#include "Observer.h"
#include "Loader.h"

class Viewer : public Observer{

public:
    explicit Viewer(Loader *loader) : loader(loader){
        names.push_back("File1");
        names.push_back("File2");
        names.push_back("File3");

    }

    ~Viewer() {
        loader->detach(this);
    }

    list<const char*> getNames(){
        return names;
    }


    void update(){
        for (auto &itr : loader->getFiles()) {
            cout << itr->getContent().c_str();
        }
        }


private:
    Loader *loader;
    list<const char*> names;
    int i=0;
};


#endif //PROGRESS_BAR_VIEWER_H
