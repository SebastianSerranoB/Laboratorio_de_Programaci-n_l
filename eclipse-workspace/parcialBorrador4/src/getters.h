/*
 * getters.h
 *
 *  Created on: 30 abr 2022
 *      Author: admin
 */

#ifndef GETTERS_H_
#define GETTERS_H_

#include "parcialABM.H"


int getInteger(int min, int max, char text[]);
float getFloat(int min, int max, char text[]);
int getString(char string[], int max, char text[]);
char getChar(char text[]);

sFecha getDate(char text[]);





#endif /* GETTERS_H_ */
