/*
 ============================================================================
 Name        : borrador.c
 Author      : messirve
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

float debitar(float a);
int main(void)
{
	setbuf(stdout, NULL);

	return EXIT_SUCCESS;
}
float debitar(float a)
{
	float descuentoFinal, descuento = 0.8;

	descuentoFinal =  a * descuento;
	return descuentoFinal;
}
