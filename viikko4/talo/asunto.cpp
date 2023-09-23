#include "asunto.h"

asunto::asunto(string tunniste):asunnonTunniste(tunniste)
{
    cout << "(Asunto luotu) \n";
}

void asunto::maarita(int a, int n)
{
    cout << " Huoneiston tiedot: \n" ;
    asukasmaara = a;
    neliot = n;

    cout << "  Asunnon koko " << neliot << " m2 \n";
    cout << "  Asukkaiden lukumäärä " << asukasmaara << "\n";
}

double asunto::laskeKulutus(double h)
{
    double kulutus = h*asukasmaara * neliot;
    cout << "  Asunnon " << asunnonTunniste << " kulutus silloin, kun hinta on " << h << " on " << kulutus << "\n";

    return kulutus;
}

