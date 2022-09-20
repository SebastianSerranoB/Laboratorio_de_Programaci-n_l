/*
 ============================================================================
 Name        : parcialBorrador.c
 Author      : Serrano Belloso Sebastian
 Division    : K-1

 BORRADOR PARCIAL 1-LABORATORIO 1  UTN-FRA 2022
 ============================================================================
 */

//BIBLIOTECAS C
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//BIBLIOTECAS ALUMNO
#include "Entidades.h"

#include "ABM.h"

#include "Funciones_Informar.h"
#include "Funciones_Listar.h"

#include "Funciones_Get.h"
#include "Funciones_Calculos.h"
#include "Funciones_Ordenamiento.h"



int main(void)
{
	setbuf(stdout, NULL);
    //DECLARO ARRAYS POR ESTRUCTURA
	sAlbum albumes[MAX_ALBUM];
	sArtista artistas[MAX_ARTISTA];
	sTipoArtista tipoArtistas[MAX_TIPO_ARTISTA];
	sDiscografica discograficas[MAX_DISCOGRAFICA];

	//VARIABLES MAIN
	int opcionMenuPrincipal;


	//INICIALIZO EL ARRAY ALBUM EN LIBRE
	initArray(albumes, MAX_ALBUM);
	//INGRESO FORZADO DE ESTRUCTURAS ARTISTA, TIPO DE ARTISTA, DISCOGRAFICA Y 5 ALBUMES , pueden darse de alta hasta 10 albumes.
	cargaForzadaEstructuras(artistas, MAX_ARTISTA, tipoArtistas, MAX_TIPO_ARTISTA, discograficas, MAX_DISCOGRAFICA, albumes, MAX_ALBUM);


	 do{
		 opcionMenuPrincipal = optionMenu(1, 6, "\n\n====================   MENU PRINCIPAL   ====================\n\n[1]- ALTA\n[2]- MODIFICAR\n[3]- BAJA\n[4]- INFORMAR\n[5]- LISTAR\n\n[6]- SALIR\n"
				 	 	 	 	 	 	 	 	 "\n============================================================");
		 switch(opcionMenuPrincipal)
		 {
			 case 1:
				 	 alta(albumes, MAX_ALBUM, artistas, tipoArtistas, discograficas);
				 	 break;

			 case 2:
				 	modificacion(albumes, MAX_ALBUM);
					 break;

			 case 3:
				 	 baja(albumes, MAX_ALBUM);
					 break;

			 case 4:
				 	informar(albumes, MAX_ALBUM);
				 break;

			 case 5:
				 	 listar(albumes, MAX_ALBUM, artistas, tipoArtistas, discograficas);
				 break;

			 case 6:
				 printf("\nHas salido del menu principal.");
					break;
		 }

	 }while(opcionMenuPrincipal != 6);


	return EXIT_SUCCESS;
}
