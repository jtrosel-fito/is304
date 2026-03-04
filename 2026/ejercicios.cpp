#include <iostream>
#include "vectorej.hh"
using namespace std;

void ej1() {
   Vector<int> v(15);
    for(int i = 0; i < 10; i++) {
         v.push_back(i);
    }
    v.print();
    cout << v.size() << endl;
    cout << v.capacity() << endl;
    v.pop_back();
    v.pop_front();
    v.print();
    v.insert(2, 99);
    v.print();
}

void ej2() {
     Vector<int> v;
     v.push_back(5);
     v.push_back(10);
     v.push_back(15);
     v.push_back(20);
     v.push_back(25);
     cout << v.front() << endl;
     cout << v.back() << endl;
     v.at(2);
     v[1] = 100;
     v.print();
     // la funcion at evalua el rango del vector, el operador no.
}

void ej3(){
     Vector<string> v;
     v.push_back("The");
     v.push_back("quick");
     v.push_back("brown");
     v.push_back("fox");
     v.push_back("jumps");
     cout << v.size() << endl;
     cout << v.capacity() << endl;
     v.print();
     v.pop_back();
     v.pop_front();
     v.print();
     v.insert(2, "profe pongame 5");
     v.print();
}
void ej4() {
     int from, to;
     
     Vector<int> v;
     for (int i = 0; i < 6; i++) {
          v.push_back(i*10);
     }
     v.print();
     cout << "Ingrese el inicio del rango a eliminar : ";
     cin >> from;
     cout << "Ingrese el final del rango a eliminar : ";
     cin >> to;
     v.erase(from, to);
     v.print();
}
void ej5() {
     Vector<int> v;
     for (int i = 0; i < 10; i++) {
          v.push_back(i);
     }
     v.print();
     v.clear();
     v.print();
}
void ej6() {
     int num;
     cout << "Ingrese un numero para ver si el vector lo contiene: ";
     cin >> num;
     Vector<int> v;
     for (int i = 0; i < 10; i++) {
          v.push_back(i);
     }   
     cout << v.contains(num) <<endl;
}

void ej7() {
     int num;
     cout << "Ingrese un numero a buscar: ";
     cin >> num;
     Vector<int> v;
     for (int i = 0; i < 10; i++) {
          v.push_back(i);
     }
     cout << v.find(num) <<endl;
}

void ej8() {
     int num;   
     Vector<int> v;
     v.push_back(5);
     v.push_back(10);
     v.push_back(15);
     v.push_back(15);
     v.push_back(25);
     v.print();
     cout << "Ingrese un numero a eliminar: ";
     cin >> num;
     v.remove(num);
     v.print();
}

void ej9() {
     int num, cambio;
     Vector<int> v;
     v.push_back(10); v.push_back(20); v.push_back(30); v.push_back(40);
     v.print();
     cout << "Ingrese un numero a cambiar: ";
     cin >> num;
     cout << "Ingrese el nuevo numero: ";
     cin >> cambio;
     v.replace(num, cambio);
     v.print();
}

void ej10() {
     int num;
     Vector<int> v;
     v.push_back(10); v.push_back(20); v.push_back(30); v.push_back(20);
     v.print();
     cout << "Ingrese un numero a eliminar: ";
     cin >> num;
     v.remove_all(num);
     v.print();
}
void ej11(){
     int num, cambio;
     Vector<int> v;
     v.push_back(10); v.push_back(20); v.push_back(30); v.push_back(20);
     v.print();
     cout << "Ingrese un numero a cambiar: ";
     cin >> num;
     cout << "Ingrese el nuevo numero: ";
     cin >> cambio;
     v.replace_all(num, cambio);
     v.print();
}

void ej12(){
     int num;
     Vector<int> v;
     v.push_back(10); v.push_back(20); v.push_back(30); v.push_back(20); v.push_back(20);
     v.print();
     cout << "Ingrese un numero a contar: ";
     cin >> num;
     cout << v.count(num) << endl;
}

