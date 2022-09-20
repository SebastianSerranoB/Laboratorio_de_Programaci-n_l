/*
 * ABM.c
 *
 *  Created on: 3 may 2022
 *      Author: admin
 */


/* ****** INCLUDES ****** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "Entidades.h"

#include "ABM.h"

#include "Funciones_Informar.h"
#include "Funciones_Listar.h"

#include "Funciones_Get.h"
#include "Funciones_Calculos.h"
#include "Funciones_Ordenamiento.h"


/* ****************************************************************/




//**** FUNCIONES GENERICAS ABM ****

//====================    UTILIDAD     ====================

int optionMenu(int min, int max, char text[])
{
	int rtn;
	int option;
	rtn = -1;

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




//****  FUNCIONES MOSTRAR  ****
int mostrarUnAlbum(sAlbum array[], int indice)
{
	int rtn;
	rtn = 0;

	if(array != NULL && indice >= 0)
	{
		printf("\n==============================\n\n[ TITULO ] :  { %s }\n[ IMPORTE ] :  { %.2f }\n[ FECHA DE PUBLICACION ] : { %d, %d, %d }\n [ PAIS ] :  { %d }\n\n==============================", array[indice].titulo, array[indice].precio, array[indice].fechaAlbum.dia, array[indice].fechaAlbum.mes, array[indice].fechaAlbum.anio, array[indice].idPais);
		rtn = 1;
	}
	else
	{
		printf("\nNo se encontro el album a imprimir.");
	}


	return rtn;
}


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
				rtn = 1;
			}
		}

	}

	return rtn;
}
//====================    ALTA     ====================


sAlbum cargaDeDatos(sArtista artistas[], sTipoArtista tipoArtistas[], sDiscografica discograficas[], sPais paises[])
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

		//MOSTRAR PAISES HARDCODEADOS
		mostrarPaises(paises, MAX_PAISES);
		auxiliar.idPais = getInteger(1, MAX_PAISES, "\nIngrese el ID de el pais: ");



	return auxiliar;
}


int alta(sAlbum array[], int lenght, sArtista artistas[], sTipoArtista tipoArtistas[], sDiscografica discograficas[], sPais paises[])
{
	int rtn;
	int index;
	sAlbum aux;
	rtn = 0;

	if(array != NULL && artistas != NULL && tipoArtistas != NULL && discograficas != NULL && paises != NULL &&  lenght > 0)
	{
		index = buscarIndiceLibre(array, lenght);
		if(index > -1)
		{
			aux = cargaDeDatos(artistas, tipoArtistas, discograficas, paises);
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
		printf("\nNo se ha encontrado ningun album en lista, ingrese uno (OPCION 1).");
	}

	return rtn;
}





//====================    MODIFICACION     ====================

int modificacion(sAlbum array[], int lenght, sPais paises[])
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
					opcionModificar = optionMenu(1, 5, "\n==========  MODIFICAR  ==========\n1- TITULO\n2- FECHA DE PUBLICACION\n3- IMPORTE\n4- PAIS\n5- SALIR AL MENU PRINCIPAL\n\n==============================");
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
								mostrarPaises(paises, MAX_PAISES);
								array[indice].idPais = getInteger(1, MAX_PAISES, "\nIngrese el nuevo pais");
								break;
							case 5:
								printf("\nHa salido al menu principal.");
								break;
						}
				}while(opcionModificar != 5);


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
		printf("\nNo se ha encontrado ningun album en lista, ingrese uno (OPCION 1).");
	}


	return rtn;
}


//----------------------------MOSTRAR ESTRUCTURAS PERIFERICAS--------------------------

int mostrarArtistas(sArtista artistas[], int lenght)
{
	int i;
	int rtn;
	int flagOcupado;
	rtn = 0, flagOcupado = 0;

	if(artistas != NULL && lenght > 0)
	{
		printf("\n\n==========  ARTISTAS  ==========\n");
		for(i=0;i<lenght;i++)
		{
			if(artistas[i].estado == OCUPADO)
			{
				printf("\n[ NOMBRE ]  :  { %s }", artistas[i].nombre);
				printf("\n[ ID ]  :  { %d }\n", artistas[i].idArtista);
				flagOcupado = 1;
				rtn = 1;
			}
		}
	}

	if(flagOcupado == 0)
	{
		printf("\nNo se registrarion artistas.");
	}


	return rtn;
}
int mostrarTiposDeArtistas(sTipoArtista  tipoArtistas[], int lenght)
{
	int i;
	int rtn;
	int flagOcupado;
	rtn = 0, flagOcupado = 0;

	if(tipoArtistas != NULL && lenght > 0)
	{
		printf("\n\n==========  TIPOS DE ARTISTA  ==========\n");

		for(i=0;i<lenght;i++)
		{
			if(tipoArtistas[i].estado == OCUPADO)
			{
				printf("\n[ TIPO ]  :  { %s }", tipoArtistas[i].descripcion);
				printf("\n[ ID ]  :  { %d }\n", tipoArtistas[i].idTipoArtista);
				flagOcupado = 1;
				rtn = 1;
			}

		}

	}

	if(flagOcupado == 0)
	{
		printf("\nNo se registrarion tipos de artistas");
	}

	return rtn;
}



int mostrarDiscograficas(sDiscografica discograficas[], int lenght)
{
	int i;
	int rtn;
	int flagOcupado;
	rtn = 0, flagOcupado = 0;

	if(discograficas != NULL && lenght > 0)
	{
		printf("\n\n==========  DISCOGRAFICAS  ==========\n");

		for(i=0;i<lenght;i++)
		{
			if(discograficas[i].estado == OCUPADO)
			{
				printf("\n[ NOMBRE ]  :  { %s }", discograficas[i].descripcion);
				printf("\n[ ID ]  :  { %d }\n", discograficas[i].idDiscografica);
				flagOcupado = 1;
				rtn = 1;
			}

		}
		if(flagOcupado == 0)
		{
			printf("\nNo se registaron discograficas.");
		}

	}


	return rtn;
}

void mostrarUnaDiscografica(sDiscografica discografica[], int indice)
{
	printf("\nDiscografica: %s", discografica[indice].descripcion);
}

int mostrarPaises(sPais paises[], int lenght)
{
	int rtn;
	int i;
	int flagOcupado;
	flagOcupado = 0;
	rtn = 0;

	if(paises != NULL && lenght > 0)
	{
		printf("\n\n==========  PAISES  ==========\n");

		for(i=0;i<lenght;i++)
		{
			if(paises[i].estado == OCUPADO)
			{
				printf("\n[ NOMBRE ]  :  { %s }", paises[i].descripcion);
				printf("\n[ ID ]  :  { %d }\n", paises[i].idPais);
				flagOcupado = 1;
				rtn = 1;
			}

		}
		if(flagOcupado == 0)
		{
			printf("\nNo se registaron paises.");
		}

	}


	return rtn;
}
