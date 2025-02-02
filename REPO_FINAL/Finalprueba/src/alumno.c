/*
 * alumno.c
 *
 *  Created on: 31 ago 2022
 *      Author: admin
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "LinkedList.h"
#include "Pokemon.h"
#include "controller.h"
#include "alumno.h"
#include "parser.h"

//mostrar en pantalla los de tipo agua variocolor
/*6) Batalla pokemon: Nos hemos encontrado con el jefe del team Rocket, Giovanni. El
							malvado jugar� su batalla final con Lugia, pok�mon de tipo Ps�quico. La �nica forma
							de ganarle ser� formando un equipo con las siguientes caracter�sticas: un pok�mon
							de tipo Fire de tama�o XL, con ataque Lanzallamas y cuyo valor de ataque sea
							superior a 80 o de tipo Water tama�o L, con ataque hidrobomba entre superior a 80.
							Determinar cu�ntos pokemones cumplen con dichas caracter�sticas y anunciar si
							ganamos la batalla o no. Tener en cuenta que necesitamos m�nimo 3 pokemones para
							vencer a este pok�mon legendario.
							break;*/

int batallaPokemon(LinkedList* this){

	int retorno;
	int i;
	int contadorPokemonFuerte;
	ePokemon* auxPokemon = NULL;
	int auxValorAtaque;
	char auxTipo[100];
	char auxTamanio[100];
	char auxAtaqueCargado[100];
	contadorPokemonFuerte = 0;
	retorno = -1;


	if(this != NULL && ll_len(this) > 0)
	{
		for(i=0;i<ll_len(this);i++)
		{
			auxPokemon = (ePokemon*)ll_get(this, i);
			if(auxPokemon != NULL)
			{
				//tipo fire XL lanzallamas ATAQUE > 80 || WATER L HIDROBOMBA > 80
				Pokemon_getAtaqueCargado(auxPokemon, auxAtaqueCargado);
				Pokemon_getTamanio(auxPokemon, auxTamanio);
				Pokemon_getTipo(auxPokemon, auxTipo);
				Pokemon_getValorAtaque(auxPokemon, &auxValorAtaque);

				if(auxValorAtaque > 80 && stricmp(auxTipo,"Fire") == 0
					&& stricmp(auxTamanio,"XL") == 0  && stricmp(auxAtaqueCargado,"Lanzallamas") == 0)
				{
					contadorPokemonFuerte++;
				}else{
					if(auxValorAtaque > 80 && stricmp(auxTipo,"Water") == 0 && stricmp(auxTamanio,"L") == 0  && stricmp(auxAtaqueCargado,"Hidrobomba") == 0)
					{
						contadorPokemonFuerte++;
					}
				}

				retorno = 0;
			}
		}

		if(contadorPokemonFuerte > 2)
		{
			printf("\nVICTORIA! VENCISTE AL LIDER DEL EQUIPO ROCKET.");
			printf("\nGiovanni: Esto no ha terminado, nos volveremos a ver en el campo de combate.");
		}else{
			printf("\nDERROTA! TUS POKEMONS ESTAN DANIADOS, CORRE A UN CENTRO MEDICO");
			printf("\nGiovanni: ... no eres rival.");

		}

	}else{
		printf("\nError, debe haber al menos un elemento en lista para la batalla.");
	}


	return retorno;
}

int stringEmpty(char string[])
{
	int rtn;
	int i;
	rtn = 0;


		for(i=0;i<strlen(string);i++)
		{
			if(string[i] != ' ')
			{
				rtn = 1;
				break;
			}
			else
			{
				rtn = 0;
			}

		}


	return rtn;
}

void getString(char string[], int lenght, char text[])
{
	char auxiliar[1024];


	printf("\n%s", text);
	fflush(stdin);
	gets(auxiliar);

	while(strlen(auxiliar) < 1 || strlen(auxiliar) > lenght || stringEmpty(auxiliar) == 0)
	{
		printf("\nError, ingrese al menos un caracter distinto de vacio, y un texto menor a %d caracteres:  ", lenght);
		fflush(stdin);
		gets(auxiliar);
	}

	strcpy(string, auxiliar);
}

int isName(char string[])
{
	int rtn;
	int i;
	rtn = 0;

	/*
	  65A  90Z  97a 122z  ||129 u:  154 U:||  130 � 144 � || desde 160 a- i -o- u- con acento- �- �  hasta 165||
	  */

	for(i=0;i<strlen(string);i++)
	{
		if(isalpha(string[i]) == 0 && string[i] != ' ' && string[i] != '\0' && string[i] != '\n')
		{
			if((string[i] != 154 && string[i] != 129) && (string[i] < 160 || string[i] > 165) && (string[i] != 130 && string[i] != 144))
			{
				rtn = 0;
			}
			else
			{
				rtn = 1;
			}
		}
		else
		{
			rtn = 1;
		}

	}


	return rtn;
}


