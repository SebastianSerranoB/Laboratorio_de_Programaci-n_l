/*
 ============================================================================
 Name        : pruebasTP2.c
 Author      : Serrano Belloso Sebastian
 Version     :
 Copyright   : 
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char getName(char name[], leng);
int main(void) {
	setbuf(stdout, NULL);



	return EXIT_SUCCESS;
}

int getIdPassenger(sPassenger passengerList[], int passengerLen, Sflight flightList[], int flightLen)
{
	int id;
	int index;


	id = getInt(1, passengerLen, "\nEnter passenger's ID: ");
	index = findPassengerById(passengerList, passengerLen, id);
	if(index < 0)
	{
		id = getInt(0, passengerLen,"\nID not found, try again: ");
		index = findPassengerById(passengerList, passengerLen, id);
	}


	return index;
}

char isId(sPassenger passenger, sFlight list, int len, char text[])
{
	char option;

	printPassenger(passenger, list, len);
	option = getChar(text);

	while(toupper(option) != 'Y' && toupper(option) != 'N')
	{
		option = getChar("\nError, enter a valid option: 'Y' or 'N' : ");
	}


	return option;
}
/*
int getIdPassenger(sPassenger passengerList[], int passengerLen, Sflight flightList[], int flightLen);
char isId(sPassenger passenger, sFlight list, int len, char text[]);
*/

