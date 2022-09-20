/*
 * ticket.c
 *
 *  Created on: 25 abr. 2022
 *      Author: Quiroz Family
 */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "ticket.h"


 int inicializarTickets(eTicket listaTicket[] ,int tam)
 {
	 int i;
	 int retorno = -1;

	 if(listaTicket != NULL && tam > 0)
	 {
		 retorno = 0;
		for( i=0; i<tam; i++)
		{
			listaTicket[i].estado = 0;

		}
	 }

 return retorno;
 }

 int buscarEspacioLibre(eTicket listaTickets[],int tam)
 {
	 int i;
	 int indice = -1;

	 for(i=0;i<tam;i++)
	 {
		 if(listaTickets[i].estado == 0)
		 {
			 indice = i;
			 break;
		 }

	 }


	return indice;
 }

 int altaTickets(eTicket listaTickets[],int tam)
 {
	 int indice;
	 int retorno = -1;

	 if(listaTickets != NULL && tam > 0)
	 {
		 indice = buscarEspacioLibre(listaTickets,tam);

		 if(indice != -1)
		 {
			 listaTickets[indice] = cargarTicket();
			 retorno = 0;
		 }

	 }

	 return retorno;
 }



eTicket cargarTicket(void)
{
	eTicket ticket;

	printf("Codigo: ");
	scanf("%d", &ticket.codigo);

	printf("Nombre: ");
	fflush(stdin);
	scanf("%[^\n]", ticket.nombre);

	printf("Apellido: ");
	fflush(stdin);
	scanf("%[^\n]", ticket.apellido);

	printf("Horario de salida: ");
	scanf("%d", &ticket.horarioSalida);

	printf("Horario de llegada: ");
	scanf("%d", &ticket.horarioLlegada);

	ticket.estado = 1;

	return ticket;
}

int buscarCodigo(eTicket listaTickets[],int tam,int codigo)
{
	int i;
	int retorno= -1;

	for(i=0;i<tam;i++)
	{
		if(listaTickets[i].codigo == codigo && listaTickets[i].estado == 1)
		{
			retorno =i;
			break;
		}

	}

	 return retorno;
}

int menu( char opciones[]  )
{
	int opcion;

	printf( opciones );

	printf("\nOpcion: ");
	scanf("%d", &opcion);

	return opcion;
}

void MostrarUnTicket(eTicket unTicket)
{

	printf("%d %s %s %d %d\n", unTicket.codigo, unTicket.nombre, unTicket.apellido, unTicket.horarioSalida, unTicket.horarioLlegada);
}

void mostrarTickets(eTicket listaTickets[],int tam)
{
	int i;

	printf("codigo nombre apellid horarioS horarioL\n");
	for(i = 0;i<tam;i++)
	{
		if(listaTickets[i].estado == 1)
		{
			MostrarUnTicket(listaTickets[i]);
		}

	}

}
