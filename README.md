_________________________________________________
# 0220PED_Proyecto
_________________________________________________
Integrantes:

Kevin Joshua Montano Martinez 00176020

Jonathan Adriel Morales Orellana 00095520

José Danilo Bonilla Vides 00019520

Danny Rigoberto Argueta Bran 00042220

__________________________________________________
    Sistema de abordaje para un aeropuerto
__________________________________________________
INDICE:

1) Requisitos del sistema
2) Descripcion del proyecto
3) Estructuras utilizadas
4) Librerias utilizadas
5) Funciones que integra el programa
6) Resumen de lo que hace el programa
__________________________________________________
1) Requisitos del sistema
__________________________________________________

Requerimientos Para Instalar C++ - (DevC++) 

Estos son los mínimos requisitos del sistema que utiliza Dev-C++:

- Microsoft Windows 95, 98, NT 4, 2000, XP
- 8 MB de RAM con un archivo de intercambio grande
- Procesador compatible Intel a 100 Mhz
- 30 MB de espacio libre en el disco duro

 Estos son los requisitos recomendados de Dev-C++:

- Microsoft Windows 2000, XP
- 32 MB de RAM
- Procesador compatible Intel a 400
- 200 MB de espacio libre en el disco duro
__________________________________________________
2)Descripcion del proyecto:
__________________________________________________

El siguiente proyecto es un programa para llevar un control de vuelos de un aeropuerto y de los pasajeros que
corresponden a cada uno de los vuelos.
__________________________________________________
3)Estructuras utilizadas:
__________________________________________________

1. Colas
2. Listas simplemente enlazadas
__________________________________________________
4)Librerias utilizadas:
__________________________________________________

<iostream>
<string>
<Windows.h>
<queue>
<vector>
<stack>
<iomanip>
__________________________________________________
5) Ejecución del programa:
__________________________________________________

El menú el de funciones del programa contiene Ocho Opciones:
1.	Ingresar un Vuelo
2.  Mostrar Vuelos
3.	Ingresar datos de un pasajero
4.	Abordar pasajeros de un vuelo
5.	Eliminar pasajero de un vuelo
6.	Cancelar vuelo
7.	Mostrar datos de pasajeros de un vuelo
8.	Salir del programa
___________________________________________________
6)Resumen de lo que hace el programa
___________________________________________________

En Primer lugar, este programa es para ayudar a las aerolineas para llevar un control, en los vuelos y pasajeros que abordan a los aviones.

-La Primera opción es para registrar el vuelo que esta a punto de salir, su destino, a que horas partió, el tiempo estimado de vuelo y su nombre de referencia.

-la Segunda, complementa a la primera, ya que solo muestra los datos previamente ingresados, en el caso que no haya ningún vuelo registrado, nos mostraria un mensaje de error que no hay ningun vuelo registrado.

-La Tercera opción, es de ingresar datos de un pasajero, se pediran la documentación necesaria al pasajero, nombre, DUI, Edad, y se le presenta las opciones de Clases, las cuales son
-Primera
-Ejecutiva 
-Turista

-La Cuarta opción, consinste en que luego de tener a los pasajeros, es necesario avisarles del abordaje a su respectivo avion, se les abrirá un menu de alimentos, los cuales son diferentes dependiendo de la clase.

-La Quinta opción, es en caso de que sea necesario eliminar a un pasajero del vuelo que tenia programado.

-La Sexta opción, es en caso de que suceda algo en la pista, en el mismo avión o alguna causa meteorológica, se da la opción que se pueda cancelar el vuelo.

-La Septima opción, mostrará los datos de aquellos pasajeros que se encuentren registrados en algun vuelo programado.

- La última opción es para salir del programa.
