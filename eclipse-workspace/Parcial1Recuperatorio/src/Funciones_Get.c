/*
 * Funciones_Get.c
  *
  *
  *  ALUMNO: SEBASTIAN SERRANO BELLOSO
  *  DNI: 42.810.404
  *  DIVISION: K-1
  *  MATERIA: LABORATORIO DE PROGRAMACION I
  *  PARCIAL I
  *  UTN-FRA 04/05/2022
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "Entidades.h"

#include "ABM.h"

#include "Funciones_Informar.h"
#include "Funciones_Listar.h"

#include "Funciones_Get.h"

#include "Funciones_Ordenamiento.h"


int getInteger(int min, int max, char text[])
 {
 	 int rtn;
 	 int integer;
 	 rtn = 0;

 	if(text != NULL)
 	{
 		printf("\n%s", text);
 		scanf("%d", &integer);
 		while(integer < min || integer > max)
 		{
 			printf("\nError, reingrese un entero(>= %d && <= %d): ", min, max);
 			scanf("%d", &integer);
 		}

 		rtn = integer;
 	}



 	 return rtn;
 }



float getFloat(int min, int max, char text[])
{
	float rtn;
	float floatNumber;
	rtn = 0;

	if(text != NULL)
	{
		printf("%s", text);
		scanf("%f", &floatNumber);
		while(floatNumber < min || floatNumber > max)
		{
			printf("\nError, reingrese un numero(>= %d && <= %d) :", min, max);
			scanf("%f", &floatNumber);
		}
		rtn = floatNumber;
	}


	return rtn;
}



int getString(char string[], int max, char text[])
{
	int rtn;
	rtn = 0;

	if(string != NULL && text != NULL)
	{
		printf("%s", text);
		fflush(stdin);
		gets(string);
		while((strlen(string)) < 1 || (strlen(string) > max))
		{
			printf("\nError, intente nuevamente(maximo = %d caracteres): " , max);
			fflush(stdin);
			gets(string);
		}
		rtn = 1;
	}

	return rtn;
}



char getChar(char text[])
{
	char caracter;

	printf("%s", text);
	fflush(stdin);
	scanf("%c", &caracter);

	return caracter;
}



sFecha getDate(char text[])
{
	sFecha date;

	printf("%s", text);
	date.anio = getInteger(MIN_FECHA, MAX_FECHA, "Ingrese el anio: ");
	date.mes = getInteger(1, 12, "Ingrese el numero de mes: ");
	date.dia = getInteger(1, 31, "Ingrese el dia: ");

	return date;
}
