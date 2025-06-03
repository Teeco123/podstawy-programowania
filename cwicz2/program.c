#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Zadanie a) - Przelicznik temperatur
void zadanie_a() {
  float celsius, fahrenheit;

  printf("=== ZADANIE A: PRZELICZNIK TEMPERATUR ===\n");
  printf("Podaj temperature w stopniach Celsjusza: ");
  scanf("%f", &celsius);

  // Przeliczenie Celsius na Fahrenheit: TF = (TC * 9/5) + 32
  fahrenheit = (celsius * 9.0 / 5.0) + 32.0;

  printf("%.1f stopni Celsjusza to %.1f stopni Fahrenheita\n", celsius,
         fahrenheit);

  // Opcjonalnie też w drugą stronę
  printf("\nPodaj temperature w stopniach Fahrenheita: ");
  scanf("%f", &fahrenheit);

  // Przeliczenie Fahrenheit na Celsius: TC = (TF - 32) * 5/9
  celsius = (fahrenheit - 32.0) * 5.0 / 9.0;

  printf("%.1f stopni Fahrenheita to %.1f stopni Celsjusza\n", fahrenheit,
         celsius);
}

// Zadanie b) - Generator liczb losowych w przedziale
void zadanie_b() {
  int min, max, liczba_losowa;

  printf("\n=== ZADANIE B: GENERATOR LICZB LOSOWYCH ===\n");
  printf("Podaj dolna granice przedzialu: ");
  scanf("%d", &min);
  printf("Podaj gorna granice przedzialu: ");
  scanf("%d", &max);

  // Inicjalizacja generatora liczbami pseudolosowymi
  srand(time(NULL));

  // Generowanie liczby w przedziale [min, max]
  liczba_losowa = min + rand() % (max - min + 1);

  printf("Wylosowana liczba z przedzialu [%d, %d]: %d\n", min, max,
         liczba_losowa);
}

// Zadanie c) - Generator liczb rzeczywistych z zadaną dokładnością
void zadanie_c() {
  float min, max, liczba_losowa;
  int dokladnosc;

  printf("\n=== ZADANIE C: GENERATOR LICZB RZECZYWISTYCH ===\n");
  printf("Podaj dolna granice przedzialu (liczba rzeczywista): ");
  scanf("%f", &min);
  printf("Podaj gorna granice przedzialu (liczba rzeczywista): ");
  scanf("%f", &max);
  printf("Podaj dokladnosc (liczba miejsc po przecinku 0-4): ");
  scanf("%d", &dokladnosc);

  // Ograniczenie dokładności do zakresu 0-4
  if (dokladnosc < 0)
    dokladnosc = 0;
  if (dokladnosc > 4)
    dokladnosc = 4;

  // Inicjalizacja generatora (gdyby nie była wcześniej wywołana)
  srand(time(NULL));

  // Generowanie liczby rzeczywistej w przedziale [min, max]
  liczba_losowa = min + ((float)rand() / RAND_MAX) * (max - min);

  // Wyświetlenie z odpowiednią dokładnością
  switch (dokladnosc) {
  case 0:
    printf("Wylosowana liczba z przedzialu [%.0f, %.0f]: %.0f\n", min, max,
           liczba_losowa);
    break;
  case 1:
    printf("Wylosowana liczba z przedzialu [%.1f, %.1f]: %.1f\n", min, max,
           liczba_losowa);
    break;
  case 2:
    printf("Wylosowana liczba z przedzialu [%.2f, %.2f]: %.2f\n", min, max,
           liczba_losowa);
    break;
  case 3:
    printf("Wylosowana liczba z przedzialu [%.3f, %.3f]: %.3f\n", min, max,
           liczba_losowa);
    break;
  case 4:
    printf("Wylosowana liczba z przedzialu [%.4f, %.4f]: %.4f\n", min, max,
           liczba_losowa);
    break;
  }
}

int main() {
  // Ustawienie polskiej lokalizacji dla polskich znaków
  setlocale(LC_CTYPE, "Polish");

  int wybor;

  do {
    printf("\n=== MENU GLOWNE ===\n");
    printf("1. Zadanie A - Przelicznik temperatur\n");
    printf("2. Zadanie B - Generator liczb losowych (calkowite)\n");
    printf("3. Zadanie C - Generator liczb losowych (rzeczywiste)\n");
    printf("4. Wykonaj wszystkie zadania\n");
    printf("0. Wyjscie\n");
    printf("Wybierz opcje (0-4): ");
    scanf("%d", &wybor);

    switch (wybor) {
    case 1:
      zadanie_a();
      break;
    case 2:
      zadanie_b();
      break;
    case 3:
      zadanie_c();
      break;
    case 4:
      zadanie_a();
      zadanie_b();
      zadanie_c();
      break;
    case 0:
      printf("Koniec programu.\n");
      break;
    default:
      printf("Nieprawidlowy wybor!\n");
    }

    if (wybor != 0) {
      printf("\nNacisnij Enter, aby kontynuowac...");
      getchar(); // Pobranie znaku Enter z bufora
      getchar(); // Oczekiwanie na naciśnięcie Enter
    }

  } while (wybor != 0);

  return 0;
}
