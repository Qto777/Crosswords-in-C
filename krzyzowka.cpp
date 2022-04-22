#include <iostream>
#include <stdlib.h>
#include <fstream>
#include "gra.h"
#include "krzyzowka.h"
using namespace std;
//Olga Grabowska 304974

Krzyzowka::Krzyzowka(){
    n = 5;
    m = 5;
    letters = new char* [n];
    for (int i = 0; i < n; i++)
    {
        letters[i] = new char [m];
        for (int  j = 0; j < m; j++)
            letters[i][j] = '+';
    }
    licznik++;
}

Krzyzowka::Krzyzowka(string Name, int N, int M){
    nazwa = Name;
    n = N;
    m = M;
    letters = new char* [n];
    for (int i = 0; i < n; i++)
    {
        letters[i] = new char [m];
        for (int  j = 0; j < m; j++)
            letters[i][j] = 'a';
    }
    licznik++;
}
Krzyzowka::Krzyzowka(Krzyzowka &crossword){
    nazwa = crossword.nazwa;
    n = crossword.n;
    m = crossword.m;
    letters = new char* [n];
    for (int i = 0; i < n; i++)
    {
        letters[i] = new char [m];
        for (int  j = 0; j < m; j++)
            letters[i][j] = 'a';
    }
    licznik++;
}

Krzyzowka &Krzyzowka::operator=(const Krzyzowka & maka){
    if(&maka==this)
    {
        return *this;
    }
    for (int x = 0; x < n; x++)
        delete [] letters[x];
    delete [] letters;
    letters = new char* [maka.n];
    for (int i = 0; i < maka.n; i++)
    {
        letters[i] = new char [maka.m];
        for (int  j = 0; j < maka.m; j++)
            letters[i][j] = '+';
    }
    return *this;
}

void Krzyzowka::Print(){
    cout << nazwa << endl;
    cout << "n x m: " << n << " x " << m << endl;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
            cout << letters[i][j] << " ";
        cout << endl;
    }
    cout << endl;
}

void Krzyzowka::Clear(char znak){
    for (int i = 0; i < n; i++)
    {
        letters[i] = new char [m];
        for (int  j = 0; j < m; j++)
            letters[i][j] = znak;
    }
}

void Krzyzowka::Set(int col, int row, char znak){
    letters[col][row] = znak;
}

void Krzyzowka::Write(char* a){
    ofstream ofile;
    ofile.open(a);
    ofile << nazwa << endl;
    ofile << "n x m: " << n << " x " << m << endl;
    for(int i = 0; i < n; i++)
    {
      for (int j = 0; j < m; j++)
        ofile << letters[i][j] << " ";
    ofile << endl;
    }
    ofile.close();
}
