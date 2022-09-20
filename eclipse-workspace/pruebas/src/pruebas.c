/*
 ============================================================================
 Name        : pruebas.c
 Author      : Serrano Belloso Sebastian
 Version     :
 Copyright   : 
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>


int main(void)
{
	setbuf(stdout, NULL);
	/*int ID,TIPO, estado;
	float price = 25000.2902;
	char nombre[] = {"Lionel"};
	char apellido[] = {"messi"};
	char flycode[] = {"flycode10"};

	printf("\n\n\t#####################################################                   PASSENGER                    #####################################################\n\n");
	printf("\t|   ID   |" "\t|       NAME       |" "\t|      LAST NAME      |" "\t |      PRICE      |" "\t|      FLY CODE      |" "\t|    TYPE    |" "\t|      STATUS      |");
	printf("\n\t[ %d ]" "\t  [ %s ]" "\t\t   [ %s ]" "\t\t    [ %.2f ]" "\t   [ %s ]" "\t    [ %d ]" "\t   [ %d ]", ID, nombre, apellido, price, flycode, TIPO, estado);
	printf("\n\n\t##########################################################################################################################################################\n");*/

/*
#define ACTIVO 1
#define CANCELADO 2
#define DEMORADO 3



	typedef struct{

		int flightStatus;
		 char flightID[51];
	}sFlight;

	typedef struct{

		int id;
		char name[51];
		char flyCode[51];
		int typePassenger;

		sFlight flight;

	}sPassenger;


		sPassenger passenger[3];
		passenger[1].id = 10;
		strcpy(passenger[1].name, "SEBASTIAN");
		strcpy(passenger[1].flyCode, "101");
		passenger[1].typePassenger = 2;
		strcpy(passenger[1].flight.flightID,passenger[1].flyCode);
		passenger[1].flight.flightStatus = ACTIVO;

		if(strcmp(passenger[1].flight.flightID, "101") == 0)
		{
			passenger[1].flight.flightStatus = DEMORADO;
		}
		printf("%d", passenger[1].flight.flightStatus);



		typedef struct
		{
		    int dia;
		    int mes;
		    int anio;
		}eFecha;

		typedef struct{
			int idAutor;
			char nombre[31];
			int nacionalidad;
			eFecha fechaNac;
			int estado;
		}eAutor;
		*/





	char caracter;

	printf("\nIngrese un caracter: ");
	fflush(stdin);
	scanf("%c", &caracter);
	printf("El caracter es : %c" , caracter);



	char string[] = "\n1- Todas las discográficas\t\t2- Todos los tipos de artistas musicales\n3- Todos los artistas\t\t4- Todos los álbumes\n5- Realizar un solo listado de los álbumes ordenados por los siguientes criterios: -Importe(descendentemente) o Título (ascendentemente)\n6- Todos los álbumes cuya fecha de publicación es posterior a 31/12/1999\n7- Todos los álbumes que no superan el promedio de los importes\t\t8- Todos los álbumes de un artista determinado\n9- Todos los álbumes de cada año\t\t10- El álbum o los álbumes más baratos");


	return EXIT_SUCCESS;
}
