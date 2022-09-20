/*
 * Entidades.h
 *
 *  Created on: 28 jun 2022
 *      Author: admin
 */

#include "LinkedList.h"
#include <stdio.h>

typedef struct
{
	int id;
	char nombre[50];
	char apellido[50];
	float precio;

}Empleado;



//============= CONSTRUCTORES ESTRUCTURA =====================//
/**
 * @brief constructor de elementoStruct, asigna memoria para un elemento e inicializa los diferentes campos que lo componen
 *
 * @return Si puede reservar memoria, retorna un puntero a el elemento, de caso contrario, retorna NULL
 */
Empleado* Empleado_new();

/**
 * @brief constructor de elementoStruct, asigna memoria para un elemento y carga sus diferentes campos con los parametros recibidos
 *
 * @param idStr		id del elemento en formato string(char)
 * @param nombreStr	nombre del elemento en formato string(char)
 * @param apellidoStr	apellido del elemento en formato string(char)
 * @param precioStr	precio del elemento en formato string(char)

 * @return	Si puede cargar un elemento con exito, retorna un puntero al mismo, de caso contrario retorna NULL
 */
Empleado* Empleado_newParametros(char* idStr,char* nombreStr,char* apellidoStr,char* precioStr);

//==============  SETTERS/GETTERS   ====================//

int Empleado_setId(Empleado* this,int id);

/**
 * @brief	Funcion getter, asigna el ID de un elemento(this) en una variable id
 *
 * @param this	puntero a un elemento de la estructura
 * @param id	parametro donde se asignara el campo correspondiente de la estructura
 * @return	si this y el campo a asignar son != NULL retorna (0), sino, retorna (-1)
 */
int Empleado_getId(Empleado* this,int* id);

/**
 * @brief 	funcion setter para el campo nombre de elemento, recibe como parametro el nombre y lo asigna en el campo correspondiente.
 *
 * @param this	 puntero a un elemento de la estructura
 * @param nombre parametro que se asignara en en el campo nombre de la estructura
 * @return Si this y nombre son != NULL retorna (0), sino , retorna (-1)
 */
int Empleado_setNombre(Empleado* this,char* nombre);

/**
 * @brief	Funcion getter, asigna el nombre de un elemento(this) en una variable nombre
 *
 * @param this	puntero a un elemento de la estructura
 * @param nombre	parametro donde se asignara el campo correspondiente de la estructura
 * @return	si this y el campo a asignar son != NULL retorna (0), sino, retorna (-1)
 */
int Empleado_getNombre(Empleado* this,char* nombre);


/**
 * @brief 	funcion setter para el campo apellido de elemento, recibe como parametro el apellido y lo asigna en el campo correspondiente.
 *
 * @param this	 puntero a un elemento de la estructura
 * @param apellido	 parametro que se asignara en en el campo apellido de a estructura
 * @return	si this es != NULL y apellido es valido retorna (0), sino, retorna (-1)
 */
int Empleado_setApellido(Empleado* this,char* apellido);

/**
 * @brief	Funcion getter, asigna el apellido de un elemento(this) en una variable apellido
 *
 * @param this	puntero a un elemento de la estructura
 * @param apellido	parametro donde se asignara el campo correspondiente de la estructura
 * @return	si this y el campo a asignar son != NULL retorna (0), sino, retorna (-1)
 */
int Empleado_getApellido(Empleado* this,char* apellido);

/**
 * @brief 	funcion setter para el campo precio de elemento, recibe como parametro el precio y lo asigna en el campo correspondiente.
 *
 * @param this	this puntero a un elemento de la estructura
 * @param precio	 parametro que se asignara en en el campo precio de a estructura
 * @return	si this es != NULL y precio es valido retorna (0), sino, retorna (-1)
 */
int Empleado_setPrecio(Empleado* this,float precio);

/**
 * @brief	Funcion getter, asigna el precio de un elemento(this) en una variable precio
 *
 * @param this	puntero a un elemento de la estructura
 * @param precio	parametro donde se asignara el campo correspondiente de la estructura
 * @return	si this y el campo a asignar son != NULL retorna (0), sino, retorna (-1)
 */
int Empleado_getPrecio(Empleado* this,float* precio);

/**
 * @brief Si this es != NULL libera la asignacion de memoria de this (free).
 *
 * @param this	puntero a un elemento de la linkedList
 */
void Empleado_delete(Empleado* this);

//==================== PRINT =====================================//
/**
 * @brief Funcion que muestra por consola los diferentes campos del elemento recibido como parametro.
 *
 * @param this	puntero al elemento a ser mostrado
 * @return	retorna (0) si this es != NULL, de caso contrario, retorna (-1)
 */
int printOneElement(Empleado* this);

/**
 * @brief Funcion que muestra por consola todos los elementos cargados en lista
 *
 * @param pList puntero a lista de elentos.
 * @return Si pList es != NULL y existe al menos un elemento en lista, retorna (0), de caso contrario, retorna (-1)
 */
int listAllElements(LinkedList* pList);


/**
 * @brief Guarda lista linkedList en formato texto
 * @param pFile puntero al archivo donde se guardara la lista
 * @param pList puntero a la LinkedList
 * retorna(0) si ok, (-1) si ERROR
 */
int guardar_texto(FILE* pFile, LinkedList* pLista);
