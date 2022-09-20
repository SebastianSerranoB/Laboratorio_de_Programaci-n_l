/*
 * functions8.c
 *
 *
 *  Created on: 20 abr 2022
 *      Author: admin
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define CANT 5
#define EEUU 1
#define CHINA 2
#define OTRO 3
#define IPHONE 4
#define MAC 5
#define IPAD 6
#define ACCESORIOS 7

int mainMenu(char text[])
{
	int enteredOption;
	printf(text);

	printf("\n\nIngrese una opcion: ");
	scanf("%d", &enteredOption);

	return enteredOption;
}

typedef struct
{
	int estado;
	int idProducto;
	int nacionalidad;
	int tipo;
	char descripcion[101];
	float precio;

}sProducto;

sProducto alta(void)
{
	sProducto producto;

	printf("\n Ingrese el ID del producto: ");
	scanf("%d", &producto.idProducto);

	printf("\n Ingrese la nacionalidad del producto: ");
	scanf("%d", &producto.nacionalidad);

	printf("\n Ingrese el tipo de producto: ");
	scanf("%d", &producto.tipo);

	printf("\n Ingrese la descripcion del producto: ");
	fflush(stdin);
	gets(producto.descripcion);
	strlwr(producto.descripcion);


	printf("\n Ingrese el precio del producto: ");
	scanf("%f", &producto.precio);

	producto.estado = 1;

	return producto;
}

void showProduct(sProducto producto)
{
	printf("\n---PRODUCTO---\nTIPO: %d\nDESCRIPCION: %s\nPRECIO: %.2f\nID: %d\nNACIONALIDAD: %d", producto.tipo, producto.descripcion, producto.precio, producto.idProducto, producto.nacionalidad);
}
