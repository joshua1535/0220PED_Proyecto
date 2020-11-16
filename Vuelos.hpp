#include "iostream"
#include "string"
#include "stack"
#include "ctime"

using namespace std;

struct Vuelo{
    string partida;
    string destino;
    float despegue;
    float hora;
    string nombre;
}; using vuelo = struct Vuelo;

vuelo AddVuelo(){
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

    return flight;
}