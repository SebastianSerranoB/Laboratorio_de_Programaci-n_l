
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void getString(char palabra[],char mensaje[],int tamanio);
int getInt(char mensaje[]);
int esNumerica(char auxiliar[]);

int main(void)
{
	setbuf(stdout, NULL);
	char nombre [20];
	int numero;


	//getString(nombre,"ingresa tu nombre",20);
	//printf("%s",nombre);

	numero = getInt("ingrese un numero");


	printf("%d",numero);


	return EXIT_SUCCESS;
}


void getString(char palabra[],char mensaje[],int tamanio)//valida no pasar el limite de una cadena de caracteres
{
	char auxilar[1024];
	int cantidadLetras;

	printf("%s",mensaje);
	fflush(stdin);
	gets(auxilar);

	cantidadLetras = strlen(auxilar);

	while(cantidadLetras > tamanio)
	{
		printf("%s",mensaje);
		fflush(stdin);
		gets(auxilar);

	}

	strcpy(palabra,auxilar);


}


int getInt(char mensaje[])//que sea un numero
{
	int retorno = -1;
	int esNumero;
	char auxiliar[30];




	getString(auxiliar,mensaje,30); // donde se va a guardar, ingresa un numero,limite de la cadena

	while(esNumerica(auxiliar) < 1)
	{
	  getString(auxiliar,mensaje,30);
	}

	esNumero = atoi(auxiliar);

	retorno = esNumero;

 return retorno;
}


int esNumerica(char auxiliar[])
{
	int i;
	int largo;
	int retorno =-1;

	if(auxiliar != NULL)
	{
		retorno = 1;

		largo = strlen(auxiliar);

		for(i=0;i<largo;i++)
		{
			if(isdigit(auxiliar[i])==0)
			{
				retorno =0;
				break;

			}

		}
	}


	return retorno;

}

//  isdigit(caracter) 0 si no es un numero y mayor a 0 si es un numero

