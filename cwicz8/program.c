#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Funkcja sortująca tablicę metodą bąbelkową
void sortuj_tablice(int *tablica, int rozmiar) {
  int temp;
  for (int i = 0; i < rozmiar - 1; i++) {
    for (int j = 0; j < rozmiar - 1 - i; j++) {
      if (tablica[j] > tablica[j + 1]) {
        // Zamiana miejscami
        temp = tablica[j];
        tablica[j] = tablica[j + 1];
        tablica[j + 1] = temp;
      }
    }
  }
}

// Funkcja wyświetlająca tablicę
void wyswietl_tablice(int *tablica, int rozmiar) {
  for (int i = 0; i < rozmiar; i++) {
    printf("%d ", tablica[i]);
  }
  printf("\n");
}

// Funkcja sprawdzająca czy liczba już istnieje w tablicy
int czy_istnieje(int *tablica, int rozmiar, int liczba) {
  for (int i = 0; i < rozmiar; i++) {
    if (tablica[i] == liczba) {
      return 1; // liczba istnieje
    }
  }
  return 0; // liczba nie istnieje
}

// Program 1: Sortowanie liczb w tablicy
void program_sortowanie() {
  printf("=== PROGRAM 1: SORTOWANIE TABLICY ===\n");

  int rozmiar;
  printf("Podaj rozmiar tablicy: ");
  scanf("%d", &rozmiar);

  int tablica[100]; // maksymalny rozmiar tablicy

  printf("Podaj %d liczb:\n", rozmiar);
  for (int i = 0; i < rozmiar; i++) {
    printf("Liczba %d: ", i + 1);
    scanf("%d", &tablica[i]);
  }

  printf("\nTablica przed sortowaniem: ");
  wyswietl_tablice(tablica, rozmiar);

  sortuj_tablice(tablica, rozmiar);

  printf("Tablica po sortowaniu: ");
  wyswietl_tablice(tablica, rozmiar);
  printf("\n");
}

// Program 2: Losowanie 6 liczb bez powtórzeń z przedziału 1-49
void program_losowanie() {
  printf("=== PROGRAM 2: LOSOWANIE 6 LICZB (1-49) ===\n");

  int wylosowane[6];
  int licznik = 0;

  // Inicjalizacja generatora liczb losowych
  srand(time(NULL));

  printf("Losowanie 6 liczb z przedziału 1-49...\n");

  while (licznik < 6) {
    int losowa = (rand() % 49) + 1; // liczba z przedziału 1-49

    // Sprawdź czy liczba już została wylosowana
    if (!czy_istnieje(wylosowane, licznik, losowa)) {
      wylosowane[licznik] = losowa;
      licznik++;
    }
  }

  printf("Wylosowane liczby (przed sortowaniem): ");
  wyswietl_tablice(wylosowane, 6);

  // Sortowanie wylosowanych liczb
  sortuj_tablice(wylosowane, 6);

  printf("Wylosowane liczby (po sortowaniu): ");
  wyswietl_tablice(wylosowane, 6);
  printf("\n");
}

int main() {
  int wybor;

  do {
    printf("=== MENU GŁÓWNE ===\n");
    printf("1. Program sortujący liczby w tablicy\n");
    printf("2. Program losujący 6 liczb (1-49)\n");
    printf("3. Uruchom oba programy\n");
    printf("0. Wyjście\n");
    printf("Wybierz opcję: ");
    scanf("%d", &wybor);
    printf("\n");

    switch (wybor) {
    case 1:
      program_sortowanie();
      break;
    case 2:
      program_losowanie();
      break;
    case 3:
      program_sortowanie();
      program_losowanie();
      break;
    case 0:
      printf("Koniec programu.\n");
      break;
    default:
      printf("Nieprawidłowy wybór!\n\n");
    }

    if (wybor != 0) {
      printf("Naciśnij Enter, aby kontynuować...");
      getchar(); // oczyszczenie bufora
      getchar(); // oczekiwanie na Enter
      printf("\n");
    }

  } while (wybor != 0);

  return 0;
}
