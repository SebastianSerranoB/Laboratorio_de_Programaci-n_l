/*
 * ABM.h
 *
 *  Created on: 3 may 2022
 *      Author: admin
 */

#ifndef ABM_H_
#define ABM_H_

#include "Entidades.h"


/* ************************************************************************************************** */
//****  FUNCIONES GENERICAS ABM ****

//****  UTILIDAD  ****

/**
 *@brief	Despliega un menu de opciones en formato texto y pide el ingreso de una opcion numerica, validandola dentro del rango posible de opciones y la retorna.
 *
 * @param min		-Recibe un valor minimo como rango de ingreso de datos.
 * @param max		-Recibe un valor maximo como rango de ingreso de datos.
 * @param text[]	-Recibe un arreglo de tipo char que contiene en formato texto, las distintas opciones de un menu y las muestra al usuario.
 *
 * @return	Retorna (-1) si el arreglo text[] es NULL(invalido), de caso contrario, retorna la opcion ingresada por el usuario.
 */
int optionMenu(int min, int max, char text[]);



/**
 * @brief				-Recibe un arreglo de tipo struct "sAlbum" y recorre sus elementos inicializando el campo "estado" en "LIBRE" para indicar que
 * 						ese indice no fue utilizado previamente ni este ocupado.
 *
 * @param list[]		-Recibe un arreglo de tipo struct "sAlbum".
 * @param lenght		-La cantidad de elementos que constituyen al arreglo list[].
 *
 * @return	Retorna (0) si el arreglo list[] es NULL o lenght es menor a 1, de caso contrario retorna (1).
 */
int initArray(sAlbum list[], int lenght);



/**
 *@brief	Recibe un arreglo de tipo struct "sAlbum" y recorre sus elementos buscando el primero que en su campo "estado" tenga el valor "LIBRE",
 *@brief	 si lo encuentra, deja de recorrer el arreglo y retorna el indice correspondiente al elemento "LIBRE"(no usado previamente ni ocupado).
 *
 * @param array[]		-Recibe un arreglo de tipo struct "sAlbum".
 * @param lenght		-La cantidad de elementos que constituyen al arreglo "array".
 *
 * @return	retorna (-1) si el arreglo recibido es NULL(invalido), si lenght es menor a 0, o si no encuentra ningun elemento del array con estado "LIBRE",
 * 			de caso contrario, retorna el indice correspondiente al elemento "LIBRE" (no utilizado previamente ni ocupado).
 */
int buscarIndiceLibre(sAlbum array[], int lenght);



/**
 *@brief	Recibe un arreglo y un identificador numerico, recorre el arreglo  buscando que coincida con ese ID, considerando que el elemento del arreglo
 *@brief	se encuentre dado de ALTA, si lo encuentra, retorna el indice correspondiente a ese elemento.
 *
 * @param array[]		-Recibe un arreglo de elemntos de tipo "sAlbum".
 * @param lenght		-La cantidad de elementos que constituyen al arreglo "array[]".
 * @param id			-Recibe un valor integer que sera utilizado como identificador para realizar una busqueda.
 *
 * @return	retorna (-1) si el array recibido es NULL(invalido), si lenght es menor a 1 o si no encuentra elementos del array en ALTA y que coincidan con el ID recibido,
 * 			de caso contrario, retorna el indice ocupado que coindice con el ID recibido.
 *
 */
int buscarPorId(sAlbum array[], int lenght, int id);






//********************** ALTA  *************************

