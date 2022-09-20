/*
 * Controller.h
 *
 *  Created on: 28 jun 2022
 *      Author: admin
 */


#include "LinkedList.h"

/**
 * @brief Lee(texto) y carga los datos de los elementos en la linkedList , desde el archivo data.csv
 *
 * @param path 	direccion del archivo que sera leido.
 * @param pArrayListPassenger puntero hacia la estructura LinkedList
 * @return	Si puede leer y cargar los datos de los elementos en la estructura, retorna (0), de caso contrario, retorna (-1)
 */
int controller_loadFromText(char* path , LinkedList* pList);

/**
 * @brief 	lee(binario) y carga los datos de los elementos en la linkedList, desde el archivo datab.bin
 *
 * @param path direccion del archivo que sera leido
 * @param pList puntero hacia la estructura LinkedList
 * @return Si puede leer y cargar los datos de los elementos en la estructura, retorna (0), de caso contrario, retorna (-1)
 */
int controller_loadFromBinary(char* path , LinkedList* pList);

/**
 * @brief	Funcion encargada de guardar los datos de la estructura linkedList  en un archivo de texto csv
 *
 * @param path direccion de el archivo donde se guardaran los datos
 * @param pList puntero a la estructura linkedList
 * @return si la lista es guardada con exito, retorna (0), de caso contrario, retorna (-1)
 */
int controller_saveAsText(char* path , LinkedList* pList);

/**
 * @brief 	Funcion encargada de guardar los datos de la estructura linkedList  en un archivo binario
 *
 * @param path	direccion de el archivo donde se guardaran los datos
 * @param plist puntero a la estructura linkedList
 * @return	si la lista es guardada con exito, retorna(0), de caso contrario, retorna (-1)
 */
int controller_saveAsBinary(char* path , LinkedList* plist);

/**
 * @brief Funcion encargada de ordenar los indices de la lista por determinado criterio
 *
 * @param pList puntero a la estructura LinkedList
 * @return Si la lista es ordenada exitosamente, retorna (0), de caso contrario retorna (-1)
 */
int controller_sortElements(LinkedList* pList);

/**
 * @brief	Funcion encargada de mostrar listados en consola los elementos cargados en la linkedList
 *
 * @param plist puntero a la estructura linkedList
 * @return Si la lista es mostrada con exito, retorna (0), de caso contrario retorna (-1)
 */
int controller_ListElements(LinkedList* pList);


/**
 * @brief	Funcion encargada de mapear una lista siguiendo determinados criterios
 *  @param plist puntero a la estructura linkedList
 * @return  retorna (0)ok, de caso contrario retorna (-1)error
 *
 */
int controller_mapList(LinkedList* pList);

/**
 * @brief	Funcion encargada de filtrar una lista siguiendo determinados criterios
 *  @param plist puntero a la estructura linkedList
 * @return  retorna (0)ok, de caso contrario retorna (-1)error
 */
int controller_filterList(LinkedList* pList);


