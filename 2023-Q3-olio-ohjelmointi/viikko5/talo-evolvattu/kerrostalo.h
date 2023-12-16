#ifndef KERROSTALO_H
#define KERROSTALO_H
#include "katutaso.h"

class kerrostalo
{
public:
    kerrostalo();
    ~kerrostalo();

    double laskeKulutus(double);

private:
    katutaso * eka;
    kerros * toka;
    kerros * kolmas;
};

#endif // KERROSTALO_H