/**
 *@brief	Recibe 5 arreglos de tipo struct relacionados entre si, recorre los indices de la estructura principal (array[],"sAlbum")
 *@brief    en busca de un elemento con estado "LIBRE" (no utilizado previamente ni ocupado), si lo encuentra le pide al usuario que ingrese valores para los distintos campos de ese elemento.
 *@brief     Finalmente se le asignan identificadores(ID) unicas  de manera automatica a cada estrcuctura y el campo "estado" del elemento en cuestion recibe el valor de "OCUPADO" (dado en alta);f
 *
 * @param array[]			-Recibe un arreglo de tipo struct "sAlubm".
 * @param lenght			-Cantidad de elementos que constituyen el arreglo array[](album).
 * @param artistas[]		-Recibe un arreglo de tipo struct "sArtista".
 * @param tipoArtistas[]	-Recibe un arreglo de tipo struct "sTipoArtista".
 * @param discograficas[]	-Recibe un arreglo de tipo struct "sDiscografica".
 * @param paises[]			-Recibe un arreglo de tipo struct "sPais".
 *
 * @return Retorna (0) si algun arreglo es NULL(invalido), si lenght es menor a 1 o si no encuentra espacios libres en el arreglo array[](album), de caso contrario, retorna (1).
 */
int alta(sAlbum array[], int lenght, sArtista artistas[], sTipoArtista tipoArtistas[], sDiscografica discograficas[], sPais paises[]);


/**
 *@brief	Funcion invocada dentro de alta(), pide al usuario el ingreso de valores para los campos (accesibles al usuario) pertenecientes a una variable de tipo struct "sAlbum" validandolos
 *@brief	y retornando esa variable cargada.
 *
 * @param artistas[]		-Recibe un arreglo de tipo struct "sArtista".
 * @param tipoArtistas[]	-Recibe un arreglo de tipo struct "sTipoArtista".
 * @param discograficas[]	-Recibe un arreglo de tipo struct "sDiscografica".
 * @param paises[]			-Recibe un arreglo de tipo struct "sPais".
 *
 * @return retorna un elemento de tipo struct "sAlbum" con valores asignados por el usuario.
 */
sAlbum cargaDeDatos(sArtista artistas[], sTipoArtista tipoArtistas[], sDiscografica discograficas[], sPais paises[]);


//********************   BAJA  *******************

/**
 *@brief	Recibe un arreglo de tipo struct "sAlbum"; si existen elementos de este arreglo dados de alta le pide al usuario el identificador(ID) del elemento a dar de baja, si el ID coincide
 *@brief	con un elemento dado de ALTA perteneciente al arreglo, lo muestra por consola y pide confirmacion de la baja al usuario, si decide darlo en baja el campo "estado" del elemento seleccionado es "BAJA"(-1).
 *
 * @param array[]		-Recibe un arreglo de tipo struct "sAlubm".
 * @param lenght		-La cantidad de elementos que constituyen el arreglo "array[]".
 *
 * @return Retorna (1) si el elemento del arreglo array[] fue dado de baja, si el arreglo  es NULL(invalido), lenght es menor a 1 o  de no haber elementos en alta retorna (0);
 */
int baja(sAlbum array[], int lenght);


//**********************   MODIFICACION   **********************

/**
 *@brief	Recibe un arreglo de tipo struct "sAlbum"; si existen elementos de este arreglo dados de alta le pide al usuario el identificador(ID) del elemento a modificar, si el ID coincide
 *@brief	con un elemento dado en ALTA perteneciente al arreglo, lo muestra por consola, le pide confirmacion de la modificacion al usuario, de acceder le pregunta  que campo desea modificar.

 * @param array[]		-Recibe un arreglo de tipo struct "sAlubm".
 * @param lenght		-La cantidad de elementos que constituyen el arreglo "array[]".
 * @param paises[]		-Recibe un arreglo de tipo struct "sPais".
 *
 * @return	 Retorna (1) si el elemento del arreglo array[] fue modificado, si el arreglo  es NULL(invalido), lenght es menor a 1 o de no haber elementos en alta retorna (0);
 */
int modificacion(sAlbum array[], int lenght, sPais paises[]);



//********************   MOSTRAR  ****************************


/**
 * @brief	Recibe un arreglo de tipo struct "sAlbum" y un indice correspondiente a un elemento de este arreglo, muestra por consola los campos que componen ese elemento.
 *
 * @param array[]		-Recibe un arreglo de tipo struct "sAlbum".
 * @param indice		-Recibe el indice del arreglo "array[]" con el que trabaja la funcion.
 *
 * @return	Retorna (0) si el arreglo recibido es NULL o el indice es menor a 0, de caso contrario, retorna (1).
 */
