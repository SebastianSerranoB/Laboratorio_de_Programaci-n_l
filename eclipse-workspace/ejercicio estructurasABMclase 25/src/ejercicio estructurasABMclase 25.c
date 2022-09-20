/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby,
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "ticket.h"

#define CANT 3




int main(void)
{
	setbuf(stdout, NULL);
	eTicket tickets[CANT];
	int i, opcion, flag;
	int contadorDatos=0, auxCodigo;
	char opciones[1024], confirmar;
	char opcionModificar;
	int datoEncontrado;

	//Inicializamos los estado

	inicializarTickets(tickets,CANT);

	do{
		opcion = menu( "MENU\n1. Alta\n2. Baja\n3. Modificar\n4. Listar\n5. Buscar un dato\n6. Salir" );

		switch( opcion ){
			//Alta
			case 1:
				if(altaTickets(tickets,CANT)== 0)
				{
					printf("carga exitosa!!!");
				}

				else
				{
					printf("error!!!");
				}
				break;

			//Baja
			case 2:
				if( contadorDatos > 0 ){
					printf("Codigo a dar de baja: ");
					scanf("%d", &auxCodigo);

					for( i=0; i<CANT; i++ ){
						if( auxCodigo == tickets[i].codigo && tickets[i].estado == 1 ){
							MostrarUnTicket( tickets[i] );
							printf("Dar de baja? [S|N]: ");
							fflush(stdin);
							scanf("%c", &confirmar);
							confirmar = toupper( confirmar );
							if( confirmar == 'S'){
								tickets[i].estado = -1;
								contadorDatos--;
								printf("Se han borrado los datos...");
							}
							else{
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
										scanf("%d", &tickets[i].codigo);
										break;
									case 2:
										printf("Nombre: ");
										fflush(stdin);
										scanf("%[^\n]",tickets[i].nombre);
										break;
									case 3:
										printf("Apellido: ");
										fflush(stdin);
										scanf("%[^\n]", tickets[i].apellido);
										break;
									case 4:
										printf("Horario de salida: ");
										scanf("%d", &tickets[i].horarioSalida);
										break;
									case 5:
										printf("Horario de llegada: ");
										scanf("%d", &tickets[i].horarioLlegada);
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

				mostrarTickets(tickets,CANT);

				break;

			case 5:
				// mostrar todos los datos al usuario antes de buscar
				datoEncontrado = buscarCodigo(tickets,CANT,100);
			if(datoEncontrado != -1)
			{
				MostrarUnTicket(tickets[datoEncontrado]);

			}
			else
			{
				printf("no se encontro el dato");
			}
			break;


			default:
				printf("La opcion ingresada es incorrecta..");
		}
	}while( opcion != 6 );



	return 0;
}
