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

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "Entidades.h"



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

