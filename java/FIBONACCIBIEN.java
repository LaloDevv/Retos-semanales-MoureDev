package RETOS2022;


public class FIBONACCIBIEN {

	public static void main(String[] args) {
		/*
		 * Escribe un programa que imprima los 50 primeros números de la sucesión
		 * de Fibonacci empezando en 0.
		 * - La serie Fibonacci se compone por una sucesión de números en
		 *   la que el siguiente siempre es la suma de los dos anteriores.
		 *   0, 1, 1, 2, 3, 5, 8, 13...
		 */
		int num1 = 0;
		int num2 = 1;
		int suma = num1 + num2;
		
		int cont = 50;
		
		System.out.println(0+" ");
		System.out.println(1+" ");
		
		while(cont>=0) {
			
			System.out.println(suma+" ");
			num1 = num2;
			num2 = suma;
			suma = num1 + num2;
			cont--;
			
		}
		
	}

}
