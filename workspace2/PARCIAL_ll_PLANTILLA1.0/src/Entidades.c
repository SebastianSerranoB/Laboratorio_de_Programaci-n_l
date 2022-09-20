/*
 * Entidades.c
 *
 *  Created on: 28 jun 2022
 *      Author: admin
 */

#include "Entidades.h"
#include "LinkedList.h"
#include "FuncionesAlumno.h"
#include  <stdio.h>
#include <stdlib.h>
#include <string.h>

//================= CONSTRUCTORES ==========================//
eComputer* eComputer_new()
{
	eComputer* newComputer;

	newComputer = (eComputer*)malloc(sizeof(eComputer)*1);
	if(newComputer != NULL)
	{
		strcpy(newComputer->descripcion,"");
		newComputer->id = -1;
		newComputer->idTipo = -1;
		newComputer->precio = -1;
		newComputer->cuotas = -1;

	}

	return newComputer;
}

eComputer* eComputer_newParametros(char* idStr,char* descripcion,char* precio,char* idTipo, char* cuotas)
{
	eComputer* newComputer = NULL;
	eComputer* rtn = NULL;


	newComputer = eComputer_new();
	if(newComputer != NULL)
	{

		eComputer_setCuotas(newComputer, atof(cuotas));
		eComputer_setPrecio(newComputer, atof(precio));
		eComputer_setIdTipo(newComputer, atoi(idTipo));
		eComputer_setId(newComputer, atoi(idStr));
		eComputer_setDescripcion(newComputer, descripcion);


		rtn = newComputer;
	}
	else
	{
		eComputer_delete(newComputer);
	}




	return rtn;
}




//================ SETTERS/GETTERS =========================//
int eComputer_setId(eComputer* this,int id)
{
	int rtn;
	rtn = -1;


	if(this != NULL && id > 0)
	{
		this->id = id;


		rtn = 0;
	}

	return rtn;
}

int eComputer_getId(eComputer* this,int* id)
{
	int rtn;
	rtn = -1;


	if(this != NULL && id != NULL)
	{
		*id = this->id;

		rtn = 0;
	}

	return rtn;
}

int eComputer_setIdTipo(eComputer* this,int idTipo)
{
	int rtn;
	rtn = -1;


	if(this != NULL && idTipo > 0)
	{
		this->idTipo = idTipo;


		rtn = 0;
	}

	return rtn;
}

int eComputer_getIdTipo(eComputer* this,int* idTipo)
{
	int rtn;
	rtn = -1;


	if(this != NULL && idTipo != NULL)
	{
		*idTipo = this->idTipo;

		rtn = 0;
	}

	return rtn;
}


int eComputer_setDescripcion(eComputer* this,char* descripcion)
{
	int rtn;
	rtn = -1;

	if(this != NULL && descripcion != NULL)
	{
		strcpy(this->descripcion, descripcion);
		rtn = 0;
	}

	return rtn;
}

int eComputer_getDescripcion(eComputer* this,char* descripion)
{
	int rtn;
	rtn = -1;

	if(this != NULL && descripion != NULL)
	{
		strcpy(descripion, this->descripcion);
		rtn = 0;
	}

	return rtn;
}


int eComputer_setPrecio(eComputer* this,float precio)
{
	int rtn;
	rtn = -1;

	if(this != NULL && precio > -1)
	{
		this->precio = precio;
		rtn = 0;
	}

	return rtn;
}

int eComputer_getPrecio(eComputer* this,float* precio)
{
	int rtn;
	rtn = -1;

	if(this != NULL && precio != NULL)
	{
		*precio = this->precio;
		rtn = 0;
	}

	return rtn;
}

int eComputer_setCuotas(eComputer* this,float cuotas)
{
	int rtn;
	rtn = -1;

	if(this != NULL && cuotas > -1)
	{
		this->cuotas = cuotas;
		rtn = 0;
	}

	return rtn;
}

int eComputer_getCuotas(eComputer* this,float* cuotas)
{
	int rtn;
	rtn = -1;

	if(this != NULL && cuotas != NULL)
	{
		*cuotas = this->cuotas;
		rtn = 0;
	}

	return rtn;
}


//=============================================================//

void eComputer_delete(eComputer* this)
{
	if(this != NULL)
	{
		free(this);
	}

}

//=========================== PRINT ===========================//
int listAllElements(LinkedList* pList)
{
	eComputer* eComputerAux;
	int i;
	int limite;
	int rtn;
	rtn = -1;

	if(pList != NULL)
	{
		limite = ll_len(pList);
		if(limite > 0)
		{
			printf("\n====================================================================  LISTADO DE ELEMENTOS ====================================================================\n");
			printf("\n  ID\t       DESCRIPCION\t\t     PRECIO\t\t   TIPO\t\t    CUOTAS");
			printf("\n================================================================================================================================================================\n");
			for(i=0;i<limite;i++)
			{
				eComputerAux = (eComputer*)ll_get(pList, i);

				if(eComputerAux != NULL)
				{
					printOneElement(eComputerAux);
					rtn = 0;
				}
			}
			printf("\n================================================================================================================================================================\n");

		}
	}


	return rtn;
}



int printOneElement(eComputer* this)
{
	int idAux;
	char descripcion[50];
	int idTipo;
	float precioAux;
	float cuotasAux;
	int rtn;
	rtn = -1;


	if(this != NULL)
	{

		if(eComputer_getId(this, &idAux) == 0 && eComputer_getDescripcion(this, descripcion) == 0 && eComputer_getIdTipo(this, &idTipo)== 0 && eComputer_getPrecio(this, &precioAux) == 0 && eComputer_getCuotas(this, &cuotasAux) == 0)
		{
			printf("\n %5d\t %15s\t%.2f",idAux, descripcion, precioAux);
			if(idTipo == 1)
			{
				printf("\t  DESKTOP");
			}
			else
			{
				printf("\t LAPTOP");
			}


			printf("\t %.2f",cuotasAux);
			rtn = 0;
		}
	}


	return rtn;
}











int guardar_texto(FILE* pFile, LinkedList* pLista)
{
	eComputer* eComputerAux;
	char auxDescripcion[50];
	char auxTipoComputadora[50];
	int auxId;
	int auxIdTipo;
	float auxPrecio;
	float auxCuotas;
	int i;
	int rtn;
	rtn = -1;

		if(pFile != NULL && pLista != NULL)
		{
			fprintf(pFile,"ID,DESCRIPCION,PRECIO,IDTIPO,CUOTAS\n");

			for(i=0;i<ll_len(pLista);i++)
			{
				eComputerAux = (eComputer*)ll_get(pLista, i);
				if(eComputerAux != NULL)
				{

					eComputer_getId(eComputerAux, &auxId);
					eComputer_getDescripcion(eComputerAux, auxDescripcion);
					eComputer_getPrecio(eComputerAux, &auxPrecio);
					eComputer_getCuotas(eComputerAux, &auxCuotas);
					eComputer_getIdTipo(eComputerAux, &auxIdTipo);

					if(auxIdTipo == 1)
					{
						strcpy(auxTipoComputadora,"DESKTOP");
					}
					else
					{
						strcpy(auxTipoComputadora,"LAPTOP");
					}



					fprintf(pFile,"%d,%s,%.2f,%s,%.2f\n",auxId, auxDescripcion, auxPrecio,auxTipoComputadora, auxCuotas);
				}
			}

			rtn = 0;
		}

		return rtn;
}
