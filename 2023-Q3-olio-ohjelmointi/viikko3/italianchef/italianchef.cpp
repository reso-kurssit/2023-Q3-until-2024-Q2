#include "italianchef.h"


ItalianChef::ItalianChef(string n, int water, int flour)
    :Chef(n), water(water), flour(flour)
{
    //name = n;
    cout << "Chef " <<name<< " constructor" << endl;
}

/*ItalianChef::~ItalianChef ()
{
    cout << "Chef " << name << " destructor "<< endl;
}*/


void ItalianChef::makePasta()
{
    cout << "Chef " << name << " makes pasta with special recipe" << endl;
    cout << "Chef " << name << " uses water = " << water << endl;
    cout << "Chef " << name << " uses flour = " << flour << endl;

}
