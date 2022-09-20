/*
 ============================================================================
 Name        : clasede20abrilEstructuras.c
 Author      : Serrano Belloso Sebastian
 Version     :
 Copyright   : 
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define CANT 3

typedef struct{
	int codigo;
	char nombre[20];
	char apellido[20];
	int horarioSalida;
	int horarioLlegada;
	int estado;
}eTicket;

int menu( char opciones[]  );
eTicket alta(void);
void MostrarUnTicket(eTicket unTicket);

int main(void){
	eTicket tickets[CANT];
	int i, opcion, flag;
	int contadorDatos=0, auxCodigo;
	char opciones[1024], confirmar;
	char opcionModificar;

	//Inicializamos los estados
	for( i=0; i<CANT; i++ ){
		tickets[i].estado = 0;
	}

	do{
		opcion = menu( "MENU\n1. Alta\n2. Baja\n3. Modificar\n4. Listar\n5. Buscar un dato\n6. Salir" );

		switch( opcion ){
			//Alta
			case 1:
				flag = 0;
				for( i=0; i<CANT; i++ ){
					if( tickets[i].estado == 0 ){
						tickets[i] = alta();
						flag = 1;
						contadorDatos++;
						break;
					}
				}
				if( flag == 0 ){
					printf("No hay espacio disponible...")
				}
				break;

			//Baja
			case 2:
				if( contadorDatos > 0 )
				{
					printf("Codigo a dar de baja: ");
					scanf("%d", &auxCodigo);

					for( i=0; i<CANT; i++ )
					{
						if( auxCodigo == tickets[i].codigo && tickets[i].estado == 1 )
						{
							MostrarUnTicket( tickets[i] );
							printf("Dar de baja? [S|N]: ");
							fflush(stdin);
							scanf("%c", &confirmar);
							confirmar = toupper( confirmar );
							if( confirmar == 'S')
							{
								tickets[i].estado = -1;
								contadorDatos--;
								printf("Se han borrado los datos...");
							}
							else
							{
								printf("No se han borrado los datos...");
							}
							break;
						}
					}
				}
				else{
					printf("No existen datos cargados...");
				}
				break;

			//Modificar
			case 3:
				if( contadorDatos > 0 ){
					printf("Codigo a modificar: ");
					scanf("%d", &auxCodigo);

					for( i=0; i<CANT; i++ ){
						if( auxCodigo == tickets[i].codigo && tickets[i].estado == 1 ){
							MostrarUnTicket( tickets[i] );
							do{
								opcionModificar = menu( "MENU\n1. Codigo\n2. Apellido\n3. Nombre\n4. Hora de Salida\n5. Hora de llegada\n6. Salir" );

								switch( opcionModificar ){
									case 1:
										printf("Codigo: ");
										scanf("%d", tickets[i].codigo);
										break;
									case 2:
										printf("Nombre: ");
										fflush(stdin);
										scanf("%[^\n]", tickets[i].nombre);
										break;
									case 3:
										printf("Apellido: ");
										fflush(stdin);
										scanf("%[^\n]", tickets[i].apellido);
										break;
									case 4:
										printf("Horario de salida: ");
										scanf("%d", tickets[i].horarioSalida);
										break;
									case 5:
										printf("Horario de llegada: ");
										scanf("%d", tickets[i].horarioLlegada);
										break;
									case 6:
										printf("Saliendo de modificar...");
									default:
										printf("La opcion ingresada es incorrecta..");
								}
							}while( opcionModificar != 6 );
							break;
						}
					}
				}
				else{
					printf("No existen datos cargados...");
				}
				break;

			//Listar
			case 4:
				if( contadorDatos > 0 ){
					for( i=0; i<CANT; i++ ){
						if( tickets[i].estado == 1 ){
							MostrarUnTicket( tickets[i] );
						}
					}
				}
				else{
					printf("No hay datos cargados...");
				}
				break;

			default:
				printf("La opcion ingresada es incorrecta..");
		}
	}while( opcion != 6 );
}

void MostrarUnTicket(eTicket unTicket){
	printf("%d %s %s %d %d\n", unTicket.codigo, unTicket.nombre, unTicket.apellido, unTicket.horarioSalida, unTicket.horarioLlegada);
}

eTicket alta(void){
	eTicket ticket;
	printf("Codigo: ");
	scanf("%d", ticket.codigo);

	printf("Nombre: ");
	fflush(stdin);
	scanf("%[^\n]", ticket.nombre);

	printf("Apellido: ");
	fflush(stdin);
	scanf("%[^\n]", ticket.apellido);

	printf("Horario de salida: ");
	scanf("%d", ticket.horarioSalida);

	printf("Horario de llegada: ");
	scanf("%d", ticket.horarioLlegada);

	ticket.estado = 1;

	return ticket;
}

int menu( char opciones[]  ){
	int opcion;

	printf( opciones );

	printf("\nOpcion: ");
	scanf("%d", &opcion);

	return opcion;
}
