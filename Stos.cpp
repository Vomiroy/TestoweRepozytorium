#include <iostream>
using namespace std;

//funkcja dodająca element
void push(string obj,string *array,int *elements){
    for (int i = *elements - 1; i >= 0; i--) {
        array[i + 1] = array[i];
    }
    array[0] = obj;
    (*elements)++;    
} 
//funkcja usuwająca element
void pop(string *array,int *elements){
    (*elements)--;
    for (int i = 0; i < *elements; i++) {
        array[i] = array[i + 1];
    }
    array[*elements] = "";
}

//funkcja wyświetlająca dodane elementy
void show(string *array,int elements){
    if (elements == 0) {
        cout << "stos jest pusty\n";
    }
    else {
        for (int i = 0; i < elements; i++) {
            cout << array[i] << " ";
        }
        cout << "\n";
    }
}

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
            case 'd': //dodawanie
                if (elements == s) {
                    cout << "stos jest pelny\n";
                    }
                else {
                    string str;
                    cout << "podaj napis\n";
                    cin >> str;
                    push(str,array,&elements);
                    cout << "dodano!\n";
                }
                break;
            case 'u': //usuwanie
                if (elements == 0) {
                    cout << "stos jest pusty\n";
                    }
                else {
                    cout << "usunieto: " << array[0] << "\n";
                    pop(array,&elements);
                }
                break;
            case 'w': //wyswietlanie
                show(array,elements);
                break;
            case 'x': //wyjscie
                loop = false;
                break;
            default: //nieznana instrukcja
                cout << "Podaj jedna z instrukcji:\n"
                << "d - aby dodac napis do stosu\n"
                << "u - aby usunac napis ze stosu\n"
                << "w - aby wyswietlic zawartosc stosu\n"
                << "x - aby zakonczyc\n";
                break;
        }
    }
}

int main() { 
    stack(6); 
}