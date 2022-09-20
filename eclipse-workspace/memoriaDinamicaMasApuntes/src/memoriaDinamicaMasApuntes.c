/*
 ============================================================================
 Name        : memoriaDinamicaMasApuntes.c
 Author      : Serrano Belloso Sebastian
 Version     :
 Copyright   : 
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
 * malloc devuele un puntero a void, a malloc hay que castearle esa devolucion al tipo que necesitamos, sea struct o int,char etc, hay que enviarle sizeoff(tipoquequeremosreservar) como parametro
 * y siempre verificar que sea distinto de null una vez que lo hicimos, si es null le decimos no hay espacio(que no tengas memoria seria rarisimo pero hay que validar) y si no, operas
 *La idea de la memoria dinamica es que no tenes que establecer valores/cantidades FIJAS de datos en tus programas eAlumno[10] y que como maximo se puedan ingresar 10 alumnos, con malloc podes modificar ese tamaño cuanto queiras,
 *realloco y acordate free , calloc no me acuerdo que hace
 *
 * */
