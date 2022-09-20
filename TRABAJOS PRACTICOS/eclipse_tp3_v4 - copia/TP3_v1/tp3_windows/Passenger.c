/*
 * Passenger.c
 *
 *  Created on: 19 may. 2022
 *      Author: Maru
 */

#include <Passenger.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


Passenger* Passenger_new()
{
	Passenger* new;

	new = (Passenger*)malloc(sizeof(Passenger)*1);


	return new;
}

Passenger* Passenger_newParametros(char* idStr,char* nombreStr, char* lastName, char* price, char* flyCode,  char* tipoPasajeroStr)
{
	Passenger* auxPassenger;

	auxPassenger = Passenger_new();
	Passenger_setId(auxPassenger, atoi(idStr));
	Passenger_setNombre(auxPassenger, nombreStr);
	Passenger_setApellido(auxPassenger, lastName);
	Passenger_setPrecio(auxPassenger, atof(price));
	Passenger_setCodigoVuelo(auxPassenger, flyCode);
	//Passenger_setTipoPasajero(auxPassenger, atoi(tipoPasajeroStr));
	//auxPassenger->isEmpty = atoi(isEmpty); //esto no es asi, asignale numeros a cada estado de vuelo y pasale un numero que se corresponda a cada uno, lo mismo para tipodePasjero

	return auxPassenger;
}


void Passenger_delete();


int Passenger_setId(Passenger* this,int id)
{
	int rtn;
	if(this != NULL && id > 0)
	{
		this->id = id;
	}

	return rtn;
}

int Passenger_getId(Passenger* this,int* id)
{
	int rtn;

	if(this != NULL && id > 0)
	{
		rtn = this->id;
	}

	return rtn;
}


int Passenger_setNombre(Passenger* this,char* nombre)
{
	int rtn;
	rtn = 0;

	if(this != NULL && nombre != NULL)
	{
		strcpy(this->nombre, nombre);
		rtn = 1;
	}


	return rtn;
}

int Passenger_getNombre(Passenger* this,char* nombre)
{
	int rtn;
	rtn = 0;
		if(this != NULL && nombre != NULL)
		{
			strcpy(nombre, this->nombre);
			rtn = 1;
		}

		return rtn;
}

int Passenger_setApellido(Passenger* this,char* apellido)
{

	int rtn;
	rtn = 0;

	if(this != NULL && apellido != NULL)
	{
		strcpy(this->apellido, apellido);
		rtn = 1;
	}

	return rtn;
}
int Passenger_getApellido(Passenger* this,char* apellido)
{
	int rtn;
	rtn = 0;

	if(this != NULL && apellido != NULL)
	{
		strcpy(apellido, this->nombre);
		rtn = 1;
	}

	return rtn;
}

int Passenger_setCodigoVuelo(Passenger* this,char* codigoVuelo)
{
	int rtn;
	rtn = 0;

	if(this != NULL && codigoVuelo != NULL)
	{
		strcpy(this->codigoVuelo, codigoVuelo);
		rtn = 1;
	}

	return rtn;
}
int Passenger_getCodigoVuelo(Passenger* this,char* codigoVuelo)
{
	int rtn;
	rtn = 0;

	if(this != NULL && codigoVuelo != NULL)
	{
		strcpy(codigoVuelo, this->codigoVuelo);
		rtn = 1;
	}

	return rtn;
}

int Passenger_setTipoPasajero(Passenger* this,int tipoPasajero)
{
	int rtn;
		rtn = 0;

		if(this != NULL && tipoPasajero != NULL)
		{
			this->tipoPasajero = tipoPasajero;
			rtn = 1;
		}

		return rtn;
}
int Passenger_getTipoPasajero(Passenger* this,int* tipoPasajero)
{
	int rtn;
	rtn = 0;

		if(this != NULL && tipoPasajero != NULL)
		{
			tipoPasajero = this->tipoPasajero;
			rtn = 1;
		}

	return rtn;
}

int Passenger_setPrecio(Passenger* this,float precio)
{
	int rtn;
		rtn = 0;

	if(this != NULL && precio != NULL)
	{
		this->precio = precio;
		rtn = 1;
	}

	return rtn;
}
int Passenger_getPrecio(Passenger* this,float* precio)
{
	int rtn;
	rtn = 0;

	if(this != NULL && precio != NULL)
	{
		precio = this->precio;
		rtn = 1;
	}

	return rtn;
}
