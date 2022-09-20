/*
 ============================================================================
 Name        : repaso2-1.c
 Author      :Serrano Sebastian
 Division   :K-1
 Ejercicio 2-1:
Crear una función que reciba como parámetro un numero entero. La función retornara 1 en caso de que sea positivo,
 -1 en caso de que sea negativo y 0 en caso de que sea 0. Realizar la prueba lógica de la función en el main.

 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int entero(int a);

int main(void)
{
	setbuf(stdout, NULL);

	int enteroIngresado, signoEntero;

	printf("Ingrese un numero entero: \n");
	scanf("%d", &enteroIngresado);

	signoEntero = entero(enteroIngresado);
	printf("El numero %d tiene un signo: %d (1 para positivo, -1 negativo y 0 para 0)", enteroIngresado, signoEntero);



	return EXIT_SUCCESS;
}

int entero(int a)
{
	int signo;

	if(a > 0)
	{
		signo = 1;
	}
	else
	{
		if(a < 0)
		{
			signo = -1;
		}
		else
		{
			signo = 0;
		}
	}

	return signo;
}
