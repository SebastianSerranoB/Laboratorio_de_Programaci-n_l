/*
 ============================================================================
 Name        : SERRANO SEBASTIAN
 DIVISION    : K-1
 EJERCICIO REPASO 2-2
  Ejercicio 2-2:
Realizar un programa que permita el ingreso de 10 números enteros. Determinar el promedio de los positivos,
la cantidad de ceros y del menor de los negativos la suma de los antecesores. //voy a interpretarlo como  la suma de todos menos el menor ingresado;

Nota:
Utilizar la función del punto anterior y desarrollar funciones para resolver los procesos que están resaltados.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int signoEntero(int a);
float promediar(int a);
//contador y acumulador global para positivos
int j = 0, acumuladorPositivos = 0;

int sumarNegativos(int a);
int acumuladorNegativos = 0, banderaMenorNegativos = 0;

int contadorCeros(void);
int k = 0;



int main(void)
{
	setbuf(stdout, NULL);

	int i,numeroIngresado;
	int valorEntero;
	float promedioPositivos;
	int resultadoNegativos,l=0;
	int cantidadDeCeros;


	for(i=0;i<10;i++)
	{
		printf("Ingrese un numero entero: \n");
		scanf("%d", &numeroIngresado);

		valorEntero = signoEntero(numeroIngresado);
		if(valorEntero == 1)
		{
			promedioPositivos = promediar(numeroIngresado);
		}
		else
		{
			if(valorEntero == -1)
			{
				l++;
				resultadoNegativos = sumarNegativos(numeroIngresado);
			}
			else
			{
				cantidadDeCeros = contadorCeros();
			}
		}
	}

	if(j > 0)
	{
		printf("El promedio de enteros positivos es: %3.2f\n", promedioPositivos);
	}
	else
	{
		printf("No se ingresaron enteros positivos.\n");
	}

	if(k > 0)
	{
		printf("La cantidad de ceros es de: %d\n", cantidadDeCeros);
	}
	else
	{
		printf("No se ingresaron ceros.\n");
	}

	if(l > 0)
	{
		printf("La suma de negativos exceptuando el menor ingresado es: %d\n", resultadoNegativos);
	}
	else
	{
		printf("No se ingresaron enteros negativos.\n");
	}

	return EXIT_SUCCESS;
}

//funcion devuelve valor del signo
int signoEntero(int a){
	if(a > 0){
		return 1;
	}
	else{
		if( a < 0){
			return -1;
		}
		else{
			return 0;
		}
	}
}

//float promedio positivos
float promediar(int a)
{
	float promedio;

	j++;
	acumuladorPositivos += a;

	promedio = (float)acumuladorPositivos / j;
	return promedio;
}

int sumarNegativos(int a)
{
	int menorNegativo;
	acumuladorNegativos += a;

	if(a < menorNegativo || banderaMenorNegativos == 0) // como evito este tipo de warnings(en el tp no tiene que haber), no deberia inicializar minimos ni maximos
	{
		menorNegativo = a;
		banderaMenorNegativos = 1;
	}
	return acumuladorNegativos + (menorNegativo * -1);
}

int contadorCeros(void)
{
	k++;
	return k;
}
