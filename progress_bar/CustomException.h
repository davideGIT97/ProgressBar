//
// Created by davide on 29/03/23.
//
#include <string>
#include <iostream>

#ifndef PROGRESS_BAR_CUSTOMEXCEPTION_H
#define PROGRESS_BAR_CUSTOMEXCEPTION_H

using namespace std;

class myException : public exception{
public:
    explicit myException(string &n) : name(n) {}
    string getName() const { return name;}

private:
    string name;
};

#endif //PROGRESS_BAR_CUSTOMEXCEPTION_H
