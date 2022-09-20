/*
 * parser.c
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

//parser echo a medida dependiendo de el tipo y cantidad de atributos de una struct
int parser_FromText(FILE* pFile, LinkedList* lista)
{
	int retorno = -1;
	ePokemon* auxPokemon;

	char bufferNumero[128];
	char bufferNombre[128];
	char bufferTipo[128];
	char bufferTamanio[128];
	char bufferAtaqueCargado[128];
	char bufferValorAtaque[128];
	char bufferEsVarioColor[128];

	//buffer para menu, pie
	//char buffer[300];
	int contador = 0;



	if(pFile != NULL && lista != NULL)
	{
		//lee hasta encontrar el primer \n y da un enter \n
		//fscanf(pFile, "%[^\n]\n", buffer);
		do
		{
			//lee 7 veces(determinado por cant, atributos por struct) las primeras 6 lo hace hasta la coma, el ultimo hasta el \n y luego \n
			if(fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n\n", bufferNumero, bufferNombre, bufferTipo, bufferTamanio, bufferAtaqueCargado, bufferValorAtaque, bufferEsVarioColor) == 7)
			{
				//enviamos como char, los parametros al constructor que luego los convertira
				auxPokemon = Pokemon_newParametros(bufferNumero, bufferNombre, bufferTipo, bufferTamanio, bufferAtaqueCargado, bufferValorAtaque, bufferEsVarioColor);
				if(auxPokemon != NULL)
				{
					if(ll_add(lista, auxPokemon) == 0)
					{
						//contador para la cantidad de elementos cargados, sirve como control
						contador++;
					}
				}
			}

		}while(!feof(pFile));
		//mientras no llegue al final del texto, el cursor
	}

	retorno = contador;


	return retorno;
}

/*int parser_FromText(FILE* pFile , LinkedList* pArrayListPokemon)
{
	int retorno = -1;
	char numero[50];
	char nombre[50];
	char tipo[50];
	char tamanio[50];
	char ataqueCargado[50];
	char valorAtaque[50];
	char esVarioColor[50];
	ePokemon* unPokemon = NULL;
;
	if(pFile != NULL && pArrayListPokemon !=NULL)
	{
		fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n\n",numero,nombre,tipo,tamanio,ataqueCargado,valorAtaque,esVarioColor);

		while(!feof(pFile))
		{
			fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",numero,nombre,tipo,tamanio,ataqueCargado,valorAtaque,esVarioColor);

			unPokemon = pokemon_newParametros(numero,nombre,tipo,tamanio,ataqueCargado,valorAtaque,esVarioColor);

			if(unPokemon != NULL)
			{
				ll_add(pArrayListPokemon, unPokemon);
			}
		}

		retorno = 0;

	}

	return retorno;
}*/
