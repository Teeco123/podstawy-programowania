#include "program.h"

int main() {
  srand(time(NULL)); // Inicjalizacja generatora liczb losowych

  int wybor;

  do {
    menuGlowne();
    printf("Wybierz opcję (1-3): ");
    scanf("%d", &wybor);

    switch (wybor) {
    case 1:
      menuTemperatury();
      break;
    case 2:
      menuGeneratora();
      break;
    case 3:
      printf("Dziękuję za skorzystanie z programu!\n");
      break;
    default:
      printf("Nieprawidłowy wybór. Spróbuj ponownie.\n");
      break;
    }

    if (wybor != 3) {
      printf("\nNaciśnij Enter, aby kontynuować...");
      getchar();
      getchar();
    }

  } while (wybor != 3);

  return 0;
}

// Implementacja funkcji menu głównego
void menuGlowne() {
  printf("\n=== MENU GŁÓWNE ===\n");
  printf("1. Konwersja temperatur\n");
  printf("2. Generator liczb losowych\n");
  printf("3. Wyjście\n");
  printf("==================\n");
}

// === ZADANIE A) - KONWERSJA TEMPERATUR ===

// Funkcja konwertująca Celsjusz na Fahrenheit
float celsjuszNaFahrenheit(float celsius) {
  return (celsius * 9.0 / 5.0) + 32.0;
}

// Funkcja konwertująca Fahrenheit na Celsjusz
float fahrenheitNaCelsjusz(float fahrenheit) {
  return (fahrenheit - 32.0) * 5.0 / 9.0;
}

// Menu dla konwersji temperatur
void menuTemperatury() {
  int wybor;
  float temperatura, wynik;

  printf("\n=== KONWERSJA TEMPERATUR ===\n");
  printf("1. Celsjusz -> Fahrenheit\n");
  printf("2. Fahrenheit -> Celsjusz\n");
  printf("Wybierz opcję (1-2): ");
  scanf("%d", &wybor);

  switch (wybor) {
  case 1:
    printf("Podaj temperaturę w stopniach Celsjusza: ");
    scanf("%f", &temperatura);
    wynik = celsjuszNaFahrenheit(temperatura);
    printf("%.1f°C = %.1f°F\n", temperatura, wynik);
    break;
  case 2:
    printf("Podaj temperaturę w stopniach Fahrenheita: ");
    scanf("%f", &temperatura);
    wynik = fahrenheitNaCelsjusz(temperatura);
    printf("%.1f°F = %.1f°C\n", temperatura, wynik);
    break;
  default:
    printf("Nieprawidłowy wybór.\n");
    break;
  }
}

// === ZADANIE B) - GENERATOR LICZB LOSOWYCH ===

// Funkcja generująca liczbę losową w zadanym przedziale z określoną
// dokładnością
float generujLiczbe(float min, float max, int dokladnosc) {
  // Generowanie liczby losowej w przedziale [0, 1]
  float losowa = (float)rand() / RAND_MAX;

  // Skalowanie do zadanego przedziału
  float wynik = min + losowa * (max - min);

  // Zastosowanie dokładności przez odpowiednie zaokrąglenie
  float mnoznik = 1.0;
  for (int i = 0; i < dokladnosc; i++) {
    mnoznik *= 10.0;
  }

  wynik = ((int)(wynik * mnoznik + 0.5)) / mnoznik;

  return wynik;
}

// Menu dla generatora liczb losowych
void menuGeneratora() {
  float min, max;
  int dokladnosc;
  float wynik;

  printf("\n=== GENERATOR LICZB LOSOWYCH ===\n");

  printf("Podaj dolną granicę przedziału: ");
  scanf("%f", &min);

  printf("Podaj górną granicę przedziału: ");
  scanf("%f", &max);

  if (min > max) {
    printf("Błąd: dolna granica nie może być większa od górnej!\n");
    return;
  }

  printf("Podaj dokładność (liczba miejsc po przecinku 0-4): ");
  scanf("%d", &dokladnosc);

  if (dokladnosc < 0 || dokladnosc > 4) {
    printf("Błąd: dokładność musi być w przedziale 0-4!\n");
    return;
  }

  wynik = generujLiczbe(min, max, dokladnosc);

  printf("Wylosowana liczba: ");
  switch (dokladnosc) {
  case 0:
    printf("%.0f\n", wynik);
    break;
  case 1:
    printf("%.1f\n", wynik);
    break;
  case 2:
    printf("%.2f\n", wynik);
    break;
  case 3:
    printf("%.3f\n", wynik);
    break;
  case 4:
    printf("%.4f\n", wynik);
    break;
  }
}
