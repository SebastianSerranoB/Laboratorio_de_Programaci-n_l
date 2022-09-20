/*
 * FuncionesAlumno.c
 *
 *  Created on: 28 jun 2022
 *      Author: admin
 */

#include "LinkedList.h"
#include "funcionesAlumno.h"
#include "Entidades.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


//==============  MENU  =================//

int printMenu(int min, int max,char textMenu[])
{
	int opcion;
	opcion = -1;

	if(textMenu != NULL && strlen(textMenu) > 0)
	{
		printf(textMenu);
		opcion = getInt(min, max, "\n>>> Ingrese una opcion: ");
	}

	return opcion;
}


//================  ORDENAR/SORT =======================//



//EL PRECIO LO PISAMOS CON EL VALOR DE UNA SOLA CUOTA
int ordenarPorCuota(void* pElementA, void* pElementB)
{
	eComputer* eComputerUno;
	eComputer* eComputerDos;
	float auxCuotaA;
	float auxCuotaB;
	int rtn;
	rtn = -1;


	if(pElementA  != NULL && pElementB != NULL)
	{
		eComputerUno = (eComputer*)pElementA;
		eComputerDos = (eComputer*)pElementB;

		eComputer_getCuotas(eComputerUno, &auxCuotaA);
		eComputer_getCuotas(eComputerDos, &auxCuotaB);

		if(auxCuotaA > auxCuotaB)
		{
			rtn = 1;
		}
		else
		{
			if(auxCuotaA == auxCuotaB)
			{
				rtn = 0;
			}
		}

	}


	return rtn;
}


//========================= MAPEOS/CRITERIOS =================================//

/*int Empleado_Aumento(void* pElement)
{
	Empleado* auxElement = NULL;
	float sueldoAumento;
	float auxSueldo;
	int rtn;
	rtn = -1;

	if(pElement != NULL)
	{
		auxElement = (Empleado*)pElement;
		Empleado_getPrecio(auxElement, &auxSueldo);
		if(auxSueldo < 5000)
		{
			sueldoAumento = auxSueldo *1.1;
			Empleado_setPrecio(auxElement, sueldoAumento);
			rtn = 0;
		}
	}


	return rtn;
}*/










//=============  VALIDACIONES--INPUTS--  ================//

int validarDatosElemento(char* idStr,char* nombreStr,char* apellidoStr,char* precioStr)
{
	int rtn;
	rtn = -1;


	if(idStr != NULL && nombreStr != NULL && apellidoStr != NULL && precioStr != NULL)
	{
		if(strlen(idStr) < 6 || strlen(nombreStr) < 50 || strlen(apellidoStr) < 50 || strlen(precioStr) < 10 )
		{
			if(strlen(idStr) > 0 && strlen(nombreStr) > 0 && strlen(apellidoStr) > 0 && strlen(precioStr) > 0 )
			{
				rtn = 0;
			}
		}
	}


	return rtn;
}









int stringEmpty(char string[])
{
	int rtn;
	int i;
	rtn = 0;


		for(i=0;i<strlen(string);i++)
		{
			if(string[i] != ' ')
			{
				rtn = 1;
				break;
			}
			else
			{
				rtn = 0;
			}

		}


	return rtn;
}

void getString(char string[], int lenght, char text[])
{
	char auxiliar[1024];


	printf("\n%s", text);
	fflush(stdin);
	gets(auxiliar);

	while(strlen(auxiliar) < 1 || strlen(auxiliar) > lenght || stringEmpty(auxiliar) == 0)
	{
		printf("\nError, ingrese al menos un caracter distinto de vacio, y un texto menor a %d caracteres:  ", lenght);
		fflush(stdin);
		gets(auxiliar);
	}

	strcpy(string, auxiliar);
}

