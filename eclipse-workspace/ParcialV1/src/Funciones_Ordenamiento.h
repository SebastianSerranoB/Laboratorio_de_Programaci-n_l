/*
 * Funciones_Ordenamiento.h
 *
 *  Created on: 3 may 2022
 *      Author: admin
 */

#ifndef FUNCIONES_ORDENAMIENTO_H_
#define FUNCIONES_ORDENAMIENTO_H_

//**** ENTIDADES ****
#include "Entidades.h"


//**** FUNCIONES DE ORDENAMIENTO PARA ARRAYS  ****

/**
 * @brief	-Recibe un arreglo de elementos y los ordena por doble criterio, comparando el importe alojado en un indice del arreglo con los demas elementos que lo constituyen;
 * 			 primero considerando el importe, ordenandolo de menor a mayor, si el importe fuera el mismo para dos elementos, se ordena alfabeticamente desde la Z a la A.
 *
 * @param albumes[]			-Recibe un arreglo de elementos de tipo struct "sAlbumes".
 * @param length			-Recibe la cantidad de elementos corrrespondiente al array albumes[].
 *
 * @return	-Devuelve (0) si el array es NULL(invalido) o la cantidad de elementos del array es menor a 1, de caso contrario, retorna (1).
 */
int ordenarPorImporteYTitulo(sAlbum albumes[], int length);


#endif /* FUNCIONES_ORDENAMIENTO_H_ */
