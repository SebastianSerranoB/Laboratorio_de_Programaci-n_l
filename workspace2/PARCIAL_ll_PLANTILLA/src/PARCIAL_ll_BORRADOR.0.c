/*
 ============================================================================
ALUMNO: SEBASTIAN SERRANO
DNI: 42810404
PARCIAL 2 LABORATORIO DE PROGRAMACION 1
29/06/2022
DIVISION K-1
TURNO TARDE

LINKEDLIST
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

	LinkedList* pList = ll_newLinkedList();
	loadFlag = 0;



	do{
		opcionMenuPrincipal = printMenu(0, 8, "\n\n====================================   MENU PRINCIPAL  ========================================\n\n"
			"1- Cargar los datos  desde el archivo data.csv (modo texto).\n"
			"2- Listar \n"
			"3- Sort\n4- Mapear lista\n5- Mapear lista\n5- Guardar los datos en el archivo data.csv (modo texto).\n"
			"\n\n0- Salir\n"
			"=======================================================================================\n");
		switch(opcionMenuPrincipal)
		{
			case 1:
				if(loadFlag == 0)
				{
					if(controller_loadFromText("datos_SP.csv", pList) == 0){
						loadFlag = 1;
					}
				}
				else{
				    printf("\nLa lista puede cargarse solo una ves.");
				}
					break;
			case 2:
				controller_ListElements(pList);
				break;
			case 3:
				controller_sortElements(pList);
				break;
			case 4:
				controller_mapList(pList);
				break;
			case 5:
				if(loadFlag == 1)
				{
					controller_saveAsText("datos_SP.csv",pList);
				}
				else{
					printf("\nCargue la lista antes de guardar(OPCION 1-2).");
				}
					break;

			case 0:
				printf("\nHas salido del menu principal...");
				break;

		}

	}while(opcionMenuPrincipal != 0);



	ll_deleteLinkedList(pList);
	return EXIT_SUCCESS;
}
