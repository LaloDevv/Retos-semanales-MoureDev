package RETOS2022;

import java.util.Scanner;

public class ANAGRAMA {

	public static void main(String[] args) {
		/*
		 * Escribe una función que reciba dos palabras (String) y retorne verdadero o
		 * falso (Bool) según sean o no anagramas. - Un Anagrama consiste en formar una
		 * palabra reordenando TODAS las letras de otra palabra inicial. - NO hace falta
		 * comprobar que ambas palabras existan. - Dos palabras exactamente iguales no
		 * son anagrama.
		 */

		Scanner entrada = new Scanner(System.in);
		String word = "";

		do {

			System.out.println("Dime una palabra: ");
			word = entrada.nextLine();
			System.out.println("Dime otra palabra: ");
			String word1 = entrada.nextLine();
			
			//si son la misma no es un anagrama
			if (word.equals(word1)) {
				System.out.println("No es un anagrama");
			} else {
				int temp = word.length();
				int temp2 = word1.length();
				
				//si no tiene la misma longitud no es un anagrama
				if (temp == temp2) {
					
					//este array va a controlar si el char de la posicion pertinente de la primera palabra ya ha sido comprobado
					boolean[] boolString = new boolean[temp];
					
					//este array va a controlar si el char de la posicion pertinente de la segunda palabra ya ha sido comprobado
					boolean[] boolString_segunda_word = new boolean[temp];

					//los inicializamos en false
					for (int i = 0; i < temp; i++) {

						boolString[i] = false;
						boolString_segunda_word[i]= false;

					}

					for (int i = 0; i < temp; i++) {

						for (int j = 0; j < temp; j++) {
							
							//si las palabras son iguales y es la primera vez que se checkean ambas posiciones del char en las palabras,
							//se vuelven true
							if (word.charAt(i) == word1.charAt(j) && boolString[i] == false && boolString_segunda_word[j] == false) {
								boolString[i] = true;
								boolString_segunda_word[j] = true;
							}
						}
					}

					int check = 0;

					for (int i = 0; i < temp; i++) {
						//recorremos el array y si encuentra un false se le suma 1 a check
						if (boolString[i] == false) {
							check++;
						}
					}
					//para que sea un anagrama todas las pos del array deben ser true, es decir, check = 0
					if (check == 0) {
						System.out.println("Es un anagrama");
					} else {
						System.out.println("No es un anagrama");
					}

				} else {
					System.out.println("No es un anagrama");
				}

			}
		} while (!word.equals("0"));
	}

}
