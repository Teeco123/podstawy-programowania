
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int is_vowel(char c) {
  // Samogłoski w języku polskim
  char *vowels = "aeiouyAEIOUY";
  return strchr(vowels, c) != NULL;
}

int is_consonant(char c) { return isalpha(c) && !is_vowel(c); }

int is_punctuation(char c) {
  // Znaki interpunkcyjne
  char *punctuation = ".,!?;:-";
  return strchr(punctuation, c) != NULL;
}

int main() {
  char tekst[1000];

  printf("Podaj tekst do analizy:\n");
  fgets(tekst, sizeof(tekst), stdin);

  int liczba_znakow = strlen(tekst) - 1;
  int liczba_samoglosek = 0;
  int liczba_spolglosek = 0;
  int liczba_spacji = 0;
  int liczba_interpunkcyjnych = 0;
  int liczba_wyrazow = 0;

  // Analiza każdego znaku
  for (int i = 0; i < liczba_znakow; i++) {
    char c = tekst[i];

    if (is_vowel(c)) {
      liczba_samoglosek++;
    } else if (is_consonant(c)) {
      liczba_spolglosek++;
    } else if (c == ' ') {
      liczba_spacji++;
    } else if (is_punctuation(c)) {
      liczba_interpunkcyjnych++;
    }
  }

  // Liczenie wyrazów przy pomocy funkcji z string.h
  // Wyrazy oddzielone spacjami lub znakami końca linii/interpunkcyjnymi
  char delimitery[] = " \n.,!?;:-";
  char tekst_kopia[1000];
  strcpy(tekst_kopia, tekst); // użycie strcpy

  char *token = strtok(tekst_kopia, delimitery); // pierwszy wyraz
  while (token != NULL) {
    liczba_wyrazow++;
    token = strtok(NULL, delimitery); // kolejne wyrazy
  }

  // Wynik
  printf("\n--- PODSUMOWANIE ---\n");
  printf("Liczba wszystkich znaków: %d\n", liczba_znakow);
  printf("Liczba wyrazów: %d\n", liczba_wyrazow);
  printf("Liczba spacji: %d\n", liczba_spacji);
  printf("Liczba znaków interpunkcyjnych: %d\n", liczba_interpunkcyjnych);
  printf("Liczba samogłosek: %d\n", liczba_samoglosek);
  printf("Liczba spółgłosek: %d\n", liczba_spolglosek);

  return 0;
}
