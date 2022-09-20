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
#include "Funciones_Calculos.h"
#include "Funciones_Ordenamiento.h"



int listar(sAlbum albumes[], int lenghtAlbumes, sArtista artistas[], sTipoArtista tipoArtistas[], sDiscografica discograficas[])
{
	int rtn;
	int i, j;
	int flagOcupado;
	int flagPosteriorDosMil, flagAlbumArtista, flagAlbumMasBarato;
	int opcionListar,opcionArtista;

	float menorImporteAlbum;
	float acumuladorImportes, promedioImportes;
	int contadorImportes, contadorMenorPromedio;

	rtn = 0;
	flagOcupado = 0;

	flagPosteriorDosMil = 0, flagAlbumArtista = 0, flagAlbumMasBarato = 0;

	contadorImportes = 0,contadorMenorPromedio = 0; acumuladorImportes = 0;









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
			opcionListar = optionMenu(0, 10, "\n\n========================        LISTAR        ========================\n\n0- SALIR AL MENU PRINCIPAL\n\n1- Todas las discográficas\n2- Todos los tipos de artistas musicales"
					"\n3- Todos los artistas\n4- Todos los álbumes"
					"\n5- Realizar un solo listado de los álbumes ordenados por los siguientes criterios: -Importe(descendentemente: Mayor a menor importe) o Título (ascendentemente: alfabeticamente desde Z hasta la A)"
					"\n6- Todos los álbumes cuya fecha de publicación es posterior a 31/12/1999\n7- Todos los álbumes que no superan el promedio de los importes"
					"\n8- Todos los álbumes de un artista determinado\n9- Todos los álbumes de cada año\n10- El álbum o los álbumes más baratos\n"
					"\n======================================================================");
			switch(opcionListar)
			{
			case 0 :
				printf("\nHas salido al menu Principal");
				break;
			case 1:
				mostrarDiscograficas(discograficas, MAX_DISCOGRAFICA);
				break;
			case 2:
				mostrarTiposDeArtistas(tipoArtistas, MAX_TIPO_ARTISTA);
				break;
			case 3:
				mostrarArtistas(artistas, MAX_ARTISTA);
				break;
			case 4:
				mostrarAlbumes(albumes, lenghtAlbumes);
				break;
			case 5:
				ordenarPorImporteYTitulo(albumes, lenghtAlbumes);
				mostrarAlbumes(albumes, lenghtAlbumes);
				break;
			case 6:
				//VER SI SE PUEDE PASAR A UNA FUNCION
				for(i=0;i<lenghtAlbumes;i++)
				{
					if(albumes[i].estado == OCUPADO && albumes[i].fechaAlbum.anio >= 2000)
					{
						mostrarUnAlbum(albumes, i);
						flagPosteriorDosMil = 1;
					}

				}
				if(flagPosteriorDosMil == 0)
				{
					printf("\nNo existen albumes en lista con fecha posterior al años dos mil.");
				}
				break;
			case 7:
				 //TODO ESTO EN UNA FUNCION
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
						mostrarUnAlbum(albumes, i);
						contadorMenorPromedio++;
					}
				}
				if(contadorMenorPromedio == 0)
				{
					printf("\nNo se registraron albumes con importe menor al promedio.");
				}
				break;
			case 8:
				//8. Todos los álbumes de un artista determinado.
				//MOSTRAR ARTISTAS HARDCODEADOS
						mostrarArtistas(artistas, MAX_ARTISTA);
						opcionArtista = getInteger(1, MAX_ARTISTA, "\nIngrese el ID del artista: ");
						for(i=0;i<lenghtAlbumes;i++)
						{
							if(albumes[i].idArtista == opcionArtista)
							{
								mostrarUnAlbum(albumes, i);
								flagAlbumArtista = 1;
							}
						}
						if(flagAlbumArtista == 0)
						{
							printf("\nNo se registran albumes de este artista.");
						}
				break;
			case 9:
				//9. Todos los álbumes de cada año.   //podria pasarse a funcion
				for(i=MIN_FECHA;i<MAX_FECHA+1;i++)
				{
					for(j=0;j<lenghtAlbumes;j++)
					{
						if(albumes[j].estado == OCUPADO && albumes[j].fechaAlbum.anio == i)
						{
							mostrarUnAlbum(albumes, j);
						}
					}
				}
				break;
			case 10:
				//10. El álbum o los álbumes más baratos.
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
						mostrarUnAlbum(albumes, i);
					}
				}
				break;

			}
		}while(opcionListar != 0);
	}
	else
	{
		printf("\nNo se ha encontrado ningun album en lista, ingrese uno (OPCION 1).");
		return rtn;
	}



	return rtn;
}
