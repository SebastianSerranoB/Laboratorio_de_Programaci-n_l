/*
 * arrayPassenger.c
 *
 *Borrador biblioteca funciones para tp2
 *  Created on: 25 abr 2022
 *      Author: admin
 */


#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "arrayPassenger.h"

//FUNCIONES PRODUCCION ALUMNO

int optionsMenu(int min, int max, char text[])
{
	int option;


	printf("%s", text);

	option = getInteger(min, max, "\n\nEnter an option:  ");

	return option;
}

sPassenger getPassenger(void)
{
	 char auxName[51];
	 char auxLastName[51];
	 char auxFlyCode[51];

	sPassenger passenger;

	getString(auxLastName, 50, "\nEnter passenger's last name: ");
	strcpy(passenger.lastName, auxLastName);

	getString(auxName, 50, "\nEnter passenger's name: ");
	strcpy(passenger.name, auxName);

	getString(auxFlyCode, 50, "\nEnter passenger's flight code: [F1 TO F5] ");
	while(strcmp(strupr(auxFlyCode),"F1") || strcmp(strupr(auxFlyCode),"F2") || strcmp(strupr(auxFlyCode),"F3") || strcmp(strupr(auxFlyCode),"F4") || strcmp(strupr(auxFlyCode),"F5"))
	{
		getString(auxFlyCode, 50, "\nFlight code not found, try again:  [F1 TO F5] ");
	}
	strcpy(passenger.flyCode, auxFlyCode);

	passenger.price = getFloat(1,1000000, "\nEnter flight price: ");

	passenger.typePassenger = getInteger(1, 4, "\nEnter type of passenger(>0 && <4) :");



	passenger.isEmpty = OCCUPIED;

	return passenger;
}

void modifyPassenger(int index, int option, sPassenger passenger[])
{
		 char auxName[51];
		 char auxLastName[51];
		 char auxFlyCode[51];

       switch(option)
       {
       case 1: //name
    	   getString(auxName, 50, "\nEnter passenger's name: ");
    	    strcpy(passenger[index].name, auxName);
    	break;

       case 2: //last name
    	   getString(auxLastName, 50, "\nEnter passenger's last name: ");
    	   strcpy(passenger[index].lastName, auxLastName);
          	break;

       case 3: //price
    	   passenger[index].price =  getFloat(1, 1000000, "\nEnter flight price: ");
          	break;

       case 4:  //flycode
    	   getString(auxFlyCode, 50, "\nEnter passenger's flight code: ");
    	   strcpy(passenger[index].flyCode, auxFlyCode);
          	break;

       case 5:    //typepassenger
    	   passenger[index].typePassenger = getInteger(1, 3, "\nEnter type of passenger(>0 && <4) :");
          	break;

       case 6:
    	   printf("\nExited to main menu.");
    	   break;
       }
}


int findEmptySlot(sPassenger array[], int lenght)
{
	int i;
	int index;
	index = -1;

	for(i=0;i<lenght;i++)
	{
		if(array[i].isEmpty == EMPTY)
		{
			index = i;
		}
	}


	return index;
}

void printOnePassenger(sPassenger array[], int index)
{
	printf("\n\n\t###############################################################     PASSENGER     ###############################################################\n\n");

	printf("|   ID   |" "\t|       NAME       |" "\t|      LAST NAME      |" "\t |      PRICE      |" "\t|      FLY CODE      |" "\t|    TYPE    |" "\t|      STATUS      |");

	printf("\n[ %d ]" "\t  [ %s ]" "\t\t   [ %s ]" "\t\t    [ %.2f ]" "\t   [ %s ]" "\t    [ %d ]" "\t   [ %d ]",
			array[index].id, array[index].name, array[index].lastName, array[index].price, array[index].flyCode, array[index].typePassenger, array[index].isEmpty);

	printf("\n\n################################################################################################################################################\n");
}


//getters alumno
int getInteger(int min, int max, char message[])
 {
 	 int integer;

 	 printf("%s", message);
 	 scanf("%d", &integer);
 	 while(integer < min || integer > max)
 	 {
 	 	 printf("\nError, re-enter an integer(> %d && < %d) :",min, max);
 	 	 scanf("%d", &integer);
 	 }

 	 return integer;
 }

float getFloat(int min, int max, char message[])
{
	float floatNumber;

	printf("%s", message);
	scanf("%f", &floatNumber);
	while(floatNumber < min || floatNumber > max)
	{
		printf("\nError, re-enter a float(> %d && < %d) :",min, max);
		scanf("%f", &floatNumber);
	}

	return floatNumber;
}

