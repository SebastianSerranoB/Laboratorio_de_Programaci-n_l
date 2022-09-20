#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define CANT 5

int main(void){
	int vec[CANT], i;
	int menor, mayor, num;
	char opcion;
	int flag = 0, flag_A = 0;

	for(i=0; i<CANT; i++){
		vec[i] = 0; // inicializamos vector
	}

	do{
		printf("A. Alta");
		printf("\nB. Baja");
		printf("\nM. Modificar");
		printf("\nC. Menor");
		printf("\nD. Mayor");
		printf("\nE. Buscar dato");
		printf("\nS. Salir");
		printf("\nOpcion: ");
		fflush(stdin);
		scanf("%c", &opcion);
		opcion = toupper(opcion);

		switch(opcion){
			case 'A':
				for( i=0; i<CANT; i++ ){
					if( vec[i] == 0 ){
						printf("Ingrese valor a cargar en el vector: ");
						scanf("%d", &vec[i]);
						flag_A = 1;
						break;
					}
				}
				break;

			case 'B':
				break;

			case 'M':
				break;
			case 'C':
				//buscar menor
				if( flag_A == 1 ){
					menor = vec[0];

					for( i=0; i<CANT; i++ ){
						if( vec[i] < menor && vec[i] != 0 ){
							menor = vec[i];
						}
					}
						printf("El menor es: %d", menor);
				}
				else{
					printf("No existen datos cargados...");
				}

				break;

			case 'D':
				//buscar mayor
				if( flag_A == 1 ){
					mayor = vec[0];

					for( i=0; i<CANT; i++ ){
						if( vec[i] > mayor ){
							mayor = vec[i];
						}
					}
					printf("El mayor es: %d", mayor);
				}
				else{
					printf("No existen datos cargados...");
				}

				break;

			case 'E':
				if( flag_A == 1 ){
					//buscar un numero dentro del vector
					flag = 0;

					printf("Ingrese dato a buscar: ");
					scanf("%d", &num);

					for( i=0; i<CANT; i++ ){
						if( num == vec[i] ){
							/* asignacionesy modificaciones*/
							printf("Se encontro el numero");
							flag = 1;
							break;
						}
					}

					if( flag == 0 ){
						printf("El numero no se encontro");
					}
				}
				else{
					printf("No existen datos cargados...");
				}


			default:
				printf("La opci%cn %c no es v%clida", 162, opcion, 160);
		}
		printf("\n\n");

	}while( opcion != 'S' );

	return 0;
}

