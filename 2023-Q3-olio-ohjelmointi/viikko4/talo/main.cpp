#include "finnish.h"
//#include "asunto.h"
//#include "katutaso.h"
//#include "kerros.h"
#include "kerrostalo.h"

using namespace std;


int main()
{
   localeFinnish();

    //asunto oasunto;
    //oasunto.maarita(1, 39);
    //oasunto.laskeKulutus(1);

    //katutaso okatutaso;
    //okatutaso.maaritaAsunnot();
    //okatutaso.laskeKulutus(220);

    //kerros okerros;
    //okerros.maaritaAsunnot();
    //okerros.laskeKulutus(190);

   kerrostalo okerrostalo;
   okerrostalo.laskeKulutus(0.8);

    return 0;
}
