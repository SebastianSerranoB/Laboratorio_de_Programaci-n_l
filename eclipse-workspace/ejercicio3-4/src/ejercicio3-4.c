/*
 ============================================================================
 Name        : ejercicio3-4.c
 Author      : SEBASTIAN SERRANO
 Version     : DIVISION K-1
 Ejercicio 3-4:
Especializar la función anterior para que permita validar el entero ingresado en un rango
determinado.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int pidoEntero(void);

int main(void)
{
	setbuf(stdout, NULL);

	int muestroRetorno;


	//lo asigna aunque no tenga valor, asumo que es porque comparte el tipo de dato(int)
	muestroRetorno = pidoEntero();
	printf("\nMuestro el entero retornado: %d",muestroRetorno);



	return EXIT_SUCCESS;
}

int pidoEntero(void)
{
	int enteroRetornado;
	printf("Ingrese un entero: ");
	scanf("%d", &enteroRetornado);
	while(enteroRetornado < 0 || enteroRetornado > 100)
	{
		printf("\nError, reingrese el entero en un rango de 0 a 100: ");
		scanf("%d", &enteroRetornado);
	}

	return enteroRetornado;
}
