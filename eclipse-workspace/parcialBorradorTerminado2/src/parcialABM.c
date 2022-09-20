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
		printf("\nNo se ha encontrado ningun album en lista, ingrese uno (OPCION 1).");
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
		printf("\nNo se ha encontrado ningun album en lista, ingrese uno (OPCION 1).");
	}


	return rtn;
}


/*=======================     INFORMAR      ===================================*/
int informar(sAlbum array[], int lenght)
{
	int rtn,flagOcupado;
	int i, opcionInformar;
	float promedioImportes, acumuladorImportes;
	int contadorAlbumes, contadorAlbumesBajoPromedio, contadorFechaPosterior;
	rtn = 0, flagOcupado = 0, contadorAlbumes = 0, contadorFechaPosterior = 0, contadorAlbumesBajoPromedio = 0;


	if(array != NULL && lenght > 0){
		for(i=0;i<lenght;){
			if(array[i].estado == OCUPADO){
				flagOcupado = 1;
				rtn = 1;
				break;
			}
		}
	}

	if(flagOcupado == 0)
	{
		printf("\nNo se ha encontrado ningun album en lista, ingrese uno(OPCION 1).");
		return rtn;
	}
	else
	{
		do{
				opcionInformar = optionMenu(1, 3, "\n\n====================  INFORMAR  ====================\n\n1- Total y promedio de los importes, y cuántos álbumes no superan ese promedio. \n2- Cantidad de álbumes cuya fecha de publicación es posterior a 31/12/1999. \n3- SALIR AL MENU PRINCIPAL");
				switch(opcionInformar)
				{
					case 1:
						//ESTO HAY QUE METERLO EN UNA FUNCION Y FALTA EL PRINT
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

					case 2:
						//TODO ESTO A UNA FUNCION
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
							break;

					case 3:
						printf("\nHas salido al menu principal.");
							break;
				}
			}while(opcionInformar != 3);
	}

	return rtn;
}




