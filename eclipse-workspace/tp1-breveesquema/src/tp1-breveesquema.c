/*
 ============================================================================
 Name        : tp1-breveesquema.c
 Author      : messirve
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	puts("!!!Hello World!!!"); /* prints !!!Hello World!!! */
	return EXIT_SUCCESS;
}
/*
 ============================================================================
 Name        : clase4.c
 Author      :
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "funcionesAritmeticas.h"

//prototipo o firma


int main(void)
{
	setbuf(stdout, NULL);
	int opcion;
	int opcion2;

	do
	{
		printf("1-pedir datos\n2-sumar \n3-resta \n4-division \n5-multiplicacion\n6-Salir\n");
		scanf("%d",&opcion);

		switch(opcion)
		{
			case 1:
			printf("ingrese numero 1: \n");
			printf("ingrese numero 2: \n");
			break;

			case 2:
			printf("estoy en la opcion 2\n");
			break;

			case 3:
			printf("estoy en la opcion 3\n");
			break;

			case 4:
			printf("estoy en la opcion 4\n");
			break;

			case 5:
			printf("estoy en la opcion 5\n");
			break;

			case 6:
			printf("chau\n");
			break;

			default:
			printf("error no ingreso una opcion correcta\n");
			break;




		}


	}while(opcion != 6);


	return EXIT_SUCCESS;
}

