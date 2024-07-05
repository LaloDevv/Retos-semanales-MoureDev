/*
 * Crea un programa que calcule los puntos de una palabra.
 * - Cada letra tiene un valor asignado. Por ejemplo, en el abecedario
 *   español de 27 letras, la A vale 1 y la Z 27.
 * - El programa muestra el valor de los puntos de cada palabra introducida.
 * - El programa finaliza si logras introducir una palabra de 100 puntos.
 * - Puedes usar la terminal para interactuar con el usuario y solicitarle
 *   cada palabra.
 */
#include <iostream>

using namespace std;

int main(){

    int score;

    do
    {
        score = 0;
        string word;

        cout << "Dime una palabra: ";
        cin >> word;

        for(int i = 0; i < word.length();i++){

            if(word[i] >= 97 && word[i] <= 122){
                score += word[i] - 97; 
            }else if(word[i] >= 65 && word[i] <= 90){
                score += word[i] - 65;
            }
        }

        cout << "La puntuacion de esa palabra es: " << score << endl;

        if(score != 100){
            cout << "No has obtenido una puntuacion de 100, intentelo de nuevo" << endl;
        }else{
            cout << "\tEnhorabuena, ha obtenido una puntuacion de 100, usted gana";
        }


    } while (score < 100 || score > 100);
    

    return 0;
}
