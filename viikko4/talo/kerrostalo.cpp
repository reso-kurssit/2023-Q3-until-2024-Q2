#include "kerrostalo.h"

kerrostalo::kerrostalo():eka(katutaso(1)), toka(kerros(2)), kolmas(kerros(3))
{
    cout << "(Kerrostalo luotu) \n";

    cout << "Määritetään kerrostalon kaikki huoneistot \n";

    //eka = katutaso(0);
    //toka = kerros(1);
    //kolmas = kerros(2);

    eka.maaritaAsunnot();
    toka.maaritaAsunnot();
    kolmas.maaritaAsunnot();
}


double kerrostalo::laskeKulutus(double h)
{
    cout << " Talonyhtiön kulutukset: \n";
     double kulutus = eka.laskeKulutus(h) +
             toka.laskeKulutus(h) +
             kolmas.laskeKulutus(h);

     cout << " Kokonaiskulutus on " << kulutus << "\n";
     return kulutus;
}

kerrostalo::~kerrostalo()
{
   cout <<  "(Koko kerrostalo tuhottu)" << endl;
}
