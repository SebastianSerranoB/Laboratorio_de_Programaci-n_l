/*
 * Funciones_Informar.c
 *
 *  Created on: 3 may 2022
 *      Author: admin
 */



#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "Entidades.h"
#include "Funciones_Informar.h"
#include "Funciones_Get.h"
#include "Funciones_Ordenamiento.h"

/*=======================     INFORMAR      ===================================*/
int informar(sAlbum array[], int lenght)
{
	int rtn,flagOcupado;
	int i, opcionInformar;
	float promedioImportes, acumuladorImportes;
	int contadorAlbumes, contadorAlbumesBajoPromedio, contadorFechaPosterior;
	rtn = 0, flagOcupado = 0, contadorAlbumes = 0, contadorFechaPosterior = 0, contadorAlbumesBajoPromedio = 0;


	if(array != NULL && lenght > 0){
		for(i=0;i<lenght;){
			if(array[i].estado == OCUPADO){
				flagOcupado = 1;
				rtn = 1;
				break;
			}
		}
	}

	if(flagOcupado == 0)
	{
		printf("\nNo se ha encontrado ningun album en lista, ingrese uno(OPCION 1).");
		return rtn;
	}
	else
	{
		do{
				opcionInformar = optionMenu(1, 3, "\n\n====================  INFORMAR  ====================\n\n1- Total y promedio de los importes, y cuántos álbumes no superan ese promedio. \n2- Cantidad de álbumes cuya fecha de publicación es posterior a 31/12/1999. \n3- SALIR AL MENU PRINCIPAL");
				switch(opcionInformar)
				{
					case 1:
						//ESTO HAY QUE METERLO EN UNA FUNCION Y FALTA EL PRINT
						for(i=0;i<lenght;i++)
						{
							if(array[i].estado == OCUPADO)
							{
								acumuladorImportes += array[i].precio;
								contadorAlbumes++;
							}
						}
						promedioImportes = acumuladorImportes / contadorAlbumes;

						for(i=0;i<lenght;i++)
						{
							if(array[i].estado == OCUPADO && array[i].precio < promedioImportes)
							{
								contadorAlbumesBajoPromedio++;
							}
						}
						printf("\nEl total acumulado de importes por album es: %.2f y el promedio total: %.2f", acumuladorImportes, promedioImportes);
						if(contadorAlbumesBajoPromedio > 0)
						{
							printf("\nLa cantidad de precios de album debajo del promedio de importes es: %d", contadorAlbumesBajoPromedio);
						}
						else
						{
							printf("\nNo se ingresaron precios de albums debajo del promedio de importes.");
						}
							break;

					case 2:
						//TODO ESTO A UNA FUNCION
						for(i=0;i<lenght;i++)
						{
							if(array[i].estado == OCUPADO && array[i].fechaAlbum.anio >= 2000)
							{
								contadorFechaPosterior++;
							}
						}

						if(contadorFechaPosterior > 0)
						{
							printf("\nLa cantidad de albumes publicados en el año 2000 o posterior es: %d", contadorFechaPosterior);
						}
						else
						{
							printf("\nNo se ingresaron albumes del año 2000 o posteriores.");
						}
							break;

					case 3:
						printf("\nHas salido al menu principal.");
							break;
				}
			}while(opcionInformar != 3);
	}

	return rtn;
}
