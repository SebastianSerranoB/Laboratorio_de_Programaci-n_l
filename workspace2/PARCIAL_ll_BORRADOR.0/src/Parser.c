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
	Empleado* empleadoAux;
	char idAux[5];
	char nombreAux[51];
	char apellidoAux[51];
	char precioAux[10];
	int rtn;
	int cant;
	rtn = -1;

	empleadoAux = Empleado_new();

	if(pFile != NULL && pList != NULL)
	{
		fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",idAux, nombreAux, apellidoAux, precioAux);

		do{
			cant = fscanf(pFile,"%[^,],%[^,],%[^,]%[^\n]\n",idAux, nombreAux, apellidoAux, precioAux);
			if(cant == 4)
			{
				empleadoAux = Empleado_newParametros(idAux, nombreAux, apellidoAux, precioAux);
				if(empleadoAux != NULL)
				{
					ll_add(pList, empleadoAux);
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


int parser_ElementFromBinary(FILE* pFile , LinkedList* pList)
{
	Empleado* auxEmpleado;
	int cant;
	int rtn;
	rtn = -1;

	if(pFile != NULL && pList != NULL)
	{
		do{
			auxEmpleado = Empleado_new();
			cant = fread(auxEmpleado,sizeof(Empleado),1,pFile);
			if(auxEmpleado != NULL && cant == 1)
			{
				ll_add(pList, auxEmpleado);
				rtn = 0;
			}

		}while(feof(pFile) == 0);


	}

	return rtn;
}







