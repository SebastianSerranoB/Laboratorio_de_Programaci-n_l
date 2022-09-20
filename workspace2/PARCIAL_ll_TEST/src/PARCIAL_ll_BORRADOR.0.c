/*
 ============================================================================
 Name        : 0.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "FuncionesAlumno.h"

int main(void)
{
	setbuf(stdout, NULL);
	int opcionMenuPrincipal;
	int loadFlag;
	int saveBinFlag;
	int saveTextFlag;
	int respuestaGuardar;
	LinkedList* pList = ll_newLinkedList();
	loadFlag = 0;
	saveBinFlag = 0;
	saveTextFlag = 0;



	do{
		opcionMenuPrincipal = printMenu(0, 8, "\n\n====================================   MENU PRINCIPAL  ========================================\n\n"
			"1- Cargar los datos  desde el archivo data.csv (modo texto).\n"
			"2- Cargar los datos  desde el archivo data.bin (modo binario).\n"
			"3- Listar\n4- Ordenar\n5- Mapear lista\n6- Filtrar lista\n7- Guardar los datos en el archivo data.csv (modo texto).\n"
			"8- Guardar los datos en el archivo data.bin (modo binario).\n\n0- Salir\n"
			"=======================================================================================\n");
		switch(opcionMenuPrincipal)
		{
			case 1:
				if(loadFlag == 0)
				{
					if(controller_loadFromText("data.txt", pList) == 0){
						loadFlag = 1;
					}
				}
				else{
				    printf("\nLa lista puede cargarse solo una ves.");
				}

					break;
			case 2:
				if(loadFlag == 0)
				{
					if(controller_loadFromBinary("data.bin", pList) == 0)
					{
						loadFlag = 1;
					}
				}
				else{
					 printf("\nLa lista puede cargarse solo una ves.");
				}
					break;
			case 3:
				controller_ListElements(pList);
				break;
			case 4:
				controller_sortElements(pList);
				break;
			case 5:
				controller_mapList(pList);
				break;
			case 6:
				controller_filterList(pList);
				break;
			case 7:
				if(loadFlag == 1)
				{
					if(controller_saveAsText("data.csv",pList) == 0)
					{
						saveTextFlag = 1;
					}
				}
				else{
					printf("\nCargue la lista antes de guardar(OPCION 1-2).");
				}
					break;
			case 8:
				if(loadFlag == 1)
				{
					if(controller_saveAsBinary("data.bin", pList) == 0)
					{
						saveBinFlag = 1;
					}
				}
				else{
					printf("\nCargue la lista antes de guardar(OPCION 1-2).");
				}

					break;

			case 0:
				if(saveBinFlag == 0 || saveTextFlag == 0)
				{
					respuestaGuardar = salirSinGuardar();
				}
				else{
					respuestaGuardar = 0;
				}
					break;
		}

	}while(opcionMenuPrincipal != 0 || respuestaGuardar != 0);
	printf("\nHas salido del menu principal...");


	ll_deleteLinkedList(pList);
	return EXIT_SUCCESS;
}
