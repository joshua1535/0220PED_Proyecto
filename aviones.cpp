#include <iostream>
#include <string>
#include <Windows.h>
#include <queue>
#include <vector>
#include <stack>

using namespace std;

struct Personas{
    string name;
    int ID;
    int Age;
    string comida = "*Sin registrar*";
    string typeflight;
}; using persona = struct Personas; const persona invalid = {{" "},-1,-1,{" "},{" "}};

struct Vuelo{
    string partida;
    string destino;
    int despegue;
    float hora;
    string nombre;
    string status = "*Sin Abordar*";
    queue<persona> Primera;
    queue<persona> Ejecutiva;
    queue<persona> Turista;
}; using vuelo = struct Vuelo; vector<vuelo> Vuelos;

void AddVuelo(){
    vuelo flight;
    
    cout << "\nIngrese el lugar de partida del vuelo: ";
    getline(cin,flight.partida);

    if(flight.partida == " " || flight.partida == "" || flight.partida == "  " || flight.partida == "   " || flight.partida == "    "){
       do{
           cout <<"\nDato inv"<< char(160) << "lido!\n";
           cout << "\nIngrese el lugar de partida nuevamente: ";
           getline(cin,flight.partida);
       }while(flight.partida == " " || flight.partida == "" || flight.partida == "  " || flight.partida == "   " || flight.partida == "    ");
   }

    cout << "\nIngrese el lugar de destino: ";
    getline(cin,flight.destino);

    if(flight.destino == " " || flight.destino == "" || flight.destino == "  " || flight.destino == "   " || flight.destino == "    "){
       do{
           cout <<"\nDato inv"<< char(160) << "lido!\n";
           cout << "\nIngrese el lugar de destino nuevamente: ";
           getline(cin,flight.destino);
       }while(flight.destino == " " || flight.destino == "" || flight.destino == "  " || flight.destino == "   " || flight.destino == "    ");
   }

    cout << "\nIngrese la hora de despegue (formato 24h): ";
    cin >> flight.despegue;

    if(flight.despegue < 0 || flight.despegue > 23){
        do{
            cout << "Dato inv" << char(160) << "lido!\n";
            cout << "\nIngrese la hora de despeque (formato 24h): ";
        }while(flight.despegue < 0 || flight.despegue > 23);
    }

    cout << "\nIngrese la duraci" << char(162) << "n del vuelo: ";
    cin >> flight.hora; cin.ignore();

    if(flight.hora < 0 || flight.hora > 20.00){
        do{
            cout << "Dato inv" << char(160) << "lido!\n";
            cout << "\nIngrese la duraci" << char(162) << "n del vuelo: ";
        }while(flight.hora < 0 || flight.hora > 20.00);
    }

    cout << "\nIngrese nombre de referencia: ";
    getline(cin,flight.nombre);

    if(flight.nombre == " " || flight.nombre == "" || flight.nombre == "  " || flight.nombre == "   " || flight.nombre == "    "){
       do{
           cout <<"\nDato inv"<< char(160) << "lido!\n";
           cout << "\nIngrese el lugar de destino nuevamente: ";
           getline(cin,flight.nombre);
       }while(flight.nombre == " " || flight.nombre == "" || flight.nombre == "  " || flight.nombre == "   " || flight.nombre == "    ");
   }

    Vuelos.push_back(flight);
}

