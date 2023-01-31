#include <iostream>
using namespace std;

void stack(int s) {
    string *array = new string[s];
    
    cout << "Podaj jedna z instrukcji:\n"
    << "d - aby dodac napis do stosu\n"
    << "u - aby usunac napis ze stosu\n"
    << "w - aby wyswietlic zawartosc stosu\n"
    << "x - aby zakonczyc\n";
    
    char instrukcja; //info od uzytkownika
    bool loop = true; //czy zapetlac
    int elements = 0; //ilosc elementow
    while (loop) {
        cin >> instrukcja;
        switch (instrukcja) { 
            case 'x': //wyjscie
                loop = false;
                break;
            default: //nieznana instrukcja
                cout << "Podaj jedna z instrukcji:\n"
                << "x - aby zakonczyc\n";
                break;
        }
    }
}

int main() { 
    stack(6); 
}