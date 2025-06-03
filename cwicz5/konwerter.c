#include "konwerter.h"

// Kursy walut (przykładowe, z grudnia 2024)
Waluta waluty[] = {
    // Europa
    {"Euro", 0.23, "EUR"},
    {"Funt brytyjski", 0.19, "GBP"},
    {"Frank szwajcarski", 0.22, "CHF"},
    {"Korona czeska", 5.8, "CZK"},

    // Ameryka Północna
    {"Dolar amerykański", 0.25, "USD"},
    {"Dolar kanadyjski", 0.34, "CAD"},
    {"Peso meksykańskie", 5.1, "MXN"},

    // Ameryka Południowa
    {"Real brazylijski", 1.2, "BRL"},
    {"Peso argentyńskie", 250.0, "ARS"},

    // Azja
    {"Jen japoński", 30.0, "JPY"},
    {"Juan chiński", 1.8, "CNY"},
    {"Rupia indyjska", 21.0, "INR"},
    {"Won południowokoreański", 340.0, "KRW"},

    // Afryka
    {"Rand południowoafrykański", 4.5, "ZAR"},
    {"Funt egipski", 12.0, "EGP"},

    // Oceania
    {"Dolar australijski", 0.38, "AUD"},
    {"Dolar nowozelandzki", 0.42, "NZD"},

    // Europa Wschodnia / Azja
    {"Rubel rosyjski", 25.0, "RUB"},
    {"Hrywna ukraińska", 10.5, "UAH"}};

int liczba_walut = sizeof(waluty) / sizeof(waluty[0]);

void menu_walut() {
  printf("\n=== KONWERTER WALUT (PLN -> inne waluty) ===\n");
  printf("Dostępne waluty:\n\n");

  printf("EUROPA:\n");
  printf("1.  %s (%s)\n", waluty[0].nazwa, waluty[0].symbol);
  printf("2.  %s (%s)\n", waluty[1].nazwa, waluty[1].symbol);
  printf("3.  %s (%s)\n", waluty[2].nazwa, waluty[2].symbol);
  printf("4.  %s (%s)\n", waluty[3].nazwa, waluty[3].symbol);

  printf("\nAMERYKA PÓŁNOCNA:\n");
  printf("5.  %s (%s)\n", waluty[4].nazwa, waluty[4].symbol);
  printf("6.  %s (%s)\n", waluty[5].nazwa, waluty[5].symbol);
  printf("7.  %s (%s)\n", waluty[6].nazwa, waluty[6].symbol);

  printf("\nAMERYKA POŁUDNIOWA:\n");
  printf("8.  %s (%s)\n", waluty[7].nazwa, waluty[7].symbol);
  printf("9.  %s (%s)\n", waluty[8].nazwa, waluty[8].symbol);

  printf("\nAZJA:\n");
  printf("10. %s (%s)\n", waluty[9].nazwa, waluty[9].symbol);
  printf("11. %s (%s)\n", waluty[10].nazwa, waluty[10].symbol);
  printf("12. %s (%s)\n", waluty[11].nazwa, waluty[11].symbol);
  printf("13. %s (%s)\n", waluty[12].nazwa, waluty[12].symbol);

  printf("\nAFRYKA:\n");
  printf("14. %s (%s)\n", waluty[13].nazwa, waluty[13].symbol);
  printf("15. %s (%s)\n", waluty[14].nazwa, waluty[14].symbol);

  printf("\nOCEANIA:\n");
  printf("16. %s (%s)\n", waluty[15].nazwa, waluty[15].symbol);
  printf("17. %s (%s)\n", waluty[16].nazwa, waluty[16].symbol);

  printf("\nINNE:\n");
  printf("18. %s (%s)\n", waluty[17].nazwa, waluty[17].symbol);
  printf("19. %s (%s)\n", waluty[18].nazwa, waluty[18].symbol);

  printf("\n0. Wyjście\n");
  printf("==========================================\n");
}

double konwertuj_walute(double kwota_pln, double kurs) {
  return kwota_pln * kurs;
}

void wyswietl_wynik(double kwota_pln, double kwota_docelowa,
                    const char *nazwa_waluty, const char *symbol) {
  printf("\n--- WYNIK KONWERSJI ---\n");
  printf("%.2lf PLN = %.2lf %s (%s)\n", kwota_pln, kwota_docelowa, symbol,
         nazwa_waluty);
  printf("----------------------\n");
}

void uruchom_konwerter() {
  int wybor;
  double kwota_pln, kwota_docelowa;

start_konwertera:
  menu_walut();

  printf("Wybierz walutę (0-19): ");
  scanf("%d", &wybor);

  switch (wybor) {
  case 1:
  case 2:
  case 3:
  case 4:
  case 5:
  case 6:
  case 7:
  case 8:
  case 9:
  case 10:
  case 11:
  case 12:
  case 13:
  case 14:
  case 15:
  case 16:
  case 17:
  case 18:
  case 19:
    printf("Podaj kwotę w PLN: ");
    scanf("%lf", &kwota_pln);

    if (kwota_pln < 0) {
      printf("Kwota nie może być ujemna!\n");
      break;
    }

    kwota_docelowa = konwertuj_walute(kwota_pln, waluty[wybor - 1].kurs);
    wyswietl_wynik(kwota_pln, kwota_docelowa, waluty[wybor - 1].nazwa,
                   waluty[wybor - 1].symbol);
    break;

  case 0:
    printf("Zamykanie konwertera walut...\n");
    break;

  default:
    printf("Nieprawidłowy wybór! Spróbuj ponownie.\n");
    break;
  }

  if (wybor != 0) {
    printf("\nNaciśnij Enter, aby kontynuować...");
    getchar();
    getchar();
    goto start_konwertera;
  }
}

int main() {
  printf("Program Konwertera Walut z konstrukcją switch/case i pętlą goto\n");
  printf("Kursy walut są przykładowe i mogą nie odpowiadać aktualnym "
         "wartościom.\n");
  uruchom_konwerter();
  return 0;
}
