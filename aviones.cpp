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
    string comida;
    string typeflight;
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
}; using vuelo = struct Vuelo; vector<vuelo> Vuelos;

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

    Vuelos.push_back(flight);
}

persona AddPersona(){
   bool primera = false;
   bool ejecutiva = false;
   bool turista = false;
   persona viajero;
   cout << "\nIngrese el nombre del pasajero: ";
   getline(cin,viajero.name);
   cout << "\nIngrese el DUI del pasajero: ";
   cin >> viajero.ID;
   cout << "\nIngrese la edad del pasajero: ";
   cin >> viajero.Age;
   cout<< "\nIngrese el tipo de vuelo del pasajero: ";
   int opcion=0;
   do {
       cout << "\n1------------Primera Clase";
       cout << "\n2------------Clase Ejecutiva";
       cout << "\n3------------Clase Turista";
       cin >> opcion;
       switch (opcion){
           case 1:
                viajero.typeflight = "Primera Clase";
                break;
           case 2:
                viajero.typeflight = "Clase Ejecutiva";
                break;
           case 3:
                viajero.typeflight = "Clase Turista";
                break;
            default:
            cout << "\nIngrese una opcion valida ";
       }
   } while (opcion<1 || opcion>3);  

   return viajero;
}

void Persona_a_Vuelo(){
    persona unapersona = AddPersona();
    string nombreVuelo;
    int opcion=0;

    if (Vuelos.empty())
    {
        cout << "No hay ningun vuelo registrado" << endl;
        return;
    }
    
    /*cout << "Ingrese el vuelo del pasajero "<< unapersona.name<<" : ";
    for (int i=0;i<Vuelos.size();i++)
    {
        cout << i+1<<") "<<Vuelos.at(i).nombre<<endl;
    }*/
    do 
    {
        cout << "Ingrese el vuelo del pasajero "<< unapersona.name<<" : ";
        for (int i=0;i<Vuelos.size();i++)
        {
        cout << i+1<<") "<<Vuelos.at(i).nombre<<endl;
        }
        cin >> opcion;cin.ignore();        
    }while(opcion<0 || opcion > Vuelos.size());
    nombreVuelo = Vuelos.at(opcion-1).nombre;
    for (int i = 0;i<Vuelos.size();i++)
    {
        if (nombreVuelo==Vuelos.at(i).nombre)
        {
            if (unapersona.typeflight=="Primera Clase")
            {
                Vuelos.at(i).Primera.push(unapersona);
            }
            else if (unapersona.typeflight=="Clase Ejecutiva")
            {
                Vuelos.at(i).Ejecutiva.push(unapersona);
            }
            else if (unapersona.typeflight=="Clase Turista")
            {
                Vuelos.at(i).Turista.push(unapersona);
            }
        }
    }   
}
bool eliminarPrimera(int n, bool &fin){
    queue<persona> auxiliar = Vuelos.at(0).Primera;
    queue<persona> pivote;
     if (Vuelos.at(0).Primera.empty()){
         fin=true;
         return fin;
     }
     else {

     while(Vuelos.at(0).Primera.front().ID!=n && !Vuelos.at(0).Primera.empty()){
        pivote.push(Vuelos.at(0).Primera.front());
		Vuelos.at(0).Primera.pop();
	}
     if (Vuelos.at(0).Primera.empty()){
        cout << "El pasajero no se encuentra en la base de datos de la Primera Clase" << "\n";
        Vuelos.at(0).Primera = auxiliar;
        fin=true;
        return fin;
    }

    else if (Vuelos.at(0).Primera.front().ID==n){
        cout << "Se eliminara al pasajero " << "\n";
        cout <<Vuelos.at(0).Primera.front().ID<< " " << Vuelos.at(0).Primera.front().name<<"\n";
        Vuelos.at(0).Primera.pop();
        cout << "Se elimino correctamente el pasajero!" << "\n";
        while (!pivote.empty()){
        Vuelos.at(0).Primera.push(pivote.back());
        pivote.pop();      
    }
    fin = false;
  return fin;
}
     }
    }
   
  
   
