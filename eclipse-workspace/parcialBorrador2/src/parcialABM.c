/*
 * parcialABM.c
 *
 *  Created on: 30 abr 2022
 *      Author: SEBASTIAN SERRANO
 */

/* ****** INCLUDES ****** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "parcialABM.h"
#include "getters.h"


/* ***************************************************************
****  AUTOINCREMENTALES  ****
static int obtenerIdAlbum(void);
static int obtenerIdArtista(void);
static int obtenerIdTipoArtista(void);
static int obtenerIdDiscografica(void);


static int obtenerIdAlbum(void)
{
	static int incrementalAlbum = 0;
	return incrementalAlbum++;
}

static int obtenerIdArtista(void)
{
	static int incrementalArtista = 0;
	return incrementalArtista++;
}

static int obtenerIdTipoArtista(void)
{
	static int incrementalTipoArtista = 0;
	return incrementalTipoArtista++;
}
static int obtenerIdDiscografica(void)
{
	static int incrementalDiscografica = 0;
	return incrementalDiscografica++;
}
                                             */


/* *************************************************************** */
//**** FUNCIONES GENERICAS ABM ****

//====================    UTILIDAD     ====================

int optionMenu(int min, int max, char text[])
{
	int rtn;
	int option;
	rtn = 0;

	if(text != NULL)
	{
		printf("%s", text);
		option = getInteger(min, max, "\nIngrese una opcion: ");

		rtn = option;
	}


	return rtn;
}

int initArray(sAlbum list[], int lenght)
{
	int i;
	int rtn;
	rtn = 0;

	if(list != NULL && lenght >= 0)
	{
		for(i=0;i<lenght;i++)
		{
			list[i].estado = LIBRE;
		}
		rtn = 1;
	}


	return rtn;
}

int buscarPorId(sAlbum array[], int lenght, int id)
{
	int indice;
	int i;
	indice = -1;

	if(array != NULL && lenght > 0)
	{
		for(i=0;i<lenght;i++)
		{
			if(array[i].estado == OCUPADO && array[i].idAlbum == id)
			{
				indice = i;
				break;
			}
		}
	}


	return indice;
}

int buscarIndiceLibre(sAlbum array[], int lenght)
{
	int indice;
	int i;
	indice = -1;


	if(array != NULL && lenght >= 0)
	{
		for(i=0;i<lenght;i++)
		{
			if(array[i].estado == LIBRE)
			{
				indice = i;
				break;
			}
		}

	}


	return indice;
}

//MOSTRARUNALBUM
int mostrarUnAlbum(sAlbum array[], int indice)
{
	int rtn;
	rtn = 0;

	if(array != NULL && indice >= 0)
	{
		printf("\n==============================\n\n[ TITULO ] :  { %s }\n[ IMPORTE ] :  { %.2f }\n[ FECHA DE PUBLICACION ] : { %d, %d, %d }\n\n==============================", array[indice].titulo, array[indice].precio, array[indice].fechaAlbum.dia, array[indice].fechaAlbum.mes, array[indice].fechaAlbum.anio);
		rtn = 1;
	}
	else
	{
		printf("\nNo se encontro el album a imprimir.");
	}


	return rtn;
}
//MOSTRARTODOSLOSALBUMES
int mostrarAlbumes(sAlbum array[], int lenght)
{
	int rtn;
	int i;
	rtn = 0;

	if(array != NULL && lenght > 0)
	{
		for(i=0;i<lenght;i++)
		{
			if(array[i].estado == OCUPADO)
			{
				mostrarUnAlbum(array, i);
			}
		}

		rtn = 1;
	}

	return rtn;
}
//====================    ALTA     ====================


sAlbum cargaDeDatos(sArtista artistas[], sTipoArtista tipoArtistas[], sDiscografica discograficas[])
{
	sAlbum auxiliar;
	char auxTitulo[31];





	getString(auxTitulo, 31, "\nIngrese el titulo del album: ");
	strcpy(auxiliar.titulo, auxTitulo);
	auxiliar.precio = getFloat(1, 1000000, "\nIngrese el precio del album: ");
	auxiliar.fechaAlbum = getDate("\nIngrese la fecha de publicacion.");


		//MOSTRAR ARTISTAS HARDCODEADOS
		mostrarArtistas(artistas, MAX_ARTISTA);
		auxiliar.idArtista = getInteger(1, MAX_ARTISTA, "\nIngrese el ID del artista: ");

		//MOSTRAR TIPOS DE ARTISTAS DISPONIBLES (1,2)
		mostrarTiposDeArtistas(tipoArtistas, MAX_TIPO_ARTISTA);
		auxiliar.idTipoArtista = getInteger(1, MAX_TIPO_ARTISTA, "\nIngrese el ID del tipo Artista: ");

		//MOSTRAR DISCOGRAFICAS HARDCODEADAS
		mostrarDiscograficas(discograficas, MAX_DISCOGRAFICA);
		auxiliar.idDiscografica = getInteger(1, MAX_DISCOGRAFICA, "\nIngrese el ID de la discografica: ");


	return auxiliar;
}


