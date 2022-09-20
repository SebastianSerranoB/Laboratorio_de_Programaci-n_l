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

int subMenu(void)
{
	int opcionIngresada;

	printf("\n\n1-Mostrar todos los numeros.\n2-Mostrar un numero\n3-Salir del subMenu");
	printf("\n\nOpcion ingresada: ");
	scanf("%d", &opcionIngresada);
	while(opcionIngresada < 1 || opcionIngresada > 3)
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

void muestroUnNumero(int vector[], int posicion)
{
	printf("\nEn el indice %d, el numero es: %d",posicion, vector[posicion]);
}

void mostrarVector(int vector[], int cantidad)
{
	int i;
	for(i=0;i<cantidad;i++)
	{
		muestroUnNumero(vector, i);
	}
}

void muestroPromedio(int vector[], int cantidad)
{

	int i, acumulador;
	float promedio;
	acumulador = 0;

	for(i=0;i<cantidad;i++)
	{
		acumulador += vector[i];
	}
	if(acumulador != 0)
	{
		promedio = (float)acumulador / cantidad;
		printf("\nEl promedio total es: %.2f", promedio);
	}
	else
	{
		printf("\nError, debe ingresar al menos un numero.(OPCION 2)");
	}
}


