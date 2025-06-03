#include "program.h"

// Zadanie a) - Pierwiastki równania kwadratowego
void rownanie_kwadratowe() {
  double a, b, c;
  double delta, x1, x2;

  printf("\n=== ROZWIĄZYWANIE RÓWNANIA KWADRATOWEGO ===\n");
  printf("Równanie postaci: ax² + bx + c = 0\n");

  printf("Podaj współczynnik a: ");
  scanf("%lf", &a);

  if (a == 0) {
    printf("To nie jest równanie kwadratowe (a = 0)!\n");
    return;
  }

  printf("Podaj współczynnik b: ");
  scanf("%lf", &b);

  printf("Podaj współczynnik c: ");
  scanf("%lf", &c);

  printf("\nRównanie: %.2fx² + %.2fx + %.2f = 0\n", a, b, c);

  // Obliczanie delty
  delta = b * b - 4 * a * c;

  if (delta > 0) {
    x1 = (-b + sqrt(delta)) / (2 * a);
    x2 = (-b - sqrt(delta)) / (2 * a);
    printf("Równanie ma dwa pierwiastki rzeczywiste:\n");
    printf("x₁ = %.4f\n", x1);
    printf("x₂ = %.4f\n", x2);
  } else if (delta == 0) {
    x1 = -b / (2 * a);
    printf("Równanie ma jeden pierwiastek podwójny:\n");
    printf("x = %.4f\n", x1);
  } else {
    printf("Równanie nie ma pierwiastków rzeczywistych (delta < 0).\n");
    printf("Delta = %.4f\n", delta);
  }
}

// Zadanie b) - Sortowanie trzech liczb w kolejności rosnącej
void sortuj_trzy_liczby() {
  double a, b, c;
  double min, srodek, max;

  printf("\n=== SORTOWANIE TRZECH LICZB ===\n");

  printf("Podaj pierwszą liczbę: ");
  scanf("%lf", &a);

  printf("Podaj drugą liczbę: ");
  scanf("%lf", &b);

  printf("Podaj trzecią liczbę: ");
  scanf("%lf", &c);

  printf("\nPodane liczby: %.2f, %.2f, %.2f\n", a, b, c);

  // Sortowanie z wykorzystaniem instrukcji warunkowych
  if (a <= b && a <= c) {
    min = a;
    if (b <= c) {
      srodek = b;
      max = c;
    } else {
      srodek = c;
      max = b;
    }
  } else if (b <= a && b <= c) {
    min = b;
    if (a <= c) {
      srodek = a;
      max = c;
    } else {
      srodek = c;
      max = a;
    }
  } else {
    min = c;
    if (a <= b) {
      srodek = a;
      max = b;
    } else {
      srodek = b;
      max = a;
    }
  }

  printf("Liczby w kolejności rosnącej: %.2f, %.2f, %.2f\n", min, srodek, max);
}

int main() {
  int wybor;

  do {
    printf("\n=== MENU GŁÓWNE ===\n");
    printf("1. Rozwiąż równanie kwadratowe\n");
    printf("2. Sortuj trzy liczby\n");
    printf("0. Wyjście\n");
    printf("Wybierz opcję: ");
    scanf("%d", &wybor);

    if (wybor == 1) {
      rownanie_kwadratowe();
    } else if (wybor == 2) {
      sortuj_trzy_liczby();
    } else if (wybor == 0) {
      printf("Koniec programu.\n");
    } else {
      printf("Nieprawidłowy wybór!\n");
    }

  } while (wybor != 0);

  return 0;
}
