/*
 * Controller.c
 *
 *  Created on: 28 jun 2022
 *      Author: admin
 */

#ifndef CONTROLLER_C_
#define CONTROLLER_C_

#include <stdio.h>
#include <stdlib.h>

#include "LinkedList.h"
#include "Controller.h"
#include "Parser.h"
#include "Entidades.h"
#include "FuncionesAlumno.h"

int controller_loadFromText(char* path , LinkedList* pList)
{
	FILE* pFile;
    int rtn;
    rtn = -1;

    if(path != NULL && pList != NULL)
    {
    	pFile = fopen(path, "r");

    	if(parser_ElementFromText(pFile, pList) == 0)
    	{
    		printf("\nLISTA CARGADA EXITOSAMENTE!");
    		rtn = 0;
    	}
    	else
    	{
    		printf("\nERROR, NO PUDO LEERSE EL ARCHIVO.");
    	}

    	fclose(pFile);
    }
    else
    {
    	printf("\nERROR...");
    }

    return rtn;
}




int controller_saveAsText(char* path , LinkedList* pList)
{
	FILE* pFile = NULL;
	int rtn;
	rtn = -1;

	if(path != NULL && pList != NULL && ll_len(pList) > 0)
	{
		pFile = fopen(path,"w");
		if(pFile != NULL)
		{
			if(guardar_texto(pFile, pList) == 0 )
			{
				printf("\nARCHIVO DE TEXTO GUARDADO EXITOSAMENTE.");
				rtn = 0;
			}
			fclose(pFile);
		}
		else
		{
			printf("\ERROR, EL ARCHIVO NO FUE GUARDADO.");
		}
	}
	else
	{
		printf("\nERROR, VERIFIQUE QUE EXISTAN ELEMENTOS EN LISTA.");
	}


    return rtn;
}


int controller_sortElements(LinkedList* pList)
{
	int rtn;

	rtn = -1;

	if(pList != NULL && ll_len(pList) > 1)
	{
		rtn = 0;


		printf("\nOrdenando lista.. aguarde un segundo.");
		ll_sort(pList, ordenarPorCuota, 1);
		printf("\nLista ordenada por ID exitosamente.");

	}
	else
	{
		printf("\nDebe cargar al menos dos elementos para ordenarlos.");
	}


    return rtn;
}

int controller_ListElements(LinkedList* pList)
{
    int rtn;
    rtn = -1;

    if(pList != NULL)
    {
    	if(listAllElements(pList) == 0)
		{
    		rtn = 0;
		}
    	else
    	{
    		printf("\nNO EXISTEN ELEMENTOS EN LISTA.");
    	}
    }
    else
    {
    	printf("\nError.. lista no valida.");
    }

    return rtn;
}

int controller_mapList(LinkedList* pList)
{
	LinkedList* listaMapeada = NULL;
	FILE* pFile = NULL;
	int rtn;
	rtn = -1;

	pFile = fopen("dataMaped.txt","w");

	if(pList != NULL && ll_len(pList) > 0)
	{
		listaMapeada = ll_map(pList, Empleado_Aumento);
		if(listaMapeada != NULL && pFile != NULL)
		{
			//listAllElements(listaMapeada);
			printf("\nMapeado con exito;");
			if(guardar_texto(pFile, listaMapeada) == 0)
			{
				printf("\nLa lista mapeada ha sido guardada en un archivo txt.");
			}
			free(listaMapeada);
			rtn = 0;
		}
	}
	else
	{
		printf("\nError.. lista no valida.");
	}


	return rtn;
}





#endif /* CONTROLLER_C_ */
