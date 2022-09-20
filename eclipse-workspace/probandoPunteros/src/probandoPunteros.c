/*
 ============================================================================
 Name        : probandoPunteros.c
 Author      : Serrano Belloso Sebastian
 Version     :
 Copyright   : 
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main(void) {
	setbuf(stdout, NULL);

#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	int id;
	char descripcion[20];
	float precio;
}eProducto;



int main(void) {
	setbuf(stdout, NULL);
	eProducto miProducto = {1000, "Oreo", 120.31};
	eProducto* pProducto;
	eProducto lista[3]={{1000, "Oreo", 120.31},
	                    {1001, "Sonrisas", 100.24},
	                    {1002, "Rumbas", 106.99}
	                   };



	pProducto = lista;

	for(int i=0; i<3; i++)
	{
	    //printf("%4d %-15s %4.2f \n", (*(pProducto+i)).id, (*(pProducto+i)).descripcion, (*(pProducto+i)).precio);
	     printf("%4d %-15s %4.2f \n", (pProducto+i)->id, (pProducto+i)->descripcion, (pProducto+i)->precio);

	}

	//printf("%4d %-15s %4.2f\n", (*pProducto).id, (*pProducto).descripcion, (*pProducto).precio);
    //printf("%4d %-15s %4.2f\n", pProducto->id, pProducto->descripcion, pProducto->precio);

	return EXIT_SUCCESS;
}


	return EXIT_SUCCESS;
}
