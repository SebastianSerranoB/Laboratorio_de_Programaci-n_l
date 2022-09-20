/*
 * FuncionesAlumno.h
 *
 *  Created on: 28 jun 2022
 *      Author: admin
 */

#ifndef FUNCIONESALUMNO_H_
#define FUNCIONESALUMNO_H_

//======== INCLUDES ============//
#include "LinkedList.h"

#include <stdio.h>





//==============  MENU  =================//


/**
 * @brief despliega un menu y retorna opcion elegida por usuario
 */
int printMenu(int min, int max, char textMenu[]);

//==============  SORT  =================//
/**
 * @brief	Funcion que realiza una comparacion por nombre entre dos elemento
 *
 * @param pPassengerA	puntero al primer elemento
 * @param pPassengerB	puntero al segundo elemento
 *
 * @return Retorna 1 si el nombre del primer elemento es mayor que el del segundo, 0 si son iguales y -1 si es menor.
 */
int ordenarPorNombre(void* pElementA, void* pElementB);

/**
 * @brief Funcion que realiza una comparacion por apellido entre dos elemento
 *
 * @param pPassengerA	puntero hacia el primero elemento
 * @param pPassengerB puntero hacia el segundo elemento
 *
 * @return	Retorna 1 si el apellido del primer elemento es mayor que el del segundo, 0 si son iguales y -1 si es menor.
 */
int ordenarPorApellido(void* pElementA, void* pElementB);

/**
 * @brief	Funcion que realiza una comparacion por precio entre dos elemento.
 *
 * @param pPassengerA	puntero al primer elemento
 * @param pPassengerB	puntero al segundo elemento
 *
 * @return Retorna 1 si el primero es mayor que el segundo, 0 si son iguales y -1 si es menor
 */
int ordenarPorPrecio(void* pElementA, void* pElementB);

/**
 * @brief 	Funcion que realiza una comparacion por ID entre dos elementos.
 *
 * @param pPassengerA	puntero al primer elemento
 * @param pPassengerB	puntero al segundo elemento
 *
 * @return	retorna 1 si el primero es mayor que el segundo, 0 si son iguales y -1 si es menor.
 *
 */
int ordenarPorId(void* pElementA, void* pElementB);


//========================== FILTER/CRITERIOS =========================//

int Empleado_descuento(void* pElement);

//========================= MAPEOS/CRITERIOS =================================//

int Empleado_Aumento(void* pElement);

//=============================================================================//














int salirSinGuardar(void);


//=============  VALIDACIONES--INPUTS--  ================//

/**
 * @brief	recibe en formato char los diferentes campos de la estrucrura , valida que se corresponda con el formato declarado en la estructura.
 *
 * @param idStr   		    puntero char, contiene el ID del elemento recibido como texto(char)
 * @param nombreStr			puntero char, contiene el nombre del elemento recibido como texto(char)
 * @param apellidoStr		puntero char, contiene el apellido del elemento recibido como texto(char)
 * @param precioStr			puntero char, contiene el precio del elemento recibido como texto(char)
 *
 * @return	si los parametros recibidos son != NULL y se corresponden con el formato de la estructura devuelve (0), de no ser el caso, devuelve (-1)
 */
int validarDatosElemento(char* idStr,char* nombreStr,char* apellidoStr,char* precioStr);









void getString(char string[], int lenght, char text[]);

/**
 * @brief validates emptiness of array of chars(string)
 * @param string array of chars(string)
 * @return if array of chars(string) is empty, returns 0, else, returns 1(ok).
 */
int stringEmpty(char string[]);

/**
 * @brief Validates that the string received is a valid integer number.
 * @param auxInteger array of chars(string)
 * @return if array of chars(string) is a valid integer number returns 1(ok), else, returns 0.
 */
int isInteger(char auxInteger[]);

/**
 * @brief ask's to the user, validates and returns integer.
 * @param min min integer value allowed for entry
 * @param max max integer value allowed for entry
 * @param text text to be printed as entry instructions for the user.
 * @return returns validated integer entered by the user
 */
int getInt(int min, int max, char text[]);

/**
 * @brief Validates that the array of chars(string) is a float number.
 * @param auxFloat array of chars(string)(float)
 * @return if array of chars(string) is a valid float number it returns 1(ok), else, returns 0.
 */
int isFloat(char auxFloat[]);

/**
 * @brief ask's to the user, validates and returns a float number.
 * @param min min float value allowed for entry.
 * @param max max float value allowed for entry.
 * @param text text to be printed as entry instructions for the user.
 * @return returns a validated float number, entered by the user.
 */
float getFloat(float min, float max, char text[]);

/**
 * @brief Ask's to the user and returns a char variable
 * @param text text to be printed as entry instructions for the user
 * @return returns a char variable entered by the user.
 */
char getChar(char text[]);

/**
 * @brief ask's to the user, validates and loads name
 * @param string array of char(string(name)
 * @param lenght max lenght of array of chars(string)
 * @param text text to be printed as entry instructons.
 */
void getName(char string[], int lenght, char text[]);

/**
 * @brief Validates that the array of chars(string) is a name.
 * @param string array of chars(string)
 * @return if array of chars(string) is a valid name it returns 1, else, returns 0.
 */
int isName(char string[]);
//===========================================================//


#endif /* FUNCIONESALUMNO_H_ */