void getString(char string[], int max, char message[])
{
	printf("%s", message);
	fflush(stdin);
	gets(string);
	if((strlen(string)) < 1 || (strlen(string) > max))
	{
		printf("\nError, re-enter characters(max = %d): " , max);
		fflush(stdin);
		gets(string);
	}

}


//2. Total y promedio de los precios de los pasajes, y cuántos pasajeros superan el precio
//promedio.

void printPrices(sPassenger array[], int lenght)
{
	int counter, plusAverageCounter, i;
	float accumulator, averagePrice;

	counter = 0, accumulator = 0,plusAverageCounter = 0;

	for(i=0;i<lenght;i++)
	{
		if(array[i].isEmpty == OCCUPIED)
		{
			accumulator += array[i].price;
			counter++;
		}
	}

	averagePrice = accumulator / counter;

	for(i=0;i<lenght;i++)
	{
		if(array[i].price > averagePrice && array[i].isEmpty == OCCUPIED)
		{
			plusAverageCounter++;
		}
	}

	printf("\nThe total of prices acumulated is: %.2f", accumulator);
	printf("\nThe average price for tickets is: %.2f", averagePrice);
	if(plusAverageCounter > 0)
	{
		printf("\nThe amount of tickets with a price higher then average is: %d", plusAverageCounter);
	}
	else
	{
		printf("\nThere are no ticket prices higher then average.");
	}

}

void printCase(int printMenuOption, sPassenger array[], int lenght)
{
	int order;

	switch(printMenuOption)
	{
	case 1:
		order = getInteger(0, 1, "\nEnter order: 0 for minor to major || 1 for major to minor.");
		sortPassengers(array, lenght, order); //ojo con el sort, esta ordenando apellidos sin cambiar tambien el resto de datos del usuario
		printPassenger(array, lenght);
		break;

	case 2:
		printPrices(array, lenght);
			break;

	case 3:
		order = getInteger(0, 1, "\nEnter order: 0 for minor to major || 1 for major to minor.");
		sortPassengersByCode(array, lenght, order);
		printPassenger(array, lenght);
			break;

	case 4:
		printf("\nExited to main menu.");
			break;
	}
}

void flightStatus(sPassenger array[], int lenght)
{
	int i;


	for(i=0;i<lenght;i++)
	{
		if(array[i].isEmpty == OCCUPIED)
		{
			switch(array[i].flightData.flightID)
			{
				case "F1":
				case "F2":
					array[i].flightData.flightStatus = ACTIVE;
					break;
				case "F3":
				case "F4":
					array[i].flightData.flightStatus = DELAYED;
					break;
				case "F5":
					array[i].flightData.flightStatus = CANCELED;
					break;
			}

		}

	}
}

//FUNCIONES PEDIDAS EN LA CATEDRA
int initPassenger(sPassenger array[], int lenght)
{
	int i;

	if(array == NULL || lenght < 1)   //Null verifica direccion de memoria sea correcta, lenght que no sea menor a 1, no puede ser un array de 0
	{
		printf("\nError, send a valid parameter(!= NULL).");
		return -1;
	}

	for(i=0;i<lenght;i++)
	{
		array[i].isEmpty = 0;
	}


	return 0;
}

int addPassenger(sPassenger array[], int lenght, int id, char name[],char
lastName[],float price,int typePassenger, char flycode[])
{
	int index;

	if(array == NULL || lenght < 1)
	{
		return -1;
	}

	if(findEmptySlot(array, lenght) < 0)
	{
		return -1;
	}
	else
	{
		index = findEmptySlot(array, lenght);
	}


	strcpy(array[index].name, name);
	strcpy(array[index].lastName, lastName);
	strcpy(array[index].flyCode, flycode);
	strcpy(array[index].flightData.flightID,flycode);

	array[index].price = price;
	array[index].typePassenger = typePassenger;

	array[index].id = id;
	array[index].isEmpty = OCCUPIED;

	printf("\n\nPassenger %d(ID) successfully added", id);

	return 0;
}

int findPassengerById(sPassenger array[], int len, int id)
{
	int index;
	int i;
	index = -1;

	for(i=0;i<len;i++)
	{
		if(array[i].id == id)
		{
			index = i;
			break;
		}
	}


		return index;
}

