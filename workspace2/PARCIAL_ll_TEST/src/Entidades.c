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
Empleado* Empleado_new()
{
	Empleado* newEmpleado;

	newEmpleado = (Empleado*)malloc(sizeof(Empleado)*1);
	if(newEmpleado != NULL)
	{
		strcpy(newEmpleado->nombre,"");
		strcpy(newEmpleado->apellido,"");
		newEmpleado->id = -1;
		newEmpleado->precio = -1;
	}

	return newEmpleado;
}

Empleado* Empleado_newParametros(char* idStr,char* nombreStr,char* apellidoStr,char* precioStr)
{
	Empleado* newEmpleado = NULL;
	Empleado* rtn = NULL;


	newEmpleado = Empleado_new();
	if(newEmpleado != NULL)
	{
		if(validarDatosElemento(idStr, nombreStr, apellidoStr, precioStr) == 0)
		{
			Empleado_setId(newEmpleado, atoi(idStr));
			Empleado_setNombre(newEmpleado, nombreStr);
			Empleado_setApellido(newEmpleado, apellidoStr);
			Empleado_setPrecio(newEmpleado, atof(precioStr));

			rtn = newEmpleado;
		}
		else
		{
			Empleado_delete(newEmpleado);
		}

	}


	return rtn;
}




//================ SETTERS/GETTERS =========================//
int Empleado_setId(Empleado* this,int id)
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

int Empleado_getId(Empleado* this,int* id)
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


int Empleado_setNombre(Empleado* this,char* nombre)
{
	int rtn;
	rtn = -1;

	if(this != NULL && nombre != NULL)
	{
		strcpy(this->nombre, nombre);
		rtn = 0;
	}

	return rtn;
}

int Empleado_getNombre(Empleado* this,char* nombre)
{
	int rtn;
	rtn = -1;

	if(this != NULL && nombre != NULL)
	{
		strcpy(nombre, this->nombre);
		rtn = 0;
	}

	return rtn;
}

int Empleado_setApellido(Empleado* this,char* apellido)
{
	int rtn;
	rtn = -1;

	if(this != NULL && apellido != NULL)
	{
		strcpy(this->apellido, apellido);
		rtn = 0;
	}

	return rtn;
}

int Empleado_getApellido(Empleado* this,char* apellido)
{
	int rtn;
	rtn = -1;

	if(this != NULL && apellido != NULL)
	{
		strcpy(apellido, this->apellido);
		rtn = 0;
	}

	return rtn;
}

int Empleado_setPrecio(Empleado* this,float precio)
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

int Empleado_getPrecio(Empleado* this,float* precio)
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
//=============================================================//

void Empleado_delete(Empleado* this)
{
	if(this != NULL)
	{
		free(this);
	}

}

//=========================== PRINT ===========================//
int listAllElements(LinkedList* pList)
{
	Empleado* empleadoAux;
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
			printf("\n  ID\t       NOMBRE\t\t     APELLIDO\t\t   PRECIO");
			printf("\n================================================================================================================================================================\n");
			for(i=0;i<limite;i++)
			{
				empleadoAux = (Empleado*)ll_get(pList, i);

				if(empleadoAux != NULL)
				{
					printOneElement(empleadoAux);
					rtn = 0;
				}
			}
			printf("\n================================================================================================================================================================\n");

		}
	}


	return rtn;
}



int printOneElement(Empleado* this)
{
	int idAux;
	char nombreAux[50];
	char apellidoAux[50];
	float precioAux;
	int rtn;
	rtn = -1;


	if(this != NULL)
	{

		if(Empleado_getId(this, &idAux) == 0 && Empleado_getNombre(this, nombreAux) == 0 && Empleado_getApellido(this, apellidoAux) == 0 && Empleado_getPrecio(this, &precioAux) == 0)
		{

			printf("\n %5d\t %15s\t%15s\t %.2f",idAux, nombreAux, apellidoAux, precioAux);
			rtn = 0;
		}
	}


	return rtn;
}











int guardar_texto(FILE* pFile, LinkedList* pLista)
{
	Empleado* auxEmpleado;
	char auxName[50];
	char auxApellido[50];
	int auxId;
	float auxPrecio;
	int i;
	int rtn;
	rtn = -1;

		if(pFile != NULL && pLista != NULL)
		{
			fprintf(pFile,"ID,NAME,LASTNAME,PRICE\n");

			for(i=0;i<ll_len(pLista);i++)
			{
				auxEmpleado = (Empleado*)ll_get(pLista, i);
				if(auxEmpleado != NULL)
				{

					Empleado_getId(auxEmpleado, &auxId);
					Empleado_getNombre(auxEmpleado, auxName);
					Empleado_getApellido(auxEmpleado, auxApellido);
					Empleado_getPrecio(auxEmpleado, &auxPrecio);


					fprintf(pFile,"%d,%s,%s,%.2f\n",auxId, auxName, auxApellido, auxPrecio);
				}
			}

			rtn = 0;
		}

		return rtn;
}