persona AddPersona(){
    if(Vuelos.empty()){
        cout << "\nNo hay ning"<< char(163) << "n vuelo registrado!\n";
        return invalid;
    }

   bool primera = false, ejecutiva = false, turista = false;
   persona viajero;

   cout << "\nIngrese el nombre del pasajero: ";
   getline(cin,viajero.name);

   if(viajero.name == " " || viajero.name == "" || viajero.name == "  " || viajero.name == "   " || viajero.name == "    "){
       do{
           cout <<"\nDato inv"<< char(160) << "lido!\n";
           cout << "\nIngrese el nombre nuevamente: ";
           getline(cin,viajero.name);
       }while(viajero.name == " " || viajero.name == ""|| viajero.name == "  " || viajero.name == "   " || viajero.name == "    ");
   }

   cout << "\nIngrese el DUI del pasajero: ";
   cin >> viajero.ID;

   cout << "\nIngrese la edad del pasajero: ";
   cin >> viajero.Age;

   if(viajero.Age <= 0){
       do{
           cout << "Dato inv"<< char(160) << "lido!\n";
           cout << "Ingrese la edad nuevamente: ";
           cin >> viajero.Age; cin.ignore();
       }while(viajero.Age <= 0);
   }

   int opcion = 0;

   do{
       cout << "\n\tA continuaci"<< char(162) << "n se le muestran las clases disponibles:";
       cout << "\n\t1- Primera Clase.";
       cout << "\n\t2- Clase Ejecutiva.";
       cout << "\n\t3- Clase Turista.";
       cout << "\n\n\tIngrese el tipo de vuelo del pasajero: ";
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
            cout << "\n\tIngrese una opci"<< char(162) << "n valida.";
       }
   }while (opcion < 1 || opcion > 3);  

   return viajero;
}

void Persona_a_Vuelo(){
    persona unapersona = AddPersona();
    string nombreVuelo;
    int opcion = 0;

    if(Vuelos.empty()){
        return;
    }

    do{
        cout << "\n---- Lista de vuelos ----\n";
        for (int i = 0; i < Vuelos.size(); i++){
        cout << i+1<<") "<< Vuelos.at(i).nombre << endl;
        }
        cout << "\nIngrese el vuelo del pasajero ["<< unapersona.name<<"]: ";
        cin >> opcion;cin.ignore(); 
        opcion = opcion - 1;
        if(opcion < 0 || opcion >= Vuelos.size()){
            cout << "\nIngrese una opci"<< char(162) << "n valida.";
        } 
    }while(opcion < 0 || opcion >= Vuelos.size());

    nombreVuelo = Vuelos.at(opcion).nombre;

    for (int i = 0; i < Vuelos.size(); i++){
        if(nombreVuelo == Vuelos.at(i).nombre){
            if(unapersona.typeflight == "Primera Clase"){
                Vuelos.at(i).Primera.push(unapersona);
                cout << "\nSe ha agregado con " << char(130) << "xito al pasajero.\n";
            }else if(unapersona.typeflight == "Clase Ejecutiva"){
                Vuelos.at(i).Ejecutiva.push(unapersona);
                cout << "\nSe ha agregado con " << char(130) << "xito al pasajero.\n";
            }else if(unapersona.typeflight == "Clase Turista"){
                Vuelos.at(i).Turista.push(unapersona);
                cout << "\nSe ha agregado con " << char(130) << "xito al pasajero.\n";
            }
        }
    }   
}

