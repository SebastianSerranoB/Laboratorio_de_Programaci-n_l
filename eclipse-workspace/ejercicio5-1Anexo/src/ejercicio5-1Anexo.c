/*
 ============================================================================
 Name        : ejercicio5-1Anexo.c
 Author      : Serrano Belloso Sebastian
 Division    : K-1
ANEXO 5-1:
Armar un Menú de Opciones con las siguientes opciones
1-Inicializar
2-Cargar
3-Mostrar
4-Calcular Promedio
5-Ordenar
Al ingresar a cada opción del menú deberá imprimir en pantalla el nombre del mismo. Ej: Si se
presiona la opción 1 mostrar por pantalla “Ud. ha seleccionado lo opción 1-Inicializar”
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	setbuf(stdout, NULL);
	int opcionIngresada;

	do{
		printf("\n\n1-Inicializar\n2-Cargar\n3-Mostrar\n4-Calcular Promedio\n5-Ordenar\n6-Salir del menu");
		printf("\n\nOpcion ingresada: ");
		scanf("%d", &opcionIngresada);
		switch(opcionIngresada)
		{
		case 1:
			printf("\nUd. ha seleccionado lo opción 1-Inicializar");
		break;
		case 2:
			printf("\nUd. ha seleccionado lo opción 2-Cargar");
		break;
		case 3:
			printf("\nUd. ha seleccionado lo opción 3-Mostrar");
		break;
		case 4:
			printf("\nUd. ha seleccionado lo opción 4-Calcular Promedio");
		break;
		case 5:
			printf("\nUd. ha seleccionado lo opción 5-Ordenar");
		break;
		case 6:
			printf("\nHas salido del menu principal.");
		break;
		}


	}while(opcionIngresada != 6);
	return EXIT_SUCCESS;
}
