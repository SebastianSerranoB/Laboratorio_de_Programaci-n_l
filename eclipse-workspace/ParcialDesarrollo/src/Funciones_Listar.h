/*
 * Funciones_Listar.h
 *
 *  Created on: 3 may 2022
 *      Author: admin
 */

#ifndef FUNCIONES_LISTAR_H_
#define FUNCIONES_LISTAR_H_

#include "Entidades.h"


//****  FUNCIONES LISTAR  ****

/**
 * @brief	Funcion que recibe 4 arreglos relacionados entre si y los utiliza para realizar diferentes calculos e informarlos por consola.
 *
 * @param albumes[]			-Recibe un arreglo de tipo struct "sAlbum".
 * @param lenghtAlbumes		-La cantidad de elementos que constituyen al arreglo "albumes[]".
 * @param artistas[]		-Recibe un arreglo de tipo struct "sArtista".
 * @param tipoArtistas[]	-Recibe un arreglo de tipo struct "sTipoArtista".
 * @param discograficas[]	-Recibe un arreglo de tipo struct "sDiscografica".
 *
 * @return	Retorna (0) si alguno de los arreglos recibidos es NULL,
 * 			si  lenghtAlbumes es menor a 1 o si no se registran elementos de "albumes[]" dados de ALTA, de caso contrario, retorna (1).
 */
int listar(sAlbum albumes[], int lenghtAlbumes, sArtista artistas[], sTipoArtista tipoArtistas[], sDiscografica discograficas[], sPais paises[]);

#endif /* FUNCIONES_LISTAR_H_ */
