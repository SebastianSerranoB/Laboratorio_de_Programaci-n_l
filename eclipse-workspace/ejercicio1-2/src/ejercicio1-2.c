/*
 ============================================================================
 Name        : ejercicio1-2.c
 Author      : messirve
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 Ejercicio 1-2: ingresar 3 números y mostrar cuál de los tres es el mayor.
Ejemplo:
Si ingresamos 5, 9 y 3 el programa mostrará: “El mayor de los números es el segundo”

 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	setbuf(stdout,NULL);

	int numeroUno;
	int numeroDos;
	int numeroTres;
	int mayorNumero;

	printf("Ingrese el primer numero: ");
	scanf("%d",&numeroUno);
	printf("Ingrese el segundo numero: ");
	scanf("%d",&numeroDos);
	printf("Ingrese el tercer numero: ");
	scanf("%d",&numeroTres);

	if(numeroUno > numeroDos && numeroUno > numeroTres)
	{
		mayorNumero = numeroUno;
	}
	else
	{
		if(numeroDos > numeroTres)
		{
			mayorNumero = numeroDos;
		}
		else
		{
			mayorNumero = numeroTres;
		}
	}
	printf("El mayor numero es: %d",mayorNumero);

	return EXIT_SUCCESS;
}

