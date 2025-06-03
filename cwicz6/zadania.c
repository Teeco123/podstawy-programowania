#include "zadania.h"

// Funkcja obliczająca silnię podanej liczby
long long oblicz_silnie(int n) {
  if (n < 0) {
    printf("Błąd: Silnia nie jest zdefiniowana dla liczb ujemnych!\n");
    return -1;
  }

  long long silnia = 1;

  // Używamy pętli for do obliczenia silni
  for (int i = 1; i <= n; i++) {
    silnia *= i;
  }

  return silnia;
}

// Funkcja obliczająca średnią arytmetyczną liczb parzystych
// i średnią geometryczną liczb nieparzystych z zadanego przedziału
void oblicz_srednie(int poczatek, int koniec) {
  if (poczatek > koniec) {
    printf("Błąd: Początek przedziału nie może być większy od końca!\n");
    return;
  }

  // Zmienne dla liczb parzystych
  int suma_parzystych = 0;
  int liczba_parzystych = 0;

  // Zmienne dla liczb nieparzystych
  double iloczyn_nieparzystych = 1.0;
  int liczba_nieparzystych = 0;

  // Pętla for przechodząca przez cały przedział
  for (int i = poczatek; i <= koniec; i++) {
    if (i % 2 == 0) {
      // Liczba parzysta
      suma_parzystych += i;
      liczba_parzystych++;
    } else {
      // Liczba nieparzysta
      iloczyn_nieparzystych *= i;
      liczba_nieparzystych++;
    }
  }

  // Wyświetlanie wyników
  printf("Przedział: [%d, %d]\n", poczatek, koniec);

  if (liczba_parzystych > 0) {
    double srednia_arytmetyczna = (double)suma_parzystych / liczba_parzystych;
    printf("Średnia arytmetyczna liczb parzystych: %.2f\n",
           srednia_arytmetyczna);
  } else {
    printf("Brak liczb parzystych w przedziale.\n");
  }

  if (liczba_nieparzystych > 0) {
    double srednia_geometryczna =
        pow(iloczyn_nieparzystych, 1.0 / liczba_nieparzystych);
    printf("Średnia geometryczna liczb nieparzystych: %.2f\n",
           srednia_geometryczna);
  } else {
    printf("Brak liczb nieparzystych w przedziale.\n");
  }

  printf("\n");
}

int main() {
  int wybor;

  do {
    printf("=== MENU ===\n");
    printf("1. Oblicz silnię liczby\n");
    printf("2. Oblicz średnie w przedziale\n");
    printf("0. Wyjście\n");
    printf("Wybierz opcję: ");
    scanf("%d", &wybor);

    switch (wybor) {
    case 1: {
      int liczba;
      printf("Podaj liczbę do obliczenia silni: ");
      scanf("%d", &liczba);

      long long wynik = oblicz_silnie(liczba);
      if (wynik != -1) {
        printf("Silnia z %d = %lld\n\n", liczba, wynik);
      }
      break;
    }

    case 2: {
      int poczatek, koniec;
      printf("Podaj początek przedziału: ");
      scanf("%d", &poczatek);
      printf("Podaj koniec przedziału: ");
      scanf("%d", &koniec);

      oblicz_srednie(poczatek, koniec);
      break;
    }

    case 0:
      printf("Do widzenia!\n");
      break;

    default:
      printf("Nieprawidłowy wybór!\n\n");
      break;
    }

  } while (wybor != 0);

  return 0;
}
