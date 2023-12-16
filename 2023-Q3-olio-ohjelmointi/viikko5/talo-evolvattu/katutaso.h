#ifndef KATUTASO_H
#define KATUTASO_H

//include "asunto.h"
#include "kerros.h"

class katutaso:public kerros
{
public:
    katutaso(int);
    ~katutaso();

    asunto * as0a;
    asunto * as0b;

    void maaritaAsunnot() override;
    double laskeKulutus(double) override;
};


#endif // KATUTASO_H
