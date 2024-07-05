/*
 * ¿Conoces el calendario de aDEViento de la comunidad (https://adviento.dev)?
 * 24 días, 24 regalos sorpresa relacionados con desarrollo de software.
 * Desde el 1 al 24 de diciembre.
 *
 * Crea un programa que simule el mecanismo de participación:
 * - Mediante la terminal, el programa te preguntará si quieres añadir y borrar
 *   participantes, mostrarlos, lanzar el sorteo o salir.
 * - Si seleccionas añadir un participante, podrás escribir su nombre y pulsar enter.
 * - Si seleccionas añadir un participante, y este ya existe, avisarás de ello.
 *   (Y no lo duplicarás)
 * - Si seleccionas mostrar los participantes, se listarán todos.
 * - Si seleccionas eliminar un participante, podrás escribir su nombre y pulsar enter.
 *   (Avisando de si lo has eliminado o el nombre no existe)
 * - Si seleccionas realizar el sorteo, elegirás una persona al azar
 *   y se eliminará del listado.
 * - Si seleccionas salir, el programa finalizará.
 */

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<string> participantes;
    int elecc;
    bool bandera = false;
    string name;
    bool nameExits;
    int numPart;
    int random;

    do
    {

    nameExits = false;

    cout << "1 - Annadir participante" << endl;
    cout << "2 - Borrar participante" << endl;
    cout << "3 - Mostrar participantes" << endl;
    cout << "4 - Realizar sorteo" << endl;
    cout << "0 - Salir" << endl;
    cin >> elecc;

    switch (elecc)
    {
    case 1:
    
        cout << "Dime el nombre del participante: ";
        cin >> name;

        participantes.push_back(name); //.push_back coloca el dato entre parentesis en la ultima posicion del vector

        break;
    case 2:
        cout << "Dime el nombre del participante que quieres eliminar: ";
        cin >> name;

        for(int i = 0; i < participantes.size();i++){

            if(name == participantes[i]){
                participantes.erase(participantes.begin() + i); //.erase apunta y elimina el dato que está entre () reduciendo el tamaño del vector en 1, .begin apunta a la posicion inicial del vector
                nameExits = true;
            }
        }

        if(nameExits == false){
            cout << "No hay ningun participante con ese nombre" << endl;
        }else if(nameExits == true){
            cout << "Participante eliminado" << endl;
        }

        break;
    case 3:

        cout << "Estos son los participantes: " << endl;
        cout << "=============================" << endl;
        for(int i = 0; i < participantes.size(); i++){
            cout << "Participante " << i + 1 << ": " << participantes[i] << endl;
        }
        cout << "=============================" << endl;
      
        break;
    case 4:
        
        numPart = participantes.size();

        random = 0 + rand() % (numPart + 1);

        for(int i = 0; i < numPart; i++){
            if(i == random){
                cout << participantes[i] << " ha sido eliminado" << endl;
                participantes.erase(participantes.begin() + i);
            }
        }

        break;
    case 0:
        cout << "Adios";
        bandera == true;
        break;
    default:
        cout << "Intentalo de nuevo" << endl;
        break;
    }

    } while (bandera == false);

    return 0;
}

