/*
 * ticket.h
 *
 *  Created on: 25 abr. 2022
 *      Author: Quiroz Family
 */

#ifndef TICKET_H_
#define TICKET_H_

typedef struct{
	int codigo;
	char nombre[20];
	char apellido[20];
	int horarioSalida;
	int horarioLlegada;
	int estado;
}eTicket;

eTicket cargarTicket(void);
void MostrarUnTicket(eTicket unTicket);
int menu( char opciones[]);
int inicializarTickets(eTicket  listaTicket[] ,int tam);
int altaTickets(eTicket listaTickets[],int tam);
int buscarCodigo(eTicket listaTickets[],int tam,int codigo);
void mostrarTickets(eTicket listaTickets[],int tam);

#endif /* TICKET_H_ */

