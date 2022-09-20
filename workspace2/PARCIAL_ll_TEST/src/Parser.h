/*
 * Parser.h
 *
 *  Created on: 28 jun 2022
 *      Author: admin
 */

#ifndef PARSER_H_
#define PARSER_H_

#include <stdio.h>
#include "LinkedList.h"


/** @brief Parsea los datos los datos de los elementos desde el archivo data.csv (modo texto).
 *
 * @param path char*
 * @param list LinkedList*
 * @return int
 */
int parser_ElementFromText(FILE* pFile , LinkedList* pList);

/** @brief Parsea los datos los datos de los elementos desde el archivo data.bin (modo binario).
 *
 * @param path char*
 * @param list LinkedList*
 * @return int
 */
int parser_ElementFromBinary(FILE* pFile , LinkedList* pList);



#endif /* PARSER_H_ */
