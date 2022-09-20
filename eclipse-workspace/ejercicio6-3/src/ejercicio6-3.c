/*
 ============================================================================
 Name        : ejercicio6-3.c
 Author      : Serrano Belloso Sebastian
 Version     :
 Copyright   : 
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h> //get
#include <ctype.h> //inclue strlwr y upr

/*int main(void)
{
	setbuf(stdout,NULL);

	char nombre[31];
	char apellido[31];
	char apeNom[70];

	printf("\nIngrese su apellido: ");
	fflush(stdin);
	scanf("%[^\n]", apellido);    //esa manera de escribir el formato de dato, le dice^exceptuando el enter lee todo

	printf("\nIngrese su nombre: ");
	fflush(stdin);
	scanf("%[^\n]", nombre);

	//pase la cadena de datos a minuscula
	strlwr(apellido);
	strlwr(nombre);

	apellido[0] = toupper(apellido[0]); //estos trabajan con un solo caracter a diferencia de strupr, por eso debemos indicarle el indice del vector
	nombre[0] = toupper(nombre[0]);

	//apeNom[0] = '\0'; otra forma valida para "limpiar" apeNom que tiene basura ahora mismo
	srtcpy(apeNom, apellido);
	//"Gomez"
	strcat(apeNom, ", ");
	//"Gomez, "
	strcat(apeNom, nombre);
 //Gomez, Juan.

	return EXIT_SUCCESS;
}*/

int main(void)
{
	setbuf(stdout, NULL);

	char nombre[31];
	char apellido[31];
	char apeNom[70];
	int i, longitud;

	printf("\nIngrese su apellido: ");
	fflush(stdin);
	scanf("%[^\n]", apellido);

	printf("\nIngrese su nombre: ");
	fflush(stdin);
	scanf("%[^\n]", nombre);

	//pase la cadena de datos a minuscula
	strlwr(apellido);
	strlwr(nombre);

	apellido[0] = toupper(apellido[0]);
	nombre[0] = toupper(nombre[0]);

	longitud = strlen(apellido);
	for(i=0;i<longitud;i++)
	{
		if(i == 0)
		{
			apellido[i+1] = toupper(apellido[i+1]);
		}
		if(apellido[i] == ' ')
		{
			apellido[i+1] = toupper(apellido[i+1]);
		}
	}
	//apeNom[0] = '\0'; otra forma valida para "limpiar" apeNom que tiene basura ahora mismo


	strcpy(apeNom, apellido);
	strcat(apeNom, ", ");
	strcat(apeNom, nombre);


}
