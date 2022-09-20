/*
 ============================================================================
 Name        : ejercicio5-1.c
 Author      : SERRANO SEBASTIAN
 Version     : K-1
 Tema 5 (Vectores -Vectores y funciones)
Ejercicio 5-1:
Pedir el ingreso de 5 números. Mostrarlos y calcular la sumatoria de los mismos.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#define CANT 5

int main(void)
{
	setbuf(stdout, NULL);
	int vec[CANT], i, suma = 0;



	for(i = 0; i < CANT; i++)
	{
		printf("\nIngrese un numero: ");
		scanf("%d", &vec[i]);
		printf("\nEl numero ingresado es: %d",vec[i]);
		 suma += vec[i];
	}
	printf("\nLa suma total es de: %d", suma);

	return EXIT_SUCCESS;
}
//system("cls"); para clear console

//<ctype.h> // blibloteca upper lowwer
//opcion = toupper(opcion); //upper case
