/*
 ============================================================================
 Name        : ejercicio6-2.c
 Author      : Serrano Belloso Sebastian
 DIVISION    : K-1
 Ejercicio 6-2:
Realizar un programa que permita el ingreso de 10 números enteros (positivos y negativos).
Necesito generar un listado de los números positivos de manera creciente y negativos de manera
decreciente. (Como máximo 5 estructuras repetitivas)
Ejemplo:
Listado 1 : 4, 5, 6, 10, 18, 29
Listado 2 : -1,-5,-9,-12
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#define LENGHT 10

int main(void)
{
	setbuf(stdout, NULL);

	int numeros[LENGHT], numerosNegativos[LENGHT], numerosPositivos[LENGHT];
	int i, j, k,l,m,n;
	int aux;
	int contadorNegativos, contadorPositivos, contadorCeros;
	int banderaNegativos, banderaPositivos;

	banderaNegativos = 0, banderaPositivos = 0;
	contadorNegativos = 0; contadorPositivos = 0, contadorCeros = 0;


		for(j=0;j<LENGHT;j++)
		{
			printf("\nIngrese hasta 10 numeros enteros: ");
			scanf("%d", &numeros[j]);
			if(numeros[j] < 0)
			{
				numerosNegativos[j] = numeros[j];
				contadorNegativos++;
				banderaNegativos = 1;
			}
			else
			{
				if(numeros[j] > 0)
				{
					numerosPositivos[j] = numeros[j];
					contadorPositivos++;
					banderaPositivos = 1;
				}
				else
				{
					contadorCeros++;
				}
			}
		 }


	if(banderaNegativos == 1 || banderaPositivos == 1)
	{
		for(i = 0; i < LENGHT - 1; i++)                   //NOTA: posible error al realizar el ordenamiento por burbujeo  de dos indicies con el mismo for.
		{
			for(k = i + 1; k < contadorNegativos; k++)
			{
				if(numerosNegativos[i] < numerosNegativos[k])
				{
					aux = numerosNegativos[i];
					numerosNegativos[i] = numerosNegativos[k];
					numerosNegativos[k] = aux;
				}
			}

			for(l = i + 1; l < contadorPositivos; l++)
			{
				if(numerosPositivos[i] > numerosPositivos[l])
				{
					aux = numerosPositivos[i];
					numerosPositivos[i] = numerosPositivos[l];
					numerosPositivos[l] = aux;
				}
			}
		}
	}


		if(banderaNegativos == 1)
		{
			for(n=0;n<contadorNegativos;n++)
			{
				printf("\nNumeros Negativos: %d",numerosNegativos[n]);
			}

		}
		else
		{
			printf("\nNo se ingresaron numeros negativos.");
		}
		if(banderaPositivos == 1)
		{
			for(m=0;m<contadorPositivos;m++)
			{
				printf("\nNumeros positivos: %d",numerosPositivos[m]);
			}
		}
		else
		{
			printf("\nNo se ingresaron numeros positivos.");
		}



		if(contadorCeros > 0)
		{
			printf("\nLa cantidad de ceros es: %d", contadorCeros);
		}
		else
		{
			printf("\nNo se ingresaron ceros.");
		}

		return EXIT_SUCCESS;
	}

