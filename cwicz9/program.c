#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// A. Funkcja generująca tablicę 1D z liczbami losowymi
int *generuj_tablice_1D(int n, int min, int max) {
  int *tab = (int *)malloc(n * sizeof(int));
  if (tab == NULL) {
    printf("Błąd alokacji pamięci!\n");
    return NULL;
  }

  for (int i = 0; i < n; i++) {
    tab[i] = min + rand() % (max - min + 1);
  }

  return tab;
}

// B. Funkcja zwracająca tablicę 2D kwadratową z wartościami losowymi
int **generuj_tablice_kwadratowa(int n, int min, int max) {
  // Alokacja tablicy wskaźników
  int **tab = (int **)malloc(n * sizeof(int *));
  if (tab == NULL) {
    printf("Błąd alokacji pamięci!\n");
    return NULL;
  }

  // Alokacja pamięci dla każdego wiersza
  for (int i = 0; i < n; i++) {
    tab[i] = (int *)malloc(n * sizeof(int));
    if (tab[i] == NULL) {
      printf("Błąd alokacji pamięci!\n");
      // Zwolnienie już zaalokowanej pamięci
      for (int j = 0; j < i; j++) {
        free(tab[j]);
      }
      free(tab);
      return NULL;
    }

    // Wypełnienie wiersza wartościami losowymi
    for (int j = 0; j < n; j++) {
      tab[i][j] = min + rand() % (max - min + 1);
    }
  }

  return tab;
}

// C. Funkcja zwracająca tablicę 2D z losową liczbą elementów w każdym wierszu
typedef struct {
  int **dane;
  int *rozmiary_wierszy;
  int liczba_wierszy;
} Tablica2D_Nieregularna;

Tablica2D_Nieregularna *generuj_tablice_nieregularna(int wiersze, int min,
                                                     int max) {
  Tablica2D_Nieregularna *tablica =
      (Tablica2D_Nieregularna *)malloc(sizeof(Tablica2D_Nieregularna));
  if (tablica == NULL) {
    printf("Błąd alokacji pamięci!\n");
    return NULL;
  }

  tablica->liczba_wierszy = wiersze;
  tablica->dane = (int **)malloc(wiersze * sizeof(int *));
  tablica->rozmiary_wierszy = (int *)malloc(wiersze * sizeof(int));

  if (tablica->dane == NULL || tablica->rozmiary_wierszy == NULL) {
    printf("Błąd alokacji pamięci!\n");
    free(tablica);
    return NULL;
  }

  for (int i = 0; i < wiersze; i++) {
    // Losowa liczba elementów w wierszu (1 do 2*wiersze)
    tablica->rozmiary_wierszy[i] = 1 + rand() % (2 * wiersze);

    tablica->dane[i] =
        (int *)malloc(tablica->rozmiary_wierszy[i] * sizeof(int));
    if (tablica->dane[i] == NULL) {
      printf("Błąd alokacji pamięci!\n");
      return NULL;
    }

    // Wypełnienie wiersza wartościami losowymi
    for (int j = 0; j < tablica->rozmiary_wierszy[i]; j++) {
      tablica->dane[i][j] = min + rand() % (max - min + 1);
    }
  }

  return tablica;
}

// D. Funkcja zmieniająca rozmiar tablicy 2D kwadratowej
int **zmien_rozmiar_kwadratowa(int **stara_tab, int stary_rozmiar,
                               int nowy_rozmiar, int min, int max) {
  int **nowa_tab = (int **)malloc(nowy_rozmiar * sizeof(int *));
  if (nowa_tab == NULL) {
    printf("Błąd alokacji pamięci!\n");
    return NULL;
  }

  for (int i = 0; i < nowy_rozmiar; i++) {
    nowa_tab[i] = (int *)malloc(nowy_rozmiar * sizeof(int));
    if (nowa_tab[i] == NULL) {
      printf("Błąd alokacji pamięci!\n");
      return NULL;
    }

    for (int j = 0; j < nowy_rozmiar; j++) {
      if (i < stary_rozmiar && j < stary_rozmiar) {
        // Kopiowanie starych danych
        nowa_tab[i][j] = stara_tab[i][j];
      } else {
        // Wypełnienie nowych elementów losowymi wartościami
        nowa_tab[i][j] = min + rand() % (max - min + 1);
      }
    }
  }

  // Zwolnienie starej tablicy
  for (int i = 0; i < stary_rozmiar; i++) {
    free(stara_tab[i]);
  }
  free(stara_tab);

  return nowa_tab;
}

