/*
 ============================================================================
 Name        : pruebas.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char getChar(char text[]);

int main(void) {
	setbuf(stdout, NULL);

	char numeroStr[25] = "seba12";
	int numeroInt;

	numeroInt = atoi(numeroStr);
	printf("\nEl numero: %d", numeroInt);







	/*char letra;

	letra = getChar("\nIngrese una letra: ");

	printf("letra: %c", letra);
	float numero = 10;
	char numeroChar[15];

	sprintf(numeroChar,"%.2f",numero);
	printf("EL NUMERO: %s", numeroChar);*/







	return EXIT_SUCCESS;
}

char getChar(char text[])
{

	char auxString[1];

	printf("\n%s", text);
	fflush(stdin);
	gets(auxString);
	while(strlen(auxString) > 1 || strcmp(auxString," ") == 0 || strcmp(auxString, "\n") == 0 || strcmp(auxString,"") == 0)
	{
		printf("\nError, ingrese solo un caracter: ");
		fflush(stdin);
		gets(auxString);
	}

	return auxString[0];
}
