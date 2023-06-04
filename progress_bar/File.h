//
// Created by davide on 22/03/23.
//
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <sstream>
#include "CustomException.h"

#ifndef LAB_PROGRAMMAZIONE_FILE_H
#define LAB_PROGRAMMAZIONE_FILE_H

using namespace std;

class File {

public:

    explicit File(string &filename) : fileSize(0), loaded(false), title(filename){  }

    File(const File &other)
    {
        fileSize = other.fileSize;
        title = other.title;
        loaded = other.loaded;
        Content = other.Content;
    }

    ~File(){
        file.close();
    }

    bool openFile(){
        file.open(title);
        if (file.is_open()) {
            file.seekg(0, file.end);
            fileSize = file.tellg();
            file.seekg(0, file.beg);
            while (!file.eof())
                Content += file.get();
            loaded = true;
        }
        return loaded;
    }

    bool isLoaded(){
        return loaded;
    }

    string getContent(){
        return (Content);
    }

    string getTitle(){
        return (title);
    }


private:

    int fileSize;
    fstream file;
    //unique_ptr<string> Content = nullptr;
    bool loaded=false;
    string Content;
    string title;
};
#endif //LAB_PROGRAMMAZIONE_FILEP_H