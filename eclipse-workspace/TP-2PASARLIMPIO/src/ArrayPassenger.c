/*
 * ArrayPassenger.c
 *
 *  Created on: 25 may 2022
 *      Author: admin
 */

#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#include "input.h"
#include "ArrayPassenger.h"

int initPassengers(sPassenger list[], int len)
{
	int rtn;
	int i;
	rtn = -1;

	if(list != NULL && len > 0)
	{
		for(i=0;i<len;i++)
		{
			list[i].isEmpty = EMPTY;
		}
		rtn = 0;
	}

	return rtn;
}

//OTRA CARPETA?
int initFlights(sFlight list[], int len)
{
	int rtn;
	int i;
	char auxFlyCode[][11] = {"A111","B222","C333"};
	int auxFlightStatus[] = {ACTIVE, DELAYED, CANCELED};
	rtn = -1;

	if(list != NULL && len > 0)
	{
		for(i=0;i<len;i++)
		{
			list[i].flightStatus = auxFlightStatus[i];
			strcpy(list[i].flycode, auxFlyCode[i]);
		}
		rtn = 0;
	}


	return rtn;
}

int findEmptySlot(sPassenger list[], int len)
{
	int rtn;
	int index;
	rtn = -1;

	if(list != NULL && len > 0)
	{
		for(index=0;index<len;index++)
		{
			if(list[index].isEmpty == EMPTY)
			{
				rtn = index;
				break;
			}
		}
	}


	return rtn;
}

int getFlycode(char flyCode[])
{
	int rtn;
	int option;
	rtn = -1;

	if(flyCode != NULL)
	{
		rtn = 0;
		printf("\nFLIGHT CODE\n[1]A111\t\t[2]B222\t\t[3]C333");
		option = getInt(1, 3, "\nEnter flight code: ");
		if(option == 1)
		{
			strcpy(flyCode,"A111");
		}
		else
		{
			if(option == 2)
			{
				strcpy(flyCode,"B222");
			}
			else
			{
				strcpy(flyCode,"C333");
			}
		}
	}

	return rtn;
}

int getTypePassenger(void)
{
	int option;
	option = -1;

	printf("\nTYPE PASSENGER\n[1]CHILDREN\t\t[2]ADULT\t\t[3]ELDER");
	option = getInt(1, 3, "\nEnter type passenger: ");

	return option;
}

sPassenger loadPassenger(void)
{
	sPassenger auxiliar;

	getName(auxiliar.name, 51, "\nEnter passenger's first name: ");
	getName(auxiliar.lastName, 51, "\nEnter passenger's surname: ");
	auxiliar.price = getFloat(1, 1000000, "\nEnter flight price: ");
	getFlycode(auxiliar.flycode);
	auxiliar.typePassenger = getTypePassenger();

	return auxiliar;
}

int addPassenger(sPassenger list[], int len, int id, char name[],char
lastName[],float price,int typePassenger, char flycode[])
{
	int rtn;
	int index;
	rtn = -1;

	if(list != NULL && len > 0)
	{
		index = findEmptySlot(list, len);
		if(index > -1)
		{
			list[index].price = price;
			list[index].typePassenger = typePassenger;
			strcpy(list[index].lastName, lastName);
			strcpy(list[index].name, name);
			strcpy(list[index].flycode,flycode);

			list[index].id = id;
			list[index].isEmpty = OCCUPIED;
			rtn = 0;
		}
	}

	return rtn;
}

int add(sPassenger list[], int len, int idPassenger)
{
	int rtn;
	sPassenger auxiliar;
	rtn = -1;

	if(list != NULL && len > 0)
	{
		auxiliar = loadPassenger();
		if(addPassenger(list, len, idPassenger, auxiliar.name, auxiliar.lastName, auxiliar.price, auxiliar.typePassenger, auxiliar.flycode ) > -1)
		{
			rtn = 0;
		}

	}

	return rtn;
}

//MENU VA EN BIBLIOTECA APARTE DISTINTA DE ENTIDADES E INPUTS
int menu(int min, int max, char text[])
{
	int option;

	printf("%s", text);
	option = getInt(min, max,"\nEnter an option: ");


	return option;
}

