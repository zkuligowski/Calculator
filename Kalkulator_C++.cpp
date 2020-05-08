#include <iostream>
#include "funkcje.h"
#include <locale.h>
using namespace std;

char WyborDzialania;     // Wybor opcji z MENU

float a;    // Pierwsza liczba
float b;    // Druga liczba
float A;    // Współczynnik A trójmianu kwadratowego
float B;    // Współczynnik B trójmianu kwadratowego
float C;    // Wyraz wolny trójmianu kwadratowego
float D;    // Delta
float m1;   // Miejsce zerowe 1 lub Podwójne miejsce zerowe
float m2;   // Miejsce zerowe 2

int main()
{
    for (;;)
    {
        setlocale(LC_CTYPE, "Polish");                  // Język polski w konsoli
        WyswietlMENU();                                 // Wyswietla Menu ekranowe
        Wybor(WyborDzialania, a, b,A,B,C,D,m1,m2);      // Wybiera dzialanie i je wykonuje
    }
    return 0;
}

