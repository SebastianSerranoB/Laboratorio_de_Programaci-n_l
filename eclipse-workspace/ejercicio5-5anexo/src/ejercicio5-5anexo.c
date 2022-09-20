/*
 ============================================================================
 Name        : ejercicio5-5anexo.c y 6
 Author      : Serrano Belloso Sebastian
 Version     :
 Copyright   : 
 Description : Hello World in C, Ansi-style
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
	int banderaInicializar;
	banderaInicializar = 0;

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
				muestroPromedio(numeros, CANTIDAD);
			}
			else
			{
				printf("\nDebe ingresar al menos un numero para promediar.(OPCION 2)");
			}
		break;
		}
	}while(opcionIngresada != 6);


	return EXIT_SUCCESS;
}
