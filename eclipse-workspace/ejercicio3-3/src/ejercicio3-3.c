/*
 ============================================================================
          : ejercicio3-3.c
			 SERRANO SEBASTIAN
 	 	 	 DIVISION K-1

 	 	 	EJ 3-2 Crear una función que pida el ingreso de un entero y lo retorne.
 ========================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int pidoEntero(void);

int main(void)
{
	setbuf(stdout, NULL);

	int muestroRetorno;


	//lo asigna aunque no tenga valor, asumo que es porque comparte el tipo de dato(int)
	muestroRetorno = pidoEntero();
	printf("\nMuestro el entero retornado: %d",muestroRetorno);



	return EXIT_SUCCESS;
}

int pidoEntero(void)
{
	int enteroRetornado;
	printf("Ingrese un entero: ");
	scanf("%d", &enteroRetornado);

	return enteroRetornado;
}
