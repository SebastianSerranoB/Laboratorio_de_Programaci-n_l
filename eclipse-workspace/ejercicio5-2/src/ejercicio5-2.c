/*
 ============================================================================
 Name        : ejercicio5-2.c
 Author      : Serrano Sebastian
 Division     : K-1
Ejercicio 5-2:
Pedir el ingreso de 10 números enteros entre -1000 y 1000. Determinar:
a) Cantidad de positivos y negativos.
b) Sumatoria de los pares.
c) El mayor de los impares.
d) Listado de los números ingresados.
e) Listado de los números pares.
f) Listado de los números de las posiciones impares.
Anexo 5-2
g) Los números que se repiten
h) Los positivos creciente y los negativos de manera decreciente
Se deberán utilizar funciones y vectores.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#define CANT 10

int main(void)
{
	setbuf(stdout, NULL);
	int vec[CANT],i;
	int j = 0, k = 0;
	int sumaPares = 0;
	int mayorImpar, banderaImpar = 0;

	for(i = 0; i < CANT; i++)
	{
		printf("\nIngrese un numero entero: ");
		scanf("%d", &vec[i]);
		while(vec[i] < -1000 || vec[i] > 1000)
		{
			printf("Error, reingrese un entero(> -1000 && < 1000): \n");
			scanf("%d", &vec[i]);
		}

		if(vec[i]> -1)
		{
			j++;
		}
		else
		{
			k++;
		}

		if(vec[i] % 2 == 0)
		{
			sumaPares += vec[i];
		}
		else
		{
			if(vec[i] > mayorImpar || banderaImpar == 0)
			{
				mayorImpar = vec[i];
				banderaImpar = 1;
			}
		}

	}

	for(i = 0; i < CANT ;i++)
	{
		printf("%d\n", vec[i]);
	}


	return EXIT_SUCCESS;
}
