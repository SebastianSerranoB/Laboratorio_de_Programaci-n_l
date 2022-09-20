/*
 ============================================================================
 Name        : clase20Abril.c
 Author      : Serrano Belloso Sebastian
 Version     :
 Copyright   : 
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CANT 3

typedef struct
{
	int codigo;
	char nombre[20];
	char apellido[20];
	int horarioSalida;
	int horarioLlegada;
	int estado;

}eTicket;

eTicket alta(void);
eTicket alta(void)
{



	eTicket ticket;
	printf("codigo: ");
	scanf("%d", ticket.codigo);
	printf("\nNombre: ");

	fflush(stdin);
	scanf("%[^\n]", ticket.nombre);

	printf("\nApellido: ");
	fflush(stdin);
	gets(ticket.apellido);

	printf("\nhorario de salida: ");
	scanf("%d", ticket.horarioSalida);

	printf("\nhorario de llegada: ");
	scanf("%d", ticket.horarioLlegada);

	ticket.estado = 1;

	return ticket;
}

///////COMIENZA EL MAIN//////////
int main(void)
{
	eTicket tickets[CANT];
	setbuf(stdout, NULL);
	int opcionIngresada,i,flag, contadorDatos=0;
	int auxCodigo;
	char confirmar;
	int opcionModificar;

	//char textoMenu[1024]; la inicializamos con espacio para asegurarnos el texto del menu no sobrepase el limite

	//sprintf(opciones, "hola"); No muestra nada, sino que guarda el texto de la derecha en opciones, fprintf(); guarda en un archivo

	//INICIALIZO EN 0 EL ESTADO PARA LAS POSICIONES DEL ARRAY, EL ESTADO FUNCIONA COMO BANDERA, 0 "LIBRE 1 "OCUPADO"
	for(i=0;i<CANT;i++)
	{
		tickets[i].estado = 0;
	}




	do
	{		//int mainMenu(char textoMenu[]); funcion generica para menus , recibe texto del menu y devuelve opcion
		printf("\n\n1 -ALTA producto\n2 -BAJA producto\n3 -MODIFICACION producto\n4- LISTAR productos\n5- BUSCAR un dato\n6- SALIR");

		printf("\nIngrese una opcion: ");
		scanf("%d", &opcionIngresada);
		switch(opcionIngresada)
		{
		case 1: //ALTA alta(); pasar esto a una funcion
			flag = 0;
			for(i=0; i < CANT;i++)
			{
				tickets[i] = alta();
				flag = 1;
				contadorDatos = 1;
				break;
			}
				//no informamos aca si hay o no espacio, porque primero debemos recorrer todo el for para saber esto
			if(flag == 0)
			{
				printf("\nNo hay espacio disponible.");
			}
		break;
		case 2: //BAJA
			if(contadorDatos > 0)   //no usamos una flagDatos porque genera problemas
			{
				printf("Codigo a dar de baja: ");
				scanf("%d", &auxCodigo);

				for(i=0;i<CANT;i++)
				{
					if(auxCodigo == tickets[i].codigo && tickets[i].estado == 1) //busco el codigo de ticket y pregunto si esta cargado, porque pueden coindir con basura auxCodigo
					{
						/*ESTO SE CONOCE COMO "BAJA FISICA" , NO ES LA MAS CONVENIENTE PORQUE PERDEMOS LOS DATOS QUE SE BAJARON
						tickets[i].codigo = 0;
						tickets[i].nombre = '\0';
						tickets[i].apellido = '\0';
						tickets[i].horarioSalida = 0;
						tickets[i].horarioLlegada = 0;
						tickets[i].estado = 0; */
						//NOS CONVIENE HACER UNA "BAJA LOGICA".
						//printear los datos para mostrarselos al useario y preguntarle
						printf("Dar de baja? [s|n]: ");
						fflush(stdin);
						scanf("%c", &confirmar);
						confirmar = tolower(confirmar);
						if(confirmar == 's')   // preguntamos si esta seguro que ese es el dato a borrar
						{
							contadorDatos--; //decrementamos el contador para que no entre de nuevo por el mismo motivo
							tickets[i].estado = -1; //necesitamos un tercer valor, distinto de los dos que usabamos 0 y 1, para distuingirlo como baja logica, ya que como empresa queremos guarda
													//r los datos de quienes fueron clientes para contactarlos y no sobreescribir sus datos
						printf("\nSe borraron los datos.");
						}
						else
						{
							printf("\nNo se han borrado los datos.");
						}
						break;
					}
				}
			}
			else
			{
				printf("\nNo existen datos cargados.");
			}
			break;
		case 3: //MODIFICAR
			if(contadorDatos > 0)
			{
				printf("Codigo a modificar: ");
				scanf("%d", &auxCodigo);


				for(i=0;i<CANT;i++)
				{
					if(auxCodigo == tickets[i].codigo && tickets[i].estado == 1)
					{
						//mostrar los datos
						do
						{
							opcionModificar = menu("\n\n1 -ALTA producto\n2 -BAJA producto\n3 -MODIFICACION producto\n4- LISTAR productos\n5- BUSCAR un dato\n6- SALIR");
							switch(opcionModificar);
							{
							case 1:
								printf("Codigo: ");
								scanf("%d", tickets[i].codigo);
							case 2:
								printf("Nombre: ");
								scanf("%s", tickets[i].nombre);
							break;
							case 3:
								printf("Apellido: ");
								scanf("%s", tickets[i].apellido);
							break;
							case 4:
								printf("\nHorario de salida: ");
								scanf("%d",tickets[i].horarioSalida);
							break;
							case 5:
								printf("\nHorario de llegada: ");
								scanf("%d", tickets[i].horarioLlegada);
							break;
							case 6:
								printf("\nSalio al menu principal.");
							break;
							default:
								printf("\nLa opcion ingresada es incorrecta.");
							break;
							}
						}while(opcionModificar != 6);
					}
				}
			}
		break;
		case 4:
		break;
		case 6:
			printf("\nHas salido del menu principal.");
		break;
		}

	}while(opcionIngresada != 6);




	return EXIT_SUCCESS;
}
