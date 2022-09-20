/*
 ============================================================================
 Name        : puntero_A_Funciones.c
 Author      : Serrano Belloso Sebastian
 Version     :
 Copyright   : 
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

*
 ============================================================================
 Name        : PunterosBase.c
 Author      :
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int sumar(int numero,int numero2);
int restar(int numero,int numero2);
void calculadora(int(*pFuncion)(int,int));
int multiplicar(int numero,int numero2);

int main(void)
{

	setbuf(stdout, NULL);


	calculadora(sumar);
	calculadora(restar);
	calculadora(multiplicar);


	return EXIT_SUCCESS;
}

int sumar(int numero,int numero2)
{
	int resultado;

	resultado = numero + numero2;

	return resultado;
}

int restar(int numero,int numero2)
{
	int resultado;

   resultado = numero - numero2;


   return resultado;

}


void calculadora(int(*pFuncion)(int,int))
{
	int resultado;


	resultado = pFuncion(10,20);

	printf("%d\n",resultado);

}

int multiplicar(int numero,int numero2)
{
	int resultado;

	   resultado = numero * numero2;


	   return resultado;
}



