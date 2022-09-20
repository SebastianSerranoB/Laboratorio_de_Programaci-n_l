/*
 ============================================================================
 Name        : RECUPERATORIO_PARCIAL_ll.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Funciones_get.h"
#include "Participante.h"


int main(void)
{

	setbuf(stdout, NULL);

		LinkedList* listaParticipantes;
		LinkedList* listaParticipantesFiltrada;
		listaParticipantes = ll_newLinkedList();

		int opcionMenu;
		char path[100];

		int flagLectura;
		flagLectura = 0;
		int flagMap = 0;


		do{
			opcionMenu = printMenu(1, 6, "\n1-Leer archivo Participantes\n2-Ordenar lista\n3-Imprimir lista por consola\n4- filtrar lista participantes\n5- Generar archivo csv, lista filtrada\n6- Salir");
			switch(opcionMenu)
			{
			case 1:
				if(flagLectura == 0)
				{
					getString(path, 100, "\nIngrese la direccion del archivo: ");
					if(leerArchivo(path, listaParticipantes) == 0){
						flagLectura = 1;
					}
				}
				else{
					printf("\nEl archivo solo puede leerse una vez..");
				}
				break;
			case 2:
				 ordenarLista(listaParticipantes);
				break;
			case 3:
				if(flagLectura == 0){
					printf("\nCargue la lista antes de imprimir, opcion 1.");
				}
				else
				{
					printList(listaParticipantes);
				}
				break;
			case 4:
				flagMap = 1;
				listaParticipantesFiltrada = filtrarLista(listaParticipantes);
				break;
			case 5:
				if(flagMap == 0)
				{
					printf("\nfiltre antes de guardar");
				}
				else
				{
					guardarEnArchivoTxt("filtrado.csv", listaParticipantesFiltrada);
				}

				break;
			case 6:

				printf("\nSaliendo del menu principal..");

				break;

			}


		}while(opcionMenu != 6);


		ll_deleteLinkedList(listaParticipantes);
		ll_deleteLinkedList(listaParticipantesFiltrada);





	return EXIT_SUCCESS;
}
