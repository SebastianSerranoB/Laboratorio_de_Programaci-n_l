/*
 * controller.c
 *
 *  Created on: 31 ago 2022
 *      Author: admin
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "LinkedList.h"
#include "Pokemon.h"
#include "controller.h"
#include "alumno.h"
#include "parser.h"


int controller_loadFromText(char* path , LinkedList* listaEntidad)
{
	int retorno = -1;

	FILE* pArchivo = NULL;

	if(listaEntidad != NULL && path != NULL)
	{
		pArchivo = fopen(path,"r");

		if(pArchivo != NULL)
		{
			if(parser_FromText(pArchivo, listaEntidad) > -1){
				printf("\nLista cargada con exito!");
				retorno = 0;
			}else{
				printf("\nError, el archivo fue abierto pero no pudo leerse.");
			}

		}
		else
		{
			printf("\nError! no pudo leerse el archivo.");
		}

		fclose(pArchivo);
	}

	return retorno;
}

int controller_List(LinkedList* pListaPokemon)
{
	int retorno;
	retorno = -1;

	if(printList(pListaPokemon) == 0)
	{
		retorno = 0;
		printf("\nListado con exito!");
	}
	else{
		printf("\nDebe haber al menos un elemento en lista para mostrarla.");
	}


	return retorno;
}

int controller_map(LinkedList* pArrayList)
{
	int retorno = -1;

	if(pArrayList != NULL && ll_len(pArrayList) > 0)
	{
		//mi map function clona la lista enviada como parametro y la retorna mapeado,
		//en este caso la igual a la original por comodidad, sino genero una nueva y retorno linked en el controller
		pArrayList = ll_map(pArrayList,Pokemon_mapearValorDeAtaque);
		printf("\nLista Mapeada con exito");
		retorno = 0;
	}else{
		printf("\nError, asegurese de que existan elementos en lista para mapear.");
	}

	return retorno;
}
