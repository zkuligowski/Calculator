#pragma once
#ifndef FUNKCJE_H
#define FUNKCJE_H


int Wybor(char WyborDzialania, float a, float b, float A, float B, float C, float D, float m1, float m2);
void WyswietlMENU();
void wyswietl(float z);
float dodawanie(float x, float y);
float odejmowanie(float x, float y);
float mnozenie(float x, float y);
float dzielenie(float x, float y);
float delta(float x, float y, float z);
float miejsce_zerowe1(float x, float y, float z);
float miejsce_zerowe2(float x, float y, float z);
void wyswietl_miejsca_zerowe(float x, float y, float z);
int modulo(int x, int y);
void wyswietl_modulo(int z);
float Sinus(float x);
float Logarytm_Naturalny(float x);


#endif