/*
 * alumnos.c
 *
 *  Created on: 18 abr. 2022
 *      Author: Quiroz Family
 */
#include <stdio.h>
#include <stdlib.h>
#include "alumnos.h"



void inicializarVector(eAlumno listaAlumnos [],int tamanio)
{
	int i;

	for(i=0;i<tamanio;i++)
	{
		listaAlumnos[i].estado = 0;

	}



}


int buscarLibre (eAlumno listaAlumnos [],int tamanio)
{

	int index = -1;
	int i;

	for(i=0;i<tamanio;i++) //1
	{
		if(listaAlumnos[i].estado == 0)
		{
			index = i;//1
			break;
		}

	}



	return index;

}


void altaAlumnos(eAlumno listaAlumnos [],int tamanio)
{
	int indice;



	indice = buscarLibre(listaAlumnos,tamanio);

	if(indice != -1)
	{
		printf("ingrese su nombre:  ");
		fflush(stdin);
		scanf("%[^\n]",listaAlumnos[indice].nombre);

		printf("ingrese su nota: ");
		scanf("%d",&listaAlumnos[indice].nota);

		printf("ingrese su edad: ");
		scanf("%d",&listaAlumnos[indice].edad);

		listaAlumnos[indice].estado = 1;


	}
	else
	{
		printf("lista llena!!!");
	}


}

void imprimirAlumnos(eAlumno listaAlumnos [],int tamanio)
{
	int i;

	for(i=0;i<tamanio;i++)
	{
		if(listaAlumnos[i].estado==1)
		{
		 printf("su nombre es: %s -- su edad es: %d -- su nota es: %d \n",listaAlumnos[i].nombre,listaAlumnos[i].edad,listaAlumnos[i].nota);
		}

	}



}


