#include <ctype.h>
#include <stdio.h>
#include <string.h>

#define MAX_TEXT_LENGTH 1000

// Funkcja sprawdzająca czy znak jest samogłoską
int czy_samogloska(char c) {
  char samogloski[] = "aeiouAEIOUąęĄĘ";
  return strchr(samogloski, c) != NULL;
}

// Funkcja sprawdzająca czy znak jest znakiem interpunkcyjnym
int czy_interpunkcja(char c) {
  char interpunkcja[] = ".,!?;:\"'()[]{}";
  return strchr(interpunkcja, c) != NULL;
}

int main() {
  char tekst[MAX_TEXT_LENGTH];
  int liczba_wyrazow = 0;
  int liczba_spacji = 0;
  int liczba_interpunkcji = 0;
  int liczba_samoglosek = 0;
  int liczba_spolglosek = 0;
  int liczba_wszystkich_znakow = 0;
  int i;
  int w_wyrazie = 0; // flaga określająca czy jesteśmy w środku wyrazu

  printf("=== ANALIZATOR TEKSTU ===\n");
  printf("Wprowadź tekst do analizy:\n");

  // Wczytanie całej linii tekstu
  if (fgets(tekst, MAX_TEXT_LENGTH, stdin) != NULL) {
    // Usunięcie znaku nowej linii na końcu (jeśli istnieje)
    int len = strlen(tekst);
    if (len > 0 && tekst[len - 1] == '\n') {
      tekst[len - 1] = '\0';
      len--;
    }

    liczba_wszystkich_znakow = len;

    // Analiza każdego znaku
    for (i = 0; i < len; i++) {
      char c = tekst[i];

      // Sprawdzanie spacji
      if (c == ' ') {
        liczba_spacji++;
        w_wyrazie = 0;
      }
      // Sprawdzanie znaków interpunkcyjnych
      else if (czy_interpunkcja(c)) {
        liczba_interpunkcji++;
        w_wyrazie = 0;
      }
      // Sprawdzanie liter
      else if (isalpha(c)) {
        // Zliczanie wyrazów
        if (!w_wyrazie) {
          liczba_wyrazow++;
          w_wyrazie = 1;
        }

        // Sprawdzanie samogłosek i spółgłosek
        if (czy_samogloska(c)) {
          liczba_samoglosek++;
        } else {
          liczba_spolglosek++;
        }
      }
      // Inne znaki (cyfry, symbole) - kończymy wyraz
      else {
        w_wyrazie = 0;
      }
    }

    // Wyświetlenie wyników analizy
    printf("\n=== WYNIKI ANALIZY ===\n");
    printf("Analizowany tekst: \"%s\"\n\n", tekst);
    printf("a) Liczba wyrazów: %d\n", liczba_wyrazow);
    printf("b) Liczba spacji: %d\n", liczba_spacji);
    printf("   Liczba znaków interpunkcyjnych: %d\n", liczba_interpunkcji);
    printf("c) Liczba samogłosek: %d\n", liczba_samoglosek);
    printf("d) Liczba spółgłosek: %d\n", liczba_spolglosek);
    printf("e) Liczba wszystkich znaków: %d\n", liczba_wszystkich_znakow);

    // Dodatkowe statystyki
    printf("\n=== DODATKOWE STATYSTYKI ===\n");
    printf("Całkowita liczba liter: %d\n",
           liczba_samoglosek + liczba_spolglosek);
    printf("Stosunek samogłosek do spółgłosek: %.2f%%\n",
           (liczba_spolglosek > 0)
               ? (float)liczba_samoglosek / liczba_spolglosek * 100
               : 0);

  } else {
    printf("Błąd wczytywania tekstu!\n");
    return 1;
  }

  return 0;
}
