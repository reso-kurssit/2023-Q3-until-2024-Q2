#ifndef ITALIANCHEF_H
#define ITALIANCHEF_H
#include <iostream>
#include "chef.h"

using namespace std;

class ItalianChef : public Chef
{
public:
    ItalianChef (string, int, int);
    //~ItalianChef ();
    string getName();
    void makePasta();

private:
    int water;
    int flour;

};

#endif // ITALIANCHEF_H
