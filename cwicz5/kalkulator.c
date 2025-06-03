#include "kalkulator.h"

// Implementacja funkcji matematycznych
double dodawanie(double a, double b) { return a + b; }

double odejmowanie(double a, double b) { return a - b; }

double mnozenie(double a, double b) { return a * b; }

double dzielenie(double a, double b) {
  if (b != 0) {
    return a / b;
  } else {
    printf("Błąd: Dzielenie przez zero!\n");
    return 0;
  }
}

int dzielenie_calkowite(int a, int b) {
  if (b != 0) {
    return a / b;
  } else {
    printf("Błąd: Dzielenie przez zero!\n");
    return 0;
  }
}

int modulo(int a, int b) {
  if (b != 0) {
    return a % b;
  } else {
    printf("Błąd: Dzielenie przez zero!\n");
    return 0;
  }
}

void menu_kalkulatora() {
  printf("\n=== KALKULATOR ===\n");
  printf("Dostępne operacje:\n");
  printf("+ - Dodawanie\n");
  printf("- - Odejmowanie\n");
  printf("* - Mnożenie\n");
  printf("/ - Dzielenie\n");
  printf("%% - Dzielenie całkowite (modulo)\n");
  printf("q - Wyjście\n");
  printf("==================\n");
}

void uruchom_kalkulator() {
  char operacja;
  double a, b, wynik;
  int ia, ib, iwynik;

start_kalkulatora:
  menu_kalkulatora();

  printf("Wybierz operację: ");
  scanf(" %c", &operacja);

  switch (operacja) {
  case '+':
    printf("Podaj pierwszą liczbę: ");
    scanf("%lf", &a);
    printf("Podaj drugą liczbę: ");
    scanf("%lf", &b);
    wynik = dodawanie(a, b);
    printf("Wynik: %.2lf + %.2lf = %.2lf\n", a, b, wynik);
    break;

  case '-':
    printf("Podaj pierwszą liczbę: ");
    scanf("%lf", &a);
    printf("Podaj drugą liczbę: ");
    scanf("%lf", &b);
    wynik = odejmowanie(a, b);
    printf("Wynik: %.2lf - %.2lf = %.2lf\n", a, b, wynik);
    break;

  case '*':
    printf("Podaj pierwszą liczbę: ");
    scanf("%lf", &a);
    printf("Podaj drugą liczbę: ");
    scanf("%lf", &b);
    wynik = mnozenie(a, b);
    printf("Wynik: %.2lf * %.2lf = %.2lf\n", a, b, wynik);
    break;

  case '/':
    printf("Podaj pierwszą liczbę: ");
    scanf("%lf", &a);
    printf("Podaj drugą liczbę: ");
    scanf("%lf", &b);
    wynik = dzielenie(a, b);
    if (b != 0) {
      printf("Wynik: %.2lf / %.2lf = %.2lf\n", a, b, wynik);
    }
    break;

  case '%':
    printf("Podaj pierwszą liczbę całkowitą: ");
    scanf("%d", &ia);
    printf("Podaj drugą liczbę całkowitą: ");
    scanf("%d", &ib);
    iwynik = modulo(ia, ib);
    if (ib != 0) {
      printf("Wynik: %d %% %d = %d\n", ia, ib, iwynik);
    }
    break;

  case 'q':
  case 'Q':
    printf("Zamykanie kalkulatora...\n");
    break;

  default:
    printf("Nieprawidłowa operacja! Spróbuj ponownie.\n");
    break;
  }

  if (operacja != 'q' && operacja != 'Q') {
    printf("\nNaciśnij Enter, aby kontynuować...");
    getchar();
    getchar();
    goto start_kalkulatora;
  }
}

int main() {
  printf("Program Kalkulatora z konstrukcją switch/case i pętlą goto\n");
  uruchom_kalkulator();
  return 0;
}
