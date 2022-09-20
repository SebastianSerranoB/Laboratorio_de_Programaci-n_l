/*
 ============================================================================
 Name        : ejercicio5_2-3Anexo.c
 Author      : Serrano Belloso Sebastian
 Division    : k-1
 ANEXO 5-2:

Realizar un programa que desde el main llame o invoque a la funci�n que muestre el Men� del
punto anterior.
Utilizar funciones y bibliotecas.
ANEXO 5-3:
Crear un Array de 5 elementos de tipo num�rico donde se cargar�n edades.
Agregar la funcionalidad para la opci�n 1 del Men� del ejercicio anterior utilizando funciones, es
decir una funci�n que inicialice el Array.
Agregar la funcionalidad para la opci�n 2 del Men� utilizando funciones, es decir una funci�n que
le pida los n�meros o edades al usuario para cargar el Array de forma secuencial.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "menuFunctions.h"
#include "ejercicio5Functions.h"

#define CANTIDAD 5

int main(void)
{
	setbuf(stdout, NULL);
	int opcionIngresada;
	int edadIngresada[CANTIDAD];
	int j;


	do{
		opcionIngresada = mainMenu();
		switch(opcionIngresada)
		{

		case 1:
			inicializarVector(edadIngresada, CANTIDAD); //
		break;
		case 2:
			cargaSecuencial(edadIngresada, CANTIDAD);
		break;
		}
	}while(opcionIngresada != 6);


	for(j=0;j<CANTIDAD;j++)
	{
		printf("\nEdades: %d",edadIngresada[j]);
	}

	return EXIT_SUCCESS;
}