int isName(char string[])
{
	int rtn;
	int i;
	rtn = 0;

	/*
	  65A  90Z  97a 122z  ||129 u:  154 U:||  130 é 144 É || desde 160 a- i -o- u- con acento- ñ- Ñ  hasta 165||
	  */

	for(i=0;i<strlen(string);i++)
	{
		if(isalpha(string[i]) == 0 && string[i] != ' ' && string[i] != '\0' && string[i] != '\n')
		{
			if((string[i] != 154 && string[i] != 129) && (string[i] < 160 || string[i] > 165) && (string[i] != 130 && string[i] != 144))
			{
				rtn = 0;
			}
			else
			{
				rtn = 1;
			}
		}
		else
		{
			rtn = 1;
		}

	}


	return rtn;
}


void getName(char string[], int lenght, char text[])
{
	char auxName[1024];

	getString(auxName, lenght, text);
	while(isName(auxName) == 0)
	{
		getString(auxName, lenght, "\nError, ingrese un nombre valido:  ");
	}


	strcpy(string, auxName);
}


int isInteger(char auxInteger[])
{
	int rtn, i, alphaCounter;
	alphaCounter = 0;
	rtn = 0;

	if(auxInteger != NULL){
		for(i=0;i<strlen(auxInteger);i++){
			if(isdigit(auxInteger[i]) == 0){
				alphaCounter++;
			}
		}
	}
	if(alphaCounter > 1 || (auxInteger[0] != 45 && (auxInteger[0] < 48 || auxInteger[0] > 57))){
		return rtn;
	}
	else{
		if(strlen(auxInteger) == 1 && auxInteger[0] == 45){
			return rtn;
		}
		else{
			rtn = 1;
		}
	}


	return rtn;
}


int getInt(int min, int max, char text[])
{
	char intAuxiliar[25];

	getString(intAuxiliar, 25, text);
	while((isInteger(intAuxiliar) == 0) || (atoi(intAuxiliar) < min || atoi(intAuxiliar) > max)){
		printf("\nError, ingrese un valor numerico entre: [> %d  &&  < %d] ", min, max);
		getString(intAuxiliar, 25," ");

	}

	return atoi(intAuxiliar);
}

int isFloat(char auxFloat[])
{
	int rtn, i;
	int alphaCounter, dotCounter, minusCounter;
	rtn = 0;
	alphaCounter = 0, dotCounter = 0, minusCounter = 0;


	if(auxFloat != NULL){
		for(i=0;i<strlen(auxFloat);i++)
		{
			if(isdigit(auxFloat[i]) == 0 && auxFloat[i] != 45 && auxFloat[i] != 46){
				alphaCounter++;
			}
			else{
				if(auxFloat[i] == 45){
					minusCounter++;
				}
				else
				{
					if(auxFloat[i] == 46){
						dotCounter++;
					}
				}
			}

		}
	}
	else{
		return rtn;
	}


	if(alphaCounter > 0 || dotCounter > 1 || minusCounter > 1){
		return rtn;
	}
	else{
		if(auxFloat[0] != 45 && (auxFloat[0] < 48 || auxFloat[0] > 57)){
			return rtn;
		}
		else{
			if(strlen(auxFloat) == 1 && auxFloat[0] == 45){
				return rtn;
			}
			else{
				if(strlen(auxFloat) > 1 && auxFloat[0] == 45 && auxFloat[1] == 46){
					return rtn;
				}
				else{
					rtn = 1;
				}
			}
		}
	}


	return rtn;
}

float getFloat(float min, float max, char text[])
{
	char floatAuxiliar[25];
	float retornoFloat;

		getString(floatAuxiliar, 25, text);
		while((isFloat(floatAuxiliar) == 0) || (atof(floatAuxiliar) < min || atof(floatAuxiliar) > max)){
			printf("\nError, ingrese un valor numerico entre: [> %.2f  &&  < %.2f] ", min, max);
			getString(floatAuxiliar, 25," ");
		}

	retornoFloat = atof(floatAuxiliar);
	return retornoFloat;
}


char getChar(char text[])
{

	char auxString[1];

	printf("\n%s", text);
	fflush(stdin);
	gets(auxString);
	while(strlen(auxString) > 1 || strcmp(auxString," ") == 0 || strcmp(auxString, "\n") == 0 || strcmp(auxString,"") == 0)
	{
		printf("\nError, ingrese solo un caracter: ");
		fflush(stdin);
		gets(auxString);
	}

	return auxString[0];
}
//=============================================================//
