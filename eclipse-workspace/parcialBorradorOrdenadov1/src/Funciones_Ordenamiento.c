/*
 * Funciones_Ordenamiento.c
 *
 *  Created on: 3 may 2022
 *      Author: admin
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "Entidades.h"

#include "ABM.h"

#include "Funciones_Informar.h"
#include "Funciones_Listar.h"

#include "Funciones_Get.h"
#include "Funciones_Calculos.h"
#include "Funciones_Ordenamiento.h"


int ordenarPorImporteYTitulo(sAlbum albumes[], int length)
{
	int rtn;
	int i, j;
	rtn = 1;
	sAlbum aux;

	for(i=0;i<length;i++)
	{
		strupr(albumes[i].titulo);
	}

	if(albumes != NULL && length > 0)
	{
		for(i=0;i<length - 1;i++)
		{
			for(j=i+1;j<length;j++)
			{
				if(albumes[i].precio < albumes[j].precio)
				{
					aux = albumes[i];
					albumes[i] = albumes[j];
					albumes[j] = aux;
				}
				else
				{
					if(albumes[i].precio == albumes[j].precio)
					{
						if(strcmp(albumes[i].titulo, albumes[j].titulo) < 0)
						{
							aux = albumes[i];
							albumes[i] = albumes[j];
							albumes[j] = aux;
						}
					}
				}


			}
		}
	}


	return rtn;
}