int mostrarUnAlbum(sAlbum array[], int indice);


/**
 * @brief	Recibe un arreglo de tipo struct "sAlbum" y recorre sus elementos imprimiendo por consola aquellos que se encuentren dados de ALTA.
 *
 * @param array[]		-Recibe un arreglo de tipo struct "sAlbum".
 * @param lenght		-Recibe la cantidad de elementos que constituyen el arreglo "array[]".
 *
 * @return	Retorna (0) si el array es NULL(invalido), si lenght es menor a 1 o si no se encuentran elementos dados en ALTA en el arreglo, de caso contrario retorna (1).
 */
int mostrarAlbumes(sAlbum array[], int lenght);


/**
 *@brief	Recibe un arreglo de tipo struct "sDiscografica" y un indice corrrespondiente a un elemento de este arreglo, imprime el contenido de ese elemento por consola.
 *
 * @param discografica[]		-Recibe un arreglo de tipo struct "sDiscografica".
 * @param indice				-El indice correspondiente al elemento del array "discografica[]".
 */
void mostrarUnaDiscografica(sDiscografica discografica[], int indice);


/**
 *@brief	Recibe un arreglo de tipo struct "sDiscografica" y  recorre sus indices imprimiendo por consola el contenido de sus elementos que se encuentren dados de ALTA.
 *
 * @param discograficas[]			-Recibe un arreglo de tipo struct "sDiscografica".
 * @param lenght					-La cantidad de elementos que constituyen el arreglo "discograficas[]".
 *
 * @return	Retorna(0) si el arreglo recibido es NULL(invalido), si lenght es menor a 1 o si no se encuentran elementos dados en ALTA en el arreglo, de caso contrario retorna (1).
 */
int mostrarDiscograficas(sDiscografica discograficas[], int lenght);


/**
 *@brief	Recibe un arreglo de tipo struct "sArtista" y  recorre sus indices imprimiendo por consola el contenido de sus elementos que se encuentren dados de ALTA.
 *
 * @param artistas[]			-Recibe un arreglo de tipo struct "sArtista".
 * @param lenght			-La cantidad de elementos que constituyen el arreglo "artistas[]".
 *
 * @return	Retorna(0) si el arreglo recibido es NULL(invalido), si lenght es menor a 1 o si no se encuentran elementos dados en ALTA en el arreglo, de caso contrario retorna (1).
 */
int mostrarArtistas(sArtista artistas[], int lenght);


/**
 *@brief	Recibe un arreglo de tipo struct "sTipoArtista" y  recorre sus indices imprimiendo por consola el contenido de sus elementos que se encuentren dados de ALTA.
 *
 * @param tipoArtistas[]			-Recibe un arreglo de tipo struct "sTipoArtista".
 * @param lenght				-La cantidad de elementos que constituyen el arreglo "tipoArtistas[]".
 *
 * @return	Retorna(0) si el arreglo recibido es NULL(invalido), si lenght es menor a 1 o si no se encuentran elementos dados en ALTA en el arreglo, de caso contrario retorna (1).
 */
int mostrarTiposDeArtistas(sTipoArtista  tipoArtistas[], int lenght);


/**
 * @brief	Recibe un arreglo de tipo struct "sPais" y  recorre sus indices imprimiendo por consola el contenido de sus elementos que se encuentren dados de ALTA.
 *
 * @param paises{}		-Recibe un arreglo de tipo struct "sPais".
 * @param lenght		-La cantidad de elementos que constituyen el arreglo "paises[]".
 *
 * @return	Retorna(0) si el arreglo recibido es NULL(invalido), si lenght es menor a 1 o si no se encuentran elementos dados en ALTA en el arreglo, de caso contrario retorna (1).
 */
int mostrarPaises(sPais paises[], int lenght);





#endif /* ABM_H_ */
