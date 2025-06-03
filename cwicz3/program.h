#ifndef PROGRAM_H
#define PROGRAM_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Deklaracje funkcji dla zadania a) - konwersja temperatur
float celsjuszNaFahrenheit(float celsius);
float fahrenheitNaCelsjusz(float fahrenheit);
void menuTemperatury();

// Deklaracje funkcji dla zadania b) - generator liczb losowych
float generujLiczbe(float min, float max, int dokladnosc);
void menuGeneratora();

// Funkcja pomocnicza do wyświetlania menu głównego
void menuGlowne();

#endif