// D. Funkcja zmieniająca rozmiar tablicy nieregularnej
Tablica2D_Nieregularna *
zmien_rozmiar_nieregularna(Tablica2D_Nieregularna *stara_tab, int nowy_rozmiar,
                           int min, int max) {
  if (stara_tab == NULL)
    return NULL;

  Tablica2D_Nieregularna *nowa_tab =
      (Tablica2D_Nieregularna *)malloc(sizeof(Tablica2D_Nieregularna));
  if (nowa_tab == NULL) {
    printf("Błąd alokacji pamięci!\n");
    return NULL;
  }

  nowa_tab->liczba_wierszy = nowy_rozmiar;
  nowa_tab->dane = (int **)malloc(nowy_rozmiar * sizeof(int *));
  nowa_tab->rozmiary_wierszy = (int *)malloc(nowy_rozmiar * sizeof(int));

  for (int i = 0; i < nowy_rozmiar; i++) {
    if (i < stara_tab->liczba_wierszy) {
      // Kopiowanie starych wierszy
      nowa_tab->rozmiary_wierszy[i] = stara_tab->rozmiary_wierszy[i];
      nowa_tab->dane[i] =
          (int *)malloc(nowa_tab->rozmiary_wierszy[i] * sizeof(int));

      for (int j = 0; j < nowa_tab->rozmiary_wierszy[i]; j++) {
        nowa_tab->dane[i][j] = stara_tab->dane[i][j];
      }
    } else {
      // Tworzenie nowych wierszy
      nowa_tab->rozmiary_wierszy[i] = 1 + rand() % (2 * nowy_rozmiar);
      nowa_tab->dane[i] =
          (int *)malloc(nowa_tab->rozmiary_wierszy[i] * sizeof(int));

      for (int j = 0; j < nowa_tab->rozmiary_wierszy[i]; j++) {
        nowa_tab->dane[i][j] = min + rand() % (max - min + 1);
      }
    }
  }

  // Zwolnienie starej tablicy
  for (int i = 0; i < stara_tab->liczba_wierszy; i++) {
    free(stara_tab->dane[i]);
  }
  free(stara_tab->dane);
  free(stara_tab->rozmiary_wierszy);
  free(stara_tab);

  return nowa_tab;
}

// E. Funkcja wyświetlająca tablicę 1D
void wyswietl_tablice_1D(int *tab, int n) {
  printf("Tablica 1D [%d elementów]:\n", n);
  for (int i = 0; i < n; i++) {
    printf("%d ", tab[i]);
  }
  printf("\n\n");
}

// E. Funkcja wyświetlająca tablicę 2D kwadratową
void wyswietl_tablice_kwadratowa(int **tab, int n) {
  printf("Tablica kwadratowa %dx%d:\n", n, n);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      printf("%3d ", tab[i][j]);
    }
    printf("\n");
  }
  printf("\n");
}

// E. Funkcja wyświetlająca tablicę nieregularną
void wyswietl_tablice_nieregularna(Tablica2D_Nieregularna *tab) {
  if (tab == NULL)
    return;

  printf("Tablica nieregularna [%d wierszy]:\n", tab->liczba_wierszy);
  for (int i = 0; i < tab->liczba_wierszy; i++) {
    printf("Wiersz %d [%d elementów]: ", i, tab->rozmiary_wierszy[i]);
    for (int j = 0; j < tab->rozmiary_wierszy[i]; j++) {
      printf("%d ", tab->dane[i][j]);
    }
    printf("\n");
  }
  printf("\n");
}

// Funkcje zwalniające pamięć
void zwolnij_tablice_kwadratowa(int **tab, int n) {
  for (int i = 0; i < n; i++) {
    free(tab[i]);
  }
  free(tab);
}

void zwolnij_tablice_nieregularna(Tablica2D_Nieregularna *tab) {
  if (tab == NULL)
    return;

  for (int i = 0; i < tab->liczba_wierszy; i++) {
    free(tab->dane[i]);
  }
  free(tab->dane);
  free(tab->rozmiary_wierszy);
  free(tab);
}

// F. Program demonstracyjny
int main() {
  srand(time(NULL));

  printf("=== DEMONSTRACJA FUNKCJI TABLICE DYNAMICZNE ===\n\n");

  // A. Demonstracja tablicy 1D
  printf("A. TABLICA 1D z liczbami losowymi:\n");
  int *tab1D = generuj_tablice_1D(10, 1, 50);
  if (tab1D != NULL) {
    wyswietl_tablice_1D(tab1D, 10);
    free(tab1D);
  }

  // B. Demonstracja tablicy kwadratowej
  printf("B. TABLICA KWADRATOWA z liczbami losowymi:\n");
  int rozmiar = 4;
  int **tabKwadrat = generuj_tablice_kwadratowa(rozmiar, 10, 99);
  if (tabKwadrat != NULL) {
    wyswietl_tablice_kwadratowa(tabKwadrat, rozmiar);

    // D. Demonstracja zmiany rozmiaru tablicy kwadratowej
    printf("D. ZMIANA ROZMIARU tablicy kwadratowej z %dx%d na 6x6:\n", rozmiar,
           rozmiar);
    tabKwadrat = zmien_rozmiar_kwadratowa(tabKwadrat, rozmiar, 6, 10, 99);
    if (tabKwadrat != NULL) {
      wyswietl_tablice_kwadratowa(tabKwadrat, 6);
      zwolnij_tablice_kwadratowa(tabKwadrat, 6);
    }
  }

  // C. Demonstracja tablicy nieregularnej
  printf("C. TABLICA NIEREGULARNA z losową liczbą elementów w wierszach:\n");
  Tablica2D_Nieregularna *tabNiereg = generuj_tablice_nieregularna(5, 1, 20);
  if (tabNiereg != NULL) {
    wyswietl_tablice_nieregularna(tabNiereg);

    // D. Demonstracja zmiany rozmiaru tablicy nieregularnej
    printf("D. ZMIANA ROZMIARU tablicy nieregularnej z %d na 8 wierszy:\n",
           tabNiereg->liczba_wierszy);
    tabNiereg = zmien_rozmiar_nieregularna(tabNiereg, 8, 1, 20);
    if (tabNiereg != NULL) {
      wyswietl_tablice_nieregularna(tabNiereg);
      zwolnij_tablice_nieregularna(tabNiereg);
    }
  }

  printf("=== KONIEC DEMONSTRACJI ===\n");
  return 0;
}
