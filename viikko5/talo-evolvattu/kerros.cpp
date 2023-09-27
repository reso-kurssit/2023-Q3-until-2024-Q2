#include "kerros.h"

kerros::kerros(int kerrosNumero):
    as1 (new asunto(to_string((kerrosNumero-1)*4+1))),
    as2 (new asunto(to_string((kerrosNumero-1)*4+2))),
    as3 (new asunto(to_string((kerrosNumero-1)*4+3))),
    as4 (new asunto(to_string((kerrosNumero-1)*4+4))),
    kerrosNumero(kerrosNumero)

{
    cout << "(Kerros luotu) \n";
}


void kerros::maaritaAsunnot()
{
    cout << "Määritetään kerroksen " << kerrosNumero << " huoneistoja \n";

    as1->maarita(2, 52);
    as2->maarita(2, 56);
    as3->maarita(2, 52);
    as4->maarita(2, 56);
}

double kerros::laskeKulutus(double h)
{
    return as1->laskeKulutus(h) +
            as2->laskeKulutus(h) +
            as3->laskeKulutus(h) +
            as4->laskeKulutus(h);
}

kerros::~kerros()
{
    delete as1;
    as1 = nullptr;
    delete as2;
    as2 = nullptr;
    delete as3;
    as3 = nullptr;
    delete as4;
    as4 = nullptr;
}
