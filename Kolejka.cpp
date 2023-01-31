#include <iostream>
using namespace std;

//funkcja wyświetlająca dodane elementy
void show(string *ciag, int *priority, int *max) {
  if (*max == 0) {
    cout << "kolejka jest pusta !\n ";
  } else {
    cout << " aktualna kolejka :\n ";

    for (int i = 1; i <= *max; i++) {
      cout << "\033[0;34m" << i << ".)\033[0m  " << ciag[*max - i];
      switch (priority[*max-i]) {
      case 1:
        cout << "\033[1;31m";
        break;
      case 2:
        cout << "\033[1;33m";
        break;
      case 3:
        cout << "\033[1;32m";
        break;
      default:
        break;
      }
      cout << "  [" << priority[*max - i] << "]\033[0m\n ";
    }
    cout << "\n";
  }
}

//funkcja dodająca element
void add(string *ciag, int *priority, int *max, int s) {
  if (*max == s) {
    cout << "kolejka jest pelna!\n";
  } else {
    string str;
    int number;
    cout << "podaj napis\n";
    cin >> str;
    cout << "Podaj priorytet\n";
    cin >> number;

    //umieszcza nowy element na na końcu kolejki lub przed elementem z większą wartością priorytetu
    int i;
    for (i = *max - 1; i >= 0 && (priority[i] <= number); i--) {
      ciag[i + 1] = ciag[i];
      priority[i + 1] = priority[i];
    }
    ciag[++i] = str;
    priority[i] = number;

    (*max)++;
    cout << "dodano!\n";
  }
}

//funkcja usuwająca element
void del(string *ciag, int *priority, int *max) {
  if (*max == 0) {
    cout << "kolejka jest pusta!\n";
  } else {
    --*max;
    cout << "usunieto: " << ciag[*max] << "!\n";
    ciag[*max] = "";
  }
}

void queue(int s) {
  string *array = new string[s];
  int priority[5] = {0, 0, 0, 0, 0}; //lista kolejności elementów

  cout << "Podaj jedna z instrukcji:\n"
       << "d -aby dodac napis do kolejki\n"
       << "u -aby usunac napis z kolejki\n"
       << "w -aby wyswietlic zawartosc kolejki\n"
       << "x -aby zakonczyc\n";

  char instrukcja;  // info od uzytkownika
  bool loop = true; // czy zapetlac
  int elements = 0; // ilosc elementow
  while (loop) {
    cin >> instrukcja;
    switch (instrukcja) {
    case 'd': // dodawanie
      add(array, priority, &elements, s);
      break;
    case 'u': // usuwanie
      del(array, priority, &elements);
      break;
    case 'w': // wyswietlanie
      show(array, priority, &elements);
      break;
    case 'x': // wyjscie
      loop = false;
      break;
    default: // nieznana instrukcja
      cout << "Podaj jedna z instrukcji:\n"
           << "d -aby dodac napis do kolejki\n"
           << "u -aby usunac napis z kolejki\n"
           << "w -aby wyswietlic zawartosc kolejki\n"
           << "x -aby zakonczyc\n";
      break;
    }
  }
}

int main() { queue(5); }