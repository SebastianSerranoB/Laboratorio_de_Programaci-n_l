/*
 ============================================================================
 Name        : repaso8-2.c
 Author      : Serrano Belloso Sebastian
 Version     :
 Copyright   : 
 Description : Hello World in C, Ansi-style

 Ejercicio 8.2
Realizar una función que reciba un puntero a char y dos char.
La función deberá reemplazar en la cadena cada ocurrencia del primer carácter recibido, por el segundo. Retornando la cantidad de reemplazos o -1 en caso de error.
tipo te dan Hola Mundo!, a, o
y te tiene que quedar Holo Mundo!
creo que seria asi

 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int reemplazo(char string[], char caracter, char* caracterReemplazo);

int main(void) {
	setbuf(stdout, NULL);

	char mensaje[12] = {"hola mundo"};
	char caracter = 'o';
	char reemplaza = 'x';
	char* caracterReemplazo;

	caracterReemplazo =  &reemplaza;


	printf("ANTES: %s", mensaje);
	reemplazo(mensaje, caracter, caracterReemplazo);
	printf("\nDESPUES: %s", mensaje);
	printf("\nCantidad de reemplazos: %d", reemplazo(mensaje, caracter, caracterReemplazo));



	return EXIT_SUCCESS;
}


int reemplazo(char string[], char caracter, char* caracterReemplazo)
{
	int retorno,i, contadorCaracteres;
	retorno = -1;
	contadorCaracteres = 0;


		if(caracterReemplazo != NULL)
		{
			for(i=0;i<12;i++)
			{
				if(string[i] == caracter)
				{
					string[i] = *caracterReemplazo;
					contadorCaracteres++;
				}
			}

			retorno = contadorCaracteres;
		}

	return retorno;
}
