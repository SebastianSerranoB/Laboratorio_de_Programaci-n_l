/*
 ============================================================================
 Name        : ejercicio2-3.c
 Author      : SEBASTIAN SERRANO
 DIVISION    : K



 Debemos alquilar el servicio de transporte para llegar a Mar del Plata con un grupo de personas, de cada persona debemos obtener los siguientes datos:
número de cliente,
estado civil ('s' para soltero", 'c' para casado o 'v' viudo),
edad( solo mayores de edad, más de 17),
temperatura corporal (validar por favor)
y genero('f' para femenino, 'm' para masculino, 'o' para no binario).
NOTA: El precio por pasajero es de $600.
Se debe informar (solo si corresponde):
a) La cantidad de personas con estado "viudo" de más de 60 años.
b) el número de cliente y edad de la mujer soltera más joven.
c) cuánto sale el viaje total sin descuento.
d) si hay más del 50% de los pasajeros que tiene más de 60 años , el precio final tiene un descuento del 25%, que solo mostramos si corresponde.

 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>


int main(void)
{
	setbuf(stdout, NULL);

	//valor del while
	char respuesta;

	//var de ingreso de datos
	char estadoCivil;
	char generoIngresado;
	int numeroClienteIngresado;
	int edadIngresada;
	float temperaturaIngresada;
	float precioPasaje;

	//vars para informar
	int edadMinimaMujer;
	int numeroClienteMujerJoven;
	int banderaMujerSolteraJoven;
	int contadorViudosMayores;
	int contadorMujeresSolteras;
	float acumuladorPrecios;
	int contadorPasajeros;
	int contadorMayores;
	float porcentajeMayores;
	float precioFinal;

	//contadores
	contadorViudosMayores = 0;
	contadorMujeresSolteras = 0;
	contadorPasajeros = 0;
	contadorMayores = 0;
	//acumuladores
	acumuladorPrecios = 0;
	//banderas
	banderaMujerSolteraJoven = 0;
	//constante
	precioPasaje = 600;

	respuesta = 's';
	while(respuesta == 's')
	{
		contadorPasajeros++;

		printf("\nIngrese el numero del cliente: ");
		scanf("%d", &numeroClienteIngresado);

		printf("\nIngrese el estado civil del individuo:  ");
		fflush(stdin);
		scanf("%c", &estadoCivil);
		while(estadoCivil != 's' && estadoCivil != 'v' && estadoCivil != 'c')
		{
			printf("Error, reingrese el estado civil: s, v o c. \n");
			fflush(stdin);
			scanf("%c", &estadoCivil);
		}
		printf("Ingrese el genero: \n");
		fflush(stdin);
		scanf("%c", &generoIngresado);
		while(generoIngresado != 'f' && generoIngresado != 'm' && generoIngresado != 'o')
		{
			printf("Error, reingrese el genero: s, f u o. \n");
			fflush(stdin);
			scanf("%c", &generoIngresado);
		}
		printf("\nIngrese la edad: ");
		scanf("%d", &edadIngresada);
		while(edadIngresada < 1 || edadIngresada > 150)
		{
			printf("\nError, reingrese la edad.");
			scanf("%d", &edadIngresada);
		}
		printf("\nIngrese la temperatura corporal: ");
		scanf("%f", &temperaturaIngresada);
		while(temperaturaIngresada < 25 || temperaturaIngresada > 45)
		{
			printf("Error, reingrese la temperatura: ");
			scanf("%f", &temperaturaIngresada);
		}

		//algoritmos para informar
		//a, viudos con mas de 60 años y cuento mayores de 60
		if(edadIngresada > 60)
		{
			contadorMayores++;
			if(estadoCivil == 'v')
			{
				contadorViudosMayores++;
			}
		}

		//b) el número de cliente y edad de la mujer soltera más joven.
		if(generoIngresado == 'f' && estadoCivil == 's')
		{
			if(edadIngresada < edadMinimaMujer || banderaMujerSolteraJoven == 0)
			{
				//mujerSolteraJoven = "La edad de la mujer soltera mas joven es: %d y el numero de cliente es: %d",edadMinimaMujer,numeroClienteMujerJoven;  COMO HACEMOS ESTE STRING? LO DECLARO COMO CHAR?COMILLAS?
				edadMinimaMujer = edadIngresada;
				numeroClienteMujerJoven = numeroClienteIngresado;
				banderaMujerSolteraJoven = 1;
				contadorMujeresSolteras++;

			}
		}
		//c) cuánto sale el viaje total sin descuento.
		acumuladorPrecios += precioPasaje;

		printf("\n¿Ingresara otro cliente: s o n? ");
		fflush(stdin);
		scanf("%c", &respuesta);
	}

	//informo cant. viudos mayores
	printf("La cantidad de viudos mayores de 60 es: %d\n",contadorViudosMayores);
	//b) el número de cliente y edad de la mujer soltera más joven.
	if(contadorMujeresSolteras > 0)
	{
		printf("La edad de la mujer soltera mas joven es: %d y el numero de cliente es: %d\n",edadMinimaMujer,numeroClienteMujerJoven);
	}
	else
	{
		printf("No se ingresaron mujeres solteras.\n");
	}

	//c) cuánto sale el viaje total sin descuento.
	//d) si hay más del 50% de los pasajeros que tiene más de 60 años , el precio final tiene un descuento del 25%, que solo mostramos si corresponde.
	/*if(contadorMayores > contadorPasajeros)   //ERROR SIMPLE DE LOGICA, EL CONTADOR DE PASAJEROS SIEMPRE SERA MAYOR AL DE MAYORES PUES LOS INCLUYE O COMO MINIMO ES IGUAL, LO CORRECTO SERIA HACER contadorMayores *100 / contadorPasajeros y eso ver si es mayor a 50% con un if y ahi hacer el descuento
	{
		precioFinal = acumuladorPrecios * 0.75;
		printf("El viaje total descontado es de: %f\n",precioFinal);
	}
	else
	{
		printf("\nEl viaje total sin descuento es de: %f",acumuladorPrecios);
	}*/


	porcentajeMayores = ((float)contadorMayores *100) / contadorPasajeros;
	printf("el porcentaje de mayores es de: %3.2f\n", porcentajeMayores); // para corroborar el porcentaje
	if(porcentajeMayores > 50)
	{
		precioFinal = acumuladorPrecios * 0.75;
		printf("El viaje total descontado es de: %5.2f\n",precioFinal);
	}
	else
	{
		printf("\nEl viaje total sin descuento es de: %5.2f",acumuladorPrecios);
	}

	return EXIT_SUCCESS;
}
