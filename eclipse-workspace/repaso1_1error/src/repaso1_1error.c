/*
 ============================================================================
 Name        : repaso1_1error.c
 Author      :SEBASTIAN SERRANO
 Version     :K-1

 ============================================================================
 */
//SOLUCIONADO, MIRAR REPASO 1_1, ESTE PROGRAMA SI FUNCIONA, EL PROBLEMA ESTABA EN DONDE ESCRIBIAMOS EN LA CONSOLA, "\n" Y ESPACIO despues del s o n:" ") nos solucionaron la vida
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	setbuf(stdout, NULL);

	char respuesta;

	int numeroIngresado;
	int acumuladorPositivos;
	int acumuladorNegativos;
	int contadorPositivos;
	int contadorNegativos;

	int promedioPositivos;
	int promedioNegativos;


	acumuladorPositivos = 0;
	acumuladorNegativos = 0;
	contadorPositivos = 0;
	contadorNegativos = 0;

	respuesta = 's';
	while(respuesta == 's')
	{
		printf("Ingrese un numero entero: ");
		scanf("%d", &numeroIngresado);
		if(numeroIngresado == 0)
		{
			printf("Ingrese un numero entero distinto de 0:");
			scanf("%d", &numeroIngresado);
		}
		else
		{
			if(numeroIngresado > 0)
			{
				acumuladorPositivos = acumuladorPositivos + numeroIngresado;
				contadorPositivos++;
			}
			else
			{
				acumuladorNegativos = acumuladorNegativos + numeroIngresado;
				contadorNegativos++;
			}
		}


		printf("¿Desea ingresar otro numero: ? s o n");
		fflush(stdin);
		scanf("%c", &respuesta);
	}


	if(contadorPositivos > 0)
	{
		promedioPositivos = acumuladorPositivos / contadorPositivos;
		printf("El promedio de numeros positivos es: %d ", promedioPositivos);
	}
	else
	{
		printf("No se ingresaron numeros positivos.");
	}

	if(contadorNegativos > 0)
	{
		promedioNegativos = acumuladorNegativos / contadorNegativos;
		printf("El promedio de negativos es: %d", promedioNegativos);
	}
	else
	{
		printf("No se ingresaron numeros negativos.");
	}


	return EXIT_SUCCESS;
}
