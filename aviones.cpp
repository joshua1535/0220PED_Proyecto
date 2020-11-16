#include <iostream>
#include <string>
#include <ctime>
#include <queue>
#include <vector>
#include <stack>

using namespace std;

struct Vuelo{
    string partida;
    string destino;
    float despegue;
    float hora;
}; using vuelo = struct Vuelo;

int main() 
{
    bool status = true;
    while(status) 
    {
        cout << "********** MENU **********" << endl;
        cout << "1. Ingresar un vuelo" << endl;
        cout << "2. Ingresar datos de un pasajero" << endl;
        cout << "3. Abordar pasajeros de un vuelo" << endl;
        cout << "4. Eliminar pasajero de un vuelo" << endl;
        cout << "5. Cancelar vuelo" << endl;
        cout << "6. Mostrar datos de pasajeros de un vuelo" << endl;
        cout << "7. Salir del programa" << endl;

        int option;
        cout << "\n" << "Ingrese la opción del menú que desea ejecutar: ";
        cin >> option; cin.ignore();   
    }
}