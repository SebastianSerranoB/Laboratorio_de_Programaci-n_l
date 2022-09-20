/*
 * menuFunctions.c
 *
 *  Created on: 17 abr 2022
 *      Author: admin
 */
#include <stdio.h>
#include <stdlib.h>

int mainMenu(void)
{
	int opcionIngresada;

	printf("\n\n1-Inicializar\n2-Cargar\n3-Mostrar\n4-Calcular Promedio\n5-Ordenar\n6-Salir del menu");
	printf("\n\nOpcion ingresada: ");
	scanf("%d", &opcionIngresada);
	while(opcionIngresada < 1 || opcionIngresada > 6)
	{
		printf("\nError, ingrese una opcion valida: ");
		scanf("%d", &opcionIngresada);
	}

	return opcionIngresada;
}


