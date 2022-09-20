/*
 * anexoCinco.c
 *
 *  Created on: 18 abr 2022
 *      Author: admin
 */

#include <stdlib.h>
#include <stdio.h>

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

void inicializarVector(int vector[], int cantidad)
{
	int i;

	for(i=0;i<cantidad;i++)
	{
		vector[i] = 0;
	}

}

void cargaAleatoria(int vector[], int cantidad)
{
	int i, indice;

	for(i=0;i<cantidad;i++)
	{
		printf("\nIngrese la posicion: ");
				scanf("%d", &indice);
				while(indice > cantidad)
				{
					printf("\nError, ingrese una posicion valida: ");
					scanf("%d", &indice);
				}
		printf("\nIngrese un numero: ");
		scanf("%d", &vector[indice]);
	}

}

void mostrarVector(int vector[], int cantidad)
{
	int i;
	for(i=0;i<cantidad;i++)
	{
		printf("\nNumero: %d", vector[i]);
	}
}