void getName(char string[], int lenght, char text[])
{
	char auxName[1024];

	getString(auxName, lenght, text);
	while(isName(auxName) == 0)
	{
		getString(auxName, lenght, "\nError, ingrese un nombre valido:  ");
	}


	strcpy(string, auxName);
}


int isInteger(char auxInteger[])
{
	int rtn, i, alphaCounter;
	alphaCounter = 0;
	rtn = 0;

	if(auxInteger != NULL){
		for(i=0;i<strlen(auxInteger);i++){
			if(isdigit(auxInteger[i]) == 0){
				alphaCounter++;
			}
		}
	}
	if(alphaCounter > 1 || (auxInteger[0] != 45 && (auxInteger[0] < 48 || auxInteger[0] > 57))){
		return rtn;
	}
	else{
		if(strlen(auxInteger) == 1 && auxInteger[0] == 45){
			return rtn;
		}
		else{
			rtn = 1;
		}
	}


	return rtn;
}


int getInt(int min, int max, char text[])
{
	char intAuxiliar[25];

	getString(intAuxiliar, 25, text);
	while((isInteger(intAuxiliar) == 0) || (atoi(intAuxiliar) < min || atoi(intAuxiliar) > max)){
		printf("\nError, ingrese un valor numerico entre: [> %d  &&  < %d] ", min, max);
		getString(intAuxiliar, 25," ");

	}

	return atoi(intAuxiliar);
}

int isFloat(char auxFloat[])
{
	int rtn, i;
	int alphaCounter, dotCounter, minusCounter;
	rtn = 0;
	alphaCounter = 0, dotCounter = 0, minusCounter = 0;


	if(auxFloat != NULL){
		for(i=0;i<strlen(auxFloat);i++)
		{
			if(isdigit(auxFloat[i]) == 0 && auxFloat[i] != 45 && auxFloat[i] != 46){
				alphaCounter++;
			}
			else{
				if(auxFloat[i] == 45){
					minusCounter++;
				}
				else
				{
					if(auxFloat[i] == 46){
						dotCounter++;
					}
				}
			}

		}
	}
	else{
		return rtn;
	}


	if(alphaCounter > 0 || dotCounter > 1 || minusCounter > 1){
		return rtn;
	}
	else{
		if(auxFloat[0] != 45 && (auxFloat[0] < 48 || auxFloat[0] > 57)){
			return rtn;
		}
		else{
			if(strlen(auxFloat) == 1 && auxFloat[0] == 45){
				return rtn;
			}
			else{
				if(strlen(auxFloat) > 1 && auxFloat[0] == 45 && auxFloat[1] == 46){
					return rtn;
				}
				else{
					rtn = 1;
				}
			}
		}
	}


	return rtn;
}

