/*
 ============================================================================
 Name        : repaso2-2.c
 Author      : Serrano Sebastian
 Version     :Division K-1
 Ejercicio 2-2:
Realizar un programa que permita el ingreso de 10 números enteros. Determinar el promedio de los positivos, la cantidad de ceros y del menor de los negativos la suma de los antecesores. //voy a interpretarlo como  la suma de todos menos el menor ingresado;

Nota:
Utilizar la función del punto anterior y desarrollar funciones para resolver los procesos que están resaltados.

 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int entero(int a);
float promediar(int a, int b);
int contador(int a);
int sumoNegativos(int a);


int main(void)
{
	setbuf(stdout, NULL);

	int enteroIngresado, signoEntero;
	float promedioPositivos;
	int contadorPositivos = 0, acumuladorPositivos = 0;
	int contadorCeros = 0, totalCeros;
	int resultadoNegativos, contadorNegativos = 0;
	printf("Ingrese un numero entero: \n");
	scanf("%d", &enteroIngresado);

	signoEntero = entero(enteroIngresado);
	printf("El numero %d tiene un signo: %d (1 para positivo, -1 negativo y 0 para 0)", enteroIngresado, signoEntero);
	if(signoEntero == 1)
	{
		contadorPositivos++;
		acumuladorPositivos += enteroIngresado;
		promedioPositivos = promediar(acumuladorPositivos, contadorPositivos);
	}
	else
	{
		if(signoEntero == -1)
		{
			contadorNegativos++;
			resultadoNegativos = sumoNegativos(enteroIngresado);
		}
		else
		{
			totalCeros = contador(contadorCeros);
		}
	}



	if(contadorPositivos > 0)
	{
		printf("El promedio de numeros positivos es de: %3.2f\n", promedioPositivos);
	}
	else
	{
		printf("\nNo se ingresaron enteros positivios.");
	}

	if(totalCeros > 0)
	{
		printf("\nLa cantidad de ceros es de: %d\n", totalCeros);
	}
	else
	{
		printf("\nNo se ingresaron ceros.");
	}

	if(contadorNegativos > 0)
	{
		printf("\nLa acumulacion de negativos menos el menor de ellos es: %d\n", resultadoNegativos);
	}
	else
	{
		printf("No se ingresaron enteros negativos.");
	}


	return EXIT_SUCCESS;
}

int sumoNegativos(int a)
{
	int banderaMenorNegativo = 0,menorNegativo, acumuladorNegativos = 0;

	if(a < menorNegativo || banderaMenorNegativo == 0) //entra por la bandera, e inicializa el menor.
	{
		menorNegativo = a;

		banderaMenorNegativo = 1;
	}

	acumuladorNegativos += a;
	acumuladorNegativos = acumuladorNegativos + (menorNegativo * -1);
	return acumuladorNegativos;


}

int contador(int a)
{
	a++;
	return a;
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

float promediar(int a, int b)
{
	float promedio;
	promedio = (float)a / b;
	return promedio;
}

