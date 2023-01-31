#include <chrono>
#include <iostream>
#include <queue>
#include <stack>
#include <vector>
using namespace std;

void change_type(int *type) {
  cout << "Podaj typ struktury:\n1) Stos\n2) Kolejka\n3) Wektor\n";
  cin >> *type;
}
//funkcja szukająca elementu w stosie lub wyświetlająca wskazane elementy 
string find_in_stack(stack<string> *stos,int index,string element = ""){
    stack<string> stos2;
    string str;
    bool is_in = 0;
    while(!(*stos).empty()){
      if ((*stos).size() == index)
         str = (*stos).top();
      if ((*stos).top() == element)
        is_in = 1;
      stos2.push((*stos).top());
      (*stos).pop();
    }
    while(!stos2.empty()){
      (*stos).push(stos2.top());
      stos2.pop();
    }
    if (element != ""){
      if (is_in == 1)
        return "Stos zawiera \""+element+"\"";
      else
        return "Stos nie zawiera \""+element+"\"";;
    } 
    else
      return str;
}
//funkcja szukająca elementu w kolejce lub wyświetlająca wskazane elementy 
string find_in_queue(queue<string> *kolej,int index,string element = ""){
    queue<string> kolej2;
    string str;
    bool is_in = 0;
    int size = (*kolej).size()+1;
    while(!(*kolej).empty()){
      if (size-(*kolej).size() == index)
         str = (*kolej).front();
      if ((*kolej).front() == element)
        is_in = 1;
      kolej2.push((*kolej).front());
      (*kolej).pop();
    }
    while(!kolej2.empty()){
      (*kolej).push(kolej2.front());
      kolej2.pop();
    }
    if (element != ""){
      if (is_in == 1)
        return "kolejka zawiera \""+element+"\"";
      else
        return "Kolejka nie zawiera \""+element+"\"";;
    } 
    else
      return str;
}


int main() {
  stack<string> stos;
  queue<string> kolej;
  vector<string> wektor;
  
  bool loop = 1;
  int struct_type = 0;
  char op;
  int n;
  string str;
  
  while (loop == 1) {
    if (struct_type >=1 && struct_type <=3  ) {
      cin >> op;
      switch (op) {
      case 'd':
        cout << "Podaj napis:";
        cin >> str;   
        switch (struct_type) {
        case 1:
            stos.push(str);
            break;
        case 2:
            kolej.push(str);
            break;
        case 3:
            wektor.push_back(str);
            break;
        default:
            cout << "Nieprawidlowe wejscie!\n";
            break;
        }
        break;
      case 'u':
        switch (struct_type) {
        case 1:
          if (stos.empty())
            cout << "Stos jest pusty\n";
          else
            stos.pop();
          break;
        case 2:
          if (kolej.empty()) 
            cout << "Kolejka jest pusta\n";
          else  
            kolej.pop();
          break;
        case 3:
          if (wektor.empty()) 
            cout << "Wektor jest pusty\n";
          else
            wektor.pop_back();
          break;
        default:
            cout << "Nieprawidlowe wejscie!\n";
            break;
        }
        break;
      case 'w':
        switch (struct_type) {
          case 1:
            if (stos.empty())
              cout << "Stos jest pusty\n";
            else {
              cout<<"Pierwszy element:"<<find_in_stack(&stos,1)<<"\n";
              cout <<"Ostatni element:"<<stos.top()<<"\n";
            }
            break;
          case 2:
            if (kolej.empty()) 
              cout << "Kolejka jest pusta\n";
            else {
              cout<<"Pierwszy element:"<<kolej.front()<<"\n";
              cout <<"Ostatni element:"<< kolej.back()<<"\n";
            }  
            break;
          case 3:
            if (wektor.empty()) 
              cout << "Wektor jest pusty\n";
            else {
              cout<<"Pierwszy element:"<<wektor.front()<<"\n";
              cout <<"Ostatni element:"<< wektor.back()<<"\n";
            } 
            break;
          default:
            cout << "Nieprawidlowe wejscie!";
            break;
        }
        break;
      case 'n':
        cout << "Podaj indeks: ";
        cin >> n;
        switch (struct_type) {       
        case 1:
          if (stos.empty()) 
           cout << "Stos jest pusty\n"; 
          else {
            if(n > stos.size() || (n ==0)) 
              cout << "Inkeks poza zasiegiem\n";
            else
              cout<<"Element"<< n <<"stosu:"<<find_in_stack(&stos,n)<<"\n";
          }
          break;
        case 2:
          if (kolej.empty()) 
            cout << "Kolejka jest pusta\n";
          else {
           if(n > kolej.size() || (n ==0)) 
              cout << "Inkeks poza zasiegiem\n";
            else 
              cout <<"Element"<< n <<"kolejki:"<<find_in_queue(&kolej,n)<<"\n"; 
          }  
          break;
        case 3:
          if (wektor.empty()) 
            cout << "Wektor jest pusty\n";
          else {
            if(n > wektor.size() || (n ==0))
              cout << "Inkeks poza zasiegiem\n";
            else
              cout<<"Element "<< n <<" wektora:"<<wektor.at(n-1)<<"\n"; 
          } 
          break;
        default:
          cout << "Nieprawidlowe wejscie!";
          break;
        }
        break;
      case 'f':
        cout << "Podaj element do sprawdzenia:";
        cin >> str;  
        switch (struct_type){
          case 1:
            if (stos.empty())
              cout << "Stos jest pusty\n";
            else 
              cout<<find_in_stack(&stos,1,str)<<"\n";
            break;
          case 2:
            if (kolej.empty()) 
              cout << "Kolejka jest pusta\n";
            else {
              cout<<find_in_queue(&kolej,1,str)<<"\n";
            }  
            break;
          case 3:
            if (wektor.empty()) 
              cout << "Wektor jest pusty\n";
            else {
              bool is_in = 0;
              for(string i:wektor){
                if (i == str)
                  is_in = 1;
              } 
              if (is_in == 1)
                cout<<"kolejka zawiera \""+str+"\""<<"\n";
              else
                cout<<"kolejka nie zawiera \""+str+"\""<<"\n";
            } 
            break;
          default:
            cout << "Nieprawidlowe wejscie!\n";
            break;
        }
        break;
      case 'r':
         switch (struct_type) {
          case 1:
              cout << "Rozmiar stosu:" << stos.size()<<"\n";
              break;
          case 2:
              cout << "Rozmiar kolejki:" << kolej.size()<<"\n";
              break;
          case 3:
              cout << "Rozmiar wektora:" << wektor.size()<<"\n";
              break;
          default:
              cout << "Nieprawidlowe wejscie!\n";
              break;
          }
          break;
        break;
      case 'z':
        change_type(&struct_type);
        break;
      case 'x':
        loop = 0;
        break;
      default:
        cout << "Nieprawidlowe wejscie!\n";
        break;
      }
    } 
    else {
      change_type(&struct_type);
      if (struct_type >=1 && struct_type <=3 ){
        cout
          << "Wybierz operacje:\nd) Dodaj element\nu) Usun element\nw) Pobierz "
             "skrajne elementy\nn) Pobierz n-ty element\nf) Sprawdz czy element "
             "nalezy do struktury\nr) Pobierz wielkosc strukury\nz) Zmien typ struktury\nx) zakoncz program\n";
      }
    }
  }
}
