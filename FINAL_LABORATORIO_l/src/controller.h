/*
 * controller.h
 *
 *  Created on: 31 ago 2022
 *      Author: admin
 */

#ifndef CONTROLLER_H_
#define CONTROLLER_H_

int controller_loadFromText(char* path , LinkedList* listaEntidad);
int controller_List(LinkedList* pListaPokemon);
int controller_map(LinkedList* pArrayList);
#endif /* CONTROLLER_H_ */
