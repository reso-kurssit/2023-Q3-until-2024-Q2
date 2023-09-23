#include "katutaso.h"

katutaso::katutaso(int kerrosNumero):kerros(kerrosNumero),
    as0a(asunto("0 A")),
    as0b(asunto("0 B"))
{
    cout << "(Katutaso luotu) \n";
}

void katutaso::maaritaAsunnot ()
{
    cout << "Määritetaan katutason huoneistoja \n";
    as0a.maarita(1, 55);
    as0b.maarita(1, 55);

    cout << "Määritetään kerrokselta perityt huoneistot \n";
    kerros::maaritaAsunnot();

}

double katutaso::laskeKulutus (double h)
{
    return as0a.laskeKulutus(h) +
            as0b.laskeKulutus(h) +
            kerros::laskeKulutus(h);
}

katutaso::~katutaso()
{

}