void ej13(){
     int num;
     Vector<int> v;
     v.push_back(10); v.push_back(20); v.push_back(30); v.push_back(20); v.push_back(20);
     v.print();
     cout << "Ingrese un numero a buscar: ";
     cin >> num;
     Vector<int> indices = v.indices_of(num);
     indices.print();
}

void ej14(){
     int i, j;
     Vector<int> v;
     v.push_back(10); v.push_back(20); v.push_back(30);
     v.print();
     cout << "Ingrese el primer indice a intercambiar: ";
     cin >> i;
     cout << "Ingrese el segundo indice a intercambiar: ";
     cin >> j;
     v.swap(i, j);
     v.print();
}

void ej15(){
     int num;
     Vector<int> v;
     v.push_back(10); v.push_back(20); v.push_back(30);
     v.print();
     v.reverse();
     v.print();
}

void ej16(){
     int num;
     Vector<int> v;
     v.push_back(10); v.push_back(20); v.push_back(30); v.push_back(40); v.push_back(50);
     v.print();
     cout << "Ingrese el numero de posiciones a rotar a la izquierda: ";
     cin >> num;
     v.rotate_left(num); 
     v.print();
}

void ej17(){
     int num;
     Vector<int> v;
     v.push_back(10); v.push_back(20); v.push_back(30); v.push_back(40); v.push_back(50);
     v.print();
     cout << "Ingrese el numero de posiciones a rotar a la derecha: ";
     cin >> num;
     v.rotate_right(num); 
     v.print();
     
}

void ej18(){
     Vector<int> v;
     v.push_back(30); v.push_back(10); v.push_back(20); v.push_back(50); v.push_back(40);
     v.print();
     v.sort();
     v.print();
     
}

void ej19(){
     Vector<int> a, b;
     a.push_back(1); a.push_back(2); a.push_back(3);
     b.push_back(4); b.push_back(5); b.push_back(6);
     a.print();
     b.print();
     a.append(b);
     a.print();
}

void ej20(){
     
}

void ej21(){
     
}

void ej22(){
     
}

void ej23(){
     
}

void ej24(){
     
}

void ej25(){
     
}

void ej26(){
     
}    

void ej27(){
     
}

void ej28(){
     
}

void ej29(){
     
}

void ej30(){
     
}

void ej31(){

}

int main() {
     int opcion;
     cout << "Seleccione un ejercicio del 1 al 31"<< endl;
     cin >> opcion;
     switch(opcion) {   
          case 0:
               cout << "Saliendo del programa" << endl;
               break;
          case 1:
               ej1();
               break;
          case 2:
               ej2();
               break;
          case 3:
               ej3();
               break;
          case 4:
               ej4();
               break;
          case 5:
               ej5();
               break;
          case 6:
               ej6();
               break;
          case 7:
               ej7();
               break;
          case 8:
               ej8();
               break;
          case 9:
               ej9();
               break;
          case 10:
               ej10();
               break;
          case 11:
               ej11();
               break;
          case 12:
               ej12();
               break;
          case 13:
               ej13();
               break;
          case 14:
               ej14();
               break;
          case 15:
               ej15();
               break;
          case 16:
               ej16();
               break;
          case 17:
               ej17();
               break;
          case 18:
               //ej18();
               break;
          case 19:
               //ej19();
               break;
          case 20:
               //ej20();
               break;
          case 21:
               //ej21();
               break;
          case 22:
               //ej22();
               break;
          case 23:
               //ej23();
               break;
          case 24:
               //ej24();
               break;
          case 25:  
               //ej25();
               break;
          case 26:
               //ej26();
               break;
          case 27:
               //ej27();
               break;
          case 28:
               //ej28();
               break;
          case 29: 
               //ej29();
               break;
          case 30: 
               //ej30();
               break;
          case 31: 
               //ej31();
               break;
          default:
          cout << "Opcion no valida, vuelva a intentarlo" << endl;
               main();
     }
     
    return 0;
}

////compilar g++ ejercicios.cpp -o ejercicios