int alta(sAlbum array[], int lenght, sArtista artistas[], sTipoArtista tipoArtistas[], sDiscografica discograficas[])
{
	int rtn;
	int index;
	sAlbum aux;
	rtn = 0;

	if(array != NULL && lenght > 0)
	{
		index = buscarIndiceLibre(array, lenght);
		if(index > -1)
		{
			aux = cargaDeDatos(artistas, tipoArtistas, discograficas);
			aux.idAlbum = index + 1;
			aux.estado = OCUPADO;
			array[index] = aux;

			rtn = 1;
		}
		else
		{
			printf("\nLista llena!");
		}

	}
	printf("ID: %d", array[index].idAlbum);  //chequeo dato momentaneamente, desp eliminar esta linea, en efecto, el id para el primer ingreso es 1, el error debe estar en como comparo ese ID EN modifcaion y revisar en baja tambien

	return rtn;
}

//====================    BAJA     ====================

int baja(sAlbum array[], int lenght)
{
	int rtn;
	int i, flagOcupado;
	int idIngresado, indice;
	char confirmacion;
	rtn = 0, flagOcupado = 0;


	if(array != NULL && lenght > 0)
	{
		for(i=0;i<lenght;i++)
		{
			if(array[i].estado == OCUPADO)
			{
				flagOcupado = 1;
				break;
			}
		}

	}


	if(flagOcupado == 1)
	{

		idIngresado = getInteger(1, lenght, "\nIngrese el ID a dar de baja: ");
		indice = buscarPorId(array, lenght, idIngresado);
		if(indice > -1)
		{
			mostrarUnAlbum(array, indice);

			confirmacion = getChar("\n¿Dar de baja? [S|N]?: ");
			while(toupper(confirmacion) != 'S' && toupper(confirmacion) != 'N')
			{
				printf("\nError, reingrese una respuesta valida [S|N]:");
				confirmacion = getChar("\n¿Dar de baja? [S|N]?: ");
			}
			if(toupper(confirmacion) == 'S')
			{
				array[indice].estado = BAJA;
				printf("\nSe ha dado de baja.");
				rtn = 1;
			}
			else
			{
				printf("\nNo se ha dado de baja.");
			}
		}
		else
		{
			printf("\nEl ID no coincide con ningun album cargado, intentelo nuevamente.");
		}
	}
	else
	{
		printf("\nNo se ha encontrado ningun album, ingrese uno (OPCION 1).");
	}

	return rtn;
}






//====================    MODIFICACION     ====================

int modificacion(sAlbum array[], int lenght)
{
	int rtn, i, flagOcupado, indice, idIngresado, opcionModificar;
	char confirmacion, auxTitulo[51];
	rtn = 0, flagOcupado = 0;

	if(array != NULL && lenght >= 0)
	{
		for(i=0;i<lenght;i++)
		{
			if(array[i].estado == OCUPADO)
			{
				flagOcupado = 1;
				break;
			}
		}
	}


	if(flagOcupado == 1)
	{
		idIngresado = getInteger(1, lenght, "\nIngrese el ID a modificar: ");
		indice = buscarPorId(array, lenght, idIngresado);

		if(indice > -1)
		{
			mostrarUnAlbum(array, indice);

			confirmacion = getChar("\n¿Desea modificarlo [S|N]?: ");
			while(toupper(confirmacion) != 'S' && toupper(confirmacion) != 'N')
			{
				confirmacion = getChar("\nError, ingrese una respuesta valida [S|N]: ");
			}

			if(toupper(confirmacion) == 'S')
			{
				do{
					opcionModificar = optionMenu(1, 4, "\n==========  MODIFICAR  ==========\n1- TITULO\n2- FECHA DE PUBLICACION\n3- IMPORTE\n4- SALIR AL MENU PRINCIPAL\n\n==============================");
						switch(opcionModificar)
						{
							case 1:
								getString(auxTitulo, 51, "\nIngrese el titulo: ");
								strcpy(array[indice].titulo,auxTitulo);
								break;
							case 2:
								array[indice].fechaAlbum = getDate("\nIngrese la fecha de publicacion.");
								break;
							case 3:
								array[indice].precio = getFloat(1, 1000000, "\nIngrese el nuevo precio: ");
								break;
							case 4:
								printf("\nHa salido al menu principal.");
								break;
						}
				}while(opcionModificar != 4);


				rtn = 1;
			}
			else
			{
				printf("\nNo se ha modificado.");
			}

		}
		else
		{
			printf("\nEl ID no coincide con ningun album cargado, intente nuevamente.");
		}

	}
	else
	{
		printf("\nNo se ha encontrado ningun album, ingrese uno (OPCION 1).");
	}


	return rtn;
}


