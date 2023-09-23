#include "kerros.h"
#include "kerrostalo.h"

kerros::kerros(int kerrosNumero):kerrosNumero(kerrosNumero),
    as1(asunto(to_string((kerrosNumero-1)*4+1))),
    as2(asunto(to_string((kerrosNumero-1)*4+2))),
    as3(asunto(to_string((kerrosNumero-1)*4+3))),
    as4(asunto(to_string((kerrosNumero-1)*4+4)))

{
    cout << "(Kerros luotu) \n";
}


void kerros::maaritaAsunnot()
{
    cout << "Määritetään kerroksen " << kerrosNumero << " huoneistoja \n";

    as1.maarita(2, 48);
    as2.maarita(2, 48);
    as3.maarita(2, 48);
    as4.maarita(2, 48);

}

double kerros::laskeKulutus(double h)
{
    return as1.laskeKulutus(h) +
            as2.laskeKulutus(h) +
            as3.laskeKulutus(h) +
            as4.laskeKulutus(h);
}

kerros::~kerros()
{

}