//MOSTRAR TAL VES TAMBIEN
int printPassenger(sPassenger passenger, sFlight flights[], int len)
{
	int rtn;
	rtn = -1;

	if(flights != NULL && len > 0)
	{
		printf("\n\n====================  | PASSENGER |  ====================\n\n[ SURNAME ] : { %s }\t[ NAME ] : { %s }\n[ TICKET PRICE ] : { %.2f }",passenger.lastName, passenger.name, passenger.price);
		printTypePassenger(passenger);
		printFlightStatus(passenger, flights, len);
		printf("\n==========================================================\n");

		rtn = 0;
	}

	return rtn;
}

void printFlightStatus(sPassenger passenger, sFlight list[], int len)
{
	int i;

	for(i=0;i<len;i++)
	{
		if(strcmp(passenger.flycode, list[i].flycode) == 0)
		{
			printf("\n[ FLIGHT CODE ] : { %s }", passenger.flycode);
			if(list[i].flightStatus == ACTIVE){
				printf("\t[ FLIGHT STATUS ] : { ACTIVE }");
			}
			else
			{
				if(list[i].flightStatus == DELAYED){
					printf("\t[ FLIGHT STATUS ] : { DELAYED }");
				}
				else{
					printf("\t[ FLIGHT STATUS ] : { CANCELED }");
				}
			}
		}
	}


}


void printTypePassenger(sPassenger passenger)
{

	switch(passenger.typePassenger)
	{
	case 1:
		printf("\n[ TYPE ] : { CHILDREN }");
		break;
	case 2:
		printf("\n[ TYPE ] : { ADULT }");
		break;
	case 3:
		printf("\n[ TYPE ] : { ELDER }");
		break;

	default:

		break;
	}

}


int isEmpty(sPassenger list[], int len)
{
	int rtn;
	int i;
	rtn = -1;

	if(list != NULL && len > 0)
	{
		for(i=0;i<len;i++)
		{
			if(list[i].isEmpty == OCCUPIED)
			{
				rtn = 0;
				break;
			}
		}
	}

	return rtn;
}


int findPassengerById(sPassenger list[], int len,int id)
{
	int rtn;
	int i;
	rtn = -1;

	if(list != NULL && len > 0)
	{
		for(i=0;i<len;i++)
		{
			if(list[i].isEmpty == OCCUPIED && list[i].id == id)
			{
				rtn = i;
				break;
			}
		}
	}

	return rtn;
}

int getIdPassenger(sPassenger passengerList[], int passengerLen, sFlight flightList[], int flightLen)
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

char isId(sPassenger passenger, sFlight list[], int len, char text[])
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

int modifyPassenger(sPassenger passengerList[], int passengerLen, sFlight flightList[], int flightLen)
{
	int rtn;
	char option;
	int menuOption;
	int index;

	rtn = -1;

	if(passengerList != NULL && flightList != NULL && passengerLen > 0 && flightLen > 0 && isEmpty(passengerList, passengerLen) > -1)
	{

		index = getIdPassenger(passengerList, passengerLen, flightList, flightLen);
		if(index > -1)
		{
			rtn = 0;
			option = isId(passengerList[index], flightList, flightLen, "\nModify this passenger? Y o N");

				if(toupper(option) == 'Y')
				{

					do{
						menuOption = menu(1, 6, "\n\n==========================  MODIFY  ===============================\n1- NAME\n2- SURNAME\n3- FLIGHT PRICE\n4- TYPE PASSENGER\n5- FLIGHT CODE\n\n6- EXIT TO MAIN MENU\n"
												"\n===================================================================");
						switch(menuOption)
						{
							case 1:
								getString(passengerList[index].name, 51, "\nEnter passenger's first name: ");
								break;
							case 2:
								getString(passengerList[index].lastName, 51, "\nEnter passenger's surname: ");
								break;
							case 3:
								passengerList[index].price = getFloat(1, 1000000, "\nEnter flight price: ");
								break;
							case 4:
								passengerList[index].typePassenger = getTypePassenger();
								break;
							case 5:
								getFlycode(passengerList[index].flycode);
								break;

							case 6:
								printf("\nExited to main menu.");
								break;
						}
					}while(menuOption != 6);
				}
				else{
					printf("\nPassenger not modifyed.");
				}
		}
		else{
			printf("\nID not found in list, check and try again.");
		}
	}
	else{
		printf("\nError, passengers not loaded, register one (OPTION 1).");
	}


	return rtn;
}

