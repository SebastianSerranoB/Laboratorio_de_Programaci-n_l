/*
 * Participante.c
 *
 *  Created on: 4 ago 2022
 *      Author: admin
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "LinkedList.h"
#include "Funciones_get.h"
#include "Participante.h"

//============ CONSTRUCTOR ============//

eParticipante* Participante_new()
{
	eParticipante* newParticipante = NULL;

	newParticipante = (eParticipante*)malloc(sizeof(eParticipante)*1);

	if(newParticipante != NULL)
	{
		strcpy(newParticipante->nombre,"");
		newParticipante->id = 0;
		newParticipante->edad = -1;
		newParticipante->idDificultad = -1;
		newParticipante->score = -1;
	}

	return newParticipante;
}

eParticipante* Participante_newParametros(char* id, char* nombre, char* edad, char* idDificultad, char* score)
{
	eParticipante* newParticipante = NULL;
	newParticipante = Participante_new();

	if(id != NULL && nombre != NULL && edad != NULL && idDificultad != NULL && score != NULL)
	{
		//transformar tipo de dato si es necesario(conversor)
		//set en elemento
		//corresponde una validacion para cada atributo, ya que es recibido como texto
		Participante_setId(newParticipante, atoi(id));
		Participante_setEdad(newParticipante, atoi(edad));
		Participante_setNombre(newParticipante, nombre);
		Participante_setIdDificultad(newParticipante, atoi(idDificultad));
		Participante_setScore(newParticipante, atoi(score));

	}
	else
	{
		Participante_delete(newParticipante);
		newParticipante = NULL;
	}

	return newParticipante;
}


//============ DESTRUCTOR ============//

int Participante_delete(eParticipante* this)
{
	int retorno;
	retorno = -1;

	if(this != NULL)
	{
		retorno = 0;
		free(this);
	}


	return retorno;
}


//============ SETTERS ===============//

int Participante_setId(eParticipante* this, int id){

	int retorno = -1;
	if(this != NULL && id >= 0)
	{
		this->id = id;
		retorno = 0;
	}

	return retorno;
}

int Participante_setEdad(eParticipante* this, int edad){

	int retorno = -1;
	if(this != NULL && edad >= 0)
	{
		this->edad = edad;
		retorno = 0;
	}

	return retorno;
}

int Participante_setScore(eParticipante* this, int score){

	int retorno = -1;
	if(this != NULL && score >= 0)
	{
		this->score = score;
		retorno = 0;
	}

	return retorno;
}

int Participante_setNombre(eParticipante* this, char* nombre){
	int retorno = -1;

	if(this != NULL && nombre != NULL)
	{
		strcpy(this->nombre, nombre);
		retorno = 0;
	}
	return retorno;
}

int Participante_setIdDificultad(eParticipante* this, int idDificultad){

	int retorno = -1;

	if(this != NULL && idDificultad > 0 && idDificultad < 4)
	{
		this->idDificultad = idDificultad;
		retorno = 0;
	}

	return retorno;
}

//============ GETTERS ===============//

int Participante_getNombre(eParticipante* this, char* name){
	int retorno = -1;

	if(this != NULL && name != NULL)
	{
		strcpy(name, this->nombre);
		retorno = 0;
	}
	return retorno;
}
int Participante_getId(eParticipante* this, int* id){

	int retorno = -1;
	if(this != NULL && id != NULL)
	{
		*id = this->id;
		retorno = 0;
	}

	return retorno;
}

int Participante_getEdad(eParticipante* this, int* edad){

	int retorno = -1;
	if(this != NULL && edad != NULL)
	{
		*edad = this->edad;
		retorno = 0;
	}

	return retorno;
}

int Participante_getScore(eParticipante* this, int* score){

	int retorno = -1;
	if(this != NULL && score != NULL)
	{
		*score = this->score;
		retorno = 0;
	}

	return retorno;
}





int Participante_getIdDificultad(eParticipante* this, int* idDificultad){

	int retorno = -1;
	if(this != NULL && idDificultad != NULL)
	{
		*idDificultad = this->idDificultad;
		retorno = 0;
	}

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

//============ PRINT UN_ELEMENTO =============//

int printOneElement(eParticipante* this)
{
	int id;
	int idDificultad;
	char idDificultadTxt[100];
	char nombre[300];
	int score;
	int edad;

	int rtn;
	rtn = -1;


	if(this != NULL)
	{
		Participante_getEdad(this, &edad);
		Participante_getId(this, &id);
		Participante_getNombre(this, nombre);
		Participante_getScore(this, &score);
		Participante_getIdDificultad(this, &idDificultad);

		Participante_getIdDificultadTxt(this, idDificultad, idDificultadTxt);

		printf("\n %5d\t %15s\t%5d\t   %10s\t  %5d",id, nombre, edad, idDificultadTxt , score);
			rtn = 0;
	}


	return rtn;
}



//============ PRINT LISTA_ELEMENTOS ==============//

int printList(LinkedList* this)
{
	eParticipante* participanteAux;
	int i;
	int limite;
	int rtn;
	rtn = -1;

	if(this != NULL)
	{
		limite = ll_len(this);
		if(limite > 0)
		{
			printf("\n====================================================================  LISTA  ====================================================================\n");
			printf("\n  ID\t       NOMBRE\t     EDAD\t   DIFICULTAD     SCORE");
			printf("\n================================================================================================================================================================\n");
			for(i=0;i<limite;i++)
			{
				participanteAux = (eParticipante*)ll_get(this, i);

				if(participanteAux != NULL)
				{
					printOneElement(participanteAux);
					rtn = 0;
				}
			}
			printf("\n================================================================================================================================================================\n");

		}
		else
		{
			printf("\nNo existen elementos en lista.");
		}
	}


	return rtn;
}

//=========== LEER ARCHIVO =============//

// desde aqui, abrimos el archivo, luego llamamos al parser echo a medida de la estructura
int leerArchivo(char* path , LinkedList* this)
{
	int retorno = -1;
	int elementosCargados;

	FILE* fpArchivo;
	if(path != NULL && this != NULL)
	{
		//abrimos el archivo en modo lectura
		fpArchivo = fopen(path, "r");
		if(fpArchivo != NULL)
		{

			elementosCargados = parser_FromText(fpArchivo, this);
			printf("\nSe cargaron %d elementos", elementosCargados);
			retorno = 0;
		}
		fclose(fpArchivo);

	}
	return retorno;
}

//parser echo a medida dependiendo de el tipo y cantidad de atributos de una struct
int parser_FromText(FILE* pFile, LinkedList* lista)
{
	int retorno = -1;
	eParticipante* auxParticipante;


	char bufferId[128];
	char bufferNombre[128];
	char bufferIdDificultad[128];
	char bufferEdad[128];
	char bufferScore[128];

	//buffer para menu, pie
	char buffer[300];
	int contador = 0;



	if(pFile != NULL && lista != NULL)
	{
		//lee hasta encontrar el primer \n y da un enter \n
		fscanf(pFile, "%[^\n]\n", buffer);
		do
		{
			//lee 5 veces(determinado por cant, atributos por struct) las primeras 4 lo hace hasta la coma, el ultimo hasta el \n y luego \n
			if(fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n", bufferId, bufferNombre, bufferEdad, bufferIdDificultad, bufferScore) == 5)
			{
				//enviamos como char, los parametros al constructor que luego los convertira
				auxParticipante = Participante_newParametros(bufferId, bufferNombre, bufferEdad, bufferIdDificultad, bufferScore);
				if(auxParticipante != NULL)
				{
					if(ll_add(lista, auxParticipante) == 0)
					{
						//contador para la cantidad de elementos cargados, sirve como control
						contador++;
					}
				}
			}

		}while(!feof(pFile));
		//mientras no llegue al final del texto, el cursor
	}

	retorno = contador;


	return retorno;
}


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



LinkedList* filtrarLista(LinkedList* this)
{
	LinkedList* nuevaLista = NULL;

	int opcionFiltro;
	opcionFiltro = getInt(1, 3, "\nIngrese opcion de filtro: facil(1), medio(2), dificil(3)");

	if(this != NULL)
	{
		switch(opcionFiltro)
		{
			case 1:
				nuevaLista = ll_filter(this,Participante_filtrarPorDificultadFacil);
				break;
			case 2:
				nuevaLista = ll_filter(this,Participante_filtrarPorDificultadNormal);

				break;
			case 3:
				nuevaLista = ll_filter(this,Participante_filtrarPorDificultadDificil);
				break;
			}

	}

	return nuevaLista;
}

int Participante_filtrarPorDificultadFacil(void* elemento)
{
	int retorno = -1;
	eParticipante* participanteAux = NULL;

	int idDificultad;

	if(elemento != NULL)
	{
		participanteAux = (eParticipante*) elemento;
		Participante_getIdDificultad(participanteAux, &idDificultad);


		if(idDificultad == 1)
		{
			retorno = 0;
		}
	}

	return retorno;
}

int Participante_filtrarPorDificultadNormal(void* elemento)
{
	int retorno = -1;
	eParticipante* participanteAux = NULL;

	int idDificultad;


	if(elemento != NULL)
	{
		participanteAux = (eParticipante*) elemento;
		Participante_getIdDificultad(participanteAux, &idDificultad);


		if(idDificultad == 2)
		{
			retorno = 0;
		}
	}

	return retorno;
}

int Participante_filtrarPorDificultadDificil(void* elemento)
{
	int retorno = -1;
	eParticipante* participanteAux = NULL;

	int idDificultad;


	if(elemento != NULL)
	{
		participanteAux = (eParticipante*) elemento;
		Participante_getIdDificultad(participanteAux, &idDificultad);


		if(idDificultad == 3)
		{
			retorno = 0;
		}
	}

	return retorno;
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




