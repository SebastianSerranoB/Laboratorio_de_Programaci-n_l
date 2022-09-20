/*
 ============================================================================
 Name        : ejercicio15-1.c
 Author      : Serrano Belloso Sebastian
 Version     :
 Copyright   : 
 Description : Hello World in C, Ansi-style

 Clase 15 (Punteros)
Ejercicio 15-1:
Realizar el ordenamiento de un vector de enteros. Para ello deberán crear una función que se
encargue de realizar el intercambio de los dos valores que se van a ordenar (función swap), que
solo puede recibir dos parámetros.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>


int swap(int vector[], int lenght);

int main(void) {
	setbuf(stdout, NULL);

	int numeros[5] = {1,5,2,9,8};
	int i;

	for(i=0;i<5;i++){
		printf("\nNumeros en la posicion %d es : %d", i, numeros[i]);
	}

	swap(numeros, 5);

	for(i=0;i<5;i++){
			printf("\nAFTER SWAP: Numeros en la posicion %d es : %d", i, numeros[i]);
		}

	return EXIT_SUCCESS;
}

int swap(int vector[], int lenght)
{
	 int rtn, auxiliar, i, j;
	 rtn = 0;

	 for(i=0;i<lenght-1;i++){
		 for(j=i+1;j<lenght;j++){
			 if(vector[i] > vector[j])
			 {
				 auxiliar = vector[i];
				 vector[i] = vector[j];
				 vector[j] = auxiliar;
			 }
		 }
	 }


	 return rtn;
}
