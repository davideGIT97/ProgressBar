//
// Created by davide on 15/03/23.
//

#include <fstream>
#include <string>
#include <vector>
#include "Subject.h"
#include <memory>
#include "File.h"
#include <algorithm>


#ifndef PROGRESS_BAR_LOADER_H
#define PROGRESS_BAR_LOADER_H

using namespace std;

class Loader : public Subject{
public:

    Loader() : NumOfResources(0), resouceLoaded(0), loaded(true){}

    ~Loader() override{}

    void notify() override ;

    void load(list<string>& filenames);

    void attach(Observer* o) override;

    void detach(Observer* o) override;

    int getNumOfResources() const{
        return NumOfResources;
    }

    bool LoadingComplete() const{
        return loaded;
    }

    int getRL() const {
        return resouceLoaded;
    }

    vector<File> getFiles(){
        return (files);
    }

    list<string> getNotLoaded(){
        return (notLoaded);
    }

private:
    list<Observer*> observers;
    vector<File> files;
    list<string> Loaded;
    list<string> notLoaded;
    bool loaded;
    int NumOfResources;
    int resouceLoaded;
};






#endif //PROGRESS_BAR_LOADER_H
