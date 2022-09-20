/*
 * Entidades.c
 *
 *
 *  ALUMNO: SEBASTIAN SERRANO BELLOSO
 *  DNI: 42.810.404
 *  DIVISION: K-1
 *  MATERIA: LABORATORIO DE PROGRAMACION I
 *  PARCIAL I
 *  UTN-FRA 04/05/2022
 *
 *
 *  DESARROLLO DE FUNCIONES PARA CARGA FORZADA DE ENTIDADES
 */

//****************************  BIBLIOTECAS C  *******************************
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//****************************  BIBLIOTECAS PRODUCCION ALUMNO  *******************************

#include "Entidades.h"
#include "Funciones_Get.h"




//****************************  HARDCODE  *******************************

int cargaForzadaEstructuras(sArtista artistas[], int lenghtArtistas, sTipoArtista tipoArtistas[], int lenghtTipoArtista, sDiscografica discograficas[], int lenghtDiscografica, sAlbum albumes[], int lenghtAlbumes, sPais paises[], int lenghtPaises)
{
	int rtn;
	rtn = 0;


	if(lenghtArtistas > 0  && lenghtTipoArtista > 0  && lenghtDiscografica > 0 && lenghtAlbumes > 0 && lenghtPaises > 0)
	{
		hardcodeArtistas(artistas, lenghtArtistas);
		hardcodeTipoDeArtistas(tipoArtistas,  lenghtTipoArtista);
		hardcodeDiscograficas(discograficas, lenghtDiscografica);
		hardcodeAlbumes(albumes, lenghtAlbumes);
		hardcodePaises(paises, lenghtPaises);

		rtn = 1;
	}


	return rtn;
}



int hardcodeArtistas(sArtista artista[], int lenght)
{
	int rtn, i;
	rtn = 0;

	char nombres[][50] = {"Luis Alberto Scaloneta", "Miles Davits", "Astor Piazzolo", "Led Zeppelines", "Mercedes Sopa"};


	if( lenght > 0)
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

	if( lenght > 0)
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


	if( lenght > 0)
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

int hardcodePaises(sPais paises[], int lenght)
{
	int rtn;
	int i;
	rtn = 0;

	char auxDescripcion[][51] = {"ARGENTINA", "BRASIL", "EEUU", "ESPAÑA", "CHINA"};

	if( lenght > 0)
	{
		for(i=0;i<lenght;i++)
		{
			strcpy(paises[i].descripcion, auxDescripcion[i]);
			paises[i].idPais = i + 1;
			paises[i].estado = OCUPADO;
		}

		rtn = 1;
	}

	return rtn;
}

int hardcodeAlbumes(sAlbum albumes[], int lenght)
{
	int rtn, i;
	rtn = 0;

	char auxTitulo[][51] = {"Yendo del living a la cama", "Llegando les monos", "La sopa en la mosca", "Visible", "Acariciando lo suave"};
	float auxPrecio[] = {1500, 150.25, 899.99, 1500, 500.80};
	sFecha auxFecha[] = {{ 10, 8, 1995},{25, 12, 1999},{28, 2, 2005},{7,11, 2000},{1, 1, 2010}};


	if(lenght > 0)
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
			albumes[i].idPais = i + 1;
			albumes[i].estado = OCUPADO;
		}

		rtn = 1;
	}


	return rtn;
}


/* ******************************************************************************************************************   */

//**** FUNCIONES GENERICAS ABM ****

//====================    UTILIDAD     ====================

int optionMenu(int min, int max, char text[])
{
	int rtn;
	int option;


		printf("%s", text);
		option = getInteger(min, max, "\nIngrese una opcion: ");
		rtn = option;


	return rtn;
}


int initArray(sAlbum list[], int lenght)
{
	int i;
	int rtn;
	rtn = 0;

	if( lenght >= 0)
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

	if( lenght > 0)
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


	if( lenght >= 0)
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


int estaOcupado(sAlbum array[], int lenght)
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
}



