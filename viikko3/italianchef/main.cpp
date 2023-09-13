#include <iostream>
#include "chef.h"
#include "italianchef.h"


using namespace std;

int main()
{
    Chef chef1 ("Gordon Ramsay");
    chef1.makeSalad();
    chef1.makeSoup();
    //chef1.makePasta();

    ItalianChef chef2 ("Anthony Bourdain", 100, 250);
    chef2.makeSoup();
    chef2.makePasta();

    ItalianChef chef3 ("Massimo Bottura", 150, 320);
    chef3.makeSalad();
    chef3.makePasta();

    return 0;
}

