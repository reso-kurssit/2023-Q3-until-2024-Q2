#include "chef.h"



Chef::Chef(string s)
{
    name = s;
    cout << "Chef " << name << " constructor "<< endl;

}

Chef::~Chef ()
{
    cout << "Chef " << name << " destructor "<< endl;
}

void Chef::makeSalad()
{
    cout << "Chef " << name << " makes salad "<< endl;
}


void Chef::makeSoup()
{
    cout << "Chef " << name << " makes soup "<< endl;
}

/*
void Chef::makePasta()
{
    cout << "Chef " << name << " makes plain pasta "<< endl;
}*/

