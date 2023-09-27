#ifndef ASUNTO_H
#define ASUNTO_H
#include <iostream>

using namespace std;

class asunto
{
public:
    asunto(string tunniste);

    void maarita(int, int);
    double laskeKulutus(double);

    int asukasmaara;
    int neliot;

private:
    string asunnonTunniste;
};

#endif // ASUNTO_H
