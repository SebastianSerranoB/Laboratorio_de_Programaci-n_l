#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Passenger.h"

/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int parser_PassengerFromText(FILE* pFile , LinkedList* pArrayListPassenger)
{
	int rtn;
	int i;
	int id;
	char name[51];
	char lastName[51];
	int isEmpty;
	rtn = 0;


	if(pFile != NULL && pArrayListPassenger != NULL)
	{
		fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", id, name, lastName,isEmpty);

		//si feof no llego al final de la linea
		    while(!feof(pFile)){
		        /* Lee los datos */
		        fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", id, name, lastName,isEmpty);

		        pArrayListPassenger[i] = persona_new();
		        persona_setId(pArrayListPassenger[i], atoi(id)); //atol atof
		        persona_setName(pArrayListPassenger[i],name);
		        persona_setLastName(pArrayListPassenger[i],lastName);

		        if(strcmp(isEmpty,"true") == 0)
		            persona_setIsEmpty(pArrayListPassenger[i],1);
		        else
		            persona_setIsEmpty(pArrayListPassenger[i],0);

		        i++;
		    }
		  rtn = 1;
	}



    return rtn;
}

/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int parser_PassengerFromBinary(FILE* pFile , LinkedList* pArrayListPassenger)
{

    return 1;
}
