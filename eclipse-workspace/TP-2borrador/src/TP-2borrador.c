/*
 ============================================================================
 Name        : TP-2borrador.c
 Author      : Serrano Belloso Sebastian
 Version     : Division K-1

 Borrador TP2 biblioteca ARRAY PASSENGER Y biblioteca PERSONAL.

 DUDAS PARA CLASE PROGRAMACION Y LABORATORIO
  1- ¿A QUE SE REFIERE Y POR QUE DICE QUE ES "DESEABLE" CREAR UNA ENTIDAD PERSONAL EN LA GUIA DEL TP.2? //relacion de estructuras, segun profesor no es necesario aun..(consultar)

  2-¿LAS FUNCIONES SIEMPRE DEBEN RETORNAR ALGO? ¿CUAL ES LA MANERA CORRECTA DE UTILIZAR LOS RETURNS PARA VALIDAR, a que variable igualo la funcion en el main? (NULL, -1, 1, 0) ,UN EJEMPLO DE VALIDACION: initPassenger;

  3-¿PODEMOS LLEVAR NUESTROS #define A EL HEADERFILE.H O DEBEN ESTAR EN EL MAIN, Y EN EL SOURCEFILE.C? Si podemos, deben estar en el header y no en el c

  4-¿Tenemos que utilizar obligatoriamente la funcion addPassenger? ¿Porque debemos enviarle como parametros todos los elementos que componen la struct, en ves de mandarles el array y la posicion y que retorne la variable struct cargada?

  5-¿Explicar el calculo automatico de la ID, debemos asignarle automaticamente siguiendo cual parametro, un array de numeros ej?
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <strings.h>

#include "arrayPassenger.h"



int main(void)
{
	setbuf(stdout, NULL);

	sPassenger passenger[PELEMENTS];
	sPassenger auxPassenger;

	int mainMenuOption;
	int modifyMenuOption;
	int printMenuOption;

	int passengerId;
	int passengerIdAux;

	int indexId;
	int passengersCounter;
	passengerId = 0;
	passengersCounter = 0;



	  initPassenger(passenger, PELEMENTS);


	do
	{
		mainMenuOption = optionsMenu(1, 5, "\n\n=====================  MAIN MENU  =====================\n\n1- ADD\n2- MODIFY\n3- REMOVE\n4- PRINT LIST\n5- EXIT\n\n=======================================================");
				switch(mainMenuOption)
				{
					case 1:
						if(findEmptySlot(passenger, PELEMENTS) > -1)
						{
							passengerId++;
							auxPassenger = getPassenger();
							addPassenger(passenger, PELEMENTS, passengerId, auxPassenger.name, auxPassenger.lastName, auxPassenger.price, auxPassenger.typePassenger, auxPassenger.flyCode);

							passengersCounter++;
						}
						else
						{
							printf("\nNo empty space left, remove a passenger(option 3).");
						}
						break;

					case 2:
						if(passengersCounter > 0)
						{
								passengerIdAux = getInteger(1, PELEMENTS, "\nEnter passenger ID to modifiy: ");
								indexId = findPassengerById(passenger, PELEMENTS, passengerIdAux);
								if(indexId > -1 && passenger[indexId].isEmpty == OCCUPIED)
								{
									printOnePassenger(passenger, indexId);

									modifyMenuOption = optionsMenu(1, 6, "\n\n========== MODIFY ==========\n\n1- NAME\n2- LAST NAME\n3- PRICE\n4- FLYCODE\n5- TYPE\n6- EXIT");
									modifyPassenger(indexId, modifyMenuOption, passenger);

								}
								else
								{
									printf("\nError, passenger ID not found.");
								}

						}
						else
						{
							printf("\nNo registered passengers, add one(option 1).");
						}

						break;

					case 3:
						if(passengersCounter > 0)
						{
							passengerIdAux = getInteger(1, PELEMENTS, "\nEnter passenger ID to remove: ");
							indexId = findPassengerById(passenger, PELEMENTS, passengerIdAux);
							if(indexId > -1 && passenger[indexId].isEmpty == OCCUPIED)
							{
								removePassenger(passenger, PELEMENTS, indexId);

								passengersCounter--;
							}

						}
						else
						{
							printf("\nNo registered passengers, add one(option 1).");
						}

						break;

					case 4:
						if(passengersCounter > 0)
						{
							printMenuOption = optionsMenu(1, 4,"\n\n========== PRINT ==========\n\n1- SORTED BY SURNAME AND TYPE\n2- TOTAL AND AVERAGE FLIGHT PRICE, TICKETS HIGHER THEN AVERAGE.\n3- SORTED BY FLIGHT CODE AND FLIGHT STATUS\n4- EXIT");
							printCase(printMenuOption, passenger, PELEMENTS);
						}
						else
						{
							printf("\nNo registered passengers, add one(option 1).");
						}

						break;

					case 5:
						printf("\nExited the main menu.");
						break;

					default:
						printf("\nError, enter a valid option(1-5).");
						break;
				}

	}while(mainMenuOption != 5);






	return EXIT_SUCCESS;
}
