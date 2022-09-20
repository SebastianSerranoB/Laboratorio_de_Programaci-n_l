/**
 *
 * Entidades.h
 *
 *  ALUMNO: SEBASTIAN SERRANO BELLOSO
 *  DNI: 42.810.404
 *  DIVISION: K-1
 *  MATERIA: LABORATORIO DE PROGRAMACION I
 *  PARCIAL I
 *  UTN-FRA 04/05/2022
 */


#ifndef ENTIDADES_H_
#define ENTIDADES_H_

/* ************************************************************************************************** */
//**** DEFINES ****

//TAMAÑO DEL ARRAY PARA ESTRUCTURA PRINCIPAL
#define MAX_ALBUM 10

//TAMAÑO ARRAY PARA ESTRUCTURAS PERIFERICAS
#define MAX_ARTISTA 5
#define MAX_DISCOGRAFICA 3
#define MAX_TIPO_ARTISTA 2
#define MAX_PAISES 5


//ESTADOS EN ABM
#define LIBRE  0
#define OCUPADO  1
#define BAJA  -1


/* ************************************************************************************************** */
//****  ESTRUCTURAS PARCIAL I  ****


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
	int idPais;

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

typedef struct{

	char descripcion[51];
	int idPais;
	int estado;

}sPais;


/* ************************************************************************************************** */
//**** FUNCIONES PARA  CARGA FORZADA DE ESTRUCTURAS  ****

/**
 * @brief Recibe arrays para las estructuras Album, discografica, artista , tipo de artista Y pais e inicializa los  campos de cada entidad con valores predeterminados.
 *
 * @param artistas[]  			-Arreglo de la estructura de tipo "sArtista".
 * @param lenghtArtistas   		-Cantidad de elementos designados en el arreglo de tipo "sArtista".
 * @param tipoArtistas[]			-Arreglo de la estructura de tipo "sTipoArtista".
 * @param lenghtTipoArtista		-Cantidad de elementos designados en el arreglo de tipo "sTipoArtista".
 * @param discograficas[]			-Arreglo de la estructura de tipo "sDiscografica".
 * @param lenghtDiscografica	-Cantidad de elementos designados en el arreglo de tipo "sDiscografica".
 * @param albumes[]				-Arreglo de la estructura de tipo "sAlbum".
 * @param lenghtAlbumes			-Cantidad de elementos designados en el arreglo de tipo "sAlbum".
 * @param paises[]				-Arreglo de la estructura de tipo "sPais".
 * @param lenghtPaises			-Cantidad de elementos designados en el arreglo de tipo "sPais".

 * @return 	retorno de tipo int, -(0) si existe un error [Invalid length or NULL pointer]; retorna -(1) si funciona correctamente.
 */
int cargaForzadaEstructuras(sArtista artistas[], int lenghtArtistas, sTipoArtista tipoArtistas[], int lenghtTipoArtista, sDiscografica discograficas[], int lenghtDiscografica, sAlbum albumes[], int lenghtAlbumes, sPais paises[], int lenghtPaises);

/**
 * @brief Inicializa los distintos campos de un arreglo de tipo "sArtista" con valores predeterminados.
 *
 * @param artista[]			-Arreglo de la estructura de tipo "sArtista".
 * @param lenght			-Cantidad de elementos designados en el arreglo de tipo "sArtista".
 *
 * @return retorno de tipo int, -(0) si existe un error [Invalid length or NULL pointer]; retorna -(1) si funciona correctamente.
 */
int hardcodeArtistas(sArtista artista[], int lenght);

/**
 * @brief Inicializa los distintos campos de un arreglo de tipo "sTipoArtista" con valores predeterminados.
 *
 * @param tipoArtista[]			-Arreglo de la estructura de tipo "sTipoArtista".
 * @param lenght				-Cantidad de elementos designados en el arreglo de tipo "sTipoArtista".
 *
 * @return retorno de tipo int, -(0) si existe un error [Invalid length or NULL pointer]; retorna : -(1) si funciona correctamente.
 */
int hardcodeTipoDeArtistas(sTipoArtista tipoArtista[], int lenght);

/**
 * @brief Inicializa los distintos campos de un arreglo de tipo "sDiscografica" con valores predeterminados.
 *
 * @param discografica[]			-Arreglo de la estructura de tipo "sDiscografica".
 * @param lenght					-Cantidad de elementos designados en el arreglo de tipo "sDiscografica".
 *
 * @return retorno de tipo int, -(0) si existe un error [Invalid length or NULL pointer]; retorna -(1) si funciona correctamente.
 */
int hardcodeDiscograficas(sDiscografica discografica[], int lenght);

/**
 * @brief Inicializa los distintos campos de un arreglo de tipo "sAlbum" con valores predeterminados.
 *
 * @param albumes[]					-Arreglo de la estructura de tipo "sAlbum".
 * @param lenght					-Cantidad de elementos designados en el arreglo de tipo "sAlbum".
 *
 * @return retorno de tipo int, -(0) si existe un error [Invalid length or NULL pointer]; retorna -(1) si funciona correctamente.
 */
int hardcodeAlbumes(sAlbum albumes[], int lenght);

/**
 * @brief	Inicializa los distintos campos de un arreglo de tipo "sPais" con valores predeterminados.
 *
 * @param paises	-Arreglo de la estructura de tipo "sPais".
 * @param lenght	-Cantidad de elementos designados en el arreglo del tipo "sPais".
 *
 * @return	retorno de tipo int, -(0) si existe un error [Invalid length or NULL pointer]; retorna -(1) si funciona correctamente.
 */
int hardcodePaises(sPais paises[], int lenght);



#endif /* ENTIDADES_H_ */