//****  FUNCIONES MOSTRAR  ***********************************************************
int mostrarUnAlbum(sAlbum array[],int indice, sArtista artista[], sTipoArtista tipoArtista[], sDiscografica discografica[], sPais pais[])
{
	int rtn;
	int i;
	rtn = 0;

	if(indice >= 0)
	{

		printf("\n==============================\n\n[ TITULO ] :  { %s }\n[ IMPORTE ] :  { %.2f }\n[ FECHA DE PUBLICACION ] : { %d, %d, %d }\n", array[indice].titulo, array[indice].precio, array[indice].fechaAlbum.dia, array[indice].fechaAlbum.mes, array[indice].fechaAlbum.anio);
		for(i=0;i<MAX_ARTISTA;i++)
		{
			if(array[indice].idArtista == artista[i].idArtista){
							printf("[ ARTISTA ] :  { %s }\n", artista[i].nombre);
							break;
			}
		}

		for(i=0;i<MAX_TIPO_ARTISTA;i++)
		{
			if(array[indice].idTipoArtista == tipoArtista[i].idTipoArtista){
				printf("[ TIPO ] :  { %s }\n", tipoArtista[i].descripcion);
				break;
			}
		}

		for(i=0;i<MAX_PAISES;i++)
		{
			if(array[indice].idPais == pais[i].idPais){
						printf("[ PAIS ] :  { %s }\n", pais[i].descripcion);
						break;
			}
		}

		for(i=0;i<MAX_DISCOGRAFICA;i++)
		{
			if(array[indice].idDiscografica == discografica[i].idDiscografica){
										printf("[ DISCOGRAFICA ] :  { %s }\n", discografica[i].descripcion);
			}
		}



		rtn = 1;
	}
	else
	{
		printf("\nNo se encontro el album a imprimir.");
	}


	return rtn;
}


int mostrarAlbumes(sAlbum array[], sArtista artista[], sTipoArtista tipoArtista[], sDiscografica discografica[], sPais pais[])
{
	int rtn;
	int i;
	rtn = 0;

	if( MAX_ALBUM > 0)
	{
		for(i=0;i<MAX_ALBUM;i++)
		{
			if(array[i].estado == OCUPADO)
			{
				mostrarUnAlbum(array, i, artista, tipoArtista, discografica, pais);
				rtn = 1;
			}
		}

	}

	return rtn;
}




//====================    ALTA     ============================================


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

	if( lenght > 0)
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



//====================    BAJA     =================================================

int baja(sAlbum array[], int lenght, sArtista artista[], sTipoArtista tipoArtista[], sDiscografica discografica[], sPais pais[])
{
	int rtn;
	int i, flagOcupado;
	int idIngresado, indice;
	char confirmacion;
	rtn = 0, flagOcupado = 0;


	if( lenght > 0)
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
			mostrarUnAlbum(array, indice, artista, tipoArtista, discografica, pais);

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





//====================    MODIFICACION     ============================================

int modificacion(sAlbum array[], int lenght, sPais paises[], sArtista artista[], sTipoArtista tipoArtista[], sDiscografica discografica[])
{
	int rtn, i, flagOcupado, indice, idIngresado, opcionModificar;
	char confirmacion, auxTitulo[51];
	rtn = 0, flagOcupado = 0;

	if( lenght >= 0)
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
			mostrarUnAlbum(array, indice, artista, tipoArtista, discografica, paises);

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


//----------------------------   MOSTRAR ESTRUCTURAS PERIFERICAS   --------------------------

int mostrarArtistas(sArtista artistas[], int lenght)
{
	int i;
	int rtn;
	int flagOcupado;
	rtn = 0, flagOcupado = 0;

	if( lenght > 0)
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

	if( lenght > 0)
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

	if(lenght > 0)
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

	if( lenght > 0)
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






/* *********************************    FUNCIONES ORDENAR   *************************************************  */

int ordenarPorImporteYTitulo(sAlbum albumes[], int length)
{
	int rtn;
	int i, j;
	sAlbum aux;

	rtn = 0;

	if( length > 0)
	{
		for(i=0;i<length;i++)
		{
			strupr(albumes[i].titulo);
		}


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


		rtn = 1;
	}


	return rtn;
}





/*==============================     INFORMAR      ===================================*/

int informar(sAlbum array[], int lenght)
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
				opcionInformar = optionMenu(1, 4, "\n\n====================  INFORMAR  ====================\n\n1- Total, promedio de los importes, y cuántos álbumes no superan ese promedio."
												  " \n2- Cantidad de álbumes cuya fecha de publicación es posterior a 31/12/1999.\n3-Cantidad de albumes de bandas argentinas. \n4- SALIR AL MENU PRINCIPAL\n\n====================================================");
				switch(opcionInformar)
				{
					case 1:
						informesUno(array, lenght);
							break;
					case 2:
						informesDos(array, lenght);
							break;
					case 3:
						//Informar la cantidad de álbumes de bandas argentinas.
						informesTres(array, lenght);
						break;
					case 4:
						printf("\nHas salido al menu principal.");
							break;
				}
			}while(opcionInformar != 4);
	}

	return rtn;
}



