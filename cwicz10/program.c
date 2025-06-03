#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// =============== ZADANIE A - KONWERTER DZIESIĘTNY NA SZESNASTKOWY
// ===============

// Funkcja konwertująca liczbę dziesiętną na szesnastkową
void decToHex(int decimal, char *result, int uppercase) {
  char hexDigits[] = "0123456789abcdef";
  char hexDigitsUpper[] = "0123456789ABCDEF";
  char temp[20];
  int i = 0, j;

  // Obsługa liczby 0
  if (decimal == 0) {
    strcpy(result, "0x0");
    return;
  }

  // Obsługa liczb ujemnych
  int isNegative = 0;
  if (decimal < 0) {
    isNegative = 1;
    decimal = -decimal;
  }

  // Konwersja na system szesnastkowy
  while (decimal > 0) {
    if (uppercase) {
      temp[i] = hexDigitsUpper[decimal % 16];
    } else {
      temp[i] = hexDigits[decimal % 16];
    }
    decimal /= 16;
    i++;
  }

  // Budowanie wyniku
  strcpy(result, "0x");
  if (isNegative) {
    strcpy(result, "-0x");
  }

  // Odwracanie cyfr (były zapisane od tyłu)
  j = strlen(result);
  for (int k = i - 1; k >= 0; k--) {
    result[j] = temp[k];
    j++;
  }
  result[j] = '\0';
}

void zadanieA() {
  int liczba;
  char wynik[50];
  int wybor;

  printf("\n=== ZADANIE A - KONWERTER DZIESIĘTNY -> SZESNASTKOWY ===\n");
  printf("Podaj liczbę całkowitą: ");
  scanf("%d", &liczba);

  printf("Wybierz format:\n");
  printf("1 - małe litery (np. 0xa34c)\n");
  printf("2 - wielkie litery (np. 0xA34C)\n");
  printf("Wybór: ");
  scanf("%d", &wybor);

  if (wybor == 2) {
    decToHex(liczba, wynik, 1);
  } else {
    decToHex(liczba, wynik, 0);
  }

  printf("Liczba %d w systemie szesnastkowym: %s\n", liczba, wynik);
}

// =============== ZADANIE B - SZYFR CEZARA ===============

// Funkcja szyfrująca tekst szyfrem Cezara
void szyfruj(char *tekst, int przesuniecie) {
  int i = 0;

  while (tekst[i] != '\0') {
    if (isalpha(tekst[i])) {
      if (islower(tekst[i])) {
        // Dla małych liter
        tekst[i] = ((tekst[i] - 'a' + przesuniecie) % 26) + 'a';
      } else {
        // Dla wielkich liter
        tekst[i] = ((tekst[i] - 'A' + przesuniecie) % 26) + 'A';
      }
    }
    // Znaki nie będące literami pozostają bez zmian
    i++;
  }
}

// Funkcja deszyfrująca tekst szyfrem Cezara
void deszyfruj(char *tekst, int przesuniecie) {
  int i = 0;

  while (tekst[i] != '\0') {
    if (isalpha(tekst[i])) {
      if (islower(tekst[i])) {
        // Dla małych liter
        tekst[i] = ((tekst[i] - 'a' - przesuniecie + 26) % 26) + 'a';
      } else {
        // Dla wielkich liter
        tekst[i] = ((tekst[i] - 'A' - przesuniecie + 26) % 26) + 'A';
      }
    }
    // Znaki nie będące literami pozostają bez zmian
    i++;
  }
}

// Funkcja do wczytywania całej linii tekstu
void wczytajLinie(char *bufor, int rozmiar) {
  fgets(bufor, rozmiar, stdin);
  // Usunięcie znaku nowej linii jeśli istnieje
  int len = strlen(bufor);
  if (len > 0 && bufor[len - 1] == '\n') {
    bufor[len - 1] = '\0';
  }
}

void zadanieB() {
  char tekst[1000];
  int przesuniecie;
  int wybor;
  char temp;

  printf("\n=== ZADANIE B - SZYFR CEZARA ===\n");
  printf("1 - Szyfrowanie\n");
  printf("2 - Deszyfrowanie\n");
  printf("Wybierz opcję: ");
  scanf("%d", &wybor);

  // Czyszczenie bufora
  while ((temp = getchar()) != '\n' && temp != EOF)
    ;

  printf("Podaj tekst: ");
  wczytajLinie(tekst, sizeof(tekst));

  printf("Podaj przesunięcie (0-25): ");
  scanf("%d", &przesuniecie);

  // Normalizacja przesunięcia do zakresu 0-25
  przesuniecie = przesuniecie % 26;
  if (przesuniecie < 0) {
    przesuniecie += 26;
  }

  printf("\nTekst oryginalny: %s\n", tekst);

  if (wybor == 1) {
    szyfruj(tekst, przesuniecie);
    printf("Tekst zaszyfrowany: %s\n", tekst);
  } else if (wybor == 2) {
    deszyfruj(tekst, przesuniecie);
    printf("Tekst odszyfrowany: %s\n", tekst);
  } else {
    printf("Nieprawidłowy wybór!\n");
  }
}

// =============== ZADANIE C - LICZNIK WYRAZÓW ===============

// Funkcja sprawdzająca czy znak jest separatorem wyrazów
int jestSeparatorem(char c) {
  return (c == ' ' || c == '\t' || c == '\n' || c == '\r' || c == '\0');
}

