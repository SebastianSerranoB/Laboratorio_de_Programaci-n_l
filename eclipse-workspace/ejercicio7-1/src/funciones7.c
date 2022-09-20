/*
 * funciones7.c
 *
 *  Created on: 20 abr 2022
 *      Author: admin
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int mainMenu(void)
{
	int opcionIngresada;

	printf("\n\n1 -ALTA producto\n2 -BAJA producto\n3 -MODIFICACION producto\n4- LISTADO productos\n5- LISTADO ordenado por precio\n6- LISTADO ordenado por descripcion\n7- SALIR");
	scanf("%d", &opcionIngresada);
	while(opcionIngresada < 1 || opcionIngresada > 7)
	{
		printf("\nERROR, ingrese una opcion valida: ");
		scanf("%d", &opcionIngresada);
	}

	return opcionIngresada;
}