//----------------------------HARDCODE--------------------------
int cargaForzadaEstructuras(sArtista artistas[], int lenghtArtistas, sTipoArtista tipoArtistas[], int lenghtTipoArtista, sDiscografica discograficas[], int lenghtDiscografica, sAlbum albumes[], int lenghtAlbumes)
{
	int rtn;
	rtn = 0;


	if(artistas != NULL && tipoArtistas != NULL && discograficas != NULL && albumes != NULL && lenghtArtistas > 0  && lenghtTipoArtista > 0  && lenghtDiscografica > 0 && lenghtAlbumes > 0)
	{
		hardcodeArtistas(artistas, lenghtArtistas);
		hardcodeTipoDeArtistas(tipoArtistas,  lenghtTipoArtista);
		hardcodeDiscograficas(discograficas, lenghtDiscografica);
		hardcodeAlbumes(albumes, lenghtAlbumes);

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
			artista[i].estado = OCUPADO;
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

	if(tipoArtista != NULL && lenght > 0)
	{
		for(i=0;i<lenght;i++)
		{
			strcpy(tipoArtista[i].descripcion, descripcion[i]);
			tipoArtista[i].idTipoArtista = i + 1;
			tipoArtista[i].estado = OCUPADO;
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


	if(discografica != NULL && lenght > 0)
	{
		for(i=0;i<lenght;i++)
		{
			strcpy(discografica[i].descripcion, auxDiscografica[i]);
			discografica[i].idDiscografica = i + 1;
			discografica[i].estado = OCUPADO;
		}

		rtn = 1;
	}

	return rtn;
}

int hardcodeAlbumes(sAlbum albumes[], int lenght)
{
	int rtn, i;
	rtn = 0;

	char auxTitulo[][51] = {"\nYendo del living a la cama", "Llegando les monos", "La sopa en la mosca", "Visible", "Acariciando lo suave"};
	float auxPrecio[] = {1500, 150.25, 899.99, 1500, 500.80};
	sFecha auxFecha[] = {{ 10, 8, 1995},{25, 12, 1999},{28, 2, 2005},{7,11, 2000},{1, 1, 2010}};


	if(albumes != NULL && lenght > 0)
	{

		for(i = 0; i< lenght - 5;i++)
		{

			albumes[i].precio = auxPrecio[i];
			strcpy(albumes[i].titulo, auxTitulo[i]);
			albumes[i].fechaAlbum = auxFecha[i];

			albumes[i].idAlbum = i + 1;
			albumes[i].idArtista = i + 1;
			albumes[i].idTipoArtista = i + 1;
			albumes[i].idDiscografica = i + 1;
			albumes[i].estado = OCUPADO;
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



/*======================= LISTAR , ESTO CUANDO LO TERMINE LO PASO A UNA BIBLIOTECA ===========================
 	 	 	 	 	 	 	 5. LISTAR
							1- Todas las discográficas.
							2- Todos los tipos de artistas musicales.
							3- Todos los artistas.
							4- Todos los álbumes.
							5- Realizar un solo listado de los álbumes ordenados por los siguientes criterios:
							Importe (descendentemente)
							o Título (ascendentemente)
							6. Todos los álbumes cuya fecha de publicación es posterior a 31/12/1999.
							7. Todos los álbumes que no superan el promedio de los importes.
							8. Todos los álbumes de un artista determinado.
							9. Todos los álbumes de cada año.
							10. El álbum o los álbumes más baratos.*/

int listar(sAlbum albumes[], int lenghtAlbumes, sArtista artistas[], sTipoArtista tipoArtistas[], sDiscografica discograficas[])
{
	int rtn;
	int i, j;
	int flagOcupado;
	int flagPosteriorDosMil;
	int flagAlbumArtista;
	int opcionListar,opcionArtista;
	int flagAlbumMasBarato;
	float menorImporteAlbum;

	rtn = 0;
	flagOcupado = 0;
	flagPosteriorDosMil = 0;
	flagAlbumArtista = 0;
	flagAlbumMasBarato = 0;

	float  acumuladorImportes, promedioImportes;
	int contadorImportes, contadorMenorPromedio;

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
			opcionListar = optionMenu(0, 10, "\n\n========================        LISTAR        ========================\n\n0- SALIR AL MENU PRINCIPAL\n\n1- Todas las discográficas\n2- Todos los tipos de artistas musicales\n3- Todos los artistas\n4- Todos los álbumes"
					"\n5- Realizar un solo listado de los álbumes ordenados por los siguientes criterios: -Importe(descendentemente: Mayor a menor importe) o Título (ascendentemente: alfabeticamente desde Z hasta la A)"
					"\n6- Todos los álbumes cuya fecha de publicación es posterior a 31/12/1999\n7- Todos los álbumes que no superan el promedio de los importes"
					"\n8- Todos los álbumes de un artista determinado\n9- Todos los álbumes de cada año\n10- El álbum o los álbumes más baratos\n\n======================================================================");
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


							/*ESTO IRIA DENTRO DE CADA CASE DEL SWITCH,PERO POR COMODIDAD LO HAGO ACA Y VOY PASANDO CADA CASE
							 *
							 * 5. LISTAR
							1- Todas las discográficas.
							2- Todos los tipos de artistas musicales.
							3- Todos los artistas.
							4- Todos los álbumes.
							5- Realizar un solo listado de los álbumes ordenados por los siguientes criterios:
							Importe (descendentemente)
							o Título (ascendentemente)
							6. Todos los álbumes cuya fecha de publicación es posterior a 31/12/1999.
							7. Todos los álbumes que no superan el promedio de los importes.
							8. Todos los álbumes de un artista determinado.
							9. Todos los álbumes de cada año.
							10. El álbum o los álbumes más baratos.*/




int ordenarPorImporteYTitulo(sAlbum albumes[], int length)
{
	int rtn;
	int i, j;
	rtn = 1;
	sAlbum aux;

	for(i=0;i<length;i++)
	{
		strupr(albumes[i].titulo);
	}

	if(albumes != NULL && length > 0)
	{
		for(i=0;i<length - 1;i++)
		{
			for(j=i+1;j<length;j++)
			{
				if(albumes[i].precio < albumes[j].precio)
				{
					aux = albumes[i];
					albumes[i] = albumes[j];
					albumes[j] = aux;
				}
				else
				{
					if(albumes[i].precio == albumes[j].precio)
					{
						if(strcmp(albumes[i].titulo, albumes[j].titulo) < 0)
						{
							aux = albumes[i];
							albumes[i] = albumes[j];
							albumes[j] = aux;
						}
					}
				}


			}
		}
	}


	return rtn;
}
