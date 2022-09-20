/*
 * borradorFunciones.c
 *
 *  Created on: 10 abr 2022
 *      Author: admin
 */

#include <stdio.h>
#include <stdlib.h>

int mainMenu(float km, float aerolineas, float latam)
{
	int opcionRetornada;
	printf("\n\n 1- Ingresar Kilómetros:( km = %.2f) \n 2- Ingresar precio de vuelos:(Aerolineas = %.2f, Latam = %.2f)"
			"\n 3- Calcular costos. \n 4- Informar resultados. \n 5- Carga forzada de datos. \n 6- Salir\n Opcion ingresada: ", km, aerolineas, latam);
	scanf("%d", &opcionRetornada);
	return opcionRetornada;
}

float ingresarFloat(int minimo, int maximo, char letra)
{
	float datoIngresado;


	if(letra == 'K')
	{
		printf("\nIngrese la distancia en kilometros: ");
	}
	else
	{
		if(letra == 'A')
		{
			printf("\nIngrese el precio de vuelo para la empresa Aerolineas: ");
		}
		else
		{
			printf("\nIngrese el precio de vuelo para la empresa Latam: ");
		}
	}
	scanf("%f", &datoIngresado);
	if(datoIngresado  < minimo || datoIngresado > maximo)
	{
		printf("\nError, reingrese el numero: ");
		scanf("%f", &datoIngresado);
	}

	return datoIngresado;
}

float operarPrecio(float precio, float porcentaje)
{
	float precioFinal;

	precioFinal = precio * porcentaje;
	return precioFinal;
}

float dividir(float dividendo, float divisor)
{
	float resultado;

	resultado = dividendo / divisor;
	return resultado;
}

float calcularDiferencia(float a, float b)
{
	float resultado;

	resultado = a - b;
	if(resultado < 0)
	{
		resultado = resultado * -1;
	}

	return resultado;
}

void mostrarAerolineas(float precio, float debito, float credito, float bitcoin, float precioUnitario)
{
	printf("Precio Aerolineas: $%.2f\na) Precio con tarjeta de debito: $ %.2f\nb) Precio con tarjeta de credito: $ %.2f\nc) Precio pagando con bitcoin: %.2f BTC\nd) Mostrar precio unitario: $ %.2f\n"
	, precio, debito, credito, bitcoin, precioUnitario);
}

void mostrarLatam(float precio, float debito, float credito, float bitcoin, float precioUnitario)
{
	printf("\nPrecio Latam: $%.2f\na) Precio con tarjeta de debito: $ %.2f\nb) Precio con tarjeta de credito: $ %.2f\nc) Precio pagando con bitcoin: %.2f BTC\nd) Mostrar precio unitario: $ %.2f\n"
		, precio, debito, credito, bitcoin, precioUnitario);
}
