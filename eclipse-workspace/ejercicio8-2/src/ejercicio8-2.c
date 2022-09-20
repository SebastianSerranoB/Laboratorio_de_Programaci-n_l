/*
 *  Nombre: Serrano Sebastian
 *  Division: K-1


Ejercicio 8-2:
Una empresa importadora que comercializa productos Apple, decide registrar de sus productos los
siguientes datos:
- idProducto (numerico)
- descripcion (alfanumérico)
- nacionalidad (numérico, por el momento utilizaremos un define: EEUU - CHINA - OTRO)
- tipo (numérico, por el momento utilizaremos un define: IPHONE -MAC - IPAD -
ACCESORIOS)
- precio (numérico decimal)
Realizar un programa que permita interactuar con un menú de usuarios con las siguientes
opciones:
1. ALTA Producto: Se ingresan los datos de UN solo producto. Siempre y cuando haya espacio
disponible en el array.

2. BAJA Producto: A partir del ingreso del ID. Si existe el producto desaparece de la lista,
dejando espacio disponible para un nuevo producto.
3. MODIFICACIÓN Producto: A partir del ingreso del ID. Si existe se podrá modificar el precio
o el tipo.
4. LISTADO Productos.
5. LISTADO ordenado por precio.
6. LISTADO ordenado por descripción.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/*#define CANT 5
#define EEUU 1
#define CHINA 2
#define OTRO 3
#define IPHONE 4
#define MAC 5
#define IPAD 6
#define ACCESORIOS 7 */    // PUEDEN IR EN H?

#include "functions8.h"
//bibiloteca con funciones, defines y typedef.



