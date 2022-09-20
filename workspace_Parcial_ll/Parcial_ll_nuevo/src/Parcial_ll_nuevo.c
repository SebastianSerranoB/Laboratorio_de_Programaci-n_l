/*
 ============================================================================
 Name        : Parcial_ll_nuevo.c

 Desarrollar en ANSI C:
1) Realizar un programa que lea un archivo .csv (cuyo nombre se pasa como parámetro por
línea de comandos), con los datos de equipos de cómputo, guardándolos en un
linkedList de entidades eComputer.
2) Ordenar la lista generada en el ítem anterior, con la función ll_sort, según el criterio
cuotas, de manera descendente.
3) Imprimir por pantalla los datos de las computadoras. En lugar de idTipo, se deberá
imprimir dependiendo el caso: 1=>DESKTOP; 2=>LAPTOP.
4) Desarrollar la función ll_map en la biblioteca linkedList, la cual recibirá la lista y una
función. La función ll_map ejecutará la función recibida como parámetro por cada ítem
de la lista, de esta manera, agregará el valor de la cuota sin interés sobre el precio del
equipo.
5) Generar el archivo de salida mapeado.csv conteniendo la lista del ítem anterior.
Datos:
 eComputer
 id
 descripcion
 precio
 idTipo
 cuotas
 ============================================================================
 */



#include <stdio.h>
#include <stdlib.h>
#include "getters_Alumno.h"
#include "LinkedList.h"
#include "Entidad.h"


int main(void)
{
	setbuf(stdout, NULL);

	LinkedList* listaComputadoras;
	//LinkedList* listaComputadorasMapeada;
	listaComputadoras = ll_newLinkedList();

	int opcionMenu;
	char path[100];

	int flagLectura;
	flagLectura = 0;


	do{
		opcionMenu = printMenu(1, 6, "texto");
		switch(opcionMenu)
		{
		case 1:
			if(flagLectura == 0)
			{
				getString(path, 100, "\nIngrese la direccion del archivo: ");
				if(leerArchivo(path, listaComputadoras) == 0){
					flagLectura = 1;
				}
			}
			else{
				printf("\nEl archivo solo puede leerse una vez..");
			}
			break;

		case 2:
			break;

		}


	}while(opcionMenu != 6);


	ll_deleteLinkedList(listaComputadoras);
	//ll_deleteLinkedList(listaComputadorasMapeada);

	return 0;
}
