#ifndef _krzyzowka_h_
#define _krzyzowka_h_
#include "gra.h"
using namespace std;
//Olga Grabowska 304974

class Krzyzowka : public Gra {
    int n;
    int m;
    char** letters;
public:
    Krzyzowka();
    Krzyzowka(string Name, int N, int M);
    Krzyzowka(Krzyzowka &crossword);
    //~Krzyzowka(); //niepotrzebny skoro jest wirtualny
    Krzyzowka & operator=(const Krzyzowka & maka);
    virtual void Print(); //wypisuje ROZMIAR TABLICY oraz TABLICE
    void Clear(char znak); //wypelnia wszystkie pola tablicy znakiem
    void Set(int col, int row, char znak); //wstawia znak w odpowiednie miejsce tablicy
    void Write(char* a); //zapisuje do pliku a
};



#endif // _krzyzowka_h_
