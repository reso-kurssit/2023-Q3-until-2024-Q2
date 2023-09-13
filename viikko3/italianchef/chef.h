#ifndef CHEF_H
#define CHEF_H
#include <iostream>

using namespace std;

class Chef
{
public:
    Chef (string);
    ~Chef ();
    void makeSalad();
    void makeSoup();
    //void makePasta();

protected:
    string name;

};

#endif // CHEF_H
