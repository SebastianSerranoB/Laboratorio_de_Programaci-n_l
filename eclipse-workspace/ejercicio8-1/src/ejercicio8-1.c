/*
 ============================================================================
 Name        : ejercicio8-1.c
 Author      : Serrano Belloso Sebastian
 Division    : k-1


 Ejercicio 8-1:
Crear la estructura Jugador (nombre, goles metidos, partidos jugados, promedio de goles).
Crear una función que permita cargar los datos de un jugador y otra que los muestre.
Una tercera función calculará el promedio de goles.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define CANT 5

typedef struct
{
	char nombre[25];
	int goles;
	int partidosJugados;
	float promedioGoles;
	int estado;
}sJugador;


sJugador altaJugador(void);

int main(void)
{
	setbuf(stdout, NULL);

	sJugador jugadores[CANT];
	int i;


	for(i=0;i<CANT;i++)
	{
		jugadores[i].estado = 0;
	}


	return EXIT_SUCCESS;
}

sJugador altaJugador(void)
{
	sJugador jugador;
	 jugador.estado = 1;

}
