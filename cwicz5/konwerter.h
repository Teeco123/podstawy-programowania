#ifndef KONWERTER_H
#define KONWERTER_H

#include <stdio.h>
#include <stdlib.h>

// Struktura dla waluty
typedef struct {
  char nazwa[20];
  double kurs;
  char symbol[5];
} Waluta;

// Funkcje konwertera walut
void menu_walut();
double konwertuj_walute(double kwota_pln, double kurs);
void wyswietl_wynik(double kwota_pln, double kwota_docelowa,
                    const char *nazwa_waluty, const char *symbol);
void uruchom_konwerter();

#endif
