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

/*void muestroPromedio(int vector[], int cantidad)
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
}*/

float muestroPromedio(int vector[], int cantidad)
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
		}
		else
		{
			printf("\nError, debe ingresar al menos un numero.(OPCION 2)");
		}

	return promedio;
}

void bubbleSort(int vector[], int cantidad)
{
	int i,j,aux;                                   //declaro una variable(i) que estara a la izquierda y una var(j) que estara a la derecha
													//COMPARO DE IZQUIERDA  A DERECHA, de manera incremental ,
	for(i=0;i<cantidad-1;i++)               //Como i esta a la izquierda, no tiene sentido que llegara hasta el final de cantidad(5) y quisiera comparar la posicion 4 con la 5(recordemos que el vector es 0,1,2,3,4)
	{									//el for de i inicia, j completa sus vueltas, y recien comienza la segunda de i, j da toda la vuelta, comienza la tercera de i, etc... compara la posicion i para todas las que estan a su derecha
		for(j=i+1;j<cantidad;j++)          //j=i+1 , no tendria sentido comparar el valor de un vector en el mismo indice, por eso sumandole 1 a i, la j es el indice consecuente ,
		{
			if(vector[i] > vector[j])     // i > j, si el de la izquierda es mayor a la derecha los intercambiamos(swap) si cambiamos el ">" por "<" ordenamos de manera decreciente, es decir, mayor a menor.
			{
				aux = vector[i];               //variable auxiliar guarda el valor del vector en la posicion i para que esta no se pierda al pasar el valor a la posicion j;
				vector[i] = vector[j];        //El valor en posicion j, pasa a la posicion i.
				vector[j] = aux;        //en la posicion j guardo el valor que antes del swap estaba en la posicion i.
			}
		}
	}
}