int main(void)
{
	setbuf(stdout, NULL);
	int opcionMenuPrincipal, opcionModificar;
	int i,k;
	int contadorDatosIngresados;
	contadorDatosIngresados = 0;
	int flagEspacioDisponible;
	int codigoAux;      //codigo auxiliar para comparar con codigo real
	char descripcionAux[101];
	char confirmarBaja;

	sProducto productos[CANT];
	sProducto auxProductos;


	//INICIALIZAMOS EN 0 EL ESTADO DE CADA PRODUCTO
	for(i=0;i<CANT;i++)
	{
		productos[i].estado = 0;

	}


	do
	{
		opcionMenuPrincipal = mainMenu("\n\n------MENU PRINCIPAL------\n\n1- ALTA PRODUCTO\n2- BAJA PRODUCTO\n3- MODIFICACION\n4- LISTADO PRODUCTOS\n5- LISTADO ORDENADO POR PRECIO\n6- LISTADO ORDENADO POR DESCRIPCION\n7- SALIR DEL MENU");
		switch(opcionMenuPrincipal)
		{
			case 1:
				flagEspacioDisponible = 0;                     //bandera en 0 para corroborar disponibilidad en el vector
				for(i=0;i<CANT;i++)
				{                                             //NOTA: DEBERIAMOS DISEÑAR UN ALGORITMO PARA  CORROBORAR QUE NO INGRESE UN CODIGOID YA UTILIZADO POR OTRO PRODUCTO, para esto deberiamos enviarle productos , e i como parametro formal a alta(); para que recorra un for en el ingreso de datos verificando que el id sea distinto de uno previamente ingresado
					if(productos[i].estado == 0)              //si el estado y el codigoID en ese indice del vector es 0, se puede dar de alta un producto y la flag sube a 1, deberiamo
					{
						productos[i] = alta();

						flagEspacioDisponible = 1;
						contadorDatosIngresados++;            //si se carga un producto sube el contador
						break;
					}
				}
				if(flagEspacioDisponible == 0)
				{
					printf("\n No hay espacio disponible.");
				}

				break;
			case 2:
				if(contadorDatosIngresados > 0)             //Si se cargo al menos un producto, no utilizamos la flagEspacioDisponible porque si todos los indices se cargaran , nunca entraria al for del case 1 y la flag quedaria en 0,
				{
					printf("\n Ingrese el ID del producto a dar de baja: ");
					scanf("%d", &codigoAux );
					for(i=0;i<CANT;i++)
					{
						if(codigoAux == productos[i].idProducto && productos[i].estado == 1)
						{
							showProduct(productos[i]);

							printf("\n¿ Desea dar de baja el producto) |S | N|");
							fflush(stdin);
							scanf("%c", &confirmarBaja);
							confirmarBaja = toupper(confirmarBaja);

							if(confirmarBaja == 'S')
							{
								productos[i].estado = -1;                   //Al producto dado de baja le asignamos un estado distinto de 0 y 1(nuestras referencias para el alta/baja) ya que los productos alguna vez dados en alta pueden sernos utiles a futuro, por eso guardamos su registro.
								contadorDatosIngresados--;
								printf("\n Se ha dado de baja.");
							}
							else
							{
								printf("\n%d No se ha dado de baja.", productos[i].idProducto);
							}
							break;           //break, porque no tiene sentido que siga recorriendo el for-indice si ya encontro el producto a dar de baja
						}
					}
				}
				else
				{
					printf("\n No se cargaron datos.");
				}
				break;
			case 3:
				if(contadorDatosIngresados > 0)
				{
					printf("\n Ingrese el ID del producto a modificar: ");
					scanf("%d", &codigoAux);

					for(i=0;i<CANT;i++)
					{
						if(codigoAux == productos[i].idProducto && productos[i].estado == 1)
						{
							showProduct(productos[i]);

							do
							{
								opcionModificar = mainMenu("\n------MODIFICAR------\n\n1- ID-PRODUCTO\n2- TIPO\n3- DESCRIPCION\n4- PRECIO\n5- NACIONALIDAD\n\n6- SALIR AL MENU PRINCIPAL");
								switch(opcionModificar)
								{
									case 1:
										printf("\nID-PRODUCTO: ");
										scanf("%d", &productos[i].idProducto);
										break;
									case 2:
										printf("\nTIPO: ");
										scanf("%d", &productos[i].tipo);
										break;
									case 3:
										printf("\nDESCRIPCION:  ");
										fflush(stdin);
										gets(productos[i].descripcion);
										strlwr(productos[i].descripcion);
										break;
									case 4:
										printf("\nPRECIO: ");
										scanf("%f", &productos[i].precio);
										break;
									case 5:
										printf("\nNACIONALIDAD: ");
										scanf("%d", &productos[i].nacionalidad);
										break;
									case 6:
										printf("\nHAS SALIDO AL MENU PRINCIPAL.");
									break;

									default:
										printf("\n Error, ingrese una opcion valida.");
										break;
								}

							}while(opcionModificar != 6);
						}

					}
				}
				else
				{
					printf("\nNo se cargaron datos.");
				}
				break;
			case 4:
				if(contadorDatosIngresados > 0) // LISTADO Productos.
				{
					for(i=0;i<CANT;i++)
					{
						if(productos[i].estado == 1)
						{
							showProduct(productos[i]);
						}
					}
				}
				else
				{
					printf("\n No se cargaron datos.");
				}
				break;
			case 5:
				if(contadorDatosIngresados > 0)
				{
					// LISTADO ordenado por precio.
					for(i=0;i<CANT;i++)         // recorro indice CANT veces ya que necesito corroborar desde el primero al ULTIMO esten cargados, tambien debo mostrar hasta el ultimo si corresponde (por eso el for no es (i=0;i<CANT-1;i++)
					{
						if(productos[i].estado == 1)
						{
							for(k=i+1;k<CANT;k++)
							{
								if(productos[i].precio > productos[k].precio)
								{
									auxProductos = productos[i];
									productos[i] = productos[k];
									productos[k] = auxProductos;
								}
							}
							showProduct(productos[i]);
						}
					}
				}
				else
				{
					printf("\n No se cargaron datos.");
				}
				break;
			case 6:
				// LISTADO ordenado por descripción.
				//Previamente formatee las entradas de descripcion a lowerCase para podes comparar correctamente.
				if(contadorDatosIngresados > 0)
				{
					for(i=0;i<CANT;i++)
					{
						if(productos[i].estado == 1)
						{
							for(k=i+1;k<CANT;k++)
							{
								if((strcmp(productos[i].descripcion, productos[k].descripcion) == 1))
								{
									strcpy(descripcionAux, productos[i].descripcion);
									strcpy(productos[i].descripcion, productos[k].descripcion);
									strcpy(productos[k].descripcion, descripcionAux);
								}
							}
							showProduct(productos[i]);
						}
					}
				}
				else
				{
					printf("\n No se cargaron datos.");
				}
				break;
			case 7:
				printf("\nHas salido del menu principal.");
				break;
			default:
				printf("\nError, reingrese una opcion valida.");
				break;
		}



	}while(opcionMenuPrincipal != 7);



	return EXIT_SUCCESS;
}