void informesUno(sAlbum array[], int lenght)
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


}



void informesDos(sAlbum array[], int lenght)
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

}

// Informar la cantidad de álbumes de bandas argentinas.
void informesTres(sAlbum albumes[], int lenght)
{
	int contadorAlbumes;
	int i;

	contadorAlbumes = 0;

	for(i=0;i<lenght;i++)
	{
		if(albumes[i].estado == OCUPADO && albumes[i].idPais == 1 && albumes[i].idTipoArtista == 2)
		{
			contadorAlbumes++;
		}
	}

	if(contadorAlbumes > 0)
	{
		printf("\nLa cantidad de albumes de bandas argentinas es de: %d",contadorAlbumes);
	}
	else
	{
		printf("\nNo se registran albumes de bandas argentinas.");
	}

}





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
					"\nL- Listar todos los albumes que no sean de Argentina\nM- Listar todos los albumes de Argentina que correspondan a un año determinado\nN- Listar albumes solistar por año y pais\n"
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
						posteriorDosMil(albumes, lenghtAlbumes, artistas, tipoArtistas, discograficas, paises);
							break;
					case 'G':
						bajoPromedio(albumes, lenghtAlbumes, artistas, tipoArtistas, discograficas, paises);
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
					case 'N':
						albumSolistaPorAnioYPais(albumes, lenghtAlbumes, artistas, tipoArtistas, discograficas, paises);
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

//F
void posteriorDosMil(sAlbum albumes[], int lenghtAlbumes, sArtista artistas[], sTipoArtista tipoArtistas[], sDiscografica discograficas[], sPais paises[])
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

}

//CASO G
void bajoPromedio(sAlbum albumes[], int lenghtAlbumes, sArtista artistas[], sTipoArtista tipoArtistas[], sDiscografica discograficas[], sPais paises[])
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

}

//CASO H
void mostrarAlbumDeUnArtista(sAlbum albumes[], int lenghtAlbumes, sArtista artistas[], sTipoArtista tipoArtistas[], sDiscografica discograficas[], sPais paises[])
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

}


//CASO I
void albumesPorAnio(sAlbum albumes[], int lenghtAlbumes, sArtista artistas[], sTipoArtista tipoArtistas[], sDiscografica discograficas[], sPais paises[])
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
}


//CASO J
void albumMasBarato(sAlbum albumes[], int lenghtAlbumes, sArtista artistas[], sTipoArtista tipoArtistas[], sDiscografica discograficas[], sPais paises[])
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

}


//CASO L
void albumesNoArgentinos(sAlbum albumes[], int lenghtAlbumes, sArtista artistas[], sTipoArtista tipoArtistas[], sDiscografica discograficas[], sPais paises[])
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

}


//CASO M
void albumArgentinoSegunAnio(sAlbum albumes[], int lenghtAlbumes, sArtista artistas[], sTipoArtista tipoArtistas[], sDiscografica discograficas[], sPais paises[])
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
}

//CASO N
void albumSolistaPorAnioYPais(sAlbum albumes[], int lenghtAlbumes, sArtista artistas[], sTipoArtista tipoArtistas[], sDiscografica discograficas[], sPais paises[])
{
	int i;
	int paisIngresado;
	int anioIngresado;
	int flagRegistro;

	flagRegistro = 0;

	mostrarPaises(paises, MAX_PAISES);
	paisIngresado = getInteger(1, MAX_PAISES, "\nIngrese el ID del pais: ");
	anioIngresado = getInteger(MIN_FECHA, MAX_FECHA, "\nIngrese el anio para mostrar: ");

	for(i=0;i<lenghtAlbumes;i++)
	{
		if(albumes[i].estado == OCUPADO && albumes[i].idTipoArtista == 1 && albumes[i].idPais == paisIngresado && albumes[i].fechaAlbum.anio == anioIngresado)
		{
			mostrarUnAlbum(albumes, i, artistas, tipoArtistas, discograficas, paises);
			flagRegistro = 1;
		}
	}

	if(flagRegistro == 0)
	{
		printf("\nNo se registran albumes solistas para el año y fecha ingresados.");
	}


}