// Funkcja zwracająca liczbę wyrazów w ciągu tekstowym
int liczWyrazy(char *tekst) {
  int i = 0;
  int liczbaWyrazow = 0;
  int wWyrazie = 0; // flaga określająca czy jesteśmy obecnie w wyrazie

  while (tekst[i] != '\0') {
    if (!jestSeparatorem(tekst[i])) {
      // Jeśli nie jesteśmy w wyrazie i napotkamy znak nie będący separatorem
      if (!wWyrazie) {
        liczbaWyrazow++;
        wWyrazie = 1;
      }
    } else {
      // Jeśli napotkamy separator, kończymy bieżący wyraz
      wWyrazie = 0;
    }
    i++;
  }

  return liczbaWyrazow;
}

// Alternatywna funkcja używająca biblioteki ctype.h
int liczWyrazyAlt(char *tekst) {
  int i = 0;
  int liczbaWyrazow = 0;
  int wWyrazie = 0;

  while (tekst[i] != '\0') {
    if (!isspace(tekst[i])) {
      if (!wWyrazie) {
        liczbaWyrazow++;
        wWyrazie = 1;
      }
    } else {
      wWyrazie = 0;
    }
    i++;
  }

  return liczbaWyrazow;
}

// Funkcja wyświetlająca szczegółowe informacje o tekście
void analizujTekst(char *tekst) {
  int znaki = 0;
  int litery = 0;
  int cyfry = 0;
  int spacje = 0;
  int i = 0;

  while (tekst[i] != '\0') {
    znaki++;
    if (isalpha(tekst[i])) {
      litery++;
    } else if (isdigit(tekst[i])) {
      cyfry++;
    } else if (isspace(tekst[i])) {
      spacje++;
    }
    i++;
  }

  printf("\n=== ANALIZA TEKSTU ===\n");
  printf("Całkowita liczba znaków: %d\n", znaki);
  printf("Liczba liter: %d\n", litery);
  printf("Liczba cyfr: %d\n", cyfry);
  printf("Liczba spacji: %d\n", spacje);
  printf("Liczba wyrazów: %d\n", liczWyrazy(tekst));
  printf("Liczba wyrazów (metoda alt): %d\n", liczWyrazyAlt(tekst));
}

void zadanieC() {
  char tekst[1000];
  int wybor;
  char temp;

  printf("\n=== ZADANIE C - LICZNIK WYRAZÓW ===\n");
  printf("1 - Podstawowe liczenie wyrazów\n");
  printf("2 - Szczegółowa analiza tekstu\n");
  printf("3 - Test z przykładowymi tekstami\n");
  printf("Wybierz opcję: ");
  scanf("%d", &wybor);

  // Czyszczenie bufora
  while ((temp = getchar()) != '\n' && temp != EOF)
    ;

  switch (wybor) {
  case 1:
    printf("Podaj tekst: ");
    wczytajLinie(tekst, sizeof(tekst));
    printf("Liczba wyrazów: %d\n", liczWyrazy(tekst));
    break;

  case 2:
    printf("Podaj tekst: ");
    wczytajLinie(tekst, sizeof(tekst));
    analizujTekst(tekst);
    break;

  case 3:
    printf("\n=== TESTY ===\n");

    strcpy(tekst, "");
    printf("Pusty tekst: \"%s\" -> %d wyrazów\n", tekst, liczWyrazy(tekst));

    strcpy(tekst, "   ");
    printf("Same spacje: \"%s\" -> %d wyrazów\n", tekst, liczWyrazy(tekst));

    strcpy(tekst, "jeden");
    printf("Jeden wyraz: \"%s\" -> %d wyrazów\n", tekst, liczWyrazy(tekst));

    strcpy(tekst, "dwa wyrazy");
    printf("Dwa wyrazy: \"%s\" -> %d wyrazów\n", tekst, liczWyrazy(tekst));

    strcpy(tekst, "  wiele   spacji   między   wyrazami  ");
    printf("Wiele spacji: \"%s\" -> %d wyrazów\n", tekst, liczWyrazy(tekst));

    strcpy(tekst, "Tekst\tz\ttabulatorami\ti\nnowymi\nliniami");
    printf("Różne separatory: \"%s\" -> %d wyrazów\n", tekst,
           liczWyrazy(tekst));
    break;

  default:
    printf("Nieprawidłowy wybór!\n");
  }
}

// =============== GŁÓWNA FUNKCJA PROGRAMU ===============

int main() {
  int wybor;
  char kontynuuj;

  do {
    printf("\n========================================\n");
    printf("    ĆWICZENIE 10 - TABLICE ZNAKOWE\n");
    printf("========================================\n");
    printf("1 - Zadanie A: Konwerter dziesiętny -> szesnastkowy\n");
    printf("2 - Zadanie B: Szyfr Cezara\n");
    printf("3 - Zadanie C: Licznik wyrazów\n");
    printf("0 - Wyjście\n");
    printf("Wybierz zadanie: ");
    scanf("%d", &wybor);

    switch (wybor) {
    case 1:
      zadanieA();
      break;
    case 2:
      zadanieB();
      break;
    case 3:
      zadanieC();
      break;
    case 0:
      printf("Koniec programu.\n");
      return 0;
    default:
      printf("Nieprawidłowy wybór!\n");
    }

    printf("\nCzy chcesz kontynuować? (t/n): ");
    scanf(" %c", &kontynuuj);

  } while (kontynuuj == 't' || kontynuuj == 'T');

  printf("Koniec programu.\n");
  return 0;
}
