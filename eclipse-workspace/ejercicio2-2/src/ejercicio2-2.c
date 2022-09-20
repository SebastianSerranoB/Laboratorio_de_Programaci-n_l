/*
 ============================================================================
 Name        : ejercicio2-2.c
 Author      : SEBASTIAN SERRANO
 Division	 : K1


 Ingresar 10 números enteros, distintos de cero. Mostrar:
a. Cantidad de pares e impares.
b. El menor número ingresado.
c. De los pares el mayor número ingresado.
d. Suma de los positivos.
e. Producto de los negativos.

 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	setbuf(stdout,NULL);

	int numeroIngresado;

	int contadorNumeros;
	int contadorPares;
	int contadorImpares;
	int contadorPositivos; //para verificar si se ingresaron
	int contadorNegativos; // ""

	int acumuladorPositivos;
	int productoNegativos;

	int banderaMenorNumero;
	int minimoNumero;
	int banderaMayorPar;
	int mayorNumeroPar;

	//inicializo bandera
	banderaMenorNumero = 0;
	banderaMayorPar = 0;

	//inicializo acumuladores
	acumuladorPositivos = 0;

	//inicializo contadores
	contadorPares = 0;
	contadorImpares = 0;
	//para verificar ingreso
	contadorPositivos = 0;
	contadorNegativos = 0;



	productoNegativos = 1;  //esto es una practica correcta?

	contadorNumeros = 0;
	while(contadorNumeros <10)
	{
		//pedimos y verificamos
		printf("Ingrese un numero: ");
		scanf("%d",&numeroIngresado);
		while(numeroIngresado == 0)
		{
			printf("Error, reingrese un numero: ");
			scanf("%d",&numeroIngresado);
		}
		//acumulo positivos
		if(numeroIngresado > 0)
		{
			acumuladorPositivos = acumuladorPositivos + numeroIngresado;
			contadorPositivos++; //verificar si se ingresaron
		}
		//producto negativos
		if(numeroIngresado < 0)
		{
			productoNegativos = productoNegativos * numeroIngresado;
			contadorNegativos++; //verificar si se ingresaron
		}
		//busco el minimo numero
		if(numeroIngresado < minimoNumero || banderaMenorNumero == 0)
		{
			minimoNumero = numeroIngresado;

			banderaMenorNumero = 1;
		}
		//busco pares e impares
		if((numeroIngresado % 2) == 0) // es la manera correcta? si funciona.
		{
			if(numeroIngresado > mayorNumeroPar || banderaMayorPar == 0)
			{
				mayorNumeroPar = numeroIngresado;
				banderaMayorPar = 1;
			}


			contadorPares++;
		}
		else
		{
			contadorImpares++;
		}

		//sumo contador
		contadorNumeros++;
	}


	//Pregunto si se ingresaron e informo suma positivos
	if(contadorPositivos > 0)
	{
		printf(" La suma de numeros positivos es de: %d",acumuladorPositivos);

	}
	else
	{
		printf(" No se ingresaron numeros positivos.");
	}
	//Pregunto si se ingresaron e informo producto negativos
	if(contadorNegativos > 0)
	{
		printf(" El producto de numeros negativos es de: %d",productoNegativos);
	}
	else
	{
		printf(" No se ingresaron numeros negativos.");
	}
	//informo el menor numero
	printf(" El menor numero ingresado es: %d",minimoNumero);
	//informo cantidad de pares e impares
	printf("La cantidad de numeros pares es de: %d",contadorPares);
	printf("La cantidad de numeros impares es de: %d",contadorImpares);
	//pregunto si existe e informo el mayor numero par
	if(contadorPares > 0)
	{
		printf(" El mayor numero par es: %d",mayorNumeroPar);
	}
	else
	{
		printf(" No se ingresaron numeros pares.");
	}


	return EXIT_SUCCESS;
}