/*void hardcodearDatosEmpleados(eEmpleado lista[], int tam)
{

//EJEMPLO-----------------------
	int i;
    int legajos[] = {1,8,9,7,2,4};
    char nombres[][50]= {"Carlos","Maria","Marcos","Pedro","Ana","Marcela"};
    char sexo[]= {'M','F','M','M','M','M'};
    float sueldosBruto[]= {22000,22000,15000,4000,21000,6000};
    int sector[]={1,2,3,1,3,2};

    for(i=0; i<tam; i++)
    {
        lista[i].legajo = legajos[i];
        strcpy(lista[i].nombre, nombres[i]);
        lista[i].sexo = sexo[i];
        lista[i].sueldoBruto = sueldosBruto[i];
        lista[i].sueldoNeto = sueldosBruto[i] * 0.85;
        lista[i].estado = OCUPADO;
        lista[i].idSector = sector[i];
    }
    */




//----------------------------HARDCODE--------------------------


int cargaForzadaEstructuras(sArtista artistas[], int lenghtArtistas, sTipoArtista tipoArtistas[], int lenghtTipoArtista, sDiscografica discograficas[], int lenghtDiscografica)
{
	int rtn;
	rtn = 0;


	if(artistas != NULL && tipoArtistas != NULL && discograficas != NULL && lenghtArtistas > 0  && lenghtTipoArtista > 0  && lenghtDiscografica > 0)
	{
		hardcodeArtistas(artistas, lenghtArtistas);
		hardcodeTipoDeArtistas(tipoArtistas,  lenghtTipoArtista);
		hardcodeDiscograficas(discograficas, lenghtDiscografica);
		rtn = 1;
	}


	return rtn;
}

int hardcodeArtistas(sArtista artista[], int lenght)
{
	int rtn, i;
	rtn = 0;

	char nombres[][50] = {"Luis Alberto Scaloneta", "Miles Davits", "Astor Piazzolo", "Led Zeppelines", "Mercedes Sopa"};


	if(artista != NULL && lenght > 0)
	{
		for(i=0;i<lenght;i++)
		{
			strcpy(artista[i].nombre, nombres[i]);
			artista[i].idArtista = i+1;
		}

		rtn = 1;
	}

	return rtn;
}

int hardcodeTipoDeArtistas(sTipoArtista tipoArtista[], int lenght)   //DUDA CON QUE CORRESPONDE A DESCRIPCION , A 1,2 Y A INCREMENTO
{
	int rtn, i;
	rtn = 0;


	char descripcion[][50] = {"Solista", "Banda"};

	if(tipoArtista != NULL)
	{
		for(i=0;i<lenght;i++)
		{
			strcpy(tipoArtista[i].descripcion, descripcion[i]);
			tipoArtista[i].idTipoArtista = i + 1;
		}

		rtn = 1;
	}

	return rtn;
}

int hardcodeDiscograficas(sDiscografica discografica[], int lenght)
{
	int rtn, i;
	rtn = 0;

	char auxDiscografica[][50] = {"Libertad", "Soles", "Cielo Azul Records", "Plug Records", "New Wave Records"};


	if(discografica != NULL && lenght >= 0)
	{
		for(i=0;i<lenght;i++)
		{
			strcpy(discografica[i].descripcion, auxDiscografica[i]);
			discografica[i].idDiscografica = i + 1;
		}

		rtn = 1;
	}

	return rtn;
}

//----------------------------MOSTRAR ESTRUCTURAS PERIFERICAS--------------------------

int mostrarArtistas(sArtista artistas[], int lenght)
{
	int i;
	int rtn;
	rtn = 0;

	if(artistas != NULL && lenght > 0)
	{
		printf("\n\n==========  ARTISTAS  ==========\n");
		for(i=0;i<lenght;i++)
		{
			printf("\n[ NOMBRE ]  :  { %s }", artistas[i].nombre);
			printf("\n[ ID ]  :  { %d }\n", artistas[i].idArtista);
		}
		rtn = 1;
	}


	return rtn;
}
int mostrarTiposDeArtistas(sTipoArtista  tipoArtistas[], int lenght)
{
	int i;
	int rtn;
	rtn = 0;

	if(tipoArtistas != NULL && lenght > 0)
	{
		printf("\n\n==========  TIPOS DE ARTISTA  ==========\n");

		for(i=0;i<lenght;i++)
		{
			printf("\n[ TIPO ]  :  { %s }", tipoArtistas[i].descripcion);
			printf("\n[ ID ]  :  { %d }\n", tipoArtistas[i].idTipoArtista);
		}

		rtn = 1;
	}



	return rtn;
}
int mostrarDiscograficas(sDiscografica discograficas[], int lenght)
{
	int i;
	int rtn;
	rtn = 0;

	if(discograficas != NULL && lenght > 0)
	{
		printf("\n\n==========  DISCOGRAFICAS  ==========\n");

		for(i=0;i<lenght;i++)
		{
			printf("\n[ NOMBRE ]  :  { %s }", discograficas[i].descripcion);
			printf("\n[ ID ]  :  { %d }\n", discograficas[i].idDiscografica);
		}

		rtn = 1;
	}


	return rtn;
}














