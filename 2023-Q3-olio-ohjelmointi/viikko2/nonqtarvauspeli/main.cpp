#include <iostream>
#include <cstdlib>
#include <ctime>
#include "finnish.h"
#include "Game.h"

using namespace std;

int main()
{
    localeFinnish();

    Game targets (75);
    targets.play ();

    return 0;
}
