/*
 ============================================================================
 Name        : ejercicio3-2.c
 Author      : SEBASTIAN SERRANO
  DIVISION 	K-1
Ejercicio 3-2:
Crear una función que permita determinar si un número es par o no. La función retorna 1 en caso
afirmativo y 0 en caso contrario. Probar en el main.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int parOImpar(int);

int main(void)
{
	setbuf(stdout, NULL);

	int numeroIngresado;
	int resultado;

	printf("\nIngrese un numero: ");
	scanf("%d", &numeroIngresado);
	while(numeroIngresado == 0)
	{
		printf("Error, reingrese un numero distinto de 0, lo discutimos mas tarde...");
		scanf("%d", &numeroIngresado);
	}

	resultado = parOImpar(numeroIngresado);
	printf("El numero %d es: %d", numeroIngresado, resultado);  //el print es 1 para afirmativo y 0 para negativo, se puede hacer mas bonito
	// se puede hacer un dowhile para preguntar si quiere ingresar otro

	return EXIT_SUCCESS;
}

int parOImpar(int a)
{
	if((a % 2) == 0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
