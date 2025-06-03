#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAZWA 50
#define MAX_ADRES 100
#define MAX_TELEFON 20
#define MAX_EMAIL 50
#define NAZWA_PLIKU "kontakty.txt"

// Struktura reprezentująca kontakt
typedef struct {
  char imie[MAX_NAZWA];
  char nazwisko[MAX_NAZWA];
  char adres[MAX_ADRES];
  char telefon[MAX_TELEFON];
  char email[MAX_EMAIL];
} Kontakt;

// Funkcja do wyświetlania menu
void wyswietl_menu() {
  printf("\n=== KSIĄŻKA ADRESOWA ===\n");
  printf("1. Dodaj nowy kontakt\n");
  printf("2. Wyświetl wszystkie kontakty\n");
  printf("3. Wyszukaj kontakt\n");
  printf("4. Zakończ program\n");
  printf("Wybierz opcję: ");
}

// Funkcja do dodawania nowego kontaktu
void dodaj_kontakt() {
  FILE *plik;
  Kontakt nowy_kontakt;

  // Otwieranie pliku w trybie dopisywania
  if ((plik = fopen(NAZWA_PLIKU, "a")) == NULL) {
    printf("Błąd: Nie można otworzyć pliku do zapisu!\n");
    return;
  }

  printf("\n=== DODAWANIE NOWEGO KONTAKTU ===\n");

  printf("Imię: ");
  scanf("%s", nowy_kontakt.imie);

  printf("Nazwisko: ");
  scanf("%s", nowy_kontakt.nazwisko);

  printf("Adres (bez spacji, użyj _ zamiast spacji): ");
  scanf("%s", nowy_kontakt.adres);

  printf("Telefon: ");
  scanf("%s", nowy_kontakt.telefon);

  printf("Email: ");
  scanf("%s", nowy_kontakt.email);

  // Zapisywanie kontaktu do pliku
  fprintf(plik, "%s %s %s %s %s\n", nowy_kontakt.imie, nowy_kontakt.nazwisko,
          nowy_kontakt.adres, nowy_kontakt.telefon, nowy_kontakt.email);

  fclose(plik);
  printf("Kontakt został dodany pomyślnie!\n");
}

// Funkcja do wyświetlania wszystkich kontaktów
void wyswietl_kontakty() {
  FILE *plik;
  Kontakt kontakt;
  int licznik = 0;

  // Otwieranie pliku w trybie odczytu
  if ((plik = fopen(NAZWA_PLIKU, "r")) == NULL) {
    printf("Brak kontaktów w bazie danych lub błąd odczytu pliku.\n");
    return;
  }

  printf("\n=== LISTA WSZYSTKICH KONTAKTÓW ===\n");
  printf("%-4s %-15s %-15s %-25s %-15s %-25s\n", "Nr", "Imię", "Nazwisko",
         "Adres", "Telefon", "Email");
  printf("---------------------------------------------------------------------"
         "-----------\n");

  // Odczytywanie kontaktów z pliku
  while (fscanf(plik, "%s %s %s %s %s", kontakt.imie, kontakt.nazwisko,
                kontakt.adres, kontakt.telefon, kontakt.email) == 5) {
    licznik++;

    // Zastępowanie _ spacjami w adresie
    for (int i = 0; kontakt.adres[i] != '\0'; i++) {
      if (kontakt.adres[i] == '_') {
        kontakt.adres[i] = ' ';
      }
    }

    printf("%-4d %-15s %-15s %-25s %-15s %-25s\n", licznik, kontakt.imie,
           kontakt.nazwisko, kontakt.adres, kontakt.telefon, kontakt.email);
  }

  if (licznik == 0) {
    printf("Brak kontaktów w bazie danych.\n");
  } else {
    printf("\nLiczba kontaktów: %d\n", licznik);
  }

  fclose(plik);
}

// Funkcja do wyszukiwania kontaktu
void wyszukaj_kontakt() {
  FILE *plik;
  Kontakt kontakt;
  char szukane_nazwisko[MAX_NAZWA];
  int znaleziono = 0;

  if ((plik = fopen(NAZWA_PLIKU, "r")) == NULL) {
    printf("Brak kontaktów w bazie danych lub błąd odczytu pliku.\n");
    return;
  }

  printf("\n=== WYSZUKIWANIE KONTAKTU ===\n");
  printf("Podaj nazwisko do wyszukania: ");
  scanf("%s", szukane_nazwisko);

  printf("\n=== WYNIKI WYSZUKIWANIA ===\n");

  while (fscanf(plik, "%s %s %s %s %s", kontakt.imie, kontakt.nazwisko,
                kontakt.adres, kontakt.telefon, kontakt.email) == 5) {

    // Porównywanie nazwisk (case-sensitive)
    if (strcmp(kontakt.nazwisko, szukane_nazwisko) == 0) {
      znaleziono = 1;

      // Zastępowanie _ spacjami w adresie
      for (int i = 0; kontakt.adres[i] != '\0'; i++) {
        if (kontakt.adres[i] == '_') {
          kontakt.adres[i] = ' ';
        }
      }

      printf("Imię: %s\n", kontakt.imie);
      printf("Nazwisko: %s\n", kontakt.nazwisko);
      printf("Adres: %s\n", kontakt.adres);
      printf("Telefon: %s\n", kontakt.telefon);
      printf("Email: %s\n", kontakt.email);
      printf("------------------------\n");
    }
  }

  if (!znaleziono) {
    printf("Nie znaleziono kontaktu o nazwisku: %s\n", szukane_nazwisko);
  }

  fclose(plik);
}

int main() {
  int wybor;

  printf("Witaj w programie do zarządzania kontaktami!\n");
  printf("Dane są przechowywane w pliku: %s\n", NAZWA_PLIKU);

  do {
    wyswietl_menu();
    scanf("%d", &wybor);

    switch (wybor) {
    case 1:
      dodaj_kontakt();
      break;
    case 2:
      wyswietl_kontakty();
      break;
    case 3:
      wyszukaj_kontakt();
      break;
    case 4:
      printf("Dziękujemy za użycie programu!\n");
      break;
    default:
      printf("Nieprawidłowy wybór! Spróbuj ponownie.\n");
    }
  } while (wybor != 4);

  return 0;
}
