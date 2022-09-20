/*
 ============================================================================
 Name        : probandoPunteross.c
 Author      : Serrano Belloso Sebastian
 Version     :
 Copyright   : 
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int suma(int numeroUno, int numeroDos, int* pResultado);

int main(void) {
	setbuf(stdout, NULL);

	int* pResultado;
	int resultado;
	int numeroUno;
	int numeroDos;

	numeroUno = 25;
	numeroDos = 5;

	pResultado = &resultado;
	//*pResultado = 1;  es indistinto
	resultado = 1;

	printf("ANTES: %d", resultado);
	suma(numeroUno, numeroDos, pResultado);
	printf("\nDESPUES: %d", resultado);



	return EXIT_SUCCESS;
}

int suma(int numeroUno, int numeroDos, int* pResultado)
{
	int retorno;
	retorno = 0;

	if(pResultado != NULL)
	{
		*pResultado = numeroUno + numeroDos;
		retorno = 1;
	}


	return retorno;
}
