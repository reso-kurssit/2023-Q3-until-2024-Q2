#include "kerrostalo.h"

kerrostalo::kerrostalo():eka(new katutaso(1)), toka(new kerros(2)), kolmas(new kerros(3))
{
    cout << "(Kerrostalo luotu) \n";

    cout << "Määritetään kerrostalon kaikki huoneistot \n";

    eka->maaritaAsunnot();
    toka->maaritaAsunnot();
    kolmas->maaritaAsunnot();
}

double kerrostalo::laskeKulutus(double h)
{
    cout << " Talonyhtiön kulutukset: \n";
     double kulutus = eka->laskeKulutus(h) +
             toka->laskeKulutus(h) +
             kolmas->laskeKulutus(h);

     cout << " Kokonaiskulutus on " << kulutus << "\n";
     return kulutus;
}

kerrostalo::~kerrostalo()
{
   cout <<  "(Koko kerrostalo tuhottu)" << endl;
}
