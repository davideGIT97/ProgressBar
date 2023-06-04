//
// Created by davide on 19/03/23.
//

#include "Loader.h"
#include "Subject.h"


void Loader::attach(Observer* o) {
    observers.push_back(o);
}

void Loader::detach(Observer* o) {
    observers.remove(o);
}

void Loader::notify() {
        for (const auto &itr : observers)
            itr->update();
}

//Caricamento ricorsivo
void Loader::load(list<string>& filenames){
    bool inside = false;

    for (auto itr : filenames)
        NumOfResources++;

    try {
        for (auto &itr: filenames) {

        auto found = find(Loaded.begin(), Loaded.end(), itr);
        if(found != Loaded.end()) {
            inside = true;
            NumOfResources--;
        }
        else
            inside=false;
/*
            for (auto &f: files){
                if (itr == f.getTitle()) {
                    inside = true;
                    NumOfResources--;
                }
        }
*/
            if (!inside) {
                File file(itr);
                if (file.openFile()) {
                    Loaded.push_back(itr);
                    files.push_back(file);
                    resouceLoaded++;
                    notify();
                } else {
                    throw (myException(itr));
                }

              }

        }
    } catch(myException& err){
        NumOfResources=0;
        resouceLoaded=0;
        filenames.remove(err.getName());
        notLoaded.push_back(err.getName());
        loaded=false;
        load(filenames);
    }

}








