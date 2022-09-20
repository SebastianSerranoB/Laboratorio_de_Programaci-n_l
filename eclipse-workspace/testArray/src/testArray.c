/*
 ============================================================================
 Name        : testArray.c
 Author      : Serrano Belloso Sebastian
 Version     :
 Copyright   : 
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#define CANT 3

void inicializarVector(int vector[], int lenght);

int main(void) {
	setbuf(stdout, NULL);

	//DECLARO ARRAY
	int array[CANT];
	int i;

//LLAMO A LA FUNCION
 inicializarVector(array, CANT);

//MUESTRO ARRAY INICIALIZADO
	for(i=0;i<CANT;i++)
	{
		printf("\nEl numero es: %d", array[i]);
	}



	return EXIT_SUCCESS;
} //FIN DEL MAIN


//CUERPO FUNCION
void inicializarVector(int vector[], int lenght)
{
	int i;
	for(i=0;i<lenght;i++)
	{
		vector[i] = 0;
	}

}
