/*
 ============================================================================
 Name        : ejercicio5-8anexo.c
 Author      : Serrano Belloso Sebastian
 Division    : K-1
 ANEXO 5-8:
Modificar la función que calcula el promedio en la opción 4 del Menú, para que devuelva el
resultado del promedio por parámetro por referencia. El retorno de la misma debe indicar si
funcionó correctamente.
/// ESTO ES CON UN PUNTERO
/// TAMBIEN HICE EL ORDENAMIENTO POR BUBBLE SORT
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "anexoCinco.h"

#define CANTIDAD 5

int main(void)
{
	setbuf(stdout, NULL);

	int opcionIngresada;
	int opcionSubmenu;
	int numeros[CANTIDAD];
	int posicion;
	int banderaInicializar, banderaCarga;
	banderaInicializar = 0, banderaCarga = 0;
	float promedio;

	do{
		opcionIngresada = mainMenu();
		switch(opcionIngresada)
		{
		case 1:
			inicializarVector(numeros, CANTIDAD);
			printf("\nVector inicializado en 0.");
			banderaInicializar = 1;
		break;
		case 2:
			cargaAleatoria(numeros, CANTIDAD);
			banderaCarga = 1;
		break;
		case 3:
					do{
					opcionSubmenu = subMenu();
							switch(opcionSubmenu)
							{
								case 1:
										mostrarVector(numeros, CANTIDAD);
								break;
								case 2:
									printf("\nIngrese la posicion del vector a mostrar: ");
									scanf("%d", &posicion);
									while(posicion < 0 && posicion > 4)
									{
										printf("\nError, reingrese una posicion valida: ");
										scanf("%d", &posicion);
									}
									muestroUnNumero(numeros, posicion );
								break;
								case 3:
									printf("\nHas salido del Submenu.");
								break;
							}

					   }while(opcionSubmenu != 3);
		break;
		case 4:
			if(banderaInicializar == 1)
			{
				promedio = muestroPromedio(numeros, CANTIDAD);
				printf("\nEl promedio de todos los numeros es: %.2f", promedio);
			}
			else
			{
				printf("\nDebe ingresar al menos un numero para promediar.(OPCION 2)");
			}
		break;
		case 5:
			if(banderaCarga == 1)
			{
				bubbleSort(numeros, CANTIDAD);
				printf("\nNumeros ordenados.");
			}
			else
			{
				printf("\nError, debe ingresar al menos un numero para ordenarlo.");
			}
		break;
		case 6:
			printf("\n\nHas salido del menu principal.");
		break;
		}
	}while(opcionIngresada != 6);

	return EXIT_SUCCESS;
}
