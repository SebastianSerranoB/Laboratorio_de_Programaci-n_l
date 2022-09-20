/*
 ============================================================================
 Name        : ejercicio2-4.c
 Author      : SEBASTIAN SERRANO
 Division    : K-1
Ejercicio 2-4:
Ingresar 5 caracteres e informar cuantas letras p (minúsculas) se ingresaron.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	setbuf(stdout, NULL);// consola de eclipse tiene errores por eso usamos esto

	int contadorCaracteres;
	int contadorLetras;
	char caracterIngresado;

	contadorLetras = 0;

	contadorCaracteres = 0;
	while(contadorCaracteres < 5)
	{
		printf("Ingrese un caracter: \n");
		fflush(stdin);
		scanf("%c", &caracterIngresado);

		if(caracterIngresado == 'p')
		{
			contadorLetras++;
		}


		contadorCaracteres++;
	}

	if(contadorLetras > 0)
	{
		printf("la cantidad de letras 'p' ingresadas es de: %d",contadorLetras);
	}
	else
	{
		printf("No se ingresaron letras 'p'.");
	}

	//array de caracteres +1  para verificar que no ingrese mas de un caracter
	// strlen()

	return EXIT_SUCCESS;
}