vuelo FoodMenu(vuelo FlightFood, vuelo Clone){
    int opcionP = 0; int opcionE = 0; int opcionT = 0;
    queue<persona> PrimeraC, EjecutivaC, TuristaC; 

        do{
            while(!FlightFood.Primera.empty()){
                persona UnaPersona;
                cout << "\n\t---- MEN" << char(233) << " Comida ----";
                cout << "\n\t1- Primera Opcion 01.\n\t2- Primera Opcion 02.\n\t3- Primera Opcion 03.";

                cout << "\n\tIngrese al opci" << char(162) << "n que desea para el pasajero [" << FlightFood.Primera.front().name << "]: ";
                cin >> opcionP; cin.ignore();

                switch (opcionP){
                case 1:
                    FlightFood.Primera.front().comida = "Primera Opcion 01";
                    UnaPersona = FlightFood.Primera.front();
                    FlightFood.Primera.pop();
                    PrimeraC.push(UnaPersona);
                    break;
                    
                case 2:
                    FlightFood.Primera.front().comida = "Primera Opcion 02";
                    UnaPersona = FlightFood.Primera.front();
                    FlightFood.Primera.pop();
                    PrimeraC.push(UnaPersona);
                    break;

                case 3:
                    FlightFood.Primera.front().comida = "Primera Opcion 03";
                    UnaPersona = FlightFood.Primera.front();
                    FlightFood.Primera.pop();
                    PrimeraC.push(UnaPersona);
                    break;

                default:
                    cout << "\nIngrese una opci"<< char(162) << "n valida."; 
                    break;
                }
            }
        }while(opcionP < 0 || opcionP > 3);

        Clone.Primera = PrimeraC;

        do{
            while(!FlightFood.Ejecutiva.empty()){
                persona UnaPersonaE;
                cout << "\n\t---- MEN" << char(233) << " Comida ----";
                cout << "\n\t1- Opcion Ejecutiva 01.\n\t2- Opcion Ejecutiva 02.\n\t3- Opcion Ejecutiva 03.";

                cout << "\n\tIngrese al opci" << char(162) <<"n que desea para el pasajero [" << FlightFood.Ejecutiva.front().name << "]: ";
                cin >> opcionE; cin.ignore();

                switch (opcionE){
                case 1:
                    FlightFood.Ejecutiva.front().comida = "Opcion Ejecutiva 01";
                    UnaPersonaE = FlightFood.Ejecutiva.front();
                    FlightFood.Ejecutiva.pop();
                    EjecutivaC.push(UnaPersonaE);
                    break;
                    
                case 2:
                    FlightFood.Ejecutiva.front().comida = "Opcion Ejecutiva 02";
                    UnaPersonaE = FlightFood.Ejecutiva.front();
                    FlightFood.Ejecutiva.pop();
                    EjecutivaC.push(UnaPersonaE);
                    break;

                case 3:
                    FlightFood.Ejecutiva.front().comida = "Opcion Ejecutiva 03";
                    UnaPersonaE = FlightFood.Ejecutiva.front();
                    FlightFood.Ejecutiva.pop();
                    EjecutivaC.push(UnaPersonaE);
                    break;

                default:
                    cout << "\nIngrese una opci"<< char(162) << "n valida.";
                    break;
                }
            }
        }while(opcionE < 0 || opcionE > 3);

        Clone.Ejecutiva = EjecutivaC;

        do{
            while(!FlightFood.Turista.empty()){
                persona UnaPersonaT;
                cout << "\n\t---- MEN" << char(233) << " Comida ----";
                cout << "\n\t1- Opcion Turista 01.\n\t2- Opcion Turista 02.\n\t3- Opcion Turista 03.";

                cout << "\n\tIngrese al opci" << char(162) <<"n que desea para el pasajero [" << FlightFood.Turista.front().name << "]: ";
                cin >> opcionT; cin.ignore();

                switch (opcionT){
                case 1:
                    FlightFood.Turista.front().comida = "Opcion Turista 01";
                    UnaPersonaT = FlightFood.Turista.front();
                    FlightFood.Turista.pop();
                    TuristaC.push(UnaPersonaT);
                    break;
                    
                case 2:
                    FlightFood.Turista.front().comida = "Opcion Turista 02";
                    UnaPersonaT = FlightFood.Turista.front();
                    FlightFood.Turista.pop();
                    TuristaC.push(UnaPersonaT);
                    break;

                case 3:
                    FlightFood.Turista.front().comida = "Opcion Turista 03";
                    UnaPersonaT = FlightFood.Turista.front();
                    FlightFood.Turista.pop();
                    TuristaC.push(UnaPersonaT);
                    break;

                default:
                    cout << "\nIngrese una opci"<< char(162) << "n valida.";
                    break;
                }
            }
        }while(opcionT < 0 || opcionT > 3);

        Clone.Turista = TuristaC;

        return Clone;
}

