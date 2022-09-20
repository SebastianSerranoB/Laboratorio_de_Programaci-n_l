/*
 ============================================================================
 Name        : ejercicio7-1.c
 Author      : Serrano Belloso Sebastian
 Division    : K-1



 Tema 7 (ARRAYS PARALELOS)
Ejercicio 7-1:
Una empresa importadora que comercializa productos Apple, decide registrar de sus productos los
siguientes datos:
 -idProducto (numerico)
-descripcion (alfanumérico)
- nacionalidad (numérico, por el momento utilizaremos un define: EEUU - CHINA - OTRO)
- tipo (numérico, por el momento utilizaremos un define: IPHONE -MAC - IPAD -
ACCESORIOS)
- precio (numérico decimal)
Realizar un programa que permita interactuar con un menú de usuarios con las siguientes
opciones:
i) ALTA Producto: Se ingresan los datos de UN solo producto. Siempre y cuando haya espacio
disponible en el array.
j) BAJA Producto: A partir del ingreso del ID. Si existe el producto desaparece de la lista,
dejando espacio disponible para un nuevo producto.
k) MODIFICACIÓN Producto: A partir del ingreso del ID. Si existe se podrá modificar el precio
o el tipo.
l) LISTADO Productos.
m) LISTADO ordenado por precio.
n) LISTADO ordenado por descripción.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "funciones7.h"


//nacionalidad; la trataremos con un entero definido
#define EEUU 1
#define CHINA 2
#define OTRO 3

// tipo de producto; lo trataremos como un entero definido
#define IPHONE 1
#define MAC 2
#define IPAD 3
#define ACCESORIOS 4


/*//Declaramos antes que las funciones, es global, por lo que podemos utilizar la estructura en todo el programa
struct iProducto    //struct - nombre
{
	int idProducto;
	int nacionalidad; 						//declaramos con define
	int tipo;								//declaramos con define
	float precio;
	char descripcion[30];

}; //punto y coma al en el corchete de cierre*/  //forma sin typedef

typedef struct    //typedef palabra reservada , me permite indicar el tipo sin declarar antes struct, |||iProducto nombreVariable;  || ya valdria, sino hiciera el typedef seria ||struct iProducto nombreVariable;||
{					//esto podemos llevarlo a una biblioteca en .h
	int idProducto;
	int nacionalidad;
	int tipo;
	float precio;
	char descripcion[30];

	int estado;

}sProducto;



/////////////////////COMIENZA EL MAIN////////////////////////////////////

int main(void)
{
	setbuf(stdout, NULL);
	int opcionMenuPrincipal;
	sProducto producto;              //declaro una variable de tipo struct-iProducto con nombre producto;


	do
	{
		opcionMenuPrincipal = mainMenu();
		switch(opcionMenuPrincipal)
		{


			case 7:
			printf("\nHas salido del menu principal.");
			break;
		}
	}while(opcionMenuPrincipal != 7);




	return EXIT_SUCCESS;
}
