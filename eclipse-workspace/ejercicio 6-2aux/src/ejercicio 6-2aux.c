/*
 ============================================================================
 Name        : ejercicio.c
 Author      : Serrano Belloso Sebastian
 Version     :
 Copyright   : 
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#include <stdio.h>
#include <stdlib.h>
#define CANT 10
int main(void)
{
	setbuf(stdout, NULL);
	int lista[CANT],listaPositiva[CANT], listaNegativa[CANT];
	int i;
	int contadorPositivos = 0, contadorNegativos = 0;

	//for para inicializar en 0 las listas de contador negativos y positivos
	for(i=0;i<CANT;i++)
	{
		printf("\nIngrese hasta 10 numeros enteros: ");
		scanf("%d", &lista[i]);
		if(lista[i] < 0)
		{
			listaNegativa[contadorNegativos] = lista[i];
			contadorNegativos++;
		}
		else
		{
			if(lista[i] > 0)
			{
				listaPositiva[contadorPositivos] = lista[i];
				contadorPositivos++;
			}
		}
	}

	for(i=0;i<CANT;i++)
	{
		//if(lista) preguntar si es distinto de 0
		printf("\nEl numero es: %d", lista[i]);
		printf("\nEl negativo: %d", listaNegativa[i]);
		printf("\nEl positivo: %d", listaPositiva[i]);
	}


	return EXIT_SUCCESS;
}
