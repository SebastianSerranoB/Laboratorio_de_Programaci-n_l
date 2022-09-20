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
	FILE* pFile = NULL;
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


int controller_loadFromBinary(char* path , LinkedList* pList)
{
	FILE* pFile = NULL;
	int rtn;
	rtn = -1;

	if(path != NULL && pList != NULL)
	{
		pFile = fopen(path, "rb");
		if(parser_ElementFromBinary(pFile, pList) == 0)
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
		printf("\nEL ARCHIVO NO EXISTE!");
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

int controller_saveAsBinary(char* path , LinkedList* pList)
{
	FILE* pFile = NULL;
	Empleado* auxEmpleado = NULL;
	int i;
	int rtn;

	rtn = -1;

	if(path != NULL && pList != NULL && ll_len(pList) > 0)
	{
		pFile = fopen(path,"wb");
		if(pFile != NULL)
		{
			for(i=0;i<ll_len(pList);i++)
			{
				auxEmpleado = (Empleado*)ll_get(pList, i);
				if(auxEmpleado != NULL)
				{
					fwrite(auxEmpleado,sizeof(Empleado),1,pFile);
				}
			}

			rtn = 0;
			printf("\nARCHIVO GUARDADO EXITOSAMENTE EN BINARIO.");
			fclose(pFile);
		}
		else
		{
			printf("\ERROR, NO SE GUARDO EL ARCHIVO.");
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
	int menuOpcion;
	rtn = -1;

	if(pList != NULL && ll_len(pList) > 1)
	{
		rtn = 0;
		do{
			menuOpcion = printMenu(1, 5, "\n==========================   MENU ORDENAR  =========================="
										"\n1- ORDERNAR POR NOMBRE\n2- ORDENAR POR APELLIDO\n3- ORDENAR POR PRECIO\n4- ORDENAR POR ID\n\n5- SALIR"
										"\n=====================================================================\n");
			switch(menuOpcion)
			{
			case 1:
				printf("\nOrdenando lista.. aguarde un segundo.");
				ll_sort(pList, ordenarPorNombre, 1);
				printf("\nLista ordenada por nombre exitosamente.");
				break;
			case 2:
				printf("\nOrdenando lista.. aguarde un segundo.");
				ll_sort(pList, ordenarPorApellido, 1);
				printf("\nLista ordenada por apellido exitosamente.");
				break;
			case 3:
				printf("\nOrdenando lista.. aguarde un segundo.");
				ll_sort(pList, ordenarPorPrecio, 0);
				printf("\nLista ordenada por precio exitosamente.");
				break;
			case 4:
				printf("\nOrdenando lista.. aguarde un segundo.");
				ll_sort(pList, ordenarPorId, 1);
				printf("\nLista ordenada por ID exitosamente.");
				break;
			case 5:
				printf("\nSaliendo al menu principal.");
				break;
			}

		}while(menuOpcion != 5);

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

	pFile = fopen("dataMapeda.txt","w");

	if(pList != NULL && ll_len(pList) > 0)
	{
		listaMapeada = ll_map(pList, Empleado_Aumento);
		if(listaMapeada != NULL && pFile != NULL)
		{
			//listAllElements(listaMapeada);
			printf("\nMapeado con exito;");
			if(guardar_texto(pFile, listaMapeada) == 0)
			{
				printf("\nLa lista filtrada ha sido guardada en un archivo txt.");
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

int controller_filterList(LinkedList* pList)
{
	LinkedList* listaFiltrada = NULL;
	FILE* pFile = NULL;
	int rtn;
	rtn = -1;

	pFile = fopen("dataFilter.txt","w");


	if(pList != NULL && ll_len(pList) > 0)
	{
		listaFiltrada =	ll_filter(pList, Empleado_descuento);

		if(listaFiltrada != NULL && pFile != NULL)
		{
			//listAllElements(listaFiltrada);


			printf("\nEl descuento fue aplicado exitosamente.");
			if(guardar_texto(pFile, listaFiltrada) == 0)
			{
				printf("\nLa lista filtrada ha sido guardada en un archivo txt.");

			}
			free(listaFiltrada);
			rtn = 0;
		}
	}
	else
	{
		printf("\nDebe cargar al menos dos elementos para filtrar.");
	}


	return rtn;
}





#endif /* CONTROLLER_C_ */
