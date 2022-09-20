/*
 ============================================================================
 Name        : clase8.c
 Author      :
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 ordenar el array

 */

#include <stdio.h>
#include <stdlib.h>
#include "alumnos.h"
#define TAM 3


int main(void)
{
	setbuf(stdout,NULL);
	int opcion;
    eAlumno alumnos[TAM];

    inicializarVector(alumnos,TAM);



	do
	{
		printf("1-alta\n2-baja\n3-modificar\n4-listar alumnos\n20-salir");
		scanf("%d",&opcion);



		switch(opcion)
		{
		case 1:
			altaAlumnos(alumnos,TAM);
		break;

		case 2:
			printf("baja!!!\n");
		break;

		case 3:
			printf("modificar!!!\n");
		break;

		case 4:
			imprimirAlumnos(alumnos,TAM);
		break;

		case 20:
			printf("saliste!!!\n");
		break;

		}



	}while(opcion != 20);




	return 0;
}
