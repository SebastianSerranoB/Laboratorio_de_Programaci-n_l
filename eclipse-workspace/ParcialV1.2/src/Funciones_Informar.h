/*
 * Funciones_Informar.h
 *
 *  Created on: 3 may 2022
 *      Author: admin
 */

#ifndef FUNCIONES_INFORMAR_H_
#define FUNCIONES_INFORMAR_H_


#include "Entidades.h"

//****  FUNCIONES INFORMAR  ****

/**
 * @brief	Recibe un arreglo de tipo struct "sAlbum" que sera la base para realizar diferentes calculos relativos a los valores de este arreglo,
 * 			informa los resultados obtenidos.
 *
 * @param array []		-Recibe un arreglo de elementos del tipo struct "sAlbum".
 * @param lenght		-La cantidad de elementos que constituyen el arreglo array[];
 *
 * @return Retorna (0) si el array[] es NULL(invalido) o lenght es menor a 1 o si no se encuentran elementos dados de ALTA en el arreglo, de caso contrario retorna (1);
 */
int informar(sAlbum array[], int lenght);


#endif /* FUNCIONES_INFORMAR_H_ */
