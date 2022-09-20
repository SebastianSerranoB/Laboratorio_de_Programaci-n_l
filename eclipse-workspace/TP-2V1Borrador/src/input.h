/*
 * input.h
 *
 *  Created on: 25 may 2022
 *      Author: admin
 */

#ifndef INPUT_H_
#define INPUT_H_

void getString(char string[], int lenght, char text[]);
int stringEmpty(char string[]);
int isInteger(char auxInteger[]);
int getInt(int min, int max, char text[]);
int isFloat(char auxFloat[]);
float getFloat(float min, float max, char text[]);
char getChar(char text[]);
void getName(char string[], int lenght, char text[]);
int isName(char string[]);

#endif /* INPUT_H_ */
