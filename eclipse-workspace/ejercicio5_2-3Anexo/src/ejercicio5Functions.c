/*
 * ejercicio5Functions.c
 *
 *  Created on: 17 abr 2022
 *      Author: admin
 */

#include <stdlib.h>
#include <stdio.h>



void inicializarVector(int vector[], int cantidad)
{
	int i;

	for(i=0;i<cantidad;i++)
	{
		vector[i] = 0;
	}

}

void cargaSecuencial(int vector[], int cantidad)
{
	int i;

	for(i=0;i<cantidad;i++)
	{
		printf("\nIngrese un numero: ");
		scanf("%d", &vector[i]);
	}

}