int removeOption(sPassenger passengerList[], int passengerLen, sFlight flightList[], int flightLen)
{
	int rtn;
	int id;
	int index;
	char option;
	rtn = -1;

	if(passengerList != NULL && flightList != NULL && passengerLen > 0 && flightLen > 0 && isEmpty(passengerList, passengerLen) > -1)
	{

		id = getId(passengerList, passengerLen, flightList, flightLen);
		if(id > -1)
		{
			index = findPassengerById(passengerList, passengerLen, id);
			option = isId(passengerList[index], flightList, flightLen, "\nRemove this passenger? Y o N: ");

			if(toupper(option) == 'Y'){
				removePassenger(passengerList, passengerLen, id);
				rtn = 0;
			}
			else{
				printf("\nNo passenger's were removed.");
			}
		}
		else{
			printf("\nID not found, check and try again.");
		}
	}
	else
	{
		printf("\nError, passengers not loaded, register one (OPTION 1).");
	}


	return rtn;
}

int getId(sPassenger passengerList[], int passengerLen, sFlight flightList[], int flightLen)
{
	int id;
	int index;
	int rtn;
	rtn = -1;

	id = getInt(1, passengerLen, "\nEnter passenger's ID: ");
	index = findPassengerById(passengerList, passengerLen, id);
	if(index < 0)
	{
		id = getInt(0, passengerLen,"\nID not found, try again: ");
		index = findPassengerById(passengerList, passengerLen, id);
	}
	if(index > -1)
	{
		rtn = passengerList[index].id;
	}

	return rtn;
}


int removePassenger(sPassenger list[], int len, int id)
{
	int rtn;
	int i;
	rtn = -1;

	if(list != NULL && len > 0)
	{
		for(i=0;i<len;i++)
		{
			if(list[i].isEmpty == OCCUPIED && list[i].id == id)
			{
				rtn = 0;
				list[i].isEmpty = REMOVED;
				printf("\nPassenger was removed succesfully.");
				break;
			}
		}

	}

	return rtn;
}

int printMenu(sPassenger passengerList[], int passengerLen, sFlight flightList[], int flightLen)
{
	int rtn;
	int menuOption;
	rtn = -1;


	if(passengerList != NULL && flightList != NULL && passengerLen > 0 && flightLen > 0 && isEmpty(passengerList, passengerLen) > -1)
	{
		rtn = 0;
		do{
			menuOption = getInt(1, 4, "\n\n===========================  PRINT MENU  =============================\n"
					"\n1- PRINT SORTED BY SURNAME && TYPE\n2- PRINT TOTAL && AVERAGE PRICE TICKET && AMOUNT OF TICKET'S ABOVE AVERAGE "
					"\n3- PRINT SORTED BY FLIGHT CODE && FLIGHT STATUS\n\n4- EXIT TO MAIN MENU"
										"\n=======================================================================\n");
			switch(menuOption){
			case 1:
				printBySurname(passengerList, passengerLen, flightList, flightLen);
				break;
			case 2:
				printPriceCalculus(passengerList, passengerLen, flightList, flightLen);
				break;
			case 3:
				printByFlightCode(passengerList, passengerLen, flightList, flightLen);
				break;
			case 4:
				printf("\nExited to main menu.");
				break;
			}
		}while(menuOption != 4);

	}
	else{
		printf("\nError, passengers not loaded, register one (OPTION 1).");
	}

	return rtn;
}

