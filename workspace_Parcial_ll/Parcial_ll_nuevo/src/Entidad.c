#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "getters_Alumno.h"
#include "LinkedList.h"
#include "Entidad.h"




//============ CONSTRUCTOR ============//

eComputer* Computer_new()
{
	eComputer* newComputer = NULL;

	newComputer = (eComputer*)malloc(sizeof(eComputer)*1);

	if(newComputer != NULL)
	{
		strcpy(newComputer->descripcion,"");
		newComputer->id = 0;
		newComputer->idTipo = -1;
		newComputer->precio = -1;
		newComputer->cuotas = -1;
		newComputer->precioCuota = -1;

	}


	return newComputer;
}

eComputer* Computer_newParametros(char* id, char* descripcion, char* precio, char* idTipo, char* cuotas)
{
	eComputer* newComputer = NULL;
	newComputer = Computer_new();

	if(id != NULL && descripcion != NULL && precio != NULL && idTipo != NULL && cuotas != NULL)
	{
		//transformar tipo de dato si es necesario(conversor)
		//set en elemento
		//corresponde una validacion para cada atributo, ya que es recibido como texto
		computer_setCuotas(newComputer, atoi(cuotas));
		computer_setId(newComputer, atoi(id));
		computer_setDescripcion(newComputer, descripcion);
		computer_setPrecio(newComputer, atof(precio));

		computer_setIdTipo(newComputer, atoi(idTipo));

	}
	else
	{
		Computer_delete(newComputer);
		newComputer = NULL;
	}

	return newComputer;
}


//============ DESTRUCTOR ============//

int Computer_delete(eComputer* this)
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

int computer_setId(eComputer* this, int id){

	int retorno = -1;
	if(this != NULL && id >= 0)
	{
		this->id = id;
		retorno = 0;
	}

	return retorno;
}


int computer_setPrecio(eComputer* this, float precio){

	int retorno = -1;
	if(this != NULL && precio > -1)
	{
		this->precio = precio;
		retorno = 0;
	}

	return retorno;
}

int computer_setDescripcion(eComputer* this, char* descripcion){
	int retorno = -1;

	if(this != NULL && descripcion != NULL)
	{
		strcpy(this->descripcion, descripcion);
		retorno = 0;
	}
	return retorno;
}

int computer_setIdTipo(eComputer* this, int idTipo){

	int retorno = -1;

	if(this != NULL && idTipo == 1 && idTipo == 2)
	{
		this->idTipo = idTipo;
		retorno = 0;
	}
	return retorno;
}


int computer_setCuotas(eComputer* this, int cuotas){

	int retorno = -1;

	if(this != NULL && cuotas > -1)
	{
		this->cuotas = cuotas;
		retorno = 0;
	}
	return retorno;
}
int computer_setPrecioCuota(eComputer* this, float precioPorCuota)
{
	int retorno = -1;

	if(this != NULL && precioPorCuota > -1)
	{
		this->precioCuota = precioPorCuota;
		retorno = 0;
	}
	return retorno;
}




//============ GETTERS ===============//

int computer_getDescripcion(eComputer* this, char* name){
	int retorno = -1;

	if(this != NULL && name != NULL)
	{
		strcpy(name, this->descripcion);
		retorno = 0;
	}
	return retorno;
}
int computer_getId(eComputer* this, int* id){

	int retorno = -1;
	if(this != NULL && id != NULL)
	{
		*id = this->id;
		retorno = 0;
	}

	return retorno;
}
int computer_getIdTipo(eComputer* this, int* idTipo){

	int retorno = -1;
	if(this != NULL && idTipo != NULL)
	{
		*idTipo = this->idTipo;
		retorno = 0;
	}

	return retorno;
}
int computer_getIdTipoTxt(eComputer* this, int idTipo, char* tipo){

	int retorno = -1;
	if(this != NULL && tipo != NULL)
	{
		retorno = 0;
		if(idTipo == 1)
		{
			strcpy(tipo, "DESKTOP");
		}
		else
		{
			if(idTipo == 2)
			{
				strcpy(tipo, "LAPTOP");
			}
			else
			{
				retorno = -1;
			}
		}

	}

	return retorno;
}

int computer_getPrecio(eComputer* this, float* precio){

	int retorno = -1;
	if(this != NULL && precio != NULL)
	{
		*precio = this->precio;
		retorno = 0;
	}

	return retorno;
}

int computer_getCuotas(eComputer* this, int* cuotas){

	int retorno = -1;
	if(this != NULL && cuotas != NULL)
	{
		*cuotas = this->cuotas;
		retorno = 0;
	}

	return retorno;
}

int computer_getPrecioCuota(eComputer* this, float* precioPorCuota)
{
	int retorno = -1;

	if(this != NULL && precioPorCuota != NULL)
	{
		*precioPorCuota = this->precioCuota;
		retorno = 0;
	}
	return retorno;
}

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

