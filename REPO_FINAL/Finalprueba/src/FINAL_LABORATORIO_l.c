/*
 ============================================================================
 filename:FINAL_LABORATORIO_l.c

 ALUMNO: SEBASTIAN SERRANO BELLOSO           DNI: 42.810.404
 FINAL 31/08 LABORATORIO DE PROGRAMACION l, UTN-FRA
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "LinkedList.h"
#include "Pokemon.h"
#include "controller.h"
#include "alumno.h"
#include "parser.h"



int main(void)
{
	setbuf(stdout, NULL);
	int opcionMenu;
	char path[100];
	LinkedList* listaPokemones;
	LinkedList* listaPokemonAguaVarioColor;
	int flagLectura;
	flagLectura = 0;
	listaPokemones = ll_newLinkedList();

//copypaste: Data_Pokemones.csv

	do{
		opcionMenu = printMenu(1, 10, "\n====================================================="
				"\n1-cargar archivo pokemones\n2-Eliminar Pokemon \n3-Imprimir lista por consola\n4-Filtrar de tipo Agua variocolor\n5- Mapear ataque cargado"
				"\n6-BATALLA POKEMON\n10- Salir\n=====================================================\n");
		switch(opcionMenu)
		{
		case 1:
			if(flagLectura == 0)
			{
				getString(path, 100, "\nIngrese la direccion del archivo: ");
				if(controller_loadFromText(path, listaPokemones) == 0){
					flagLectura = 1;
				}
			}else{
				printf("\nEl archivo solo puede ser leido una vez..");
			}
			break;
		case 2:
			if(eliminoYMuestroPokemon(listaPokemones) == 0){
				printf("\nEl pokemon ha sido eliminado con exito");
			}else{
				printf("\nNo se han eliminado pokemones.");
			}
			break;
		case 3:
			controller_List(listaPokemones);
			break;
		case 4:
			if(flagLectura == 1)
			{
				listaPokemonAguaVarioColor = ll_filter(listaPokemones, Pokemon_filtrarPokemonAguaVarioColor);
				controller_List(listaPokemonAguaVarioColor);
			}else{
				printf("\nDebe cargar un archivo antes de filtrarlo.");
			}

			break;
		case 5:
			controller_map(listaPokemones);
			break;
		case 6:
			batallaPokemon(listaPokemones);
			break;
		case 10:
			printf("\nHa salido del menu principal..");
			break;

		}
	}while(opcionMenu != 10);


	ll_deleteLinkedList(listaPokemones);
	ll_deleteLinkedList(listaPokemonAguaVarioColor);

	return EXIT_SUCCESS;
}