int sortPassengersBySurname(sPassenger list[], int len, int order)
{
	int rtn;
	int i;
	int j;
	sPassenger aux;
	rtn = -1;


	if(list != NULL && len > 0)
	{
		rtn = 0;
		for(i=0;i<len;i++){
			if(list[i].isEmpty == OCCUPIED){
				strupr(list[i].lastName);
				strupr(list[i].name);
			}
		}

		if(order == 1)
		{
			for(i=0;i<len-1;i++)
			{
				for(j=i+1;j<len;j++)
				{
					if(strcmp(list[i].lastName, list[j].lastName) < 0)
					{
						aux = list[i];
						list[i] = list[j];
						list[j] = aux;
					}
					else
					{
						if(strcmp(list[i].lastName, list[j].lastName) == 0)
						{
							if(list[i].typePassenger < list[j].typePassenger)
							{
								aux = list[i];
								list[i] = list[j];
								list[j] = aux;
							}
						}
					}
				}
			}
		}
		else
		{
			for(i=0;i<len-1;i++)
			{
				for(j=i+1;j<len;j++)
				{
					if(strcmp(list[i].lastName, list[j].lastName) > 0)
					{
						aux = list[i];
						list[i] = list[j];
						list[j] = aux;
					}
					else
					{
						if(strcmp(list[i].lastName, list[j].lastName) == 0)
						{
							if(list[i].typePassenger > list[j].typePassenger)
							{
								aux = list[i];
								list[i] = list[j];
								list[j] = aux;
							}
						}
					}
				}
			}
		}

	}

	return rtn;
}

int sortPassengersByFlightCode(sPassenger list[], int len, int order)
{
	int rtn;
	int i;
	int j;
	sPassenger aux;
	rtn = -1;


	if(list != NULL && len > 0)
	{
		rtn = 0;
		for(i=0;i<len;i++){
			if(list[i].isEmpty == OCCUPIED){
				strupr(list[i].lastName);
				strupr(list[i].name);
			}
		}
		if(order == 1)
		{
			for(i=0;i<len-1;i++)
			{
				for(j=i+1;j<len;j++)
				{
					if(strcmp(list[i].flycode, list[j].flycode) < 0)
					{
						aux = list[i];
						list[i] = list[j];
						list[j] = aux;
					}
					else
					{
						if(strcmp(list[i].flycode, list[j].flycode) == 0)
						{
							aux = list[i];
							list[i] = list[j];
							list[j] = aux;
						}
					}
				}
			}
		}
		else
		{
			for(i=0;i<len-1;i++)
			{
				for(j=i+1;j<len;j++)
				{
					if(strcmp(list[i].flycode, list[j].flycode) < 0)
					{
						aux = list[i];
						list[i] = list[j];
						list[j] = aux;
					}
					else
					{
						if(strcmp(list[i].flycode, list[j].flycode) == 0)
						{
							aux = list[i];
							list[i] = list[j];
							list[j] = aux;
						}
					}
				}
			}
		}

	}

	return rtn;
}

int printPassengers(sPassenger passengerList[], int passengerlength, sFlight flightList[], int flightLen)
{
	int rtn;
	int i;
	rtn = -1;

	if(passengerList != NULL && flightList != NULL && passengerlength > 0 && passengerlength > 0)
	{
		rtn = 0;
		for(i=0;i<passengerlength;i++)
		{
			if(passengerList[i].isEmpty == OCCUPIED)
			{
				printPassenger(passengerList[i], flightList, flightLen);
			}
		}
	}

	return rtn;
}

int printBySurname(sPassenger passengerList[], int passengerlength, sFlight flightList[], int flightLen)
{
	int rtn;
	int option;
	rtn = -1;

	if(passengerList != NULL && flightList != NULL && passengerlength > 0 && passengerlength > 0)
	{
		rtn = 0;
		printf("\n=== SORT IN ORDER ===\n[1] ASCENDING(Z-A)\n[0] DESCENDING(A-Z)");
		option = getInt(0, 1,"\nEnter order-> '1' || '0':  ");
		sortPassengersBySurname(passengerList, passengerlength, option);
		printPassengers(passengerList, passengerlength, flightList, flightLen);
	}

	return rtn;
}

