/*
 ============================================================================
 Name        : ejercicio1.c
 Author      : messirve
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 Ejercicio 1-1: Ingresar dos números enteros, sumarlos y mostrar el resultado.
Ejemplo:
Si ingresamos 3 y 2 el programa mostrará: “La suma entre 3 y 2 da como resultado 5”
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	setbuf(stdout,NULL);
	int numeroUno;
	int numeroDos;
	int resultado;

	printf("Ingrese el primer numero: ");
	scanf("%d",&numeroUno);
	printf("Ingrese el segundo numero: ");
	scanf("%d",&numeroDos);

	resultado = numeroUno + numeroDos;

	printf("La suma entre %d y %d es de: %d",numeroUno,numeroDos,resultado);

	return 0;
}