int eliminarEjecutiva(int n, bool &fin){
    queue<persona> auxiliar = Vuelos.at(0).Ejecutiva;
     queue<persona> pivote;
     if (Vuelos.at(0).Ejecutiva.empty()){
         fin=true;
         return fin;
     }
     else {

     while(Vuelos.at(0).Ejecutiva.front().ID!=n && !Vuelos.at(0).Ejecutiva.empty()){
        pivote.push(Vuelos.at(0).Ejecutiva.front());
		Vuelos.at(0).Ejecutiva.pop();
	}
     if (Vuelos.at(0).Ejecutiva.empty()){
        cout << "El pasajero no se encuentra en la base de datos de la Clase Ejecutiva" << "\n";
        Vuelos.at(0).Ejecutiva = auxiliar;
        fin=true;
        return fin;
    }

    else if (Vuelos.at(0).Ejecutiva.front().ID==n){
        cout << "Se eliminara al pasajero " << "\n";
        cout <<Vuelos.at(0).Ejecutiva.front().ID<< " " << Vuelos.at(0).Ejecutiva.front().name<<"\n";
        Vuelos.at(0).Ejecutiva.pop();
        cout << "Se elimino correctamente el pasajero!" << "\n";
        while (!pivote.empty()){
        Vuelos.at(0).Ejecutiva.push(pivote.back());
        pivote.pop();
        
    }
    fin = false;
  return fin;
}
     }
    }
int eliminarTurista(int n, bool &fin){
    queue<persona> auxiliar = Vuelos.at(0).Turista;
     queue<persona> pivote;
     if (Vuelos.at(0).Turista.empty()){
         fin= true;
         return fin;
     }
     else {

     while(Vuelos.at(0).Turista.front().ID!=n && !Vuelos.at(0).Turista.empty()){
        pivote.push(Vuelos.at(0).Turista.front());
		Vuelos.at(0).Turista.pop();
	}
     if (Vuelos.at(0).Turista.empty()){
        cout << "El pasajero no se encuentra en la base de datos de la Clase Turista" << "\n";
        Vuelos.at(0).Turista = auxiliar;
        fin=true;
        return fin;
    }

    else if (Vuelos.at(0).Turista.front().ID==n){
        cout << "Se eliminara al pasajero: " << "\n";
        cout <<Vuelos.at(0).Turista.front().ID<< " " << Vuelos.at(0).Turista.front().name<<"\n";
        Vuelos.at(0).Turista.pop();
        cout << "Se elimino correctamente el pasajero!" << "\n";
        while (!pivote.empty()){
        cout << "Agregando de nuevo a los pasajeros a la cola original " << pivote.front().name << " " << pivote.front().ID<< "\n";
        Vuelos.at(0).Turista.push(pivote.back());
        pivote.pop();
        
    }
    fin = false;
  return fin;
}
    }
     }

int main(){
    int DUI=0;
    bool fin=true;
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
            AddVuelo();
            break;
        
        case 2:
            Persona_a_Vuelo();
            break;

        case 3:
            
            break;

        case 4: 
            DUI=0;
            fin=true;
            cout << "Ingrese el DUI de la persona que cancelo su viaje: " << "\n";
            cin >> DUI;
            
            //eliminarPrimera(DUI, fin);
            if (eliminarPrimera(DUI, fin)==false){
                break;
                return 0;
            }
            //eliminarEjecutiva(DUI, fin);
             if (eliminarEjecutiva(DUI,fin)==false){
                break;
                return 0;
            }
            //eliminarTurista(DUI, fin);
             if (eliminarTurista(DUI,fin)==false){
                break;
                return 0;
            }
            
            break;
        
        case 5:
            
            break;

        case 6:
            
            break;

        case 7:
            cout << "\nSaliendo del programa...";
            break;

        default:
            cout << "\nIngrese una opcion valida.";
            break;
        }   
    }
}