void AbordViajeros(){
    if(Vuelos.empty()){
        cout << "\nNo hay ning"<< char(163) << "n vuelo registrado!";
        return;
    }else{
        int option = 0;
        do{
            cout << "\n---- Lista de vuelos ----\n";
            for (int i = 0; i < Vuelos.size(); i++){
            cout << i + 1 << ") "<< Vuelos.at(i).nombre << endl;
            }
            cout << "\nIngrese el vuelo que desea para abordar a los pasajeros: ";
            cin >> option; cin.ignore(); 
            option = option - 1; 

            if(option < 0 || option >= Vuelos.size()){
            cout << "\nIngrese una opci"<< char(162) << "n valida.";
        }
        }while(option < 0 || option >= Vuelos.size());

        string FlightName = Vuelos.at(option).nombre;

        for (int i = 0; i < Vuelos.size(); i++){
            if (FlightName == Vuelos.at(i).nombre){
                queue<persona> AuxPrimera = Vuelos.at(i).Primera, AuxEjecutiva = Vuelos.at(i).Ejecutiva, AuxTurista = Vuelos.at(i).Turista;
                vuelo FlightFood = Vuelos.at(i), Clone = Vuelos.at(i);

                if(AuxPrimera.empty() && AuxEjecutiva.empty() && AuxTurista.empty()){
                    cout << "\nNo hay ning" << char(163) << "n pasajero registrado en este vuelo.\n";
                    return;
                }

                cout << "\n---- Abordando a los pasajeros del vuelo [" << FlightName << "] ----\n";
                cout << "\nPrimera Clase:\n";
                if (AuxPrimera.empty()){
                    cout << "\nNo hay pasajeros registrados en esta clase.\n";
                }
                while(!AuxPrimera.empty()){
                    Sleep(25);
                    cout << "\nNombre: " << AuxPrimera.front().name;
                    cout << "\nDUI: " << AuxPrimera.front().ID;
                    cout << "\nEdad: " << AuxPrimera.front().Age << " a" << char(164) <<"os.";
                    cout << "\nClase: " << AuxPrimera.front().typeflight;
                    AuxPrimera.pop();
                }

                cout << "\n\nClase Ejecutiva:\n";
                if (AuxEjecutiva.empty()){
                    cout << "\nNo hay pasajeros registrados en esta clase.\n";
                }
                while(!AuxEjecutiva.empty()){
                    Sleep(25);
                    cout << "\nNombre: " << AuxEjecutiva.front().name;
                    cout << "\nDUI: " << AuxEjecutiva.front().ID;
                    cout << "\nEdad: " << AuxEjecutiva.front().Age << " a" << char(164) <<"os.";
                    cout << "\nClase: " << AuxEjecutiva.front().typeflight;
                    AuxEjecutiva.pop();
                }

                cout << "\n\nClase Turista:\n";
                if (AuxTurista.empty()){
                    cout << "\nNo hay pasajeros registrados en esta clase.\n";
                }
                while(!AuxTurista.empty()){
                    Sleep(25);
                    cout << "\nNombre: " << AuxTurista.front().name;
                    cout << "\nDUI: " << AuxTurista.front().ID;
                    cout << "\nEdad: " << AuxTurista.front().Age << " a" << char(164) <<"os.";
                    cout << "\nClase: " << AuxTurista.front().typeflight;
                    AuxTurista.pop();
                }
                Vuelos.at(i) = FoodMenu(FlightFood, Clone);
                Vuelos.at(i).status = "*Abordado*";
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

void CancelFlight(){
    if(Vuelos.empty()){
        cout << "\nNo hay ning"<< char(163) << "n vuelo registrado!";
        return;
    }else{
        int op = 0;
        do{
            cout << "\n---- Lista de vuelos ----\n";
            for (int i = 0; i < Vuelos.size(); i++){
            cout << i + 1 << ") "<< Vuelos.at(i).nombre << endl;
            }
            cout << "\nIngrese el vuelo que desea cancelar: ";
            cin >> op; cin.ignore(); 
            op = op - 1; 
        }while(op < 0 || op >= Vuelos.size());

        string NombreVuelo = Vuelos.at(op).nombre;

        for(int i = 0; i < Vuelos.size(); i++){
            if(NombreVuelo == Vuelos.at(i).nombre){
                Vuelos.pop_back();
                cout << "El vuelo [" << NombreVuelo << "] a sido cancelado con " << char(130) << "xito.";
            }
        }
    }
}

void ShowViajeros(){
    if(Vuelos.empty()){
        cout << "\nNo hay ning"<< char(163) << "n vuelo registrado!";
        return;
    }else{
        int option = 0;
        do{
            cout << "\n---- Lista de vuelos ----\n";
            for (int i = 0; i < Vuelos.size(); i++){
            cout << i + 1 << ") "<< Vuelos.at(i).nombre << "\t" << Vuelos.at(i).status << endl;
            }
            cout << "\nIngrese el vuelo del cual desea ver los datos de los pasajeros: ";
            cin >> option; cin.ignore(); 
            option = option - 1; 
        }while(option < 0 || option >= Vuelos.size());

        string FlightName = Vuelos.at(option).nombre;

        for (int i = 0; i < Vuelos.size(); i++){
            if (FlightName == Vuelos.at(i).nombre){
                queue<persona> ClonePrimera = Vuelos.at(i).Primera, CloneEjecutiva = Vuelos.at(i).Ejecutiva, CloneTurista = Vuelos.at(i).Turista;

                if(ClonePrimera.empty() && CloneEjecutiva.empty() && CloneTurista.empty()){
                    cout << "\nNo hay ning" << char(163) << "n pasajero registrado en este vuelo.\n";
                    return;
                }

                cout << "\n---- Mostrando los datos de los pasajeros del vuelo [" << FlightName << "] ----\n";
                cout << "\nPasajeros de Primera Clase:\n";
                if (ClonePrimera.empty()){
                    cout << "\nNo hay pasajeros registrados en esta clase.\n";
                }
                while(!ClonePrimera.empty()){
                    Sleep(100);
                    cout << "\nNombre: " << ClonePrimera.front().name;
                    cout << "\nDUI: " << ClonePrimera.front().ID;
                    cout << "\nEdad: " << ClonePrimera.front().Age << " a" << char(164) <<"os.";
                    cout << "\nClase: " << ClonePrimera.front().typeflight;
                    cout << "\nComida: " << ClonePrimera.front().comida << endl;
                    ClonePrimera.pop();
                }

                cout << "\n\nPasajeros de Clase Ejecutiva:\n";
                if (CloneEjecutiva.empty()){
                    cout << "\nNo hay pasajeros registrados en esta clase.\n";
                }
                while(!CloneEjecutiva.empty()){
                    Sleep(150);
                    cout << "\nNombre: " << CloneEjecutiva.front().name;
                    cout << "\nDUI: " << CloneEjecutiva.front().ID;
                    cout << "\nEdad: " << CloneEjecutiva.front().Age << " a" << char(164) <<"os.";
                    cout << "\nClase: " << CloneEjecutiva.front().typeflight;
                    cout << "\nComida: " << CloneEjecutiva.front().comida << endl;
                    CloneEjecutiva.pop();
                }

                cout << "\n\nPasajeros de Clase Turista:\n";
                if (CloneTurista.empty()){
                    cout << "\nNo hay pasajeros registrados en esta clase.\n";
                }
                while(!CloneTurista.empty()){
                    Sleep(200);
                    cout << "\nNombre: " << CloneTurista.front().name;
                    cout << "\nDUI: " << CloneTurista.front().ID;
                    cout << "\nEdad: " << CloneTurista.front().Age << " a" << char(164) <<"os.";
                    cout << "\nClase: " << CloneTurista.front().typeflight;
                    cout << "\nComida: " << CloneTurista.front().comida << endl;
                    CloneTurista.pop();
                }
            }
        } 
    }
}

int main(){
    int DUI=0;
    bool fin=true;
    bool status = true;

    while(status){
        cout << "\n\n********** MEN" << char(233) << " **********\n";
        cout << "1. Ingresar un vuelo.\n";
        cout << "2. Ingresar datos de un pasajero.\n";
        cout << "3. Abordar pasajeros de un vuelo.\n";
        cout << "4. Eliminar pasajero de un vuelo.\n";
        cout << "5. Cancelar vuelo.\n";
        cout << "6. Mostrar datos de pasajeros de un vuelo.\n";
        cout << "7. Salir del programa.\n";

        int option;
        cout << "\n" << "Ingrese la opci" << char(162) << "n del menu que desea ejecutar: ";
        cin >> option; cin.ignore();

        switch (option){
        case 1:
            AddVuelo();
            break;
        
        case 2:
            Persona_a_Vuelo();
            break;

        case 3:
            AbordViajeros();
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
            CancelFlight();
            break;

        case 6:
            ShowViajeros();
            break;

        case 7:
            cout << "\nSaliendo del programa...";
            status = false;
            break;

        default:
            cout << "\nIngrese una opci" << char(162) << "n valida.\n";
            break;
        }   
    }
}