float getFloat(float min, float max, char text[])
{
	char floatAuxiliar[25];
	float retornoFloat;

		getString(floatAuxiliar, 25, text);
		while((isFloat(floatAuxiliar) == 0) || (atof(floatAuxiliar) < min || atof(floatAuxiliar) > max)){
			printf("\nError, ingrese un valor numerico entre: [> %.2f  &&  < %.2f] ", min, max);
			getString(floatAuxiliar, 25," ");
		}

	retornoFloat = atof(floatAuxiliar);
	return retornoFloat;
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
//=============================================================//
//==============================================================//

//============ PRINT MENU ============//

int printMenu(int min, int max,char textMenu[])
{
	int opcion;
	opcion = -1;

	if(textMenu != NULL && strlen(textMenu) > 0)
	{
		printf(textMenu);
		opcion = getInt(min, max, "\n>>> Ingrese una opcion: ");
	}

	return opcion;
}








/*


//========== SORT ============//

//hace de controller
int ordenarLista(LinkedList* this)
{
	int retorno = -1;
	if(this != NULL && ll_len(this) > 0)
	{
		//llamamos al sort de la linkedList, luego la funcion criterio(no es necesario los parametros de esta(void), //1 ascendente, 0 descendente
		if(ll_sort(this, ordenarPorNombre, 0) == 0)
		{
			retorno = 0;
			printf("\nLista ordenada exitosamente: de la Z hasta la A");
		}
	}
	else
	{
		printf("\nNo existen elementos en lista.");
	}

	return retorno;
}

int ordenarPorNombre(void* pPassengerA, void* pPassengerB)
{
	int rtn;
	eParticipante* pasajeroUno;
	eParticipante* pasajeroDos;
	char auxNombreA[50];
	char auxNombreB[50];
	rtn = -1;

	if(pPassengerA != NULL && pPassengerB != NULL)
	{
		pasajeroUno = (eParticipante*)pPassengerA;
		pasajeroDos = (eParticipante*)pPassengerB;

		Participante_getNombre(pasajeroUno, auxNombreA);
		Participante_getNombre(pasajeroDos, auxNombreB);


		rtn = stricmp(auxNombreA, auxNombreB);
	}


	return rtn;
}

//=========== GUARDAR ARCHIVO ==================//

int guardarEnArchivoTxt(char* path , LinkedList* this)
{
	int retorno = -1;

	char bufferNombre[128];
	int bufferIdDificultad;
	int bufferId;
	int bufferScore;
	int bufferEdad;


	int len, i;
	FILE* fpArchivo;
	eParticipante* auxParticipante;

	if(this != NULL && path != NULL)
	{
		//abrimos el archivo en modo write, sobreescribe si existe algo previamente
		fpArchivo = fopen(path, "w");
		if(fpArchivo != NULL)
		{
			len = ll_len(this);
			//primero escribimos el menu, pie, si es necesario, con fprintf sin olvidar el \n
			fprintf(fpArchivo, "id,descripcion,precio,idTipo,cuotas,valorcuota\n");

			//recorremos la lista, traemos con get, cada elemento
			for(i=0;i<len; i++)
			{
				auxParticipante = (eParticipante*) ll_get(this, i);
				if(auxParticipante != NULL)
				{
					//traemos con el get del struct cada elemento necesario,
					Participante_getId(auxParticipante, &bufferId);
					Participante_getIdDificultad(auxParticipante, &bufferIdDificultad);
					Participante_getNombre(auxParticipante, bufferNombre);
					Participante_getEdad(auxParticipante, &bufferEdad);
					Participante_getScore(auxParticipante, &bufferScore);


					retorno = 0;
					//con fprintf escribimos un txt
					fprintf(fpArchivo, "%d,%s,%d,%d,%d\n", bufferId, bufferNombre, bufferEdad, bufferIdDificultad, bufferScore);

				}
			}
		}
		fclose(fpArchivo);

	}

	printf("\nArchivo filtrado con exito.");
	return retorno;

}

int Participante_getIdDificultadTxt(eParticipante* this, int idTipo, char dificultadTxt[]){

	int retorno = -1;
	if(this != NULL && dificultadTxt != NULL)
	{
		retorno = 0;
		if(idTipo == 1)
		{
			strcpy(dificultadTxt, "FACIL");
		}
		else
		{
			if(idTipo == 2)
			{
				strcpy(dificultadTxt, "NORMAL");
			}
			else
			{
				if(idTipo == 3)
				{
					strcpy(dificultadTxt, "DIFICIL");
				}
				else
				{
					retorno = -1;
				}

			}
		}

	}

	return retorno;
}



 ============================================================================
 Name        : RECUPERATORIO_PARCIAL_ll.c
 Author      :
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================


#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Funciones_get.h"
#include "Participante.h"


int main(void)
{

	setbuf(stdout, NULL);

		LinkedList* listaParticipantes;
		LinkedList* listaParticipantesFiltrada;
		listaParticipantes = ll_newLinkedList();

		int opcionMenu;
		char path[100];

		int flagLectura;
		flagLectura = 0;
		int flagMap = 0;


		do{
			opcionMenu = printMenu(1, 6, "\n1-Leer archivo Participantes\n2-Ordenar lista\n3-Imprimir lista por consola\n4- filtrar lista participantes\n5- Generar archivo csv, lista filtrada\n6- Salir");
			switch(opcionMenu)
			{
			case 1:
				if(flagLectura == 0)
				{
					getString(path, 100, "\nIngrese la direccion del archivo: ");
					if(leerArchivo(path, listaParticipantes) == 0){
						flagLectura = 1;
					}
				}
				else{
					printf("\nEl archivo solo puede leerse una vez..");
				}
				break;
			case 2:
				 ordenarLista(listaParticipantes);
				break;
			case 3:
				if(flagLectura == 0){
					printf("\nCargue la lista antes de imprimir, opcion 1.");
				}
				else
				{
					printList(listaParticipantes);
				}
				break;
			case 4:
				flagMap = 1;
				listaParticipantesFiltrada = filtrarLista(listaParticipantes);
				break;
			case 5:
				if(flagMap == 0)
				{
					printf("\nfiltre antes de guardar");
				}
				else
				{
					guardarEnArchivoTxt("filtrado.csv", listaParticipantesFiltrada);
				}

				break;
			case 6:

				printf("\nSaliendo del menu principal..");

				break;

			}


		}while(opcionMenu != 6);


		ll_deleteLinkedList(listaParticipantes);
		ll_deleteLinkedList(listaParticipantesFiltrada);





	return EXIT_SUCCESS;
}







 */


