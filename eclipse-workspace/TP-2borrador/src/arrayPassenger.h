/*
 * arrayPassenger.h
 *
 * Borrador header file funciones para tp2 , estan las funciones requeridas en el tp2 y las personales juntas, en el tp2 final hay que separarlas segun corresponda
 *      Author: admin
 */

#ifndef ARRAYPASSENGER_H_
#define ARRAYPASSENGER_H_

// FUNCIONES Y DEF REQUERIDAS EN BIBLIOTECA TP2

typedef struct{

	int flightStatus;
	char flightID[5];
}sFlight;


typedef struct{

int id;
char name[51];
char lastName[51];
char flyCode[51];
float price;
int typePassenger;
sFlight flightData;
int isEmpty;

}sPassenger;


/**
 * \brief To indicate that all position in the array are empty,
* this function put the flag (isEmpty) in TRUE in all
* position of the array
* \param list Passenger* Pointer to array of passenger
* \param len int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*/
int initPassenger(sPassenger array[], int lenght);


/** \brief add in a existing list of passengers the values received as parameters
* in the first empty position
* \param list passenger*
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
int addPassenger(sPassenger array[], int lenght, int id, char name[],char    //HAGAMOS OTRA FUNCION DE TIPO STRUCCT QUE LLAME A ESTA, PARA SIMPLIFICAR
lastName[],float price,int typePassenger, char flycode[]);

/** \brief find a Passenger by Id en returns the index position in array.
*
* \param list Passenger*
* \param len int
* \param id int
* \return Return passenger index position or (-1) if [Invalid length or
NULL pointer received or passenger not found]
*
*/
int findPassengerById(sPassenger array[], int len,int id);

/** \brief Remove a Passenger by Id (put isEmpty Flag in 1)
*
* \param list Passenger*
* \param len int
* \param id int
* \return int Return (-1) if Error [Invalid length or NULL pointer or if can't
find a passenger] - (0) if Ok
*
*/
int removePassenger(sPassenger array[], int len, int id);

/** \brief Sort the elements in the array of passengers, the argument order
indicate UP or DOWN order
*
* \param list Passenger*
* \param len int
* \param order int [1] indicate UP - [0] indicate DOWN
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int sortPassengers(sPassenger array[], int len, int order);


/** \brief print the content of passengers array
*
* \param list Passenger*
* \param length int
* \return int
*
*/
int printPassenger(sPassenger array[], int length);


/** \brief Sort the elements in the array of passengers, the argument order
indicate UP or DOWN order
*
* \param list Passenger*
* \param len int
* \param order int [1] indicate UP - [0] indicate DOWN


* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int sortPassengersByCode(sPassenger array[], int len, int order);




//#define produccion personal
#define PELEMENTS 3 // deben ser 2000, actualmente 3 para probar
#define EMPTY 0
#define OCCUPIED 1
#define ACTIVE 1
#define DELAYED 2
#define CANCELED 3

//FUNCIONES PRODUCCION ALUMNO

/**
 * \brief shows text received in parameter, ordered in a option menu-style list, gets and returns option selected by the user.
 * @param char text[] receives  text to print  as menu in console.
 * @return returns integer as menu option entered by the user.
 */
int optionsMenu(int min, int max, char text[]);

sPassenger getPassenger(void);
int findEmptySlot(sPassenger array[], int lenght);
void modifyPassenger(int index, int option, sPassenger passenger[]);
void printOnePassenger(sPassenger array[], int index);
void printCase(int printMenuOption, sPassenger array[], int lenght);
void printPrices(sPassenger array[], int lenght);

void flightStatus(sPassenger array[], int lenght);

//getters alumno
float getFloat(int min, int max, char message[]);
int getInteger(int min, int max, char message[]);
void getString(char string[], int max, char message[]);
















#endif /* ARRAYPASSENGER_H_ */
