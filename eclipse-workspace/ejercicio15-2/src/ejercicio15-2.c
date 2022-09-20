/*
 ============================================================================
 Name        : ejercicio15-2.c
 Author      : Serrano Belloso Sebastian
 Version     : 	Division k-1
 Copyright   : 
 Description : Hello World in C, Ansi-style

 Ejercicio 15-2:
Realizar una función que reciba como parámetro un puntero a entero. La función le pedirá al
usuario que cargue un valor por medio del puntero. Retornará si pudo cargarlo o no.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int getInteger(int* punteroNumero);

int main(void) {
	setbuf(stdout, NULL);

	int* pNumero;
	int numero = -1;

	pNumero = &numero;
	printf("El numero previo era: %d", *pNumero);

	getInteger(pNumero);

	printf("El numero ingresado es: %d", *pNumero);


	return EXIT_SUCCESS;
}


int getInteger(int* punteroNumero)
{
	int rtn, auxiliar;
	rtn = 0;

	if(punteroNumero != NULL)
	{
		printf("\nIngrese un numero entero: ");
		scanf("%d", &auxiliar);      									//ES POSIBLE PEDIR EL INGRESO DE UN DATO DIRECTAMENTE A *PUNTERO?
		*punteroNumero = auxiliar;
		rtn = 1;
	}

	return rtn;
}
