#include <iostream>
#include <string>
#include <ctime>
#include <queue>
#include <vector>
#include <stack>

using namespace std;

struct Personas{
    string name;
    int ID;
    int Age;
    int typeflight;
}; using persona = struct Personas;

struct Vuelo{
    string partida;
    string destino;
    float despegue;
    float hora;
    string nombre;
    queue<persona> Primera;
    queue<persona> Ejecutiva;
    queue<persona> Turista;
}; using vuelo = struct Vuelo; vector<vuelo> unVuelo;

void AddVuelo(){
    vuelo flight;
    cout << "\nIngrese el lugar de partida del vuelo: ";
    getline(cin,flight.partida);
    cout << "\nIngrese el lugar de destino: ";
    getline(cin,flight.destino);
    cout << "\nIngrese la hora de despegue: ";
    cin >> flight.despegue;
    cout << "\nIngrese la duracion del vuelo: ";
    cin >> flight.hora; cin.ignore();
    cout << "\nIngrese nombre de referencia: ";
    getline(cin,flight.nombre);

    unVuelo.push_back(flight);
}

int main(){

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

        switch (option)
        {
        case 1:
            
            break;
        
        case 2:
            
            break;

        case 3:
            
            break;

        case 4:
            
            break;
        
        case 5:
            
            break;

        case 6:
            
            break;

        case 7:
            cout << "\nSaliendo del programa...";
            return;
            break;

        default:
            cout << "\nIngrese una opcion valida.";
            break;
        }   
    }
}