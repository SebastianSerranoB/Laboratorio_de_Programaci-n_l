/*
 ============================================================================
 Name        : Probando.c
 Author      : Serrano Belloso Sebastian
 Version     :
 Copyright   : 
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main(void)
{
	setbuf(stdout, NULL);

	/* ***********************************   FUNCIONES LISTAR    ************************************** */
	int listar(sAlbum albumes[], int lenghtAlbumes, sArtista artistas[], sTipoArtista tipoArtistas[], sDiscografica discograficas[], sPais paises[])
	{
		int rtn, flagOcupado;
		char opcionListar;
		rtn = 0;
		flagOcupado = 0;



		if(lenghtAlbumes > 0){
			rtn = 1;
			flagOcupado = estaOcupado(albumes, lenghtAlbumes);
		}

		//PREGUNTO SI EXISTE ALGUN ALBUM EN ALTA
		if(flagOcupado != 1)
		{
			printf("\nNo se ha encontrado ningun album en lista, ingrese uno (OPCION 1).");
		}
		else
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
						posteriorDosMil(albumes, lenghtAlbumes, artistas, tipoArtistas, discograficas, paises)
							break;
					case 'G':
						bajoPromedio(albumes, lenghtAlbumes, artistas, tipoArtistas, discograficas, paises)
							break;
					case 'H':
						mostrarAlbumDeUnArtista(albumes, lenghtAlbumes, artistas, tipoArtistas, discograficas, paises);
							break;
					case 'I':
						albumesPorAnio(albumes, lenghtAlbumes, artistas, tipoArtistas, discograficas, paises);
							break;
					case 'J':
						albumMasBarato(albumes, lenghtAlbumes, artistas, tipoArtistas, discograficas, paises);
							break;
					case 'K':
						mostrarPaises(paises, MAX_PAISES);
							break;
					case 'L':
						albumesNoArgentinos(albumes, lenghtAlbumes, artistas, tipoArtistas, discograficas, paises);
						break;
					case 'M':
						albumArgentinoSegunAnio(albumes,  lenghtAlbumes, artistas, tipoArtistas, discograficas, paises);
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


		return rtn;
	}



}// corchete main


//PROBANDO FUNCIONES PARA LISTAR
/*//f
void posteriorDosMil(sAlbum albumes[], int lenghtAlbumes, sArtista artistas[], sTipoArtista tipoArtistas[], sDiscografica discograficas[], sPais paises[]);
//g
void bajoPromedio(sAlbum albumes[], int lenghtAlbumes, sArtista artistas[], sTipoArtista tipoArtistas[], sDiscografica discograficas[], sPais paises[]);
//h
void mostrarAlbumDeUnArtista(sAlbum albumes[], int lenghtAlbumes, sArtista artistas[], sTipoArtista tipoArtistas[], sDiscografica discograficas[], sPais paises[]);
//i
void albumesPorAnio(sAlbum albumes[], int lenghtAlbumes, sArtista artistas[], sTipoArtista tipoArtistas[], sDiscografica discograficas[], sPais paises[]);
//j
void albumMasBarato(sAlbum albumes[], int lenghtAlbumes, sArtista artistas[], sTipoArtista tipoArtistas[], sDiscografica discograficas[], sPais paises[]);
//l
void albumesNoArgentinos(sAlbum albumes[], int lenghtAlbumes, sArtista artistas[], sTipoArtista tipoArtistas[], sDiscografica discograficas[], sPais paises[]);
//m
void albumArgentinoSegunAnio(sAlbum albumes[], int lenghtAlbumes, sArtista artistas[], sTipoArtista tipoArtistas[], sDiscografica discograficas[], sPais paises[]);*/
//CASO F

/*void posteriorDosMil(sAlbum albumes[], int lenghtAlbumes, sArtista artistas[], sTipoArtista tipoArtistas[], sDiscografica discograficas[], sPais paises[])
{
	int flagPosteriorDosMil, i;
	flagPosteriorDosMil = 0;

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

}*/

//CASO G
/*void bajoPromedio(sAlbum albumes[], int lenghtAlbumes, sArtista artistas[], sTipoArtista tipoArtistas[], sDiscografica discograficas[], sPais paises[])
{
	int i, contadorImportes, contadorMenorPromedio;
	float promedioImportes, acumuladorImportes;
	contadorImportes = 0, contadorMenorPromedio = 0, acumuladorImportes = 0;

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

}*/

//CASO H
/*void mostrarAlbumDeUnArtista(sAlbum albumes[], int lenghtAlbumes, sArtista artistas[], sTipoArtista tipoArtistas[], sDiscografica discograficas[], sPais paises[])
{
	int i, opcionArtista, flagAlbumArtista;
	flagAlbumArtista = 0;


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

}*/


