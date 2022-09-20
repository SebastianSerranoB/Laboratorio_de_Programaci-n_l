/*
 ============================================================================
 Name        : ejercicio5-3.c
 Author      : Serrano Belloso Sebastian
 Division	 : K-1
 Ejercicio 5-3:
Realizar un programa que permita el ingreso de 10 números enteros distintos de cero. La carga
deberá ser aleatoria (todos los elementos se inicializan en cero por default). Determinar el
promedio de los positivos, y del menor de los negativos la suma de los antecesores (Según la recta
numérica de los reales, hasta llegar a cero).
Utilizar funciones y vectores.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#define CANT 10
int main(void)
{
	setbuf(stdout, NULL);

	int numeroIngresado[CANT];
	int i, posicion;
	char respuesta;
	int j;
	int acumuladorPositivos = 0;
	int sumaNegativos;
	sumaNegativos = 0;
	int contadorPositivos = 0;
	int menorNegativoFlag = 0;
	int menorNegativo;
	float promedioPositivos;

	j = 0;


	for(i=0;i<CANT;i++)    //inicializamos los valores del vector en 0 recorriendolo con un for e igualandolo a 0 para cada posicion del indice.
	{
		numeroIngresado[i] = 0;
	}

	do{
		j++;
		printf("\nIngrese la posicion: ");
		scanf("%d", &posicion);

		printf("\nIngrese el numero: ");
		scanf("%d", &numeroIngresado[posicion]);

		if(numeroIngresado[posicion] > 0)
		{
			contadorPositivos++;
			acumuladorPositivos += numeroIngresado[posicion];
		}
		else
		{
			if(numeroIngresado[posicion] < menorNegativo || menorNegativoFlag == 0)
			{
				menorNegativo = numeroIngresado[posicion];
				menorNegativoFlag = 1;
			}
			sumaNegativos += numeroIngresado[posicion];
		}

		printf("\n¿Desea ingresar otro numero?");
		fflush(stdin);
		scanf("%c", &respuesta);
	}while(respuesta == 'S' && j < CANT);


	promedioPositivos = (float)acumuladorPositivos / contadorPositivos;
	sumaNegativos = sumaNegativos + menorNegativo * -1;

	printf("\n el promedio de positivos es: %.2f", promedioPositivos);
	printf("\n la suma de numeros negativos es: %d", sumaNegativos);
	return EXIT_SUCCESS;
}