int printOneElement(eComputer* this)
{
	int id;
	int idTipo;
	char idTipoTxt[100];
	char descripcion[300];
	float precio;
	int cuotas;

	int rtn;
	rtn = -1;


	if(this != NULL)
	{
		computer_getId(this, &id);
		computer_getDescripcion(this, descripcion);
		computer_getIdTipo(this, &idTipo);
		// traigo el idTipo que es un atributo numerico en la struct, y lo envio a idtipotxt que le asigna el texto correspondiente al ID (VALIDO PARA CUALQUIER CONVERSOR)
		//tener en cuenta, que el idTipo se envia primero por referencia cuando lo traemos, y luego lo enviamos por valor para obtener el tipoTxt
		computer_getIdTipoTxt(this, idTipo, idTipoTxt);
		computer_getPrecio(this, &precio);
		computer_getCuotas(this, &cuotas);

		printf("\n %5d\t %15s\t%.2f\t   %10s\t  %5d",id, descripcion, precio, idTipoTxt , cuotas);
			//printf("\n %5d\t %15s\t%15s\t\t  %10.2f\t  %10s\t     %15s\t  %15s",id, nombreAux, apellidoAux, precioAux, codigoVueloAux, tipoPasajeroChar, estadoVueloChar);
			rtn = 0;
	}


	return rtn;
}



//============ PRINT LISTA_ELEMENTOS ==============//

int printList(LinkedList* this)
{
	eComputer* computerAux;
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
			printf("\n  ID\t       DESCRIPCION\t\t     PRECIO\t\t   TIPO\t\t     CUOTAS");
			printf("\n================================================================================================================================================================\n");
			for(i=0;i<limite;i++)
			{
				computerAux = (eComputer*)ll_get(this, i);

				if(computerAux != NULL)
				{
					printOneElement(computerAux);
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
	eComputer* auxComputadora;


	char bufferId[128];
	char bufferDescripcion[128];
	char bufferIdTipo[128];
	char bufferPrecio[128];
	char bufferCuotas[128];

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
			if(fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n", bufferId, bufferDescripcion, bufferPrecio, bufferIdTipo, bufferCuotas) == 5)
			{
				//enviamos como char, los parametros al constructor que luego los convertira
				auxComputadora = Computer_newParametros(bufferId, bufferDescripcion, bufferPrecio, bufferIdTipo, bufferCuotas);
				if(auxComputadora != NULL)
				{
					if(ll_add(lista, auxComputadora) == 0)
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


//=========== GUARDAR ARCHIVO ==================//

int guardarEnArchivoTxt(char* path , LinkedList* this)
{
	int retorno = -1;

	char bufferDescripcion[128];
	int bufferIdTipo;
	float bufferPrecio;
	float bufferPrecioPorCuota;
	int bufferCuotas;
	int bufferId;

	int len, i;
	FILE* fpArchivo;
	eComputer* auxComputadora;

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
				auxComputadora = (eComputer*) ll_get(this, i);
				if(auxComputadora != NULL)
				{
					//traemos con el get del struct cada elemento necesario,
					computer_getId(auxComputadora, &bufferId);
					computer_getDescripcion(auxComputadora, bufferDescripcion);
					computer_getPrecio(auxComputadora, &bufferPrecio);
					computer_getIdTipo(auxComputadora, &bufferIdTipo);
					computer_getCuotas(auxComputadora, &bufferCuotas);

					//precioCuota en este caso, es un dato mas que agregamos, no existia en el original
					computer_getPrecioCuota(auxComputadora, &bufferPrecioPorCuota);


					retorno = 0;
					//con fprintf escribimos un txt
					fprintf(fpArchivo, "%d,%s,%.2f,%d,%d,%.2f\n", bufferId, bufferDescripcion, bufferPrecio, bufferIdTipo, bufferCuotas, bufferPrecioPorCuota);

				}
			}
		}
		fclose(fpArchivo);

	}
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
		if(ll_sort(this, computer_compararPorCuotas, 0) == 0)
		{
			retorno = 0;
		}
	}
	else
	{
		printf("\nNo existen elementos en lista.");
	}

	return retorno;
}


//criterios de ordenamiento
int computer_compararPorCuotas(void* e1, void* e2)
{
	int retorno = -2;
	eComputer* computadora1;
	eComputer* computadora2;
	float precio1, precio2;

	if(e1 != NULL &&  e2 != NULL)
	{
		computadora1 = (eComputer*)e1;
		computadora2 = (eComputer*)e2;
		computer_getPrecio(computadora1, &precio1);
		computer_getPrecio(computadora2, &precio2);
		if(precio1 > precio2)
		{
			retorno = 1;
		}
		else
		{
			if(precio1 < precio2)
			{
				retorno = -1;
			}
			else
			{
				retorno = 0;
			}
		}
	}
	return retorno;


}



//========= MAP =============//

LinkedList* mapearLista(LinkedList* this)
{
	LinkedList* nuevaLista = NULL;

	if(this != NULL)
	{
		nuevaLista = ll_map(this,computer_mapearPorCuotas);
	}

	return nuevaLista;
}

int computer_mapearPorCuotas(void* elemento)
{
	int retorno = -1;
	eComputer* computadora = NULL;

	int cuotas;
	float precio;
	float precioCuota;

	if(elemento != NULL)
	{
		computadora = (eComputer*) elemento;
		computer_getCuotas(computadora, &cuotas);
		computer_getPrecio(computadora, &precio);
		precioCuota = precio/cuotas;

		if(computer_setPrecioCuota(computadora, precioCuota) == 0)
		{
			retorno = 0;
		}
	}

	return retorno;
}





