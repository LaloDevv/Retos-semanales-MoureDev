
#include <iostream>
#include <ctime>
#include <windows.h>

using namespace std;

int main()
{
    SetConsoleOutputCP(CP_UTF8);

    srand(time(NULL));

    int longitud;

    cout << "\tDime la longitud de las pistas: (introduce un numero y dale al enter que paso de hacer que solo te permita meter numeros)" << endl;
    cin >> longitud;

    char pistaAzul[longitud + 1];
    char pistaRojo[longitud + 1];

    for (int i = 0; i <= longitud + 1; i++)
    {

        if (i == 0)
        {
            pistaAzul[i] = 91;
            pistaRojo[i] = 91;
        }
        else if (i > 0 && i <= longitud)
        {
            pistaAzul[i] = '_';
            pistaRojo[i] = '_';
        }
        else if (i == longitud + 1)
        {
            pistaAzul[i] = 'A';
            pistaRojo[i] = 'R';
        }
    }

    int numTreesA = 1 + rand() % (4 - 1);
    int numTreesR = 1 + rand() % (4 - 1);

    while (numTreesA > 0)
    {
        int arbol = 1 + rand() % (longitud);

        for (int i = 1; i <= longitud; i++)
        {

            if (i == arbol)
            {
                pistaAzul[i] = 'T';
                numTreesA--;
            }
        }
    }

    while (numTreesR > 0)
    {
        int arbol = 1 + rand() % (longitud);

        for (int i = 1; i <= longitud; i++)
        {

            if (i == arbol)
            {
                pistaRojo[i] = 'T';
                numTreesR--;
            }
        }
    }

    for (int i = 0; i <= longitud + 1; i++)
    {

        cout << pistaAzul[i];
    }

    cout << endl;

    for (int i = 0; i <= longitud + 1; i++)
    {

        cout << pistaRojo[i];
    }

    Sleep(1000);
    system("cls");

    int positionA = longitud + 1;
    int positionR = longitud + 1;

    bool bandera = false;
    bool crashA = false;
    bool crashR = false;

    do
    {
        int moveA;
        int moveR;

        if (crashA == false)
        {
            moveA = 1 + rand() % (4 - 1);
        }
        else
        {
            moveA = 0;
            crashA = false;
        }

        if (crashR == false)
        {
            moveR = 1 + rand() % (4 - 1);
        }
        else
        {
            moveR = 0;
            crashR = false;
        }

        if (pistaAzul[positionA - moveA] == 'T' || pistaRojo[positionR - moveR] == 'T')
        {

            if (pistaAzul[positionA - moveA] == 'T')
            {

                pistaAzul[positionA - moveA] = 'X';
                positionA = positionA - moveA;
                pistaAzul[positionA + moveA] = '_';
                crashA = true;
            }

            if (pistaRojo[positionR - moveR] == 'T')
            {

                pistaRojo[positionR - moveR] = 'X';
                positionR = positionR - moveR;
                pistaRojo[positionR + moveR] = '_';
                crashR = true;
            }
        }

        if (crashA == false)
        {

            if (moveA > 0)
            {
                pistaAzul[positionA - moveA] = 'A';
                positionA = positionA - moveA;
                pistaAzul[positionA + moveA] = '_';
            }
            else
            {
                pistaAzul[positionA - moveA] = 'X';
            }
        }

        if (crashR == false)
        {

            if (moveR > 0)
            {

                pistaRojo[positionR - moveR] = 'R';
                positionR = positionR - moveR;
                pistaRojo[positionR + moveR] = '_';
            }
            else
            {
                pistaRojo[positionR - moveR] = 'X';
            }
        }

        for (int i = 0; i <= longitud + 1; i++)
        {

            cout << pistaAzul[i];
        }

        cout << endl;

        for (int i = 0; i <= longitud + 1; i++)
        {

            cout << pistaRojo[i];
        }

        Sleep(150);
        system("cls");

        if (positionA <= 0 && positionR <= 0)
        {
            cout << "\tHAN QUEDADO EMPATE!!!";
            bandera = true;
        }
        else if (positionR <= 0)
        {
            cout << "\tHA GANADO EL ROJO!!!";
            bandera = true;
        }
        else if (positionA <= 0)
        {
            cout << "\tHA GANADO EL AZUL!!!";
            bandera = true;
        }
        else
        {
            bandera = false;
        }

    } while (bandera == false);

    cout << endl;
    cout << "\tHasta el proximo gran premio!";
    Sleep(1500);

    return 0;
}