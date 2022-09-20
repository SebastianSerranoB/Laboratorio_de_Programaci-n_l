/*
 * ABM.h
 *
 *  Created on: 3 may 2022
 *      Author: admin
 */

#ifndef ABM_H_
#define ABM_H_

#include "Entidades.h"


/* ************************************************************************************************** */
//****  FUNCIONES GENERICAS ABM ****

//****  UTILIDAD  ****

int optionMenu(int min, int max, char text[]);
int initArray(sAlbum list[], int lenght);

int buscarPorId(sAlbum array[], int lenght, int id);
int buscarIndiceLibre(sAlbum array[], int lenght);





//**** ALTA  ****

sAlbum cargaDeDatos(sArtista artistas[], sTipoArtista tipoArtistas[], sDiscografica discograficas[]);
int alta(sAlbum array[], int lenght, sArtista artistas[], sTipoArtista tipoArtistas[], sDiscografica discograficas[]);


//***   BAJA  ****
int baja(sAlbum array[], int lenght);


//***   MODIFICACION   ****
int modificacion(sAlbum array[], int lenght);

//**** MOSTRAR ****
int mostrarUnAlbum(sAlbum array[], int indice);
int mostrarAlbumes(sAlbum array[], int lenght);

void mostrarUnaDiscografica(sDiscografica discografica[], int indice);
int mostrarDiscograficas(sDiscografica discograficas[], int lenght);

int mostrarArtistas(sArtista artistas[], int lenght);

int mostrarTiposDeArtistas(sTipoArtista  tipoArtistas[], int lenght);


#endif /* ABM_H_ */