//CASO I
//9. Todos los álbumes de cada año.
/*void albumesPorAnio(sAlbum albumes[], int lenghtAlbumes, sArtista artistas[], sTipoArtista tipoArtistas[], sDiscografica discograficas[], sPais paises[])
{
	int i,j;

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
}*/


//CASO J
/*void albumMasBarato(sAlbum albumes[], int lenghtAlbumes, sArtista artistas[], sTipoArtista tipoArtistas[], sDiscografica discograficas[], sPais paises[])
{
	int i, flagAlbumMasBarato;
	float menorImporteAlbum;
	flagAlbumMasBarato = 0;

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

}*/


//CASO L
/*void albumesNoArgentinos(sAlbum albumes[], int lenghtAlbumes, sArtista artistas[], sTipoArtista tipoArtistas[], sDiscografica discograficas[], sPais paises[])
{
	int i, flagPais;
	flagPais = 0;

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

}*/

//CASO M

/*void albumArgentinoSegunAnio(sAlbum albumes[], int lenghtAlbumes, sArtista artistas[], sTipoArtista tipoArtistas[], sDiscografica discograficas[], sPais paises[])
{
	int i, anioAlbum, flagAnioAlbum;
	flagAnioAlbum = 0;

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
}*/






















// LAS FUNCIONES QUE HICE PARA TODO INFORMAR
/*int informar(sAlbum array[], int lenght)
	{
		int rtn;
		int flagOcupado, opcionInformar;
		rtn = 0;



		if(lenght > 0){
			flagOcupado = estaOcupado(array, lenght);
			rtn = 1;
		}

		if(flagOcupado != 1){
			printf("\nNo se ha encontrado ningun album en lista, ingrese uno(OPCION 1).");
			return rtn;
		}
		else
		{

			do{
					opcionInformar = optionMenu(1, 3, "\n\n====================  INFORMAR  ====================\n\n1- Total, promedio de los importes, y cuántos álbumes no superan ese promedio."
													  " \n2- Cantidad de álbumes cuya fecha de publicación es posterior a 31/12/1999. \n3- SALIR AL MENU PRINCIPAL\n\n====================================================");
					switch(opcionInformar)
					{
						case 1:
							informesUno(array, lenght);
								break;
						case 2:
							informesDos(array, lenght);
								break;
						case 3:
							printf("\nHas salido al menu principal.");
								break;
					}
				}while(opcionInformar != 3);
		}

		return rtn;
	}*/


//FUNCION QUE RECORRE EL ALBUM PARA VER SI ALGUNO ESTA EN ALTA, DEVUELVE -1 SI NO
/*int estaOcupado(sAlbum array[], int lenght)
{
	int rtn,i;
	rtn = 0;

	if(lenght > 0)
	{
		for(i=0;i<lenght;i++)
		{
			if(array[i].estado == OCUPADO)
			{
				rtn = 1;
				break;
			}
		}
	}

	return rtn;
}*/


//CASO UNO DE INFORMAR
/*void informesUno(sAlbum array[], int lenght)
{
	int i;
	float promedioImportes, acumuladorImportes;
	int contadorAlbumes, contadorAlbumesBajoPromedio;
	acumuladorImportes = 0, contadorAlbumes = 0, contadorAlbumesBajoPromedio = 0;



	for(i=0;i<lenght;i++)
	{
		if(array[i].estado == OCUPADO)
		{
			acumuladorImportes += array[i].precio;
			contadorAlbumes++;
		}
	}
	promedioImportes = acumuladorImportes / contadorAlbumes;

	for(i=0;i<lenght;i++)
	{
		if(array[i].estado == OCUPADO && array[i].precio < promedioImportes)
		{
			contadorAlbumesBajoPromedio++;
		}
	}

	printf("\nEl total acumulado de importes por album es: %.2f y el promedio total: %.2f", acumuladorImportes, promedioImportes);
	if(contadorAlbumesBajoPromedio > 0)
	{
		printf("\nLa cantidad de precios de album debajo del promedio de importes es: %d", contadorAlbumesBajoPromedio);
	}
	else
	{
		printf("\nNo se ingresaron precios de albums debajo del promedio de importes.");
	}
		break;


}*/

/*void informesDos(sAlbum array[], int lenght)
{
	int i;
	int contadorFechaPosterior;

	contadorFechaPosterior = 0;

	for(i=0;i<lenght;i++)
	{
		if(array[i].estado == OCUPADO && array[i].fechaAlbum.anio >= 2000)
		{
			contadorFechaPosterior++;
		}
	}

	if(contadorFechaPosterior > 0)
	{
		printf("\nLa cantidad de albumes publicados en el año 2000 o posterior es: %d", contadorFechaPosterior);
	}
	else
	{
		printf("\nNo se ingresaron albumes del año 2000 o posteriores.");
	}

}*/