int printByFlightCode(sPassenger passengerList[], int passengerlength, sFlight flightList[], int flightLen)
{
	int rtn;
	int option;
	rtn = -1;

	if(passengerList != NULL && flightList != NULL && passengerlength > 0 && passengerlength > 0)
	{
		rtn = 0;
		printf("\n=== SORT IN ORDER ===\n[1] ASCENDING(C-A)\n[0] DESCENDING(A-C)");
		option = getInt(0, 1,"\nEnter order-> '1' || '0':  ");
		sortPassengersBySurname(passengerList, passengerlength, option);
		printPassengers(passengerList, passengerlength, flightList, flightLen);

	}

	return rtn;
}

/*
   2. Total y promedio de los precios de los pasajes, y cuántos pasajeros superan el precio
		promedio.*/

int printPriceCalculus(sPassenger passengerList[], int passengerlength, sFlight flightList[], int flightLen)
{
	int rtn;
	int i;
	int passengerCounter;
	int aboveAverageCounter;
	float average;
	float total;
	total = 0;
	passengerCounter = 0;
	aboveAverageCounter = 0;
	rtn = -1;

	if(passengerList != NULL && flightList != NULL && passengerlength > 0 && passengerlength > 0){
		rtn = 0;
		for(i=0;i<passengerlength;i++){
			if(passengerList[i].isEmpty == OCCUPIED){
				total += passengerList[i].price;
				passengerCounter++;
			}
		}
	}

	average = total / passengerCounter;

	for(i=0;i<passengerlength;i++){
		if(passengerList[i].isEmpty == OCCUPIED && passengerList[i].price > average){
			aboveAverageCounter++;
		}
	}

	if(passengerCounter > 0){
		printf("\nThe total price of tickets sold is: $%.2f, the average ticket is: $%.2f", total, average);
	}
	else{
		printf("\nNo passengers registered;");
	}

	if(aboveAverageCounter > 0){
		printf("\nThe amount of tickets higher then average price are: %d", aboveAverageCounter);
	}
	else{
		printf("\nNo price tickets registered are higher then average.");
	}

	return rtn;
}



//=====================     FORCED ENTRY //////// AUTOLOAD      ==========================
int forcedEntry(sPassenger passengerList[], int passengerLenght, int idPassenger)
{
	int rtn;
	int confirm;
	rtn = -1;

	if(passengerList != NULL && passengerLenght > 0 && freeSlot(passengerList, passengerLenght) > -1){
		confirm = getInt(1, 2, "\nLoad five passenger's? [1]-LOAD || [2]- EXIT\nEnter option: ");
		if(confirm == 1){
			autoLoad(passengerList, passengerLenght, idPassenger);
			rtn = 0;
		}
		else{
			printf("\nExited to main menu.");
		}

	}
	else{
		printf("\nNo space left for autoload, remove passengers (OPTION 2)");
	}

	return rtn;
}

int freeSlot(sPassenger passengerList[], int passengerLenght)
{
	int rtn;
	int i;
	int occupiedCounter;
	occupiedCounter = 0;


	for(i=0;i<passengerLenght;i++){
		if(passengerList[i].isEmpty == OCCUPIED || passengerList[i].isEmpty == REMOVED){
			occupiedCounter++;
		}
	}

	if(occupiedCounter > passengerLenght - 5){
		rtn = -1;
	}
	else{
		rtn = 0;
	}


	return rtn;
}

int autoLoad(sPassenger list[], int lenght, int idPassenger)
{
	int rtn;
	int i;

	char auxName[][51] = {"Astor", "Luis Alberto", "Mercedes", "Pat", "Floyd"};
	char auxLastName[][51] = {"Piazzola", "Spinetta", "Sosa", "Metheny", "Mayweather"};
	char auxFlyCode[][11] = {"C333", "C333", "A111", "B222", "A111"};
	float auxPrice[] = {31000, 26999.99, 21220.79, 250000.29, 647000.99};
	int auxTypePassenger[] = {3, 2, 3, 1, 1};


	if(list != NULL && idPassenger > 0){
		for(i=0;i<5;i++){
			idPassenger += i;
			addPassenger(list, lenght, idPassenger, auxName[i], auxLastName[i], auxPrice[i], auxTypePassenger[i], auxFlyCode[i]);
		}
		printf("\nPassenger's loaded succesfully.");
		rtn = 0;
	}

	return rtn;
}
