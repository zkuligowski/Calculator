#define _USE_MATH_DEFINES
#include "funkcje.h"
#include <iostream>
#include <Windows.h>
#include <conio.h>
using namespace std;
HANDLE hOut;

void WyswietlMENU()
{
    hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hOut, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
    cout << "\t\t*Kalkulator*" << endl;         
    cout << "\t0. Wyjdź" << endl;
    cout << "\t1. Dodawanie" << endl;
    cout << "\t2. Odejmowanie" << endl;
    cout << "\t3. Mnożenie" << endl;
    cout << "\t4. Dzielenie" << endl;
    cout << "\t5. Miejsca zerowe" << endl;
    cout << "\t6. Modulo" << endl;
    cout << "\t7. Sinus" << endl;
    cout << "\t8. Logarytm naturalny" << endl << endl;
    SetConsoleTextAttribute(hOut, FOREGROUND_GREEN);
}
int Wybor(char WyborDzialania, float a, float b,float A,float B, float C, float D, float m1, float m2)
{
    WyborDzialania=_getch();
    if (WyborDzialania == '0') cout << "Dziękuję za skorzystanie z kalkulatora\n\tWykonał:\n\tZbigniew Kuligowski\n\t228422" << endl << endl;
    if (WyborDzialania == '1') cout << "\t1. Dodawanie" << endl << endl;
    if (WyborDzialania == '2') cout << "\t2. Odejmowanie" << endl << endl;
    if (WyborDzialania == '3') cout << "\t3. Mnożenie" << endl << endl;
    if (WyborDzialania == '4') cout << "\t4. Dzielenie" << endl << endl;
    if (WyborDzialania == '5') cout << "\t5. Miejsca zerowe" << endl << endl;
    if (WyborDzialania == '6') cout << "\t6. Modulo" << endl << endl;
    if (WyborDzialania == '7') cout << "\t7. Sinus" << endl << endl;
    if (WyborDzialania == '8') cout << "\t8. Logarytm naturalny" << endl << endl;
    
    if (WyborDzialania == '0') exit(0);
    if (WyborDzialania > '0' && WyborDzialania < '5' || WyborDzialania == '6')
    {
        cout << "Podaj 1 liczbę:\t";
        cin >> a;
        cout << "Podaj 2 liczbę:\t";
        cin >> b;
    }
    else if (WyborDzialania == '5')
    {
        cout << "Podaj współczynnik A trójmianu kwadratowego:\t";
        cin >> A;
        cout << "Podaj współczynnik B trójmianu kwadratowego\t";
        cin >> B;
        cout << "Podaj współczynnik B trójmianu kwadratowego:\t";
        cin >> C;
    }
    else if (WyborDzialania == '7')
    {
        cout << "Podaj kąt w stopniach" << endl;
        cin >> a;
    }
     else if (WyborDzialania == '8')
    {
        cout << "Podaj liczbę logarytmowaną" << endl;
        cin >> a;
    }
     else
    {
        SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_INTENSITY);
        cout << "Wybrałeś nieprawidłowe działanie!\n\n";
        SetConsoleTextAttribute(hOut, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
    }
    switch (WyborDzialania)
    {
    case '1':
        wyswietl(dodawanie(a, b));     break;
    case '2':
        wyswietl(odejmowanie(a, b));   break;
    case '3':
        wyswietl(mnozenie(a, b));      break;
    case '4':
        if (b == 0) cout << "Nie dzielimy przez 0!" << endl << endl;
        else wyswietl(dzielenie(a, b));         break;
    case '5':
        D = delta(A, B, C);
        m1 = miejsce_zerowe1(A, B, D);
        m2 = miejsce_zerowe2(A, B, D);
        wyswietl_miejsca_zerowe(m1, m2, D);     break;
    case '6':
        wyswietl(modulo(a, b)); break;
    case '7':
        wyswietl(Sinus(a));     break;
    case '8':
        if (a <= 0) cout << "Liczba logarytmowana musi być większa od zera!" << endl <<endl;
        else wyswietl(Logarytm_Naturalny(a));    break;
    }
}
void wyswietl(float z) {
	
	cout << "Wynik wynosi:\t" << z << endl << endl;
}
float dodawanie(float x, float y) 
{
	return(x + y);
}
float odejmowanie(float x, float y)
{
	return(x - y);
}
float mnozenie(float x, float y) 
{
	return(x * y);
}
float dzielenie(float x, float y) 
{
	return(x / y);
}
float delta(float x, float y, float z) 
{
	return(y * y - 4 * x * z);
}
float miejsce_zerowe1(float x, float y, float z)
{
	return((-y - sqrt(z)) / (2 * x));
}
float miejsce_zerowe2(float x, float y, float z)
{
	return((-y + sqrt(z)) / (2 * x));
}
void wyswietl_miejsca_zerowe(float x, float y, float z)
{
    if (z < 0) cout << "Brak rozwiązań" << endl << endl;
    else if (z == 0)
    {
        cout << "\nRozwiązaniem jest jedno miejsce zerowe" << endl;
        wyswietl(x);
    }
    else if (z > 0)
    {
        cout << "\nRozwiązaniem sa dwa miejsca zerowe" << endl<< endl;
        wyswietl(x);
        wyswietl(y);
    }
}
int modulo(int x, int y)
{
    return(x % y); 
}
void wyswietl_modulo(int z)
{
    cout << "Reszta z dzielenia wynosi:\t" << endl;
}
float Sinus(float x)
{
    return sin((x * 2 * M_PI) / 360);
}
float Logarytm_Naturalny(float x)
{

    return log(x);
}
