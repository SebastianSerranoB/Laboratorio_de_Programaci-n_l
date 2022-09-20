/*
 * ArrayPassenger.h
 *
 *  Created on: 25 may 2022
 *      Author: admin
 */

#ifndef ARRAYPASSENGER_H_
#define ARRAYPASSENGER_H_


#define OCCUPIED 1
#define REMOVED -1
#define EMPTY 0

//TAL VES OTRA BIBLIO LO DE FLIGHT
#define ACTIVE 1
#define CANCELED -1
#define DELAYED 0


#define MAX_PASSENGERS 1999
#define MAX_FLIGHTS 3

typedef struct{

	int id;
	char name[51];
	char lastName[51];
	float price;
	char flycode[10];
	int typePassenger;
	int isEmpty;

}sPassenger;

//CARPETA sfLIGHT
typedef struct{
	char flycode[10];
	int flightStatus;

}sFlight;


/** \brief To indicate that all position in the array are empty,
* this function put the flag (isEmpty) in TRUE in all
* position of the array
* \param list Passenger to array of passenger
* \param len int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int initPassengers(sPassenger list[], int len);

/** \brief add in a existing list of passengers the values received as parameters
* in the first empty position
* \param list passenger
* \param len int
* \param id int
* \param name[] char
* \param lastName[] char
* \param price float
* \param typePassenger int
* \param flycode[] char
* \return int Return (-1) if Error [Invalid length or NULL pointer or without
free space] - (0) if Ok

*/
int addPassenger(sPassenger list[], int len, int id, char name[],char
lastName[],float price,int typePassenger, char flycode[]);

/** \brief find a Passenger by Id en returns the index position in array.
*
* \param list Passenger[]
* \param len int
* \param id int
* \return Return passenger index position or (-1) if [Invalid length or
NULL pointer received or passenger not found]
*
*/

/** \brief Remove a Passenger by Id (put isEmpty Flag in 1)
*
* \param list Passenger[]
* \param len int
* \param id int
* \return int Return (-1) if Error [Invalid length or NULL pointer or if can't
find a passenger] - (0) if Ok
*
*/
int removePassenger(sPassenger list[], int len, int id);
int removeOption(sPassenger passengerList[], int passengerLen, sFlight flightList[], int flightLen);
int getId(sPassenger passengerList[], int passengerLen, sFlight flightList[], int flightLen);
int findPassengerById(sPassenger list[], int len,int id);

int modifyPassenger(sPassenger passengerList[], int passengerLen, sFlight flightList[], int flightLen);

int add(sPassenger list[], int len, int idPassenger);

int findEmptySlot(sPassenger list[], int len);

sPassenger loadPassenger(void);

int getFlycode(char flyCode[]);
int getTypePassenger(void);
int isEmpty(sPassenger list[], int len);
int printMenu(sPassenger passengerList[], int passengerLen, sFlight flightList[], int flightlen);

/** \brief Sort the elements in the array of passengers, the argument order
indicate UP or DOWN order
*
* \param list Passenger*
* \param len int
* \param order int [1] indicate UP - [0] indicate DOWN
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int sortPassengersBySurname(sPassenger list[], int len, int order);
/** \brief Sort the elements in the array of passengers, the argument order
indicate UP or DOWN order
*
* \param list Passenger*
* \param len int
* \param order int [1] indicate UP - [0] indicate DOWN

Programación I – Laboratorio I

UTN FRA – Tecnicatura Superior en Programación. http://www.sistemas-utnfra.com.ar 7
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int sortPassengersByFlightCode(sPassenger list[], int len, int order);
/** \brief print the content of passengers array
*
* \param list Passenger*
* \param length int
* \return int
*
*/
int printPassengers(sPassenger passengerList[], int passengerlength, sFlight flightList[], int flightLen);
int printBySurname(sPassenger passengerList[], int passengerlength, sFlight flightList[], int flightLen);
int printByFlightCode(sPassenger passengerList[], int passengerlength, sFlight flightList[], int flightLen);
int printPriceCalculus(sPassenger passengerList[], int passengerlength, sFlight flightList[], int flightLen);

//carga forzada
int forcedEntry(sPassenger passengerList[], int passengerLenght, int idPassenger);
int freeSlot(sPassenger passengerList[], int passengerLenght);
int autoLoad(sPassenger list[], int lenght, int idPassenger);


//MENU VA EN UNA BIBLIOTECA APARTE!! DISTITNTA DE ENTIDADES E INPUTS
int menu(int min, int max, char text[]);
//EN SFLIGHT?
int initFlights(sFlight list[], int len);

//Tal ves mostrar tambien vaya aparte
int printPassenger(sPassenger passenger, sFlight flights[], int len);
void printTypePassenger(sPassenger passenger);
void printFlightStatus(sPassenger passenger, sFlight list[], int len);

//PARA MODIFY Y REMOVE
int getIdPassenger(sPassenger passengerList[], int passengerLen, sFlight flightList[], int flightLen);
char isId(sPassenger passenger, sFlight list[], int len, char text[]);

#endif /* ARRAYPASSENGER_H_ */
