/*
Viikkotehtävä 1

Laadi ohjelma, joka pyytää pelaajaa arvaamaan arvotun satunnaisen luvun annetulta väliltä 1-n. 

Kerrotaan onko hänen arvauksensa pienempi tai suurempi tai yhtäsuuri kuin etsittävä luku. 
Kun arvaus on yhtäsuuri kuin luku, peli päättyy.

Kirjoita ohjelma main-funktion sisälle ns. pääohjelmaksi. Korkein arvattava luku on 20. 

Ohjelman runko voisi olla jotain seuraavan kaltaista:
Arvotaan satunnainen luku
Kysytään pelaajalta arvaus
Tarkistetaan onko arvaus pienempi, suurempi tai yhtäsuuri kuin luku
Kerrotaan tarkistuksen tulos tyyliin ”luku on pienempi/suurempi” tai ”oikea vastaus”
Jos pelaajan vastaus ei ollut oikein, niin palataan kohtaan 2.

Vinkkejä:
-Tarvittavia muuttujia on siis vähintään 2, etsittävä luku ja palaajan arvaus.
-targetNumbergeneraattori löytyy standardikirjastoista cstdlib ja ctime. Nämä pitää siis #include-käskyillä tuoda ohjelmaan. 
Generaattorista tarvitaan funktiot srand(), joka alustaa targetNumbergeneraattorin ja rand(), joka arpoo luvun. 
Arvotun luvun voi rajoittaa halutulle välille esim modulo-operaation=jakojäännös (%) avulla (10%3 = 1)
-Ohjelmaa kirjoitettaessa ja testattaessa on syytä tulostaa cout:lla tietoa ruudulle. 
Kannattanee aloittaa tuon targetNumbergeneraattorin toiminnan testauksella ja todistaa itselleen, 
että generoitu ja esim modulo operaattorilla rajoitettu luku on välillä 1-20.

Tee tehtävän 1 ohjelma oman funktion sisälle niin, että sitä kutsutaan main-funktiosta.
Muuta toteuttamaasi funktiota siten, että funktiolle annetaan parametriksi korkein etsittävä luku, josta funktio arpoo satunnaisluvun. 
Esimerkiksi, jos tämä luku on 40, niin funktio arpoo luvun väliltä 1-40. 
Laske myös montako arvausta pelaajalla meni ja palauta tämä tieto funktiosta paluuarvona. 
Pelin loputtua tulosta arvausten määrä ruudulle main funktiosta paluuarvoa hyödyntäen. 
Käytä funktion nimenä ja prototyyppinä: int game(int maxnum);
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "finnish.h"


using namespace std;

int game(int maxnum);

int main()
{
    localeFinnish();

    cout << "RANDMAX =" << RAND_MAX << "\n";
    cout << "Time =" << time(0) <<endl;

    srand(time(0)); // satunnaislukugen alustus

    int guesses = game(15);
    
    cout<<"Arvauksia laskettu = " << guesses << endl;

    return 0;

}

int game(int maxnum) 
{
    int targetNumber = rand() % maxnum +1;
    int userNumber = -1;
    int guesses = 0;

    while (userNumber != targetNumber) 
    {
        cout<<"Arvaa luku 1-" << maxnum << " väliltä " << endl;
        cin >> userNumber;

        guesses++;

        //cout<<"Annoit numeron = "<< userNumber << endl;

        if (userNumber != targetNumber) {
            cout <<"Annoit väärän numeron! Arvaahan uudestaan" << endl;
        } else {
            cout << "Hei, sinä onnistuit! Valitsit oikean numeron!" << endl;
        }
    }

    return guesses;
}