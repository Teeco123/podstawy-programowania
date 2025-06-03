#include <math.h>
#include <stdio.h>
#include <string.h>

#define MAX_POINTS 100
#define MAX_NAME_LENGTH 50

// Struktura reprezentująca współrzędne punktu
typedef struct {
  double x;
  double y;
} Coordinates;

// Struktura reprezentująca punkt nawigacyjny
typedef struct {
  char name[MAX_NAME_LENGTH];
  Coordinates coords;
  double distance_from_previous; // odległość od poprzedniego punktu
  double total_distance;         // łączna odległość od początku trasy
} NavigationPoint;

// Funkcja obliczająca odległość między dwoma punktami (wzór Euklidesa)
double calculate_distance(Coordinates p1, Coordinates p2) {
  return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
}

// Funkcja wyświetlająca nagłówek tabeli
void print_header() {
  printf("\n%-4s %-15s %-15s %-12s %-10s\n", "Lp.", "Nazwa Punktu",
         "Wspolrzedne", "Odleglosc", "Trasa");
  printf("------------------------------------------------------------\n");
}

// Funkcja wyświetlająca informacje o punkcie nawigacyjnym
void print_point(int index, NavigationPoint point) {
  printf("%-4d %-15s (%.1f,%.1f)%-6s", index + 1, point.name, point.coords.x,
         point.coords.y, "");

  if (index == 0) {
    printf("%-12s %-10s\n", "-", "-");
  } else {
    printf("%-12.0f %-10.0f\n", point.distance_from_previous,
           point.total_distance);
  }
}

// Funkcja dodająca nowy punkt nawigacyjny
void add_navigation_point(NavigationPoint points[], int *count) {
  if (*count >= MAX_POINTS) {
    printf("Osiagnieto maksymalna liczbe punktow!\n");
    return;
  }

  NavigationPoint new_point;

  printf("\nPodaj nazwe punktu: ");
  scanf("%s", new_point.name);

  printf("Podaj wspolrzedna X: ");
  scanf("%lf", &new_point.coords.x);

  printf("Podaj wspolrzedna Y: ");
  scanf("%lf", &new_point.coords.y);

  // Obliczanie odległości od poprzedniego punktu
  if (*count == 0) {
    new_point.distance_from_previous = 0;
    new_point.total_distance = 0;
  } else {
    new_point.distance_from_previous =
        calculate_distance(points[*count - 1].coords, new_point.coords);
    new_point.total_distance =
        points[*count - 1].total_distance + new_point.distance_from_previous;
  }

  points[*count] = new_point;
  (*count)++;

  printf("Punkt dodany pomyslnie!\n");
}

// Funkcja ładująca przykładowe dane z zadania
void load_example_data(NavigationPoint points[], int *count) {
  // Punkt 1: Alfa
  strcpy(points[0].name, "Alfa");
  points[0].coords.x = 0;
  points[0].coords.y = 0;
  points[0].distance_from_previous = 0;
  points[0].total_distance = 0;

  // Punkt 2: Beta
  strcpy(points[1].name, "Beta");
  points[1].coords.x = 10;
  points[1].coords.y = 100;
  points[1].distance_from_previous =
      calculate_distance(points[0].coords, points[1].coords);
  points[1].total_distance = points[1].distance_from_previous;

  // Punkt 3: Gamma
  strcpy(points[2].name, "Gamma");
  points[2].coords.x = 23;
  points[2].coords.y = 300;
  points[2].distance_from_previous =
      calculate_distance(points[1].coords, points[2].coords);
  points[2].total_distance =
      points[1].total_distance + points[2].distance_from_previous;

  // Punkt 4: Delta
  strcpy(points[3].name, "Delta");
  points[3].coords.x = 300;
  points[3].coords.y = 200;
  points[3].distance_from_previous =
      calculate_distance(points[2].coords, points[3].coords);
  points[3].total_distance =
      points[2].total_distance + points[3].distance_from_previous;

  // Punkt 5: Theta
  strcpy(points[4].name, "Theta");
  points[4].coords.x = 100;
  points[4].coords.y = 100;
  points[4].distance_from_previous =
      calculate_distance(points[3].coords, points[4].coords);
  points[4].total_distance =
      points[3].total_distance + points[4].distance_from_previous;

  *count = 5;
  printf("Zaladowano przykladowe dane z zadania.\n");
}

// Funkcja wyświetlająca wszystkie punkty nawigacyjne
void display_all_points(NavigationPoint points[], int count) {
  if (count == 0) {
    printf("Brak punktow nawigacyjnych do wyswietlenia.\n");
    return;
  }

  print_header();
  for (int i = 0; i < count; i++) {
    print_point(i, points[i]);
  }

  printf("\nPodsumowanie wycieczki:\n");
  printf("Liczba punktow: %d\n", count);
  if (count > 0) {
    printf("Calkowita dlugosc trasy: %.2f jednostek\n",
           points[count - 1].total_distance);
  }
}

// Funkcja wyświetlająca menu
void show_menu() {
  printf("\n=== PROGRAM PUNKTOW NAWIGACYJNYCH ===\n");
  printf("1. Dodaj punkt nawigacyjny\n");
  printf("2. Wyswietl wszystkie punkty\n");
  printf("3. Zaladuj przykladowe dane\n");
  printf("4. Wyjscie\n");
  printf("Wybierz opcje: ");
}

int main() {
  NavigationPoint points[MAX_POINTS];
  int count = 0;
  int choice;

  printf("Witaj w programie do zarzadzania punktami nawigacyjnymi!\n");

  do {
    show_menu();
    scanf("%d", &choice);

    switch (choice) {
    case 1:
      add_navigation_point(points, &count);
      break;
    case 2:
      display_all_points(points, count);
      break;
    case 3:
      load_example_data(points, &count);
      break;
    case 4:
      printf("Dziekuje za korzystanie z programu!\n");
      break;
    default:
      printf("Nieprawidlowa opcja. Sprobuj ponownie.\n");
    }
  } while (choice != 4);

  return 0;
}
