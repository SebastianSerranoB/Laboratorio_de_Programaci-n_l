/*
 * Parser.c
 *
 *  Created on: 28 jun 2022
 *      Author: admin
 */

#include "Parser.h"
#include "Entidades.h"
#include <stdio.h>
#include "LinkedList.h"

int parser_ElementFromText(FILE* pFile , LinkedList* pList)
{
	eComputer* eComputerAux;
	char idAux[10];
	char descripcionAux[51];
	char idTipo[10];
	char precioAux[20];
	char cuotasAux[10];
	int rtn;
	int cant;
	rtn = -1;
	cant = 0;

	eComputerAux = eComputer_new();


	if(pFile != NULL && pList != NULL)
	{
		fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n",idAux, descripcionAux, precioAux, idTipo, cuotasAux);

		do{
			cant = fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n",idAux, descripcionAux, precioAux, idTipo, cuotasAux);
			if(cant == 5)
			{
				eComputerAux = eComputer_newParametros(idAux, descripcionAux, precioAux, idTipo,cuotasAux);

				if(eComputerAux != NULL)
				{
					ll_add(pList, eComputerAux);
					rtn = 0;
				}
			}
			else
			{
				break;
			}

		}while(feof(pFile) == 0);
	}

    return rtn;
}










