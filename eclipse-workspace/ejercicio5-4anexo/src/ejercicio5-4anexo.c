/*
 ============================================================================
 Name        : ejercicio5-4anexo.c
 Author      : Serrano Belloso Sebastian
 Division    : K-1
	ANEXO 5-4:
	Modificar la funcionalidad de la opción 2 del Menú para que la carga del Array sea de forma
	aleatoria.
	Agregar la funcionalidad de la opción 3 del Menú para mostrar por pantalla los elementos del
	Array, o sea las edades.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "anexoCinco.h"

#define CANTIDAD 5

int main(void)
{
	setbuf(stdout, NULL);

	int opcionIngresada;
	int numeros[CANTIDAD];


	do{
		opcionIngresada = mainMenu();
		switch(opcionIngresada)
		{
		case 1:
			inicializarVector(numeros, CANTIDAD);
		break;
		case 2:
			cargaAleatoria(numeros, CANTIDAD);
		break;
		case 3:
			mostrarVector(numeros, CANTIDAD);
		break;
		}


	}while(opcionIngresada != 6);


	return EXIT_SUCCESS;
}

