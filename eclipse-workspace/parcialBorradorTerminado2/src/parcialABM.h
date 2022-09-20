/*
 * parcialABM.h
 *
 *  Created on: 30 abr 2022
 *      Author: SEBASTIAN SERRANO
 */

#ifndef PARCIALABM_H_
#define PARCIALABM_H_

/* ************************************************************************************************** */
//**** DEFINES ****

//TAMAÑO DEL ARRAY PARA ESTRUCTURA PRINCIPAL
#define MAX_ALBUM 10

//TAMAÑO ARRAY PARA ESTRUCTURAS PERIFERICAS
#define MAX_ARTISTA 5
#define MAX_DISCOGRAFICA 3
#define MAX_TIPO_ARTISTA 2



//ESTADOS EN ABM
#define LIBRE  0
#define OCUPADO  1
#define BAJA  -1


/* ************************************************************************************************** */
//****  ESTRUCTURAS CATEDRA  ****
//FECHA, ARTISTA, TIPO-ARTISTA, ALBUM Y DISCOGRAFICA.

typedef struct{

	int dia;
	int mes;
	int anio;

}sFecha;

typedef struct{

	char titulo[51];
	float precio;
	sFecha fechaAlbum;

	int idAlbum;
	int estado;


	int idArtista;
	int idDiscografica;
	int idTipoArtista;

}sAlbum;

typedef struct{

	char nombre[51];
	int idArtista;
	int estado;

}sArtista;

typedef struct{

	char descripcion[51];
	int idTipoArtista;
	int estado;

}sTipoArtista;

typedef struct{

	char descripcion[51];
	int idDiscografica;
	int estado;

}sDiscografica;


/* ************************************************************************************************** */
//****  FUNCIONES GENERICAS ABM ****

//----  UTILIDAD  ----

int optionMenu(int min, int max, char text[]);
int initArray(sAlbum list[], int lenght);

int buscarPorId(sAlbum array[], int lenght, int id);
int buscarIndiceLibre(sAlbum array[], int lenght);

int mostrarUnAlbum(sAlbum array[], int indice);
int mostrarAlbumes(sAlbum array[], int lenght);



//----  ALTA  ----


sAlbum cargaDeDatos(sArtista artistas[], sTipoArtista tipoArtistas[], sDiscografica discograficas[]);
int alta(sAlbum array[], int lenght, sArtista artistas[], sTipoArtista tipoArtistas[], sDiscografica discograficas[]);


//----   BAJA  ----
int baja(sAlbum array[], int lenght);


//----   MODIFICACION   ----
int modificacion(sAlbum array[], int lenght);

//----   INFORMAR  ----
int informar(sAlbum array[], int lenght);
//----  LISTAR   ----
int listar(sAlbum albumes[], int lenghtAlbumes, sArtista artistas[], sTipoArtista tipoArtistas[], sDiscografica discograficas[]);
int ordenarPorImporteYTitulo(sAlbum albumes[], int length);



//---- HARDCODE -----
int cargaForzadaEstructuras(sArtista artistas[], int lenghtArtistas, sTipoArtista tipoArtistas[], int lenghtTipoArtista, sDiscografica discograficas[], int lenghtDiscografica, sAlbum albumes[], int lenghtAlbumes);
int hardcodeArtistas(sArtista artista[], int lenght);
int hardcodeTipoDeArtistas(sTipoArtista tipoArtista[], int lenght);
int hardcodeDiscograficas(sDiscografica discografica[], int lenght);
int hardcodeAlbumes(sAlbum albumes[], int lenght);

//----MOSTRAR ESTRUCTURAS PERIFERICAS-----
int mostrarArtistas(sArtista artistas[], int lenght);
int mostrarTiposDeArtistas(sTipoArtista  tipoArtistas[], int lenght);
int mostrarDiscograficas(sDiscografica discograficas[], int lenght);
void mostrarUnaDiscografica(sDiscografica discografica[], int indice);





#endif /* PARCIALABM_H_ */
