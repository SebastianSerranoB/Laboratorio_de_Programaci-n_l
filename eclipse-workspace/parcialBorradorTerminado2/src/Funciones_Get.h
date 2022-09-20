/**
 * Funciones_Get.h
 *

 *  ALUMNO: SEBASTIAN SERRANO BELLOSO
 *  DNI: 42.810.404
 *  DIVISION: K-1
 *  MATERIA: LABORATORIO DE PROGRAMACION I
 *  PARCIAL I
 *  UTN-FRA 04/05/2022
 *
 */


#ifndef FUNCIONES_GET_H_
#define FUNCIONES_GET_H_

//INCLUDES
#include "Entidades.h"

//DEFINES PARA EL RANGO DE FECHAS PERMITIDO
#define MIN_FECHA 1990
#define MAX_FECHA 2015


//**** FUNCIONES GET ****

/**
 * @brief	Pide el ingreso de un valor de tipo integer, validandolo dentro de un rango determinado y lo retorna.
 *
 * @param min  			-Recibe el integer que sera utilizado como el menor numero permitido para el ingreso de un valor numerico tipo integer.
 * @param max			-Recibe el integer que sera utilizado como el maximo numero permitido para el ingreso de un valor numerico tipo integer.
 * @param text[]		-Recibe un arreglo de tipo char, contiene el mensaje alfanumerico que le indica al usuario que ingresar.
 *
 * @return	Retorna (0) si el array de texto es NULL(invalido), si el array es valido, retorna el entero ingresado por el usuario, previamente validado.
 */
int getInteger(int min, int max, char text[]);



/**
 * @brief				Pide el ingreso de un valor de tipo float, validandolo dentro de un rango determinado y lo retorna.
 *
 * @param min			-Recibe el numero que sera utilizado como el menor numero permitido para el ingreso de un valor numerico tipo float.
 * @param max			-Recibe el numero que sera utilizado como el mayor numero permitido para el ingreso de un valor numerico tipo float.
 * @param text[]		-Recibe un arreglo de tipo char, contiene el mensaje alfanumerico que le indica al usuario que ingresar.
 *
 * @return	Retorna (0) si el array de texto es NULL(invalido), si el array es valido, retorna el flotante ingresado por el usuario, previamente validado.
 */
float getFloat(int min, int max, char text[]);



/**
 * @brief				Pide el ingreso de una cadena de texto, validando el largo de la cadena dentro de un rango determinado.
 *
 * @param string[]		-Recibe un arreglo de tipo char, es la variable donde se alojara la cadena de texto ingresado por el usuario
 * @param max			-Recibe el numero que sera utilizado como el mayor largo permitido para el ingreso de  la cadena de texto.
 * @param text[]		-Recibe un arreglo de tipo char, contiene el mensaje alfanumerico que le indica al usuario que ingresar.
 *
 * @return	Retorna (0) si string[] o text[] son NULL(invalido), de ser validos devuelve 1
 */
int getString(char string[], int max, char text[]);



/**
 *@brief	Pide el ingreso de un caracter al usuario y lo retorna.
 *
 * @param text[] 		-Recibe un arreglo de tipo char, contiene el mensaje alfanumerico que le indica al usuario que ingresar.
 *
 * @return Retorna el caracter ingresado por le usuario.
 *
 */
char getChar(char text[]);



/**
 *@brief	Pide el ingreso de una fecha(dia, mes, anio) al usuario que sera alojada en una variable de tipo "sFecha" y la retorna validandola previamente dentro de un rango de fechas.
 *
 * @param text[]		-Recibe un arreglo de tipo char, contiene el mensaje alfanumerico que le indica al usuario que ingresar.
 *
 * @return 	Retorna la variable de tipo "sFecha" ingresada por el usuario.
 */
sFecha getDate(char text[]);



#endif /* FUNCIONES_GET_H_ */
