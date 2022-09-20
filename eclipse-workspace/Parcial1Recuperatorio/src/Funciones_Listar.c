/*
 * Funciones_Listar.c
 *
 *  Created on: 3 may 2022
 *      Author: admin
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "Entidades.h"

#include "ABM.h"

#include "Funciones_Informar.h"
#include "Funciones_Listar.h"

#include "Funciones_Get.h"
#include "Funciones_Ordenamiento.h"



int listar(sAlbum albumes[], int lenghtAlbumes, sArtista artistas[], sTipoArtista tipoArtistas[], sDiscografica discograficas[], sPais paises[])
{
	int rtn;
	int i, j;
	int flagOcupado;
	int flagPosteriorDosMil, flagAlbumArtista, flagAlbumMasBarato,flagPais,flagAnioAlbum;
	int opcionArtista;
	char opcionListar;

	float menorImporteAlbum;
	float acumuladorImportes, promedioImportes;
	int contadorImportes, contadorMenorPromedio;
	int anioAlbum;

	rtn = 0;
	flagOcupado = 0;

	flagPosteriorDosMil = 0, flagAlbumArtista = 0, flagAlbumMasBarato = 0, flagPais = 0, flagAnioAlbum = 0;

	contadorImportes = 0,contadorMenorPromedio = 0; acumuladorImportes = 0;


/*PARTE 2:
A LO REALIZADO AGREGAR:

 Listar todos los países.
 Agregar el país al Alta y Modificación de álbumes.
 Listar todos los albumes que no sean de Argentina.
 Listar todos los albumes de Argentina que correspondan a un año determinado.*/






	//VERIRFICO NULL && LENGHT
	if(albumes != NULL && artistas != NULL && tipoArtistas != NULL && discograficas != NULL && lenghtAlbumes > 0)
	{
		for(i=0;i<lenghtAlbumes;i++)
		{
			if(albumes[i].estado == OCUPADO)
			{
				flagOcupado = 1;
				rtn = 1;
				break;
			}
		}
	}

	//PREGUNTO SI EXISTE ALGUN ALBUM EN ALTA
	if(flagOcupado == 1)
	{
		do{

				printf("\n\n========================        LISTAR        ========================\n\nZ- SALIR AL MENU PRINCIPAL\n\nA- Todas las discográficas\nB- Todos los tipos de artistas musicales"
				"\nC- Todos los artistas\nD- Todos los álbumes"
				"\nE- Realizar un solo listado de los álbumes ordenados por los siguientes criterios: -Importe(descendentemente: Mayor a menor importe) o Título (ascendentemente: alfabeticamente desde Z hasta la A)"
				"\nF- Todos los álbumes cuya fecha de publicación es posterior a 31/12/1999\nG- Todos los álbumes que no superan el promedio de los importes"
				"\nH- Todos los álbumes de un artista determinado\nI- Todos los álbumes de cada año\nJ- El álbum o los álbumes más baratos\nK- Listar todos los paises"
				"\nL- Listar todos los albumes que no sean de Argentina\nM- Listar todos los albumes de Argentina que correspondan a un año determinado"
				"\n======================================================================");


				opcionListar = getChar("\nIngrese una opcion: ");

				switch(toupper(opcionListar))
				{
				case 'A':
					mostrarDiscograficas(discograficas, MAX_DISCOGRAFICA);
						break;
				case 'B':
					mostrarTiposDeArtistas(tipoArtistas, MAX_TIPO_ARTISTA);
						break;
				case 'C':
					mostrarArtistas(artistas, MAX_ARTISTA);
						break;
				case 'D':
					mostrarAlbumes(albumes, artistas, tipoArtistas, discograficas, paises);
						break;
				case 'E':
					ordenarPorImporteYTitulo(albumes, lenghtAlbumes);
					mostrarAlbumes(albumes, artistas, tipoArtistas, discograficas, paises);
						break;
				case 'F':
					for(i=0;i<lenghtAlbumes;i++)
					{
						if(albumes[i].estado == OCUPADO && albumes[i].fechaAlbum.anio >= 2000)
						{
							mostrarUnAlbum(albumes, i, artistas, tipoArtistas, discograficas, paises);
							flagPosteriorDosMil = 1;
						}

					}
					if(flagPosteriorDosMil == 0)
					{
						printf("\nNo existen albumes en lista con fecha posterior al años dos mil.");
					}
					break;
						break;
				case 'G':
					for(i=0;i<lenghtAlbumes;i++)
					{
						if(albumes[i].estado == OCUPADO)
						{
							acumuladorImportes += albumes[i].precio;
							contadorImportes++;
						}

					}
					promedioImportes = acumuladorImportes / contadorImportes;

					for(i=0;i<lenghtAlbumes;i++)
					{
						if(albumes[i].estado == OCUPADO && albumes[i].precio < promedioImportes)
						{
							mostrarUnAlbum(albumes, i, artistas, tipoArtistas, discograficas, paises);
							contadorMenorPromedio++;
						}
					}
					if(contadorMenorPromedio == 0)
					{
						printf("\nNo se registraron albumes con importe menor al promedio.");
					}
					break;
						break;
				case 'H':
					mostrarArtistas(artistas, MAX_ARTISTA);
					opcionArtista = getInteger(1, MAX_ARTISTA, "\nIngrese el ID del artista: ");
					for(i=0;i<lenghtAlbumes;i++)
					{
						if(albumes[i].estado == OCUPADO && albumes[i].idArtista == opcionArtista)
						{
							mostrarUnAlbum(albumes, i, artistas, tipoArtistas, discograficas, paises);
							flagAlbumArtista = 1;
						}
					}

					if(flagAlbumArtista == 0)
					{
						printf("\nNo se registran albumes de este artista.");
					}
						break;
				case 'I':
					//9. Todos los álbumes de cada año.

					for(i=MIN_FECHA;i<MAX_FECHA+1;i++)
					{
						for(j=0;j<lenghtAlbumes;j++)
						{
							if(albumes[j].estado == OCUPADO && albumes[j].fechaAlbum.anio == i)
							{
								mostrarUnAlbum(albumes, j, artistas, tipoArtistas, discograficas, paises);
							}
						}
					}
						break;
				case 'J':
					for(i=0;i<lenghtAlbumes;i++)
					{
						if(albumes[i].estado == OCUPADO)
						{
							if((albumes[i].precio < menorImporteAlbum) || (flagAlbumMasBarato == 0))
							{
								menorImporteAlbum = albumes[i].precio;

								flagAlbumMasBarato = 1;
							}

						}

					}

					for(i=0;i<lenghtAlbumes;i++)
					{
						if(albumes[i].estado == OCUPADO && albumes[i].precio == menorImporteAlbum)
						{
							mostrarUnAlbum(albumes, i, artistas, tipoArtistas, discograficas, paises);
						}
					}
						break;
				case 'K':
					mostrarPaises(paises, MAX_PAISES);
						break;
				case 'L':
					for(i=0;i<lenghtAlbumes;i++)
					{
						if(albumes[i].estado == OCUPADO && albumes[i].idPais != 1)
						{
							mostrarUnAlbum(albumes, i, artistas, tipoArtistas, discograficas, paises);
							flagPais = 1;
						}
					}

					if(flagPais == 0)
					{
						printf("\nNo se encuentran albumes publicados fuera de la Argentina.");
					}
					break;
				case 'M':
					anioAlbum = getInteger(MIN_FECHA, MAX_FECHA, "\nIngrese el anio para mostrar: ");

						for(i=0;i<lenghtAlbumes;i++)
						{
							if(albumes[i].estado == OCUPADO && albumes[i].idPais == 1 && albumes[i].fechaAlbum.anio == anioAlbum)
							{
								mostrarUnAlbum(albumes, i, artistas, tipoArtistas, discograficas, paises);
								flagAnioAlbum = 1;
							}
						}
						if(flagAnioAlbum == 0)
						{
							printf("\nNo se encuentran albumes Argentinos para el anio ingresado.");
						}

						break;
				case 'Z':
					printf("\nHa salido al menu principal.");
					break;

				default:
					printf("\nOpcion no valida, intente nuevamente. ");
						break;
				}

				}while(toupper(opcionListar) != 'Z');

	}
	else
	{
		printf("\nNo se ha encontrado ningun album en lista, ingrese uno (OPCION 1).");
		return rtn;
	}



	return rtn;
}