int removePassenger(sPassenger array[], int len, int id)
{
	char confirm;

	printOnePassenger(array, id);

	printf("\n¿Delete passenger? [Y | N]");
	fflush(stdin);
	scanf("%c", &confirm);


	if(toupper(confirm) == 'Y')
	{
		array[id].isEmpty = -1;
		printf("\nPassenger removed");
	}
	else
	{
		printf("\nPassenger not removed");
	}


	return -1;
}

int sortPassengers(sPassenger array[], int len, int order)
{
	int i,j;
	char auxLastName[50];

	for(i=0;i<len;i++)
	{
		strupr(array[i].lastName);
	}



	if(order == 0)
	{
		for(i=0;i<len-1;i++)
			{
				for(j=i+1;j<len;j++)
				{
					if(strcmp(array[i].lastName, array[j].lastName) > 0)
					{
						strcpy(auxLastName, array[i].lastName);
						strcpy(array[i].lastName, array[j].lastName);
						strcpy(array[j].lastName,auxLastName);
					}
					else
					{
						if(strcmp(array[i].lastName, array[j].lastName) == 0)
						{
							if(array[i].typePassenger > array[j].typePassenger)
							{
								strcpy(auxLastName, array[i].lastName);
								strcpy(array[i].lastName, array[j].lastName);
								strcpy(array[j].lastName,auxLastName);
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
					if(strcmp(array[i].lastName, array[j].lastName) < 0)
					{
						strcpy(auxLastName, array[i].lastName);
						strcpy(array[i].lastName, array[j].lastName);
						strcpy(array[j].lastName,auxLastName);
					}
					else
					{
						if(strcmp(array[i].lastName, array[j].lastName) == 0)
						{
							if(array[i].typePassenger < array[j].typePassenger)
							{
								strcpy(auxLastName, array[i].lastName);
								strcpy(array[i].lastName, array[j].lastName);
								strcpy(array[j].lastName,auxLastName);
							}
						}
					}


				}

			}
	}


	return -1;
}

int sortPassengersByCode(sPassenger array[], int len, int order)
{
	int rtn;
	int i,j;
	char auxFlyCode[5];
	int auxFlyStatus;
	rtn = -1;

	if(array != NULL && len > 0)
	{
		if(order == 1)
		{
			for(i=0;i<len - 1;i++)
					{
						if(array[i].isEmpty == OCCUPIED)
						{
							for(j=i+1;j<len;j++)
							{
								if(strcmp(array[i].flyCode, array[j].flyCode) == 1)
								{
									strcpy(auxFlyCode, array[i].flyCode);
									strcpy(array[i].flyCode,array[j].flyCode );
									strcpy(array[j].flyCode, auxFlyCode);
								}
								else
								{
									if(strcmp(array[i].flyCode, array[j].flyCode) == 0)
									{
										if(array[i].flightData.flightStatus == array[j].flightData.flightStatus)
										{
												auxFlyStatus = array[i].flightData.flightStatus;
												array[i].flightData.flightStatus = array[j].flightData.flightStatus;
												array[j].flightData.flightStatus = auxFlyStatus;
										}
									}
								}
							}

							rtn = 0;
						}

					}

		}
		else
		{
			for(i=0;i<len - 1;i++)
					{
						if(array[i].isEmpty == OCCUPIED)
						{
							for(j=i+1;j<len;j++)
							{
								if(strcmp(array[i].flyCode, array[j].flyCode) == -1)
								{
									strcpy(auxFlyCode, array[i].flyCode);
									strcpy(array[i].flyCode,array[j].flyCode );
									strcpy(array[j].flyCode, auxFlyCode);
								}
								else
								{
									if(strcmp(array[i].flyCode, array[j].flyCode) == 0)
									{
										if(array[i].flightData.flightStatus == array[j].flightData.flightStatus)
										{
												auxFlyStatus = array[i].flightData.flightStatus;
												array[i].flightData.flightStatus = array[j].flightData.flightStatus;
												array[j].flightData.flightStatus = auxFlyStatus;
										}
									}
								}
							}

							rtn = 0;
						}

					}
		}


	}


	return rtn;
}


int printPassenger(sPassenger array[], int length)
{
	int rtn,i;
	rtn = -1;

	if(array != NULL && length > 0)
	{
		for(i=0;i<length;i++)
		{
			if(array[i].isEmpty == OCCUPIED)
			{
				printOnePassenger(array, i);
			}
		}

		rtn = 0;
	}

	return rtn;
}
