#include <math.h>
#include <stdio.h>

// Funkcja obliczająca średnią arytmetyczną
double oblicz_srednia_arytmetyczna(int suma, int liczba_elementow) {
  if (liczba_elementow == 0) {
    return 0.0;
  }
  return (double)suma / liczba_elementow;
}

// Funkcja obliczająca średnią geometryczną
double oblicz_srednia_geometryczna(double iloczyn, int liczba_elementow) {
  if (liczba_elementow == 0) {
    return 0.0;
  }
  return pow(iloczyn, 1.0 / liczba_elementow);
}

// Funkcja sprawdzająca czy liczba jest parzysta
int czy_parzysta(int liczba) { return liczba % 2 == 0; }

// Funkcja wyświetlająca wyniki
void wyswietl_wyniki(double srednia_arytm, double srednia_geom,
                     int liczba_parzystych, int liczba_nieparzystych) {
  printf("\n=== WYNIKI ===\n");

  if (liczba_parzystych > 0) {
    printf("Średnia arytmetyczna liczb parzystych: %.2f\n", srednia_arytm);
    printf("Liczba wprowadzonych liczb parzystych: %d\n", liczba_parzystych);
  } else {
    printf("Nie wprowadzono żadnych liczb parzystych.\n");
  }

  if (liczba_nieparzystych > 0) {
    printf("Średnia geometryczna liczb nieparzystych: %.2f\n", srednia_geom);
    printf("Liczba wprowadzonych liczb nieparzystych: %d\n",
           liczba_nieparzystych);
  } else {
    printf("Nie wprowadzono żadnych liczb nieparzystych.\n");
  }
}

int main() {
  int liczba;
  int suma_parzystych = 0;
  double iloczyn_nieparzystych = 1.0;
  int liczba_parzystych = 0;
  int liczba_nieparzystych = 0;

  printf("Program obliczający średnie arytmetyczną i geometryczną\n");
  printf("Wprowadzaj liczby całkowite (0 kończy wprowadzanie):\n");

  // Pętla pobierająca dane od użytkownika
  do {
    printf("Podaj liczbę: ");
    scanf("%d", &liczba);

    // Jeśli liczba to 0, kończymy pobieranie
    if (liczba == 0) {
      break;
    }

    // Sprawdzamy czy liczba jest parzysta czy nieparzysta
    if (czy_parzysta(liczba)) {
      suma_parzystych += liczba;
      liczba_parzystych++;
    } else {
      // Dla liczb nieparzystych obliczamy iloczyn
      iloczyn_nieparzystych *= liczba;
      liczba_nieparzystych++;
    }

  } while (1); // Nieskończona pętla, przerywana przez break

  // Obliczamy średnie
  double srednia_arytmetyczna =
      oblicz_srednia_arytmetyczna(suma_parzystych, liczba_parzystych);
  double srednia_geometryczna = oblicz_srednia_geometryczna(
      fabs(iloczyn_nieparzystych), liczba_nieparzystych);

  // Wyświetlamy wyniki
  wyswietl_wyniki(srednia_arytmetyczna, srednia_geometryczna, liczba_parzystych,
                  liczba_nieparzystych);

  return 0;
}
