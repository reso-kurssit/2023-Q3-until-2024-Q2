#include "finnish.h"
#include "kerrostalo.h"

using namespace std;


int main()
{
   localeFinnish();

   kerrostalo * okerrostalo = new kerrostalo();
   okerrostalo->laskeKulutus(0.95);

   delete okerrostalo;
   okerrostalo = nullptr;

   return 0;
}
