/*
 ============================================================================
 Name        : tp-1borrador1-2.c
 Author      : SEBASTIAN SERRANO
 Version     : K-1
ENUNCIADO:
 Una agencia de viaje necesita calcular costos para sus vuelos de Latam y Aerolíneas Argentinas
para ofrecerlos a sus clientes.
Se deberá ingresar por cada vuelo los km totales y el precio total del mismo.
El objetivo de la aplicación es mostrar las diferentes opciones de pagos a sus clientes.
Para ello el programa iniciará y contará con un menú de opciones:
1. Ingresar Kilómetros: ( km=x)
2. Ingresar Precio de Vuelos: (Aerolíneas=y, Latam=z)
- Precio vuelo Aerolíneas:
- Precio vuelo Latam:
3. Calcular todos los costos:
a) Tarjeta de débito (descuento 10%)
b) Tarjeta de crédito (interés 25%)
c) Bitcoin (1BTC -> 4606954.55 Pesos Argentinos)
d) Mostrar precio por km (precio unitario)
e) Mostrar diferencia de precio ingresada (Latam - Aerolíneas)
4. Informar Resultados
“Latam:
a) Precio con tarjeta de débito: r
b) Precio con tarjeta de crédito: r
c) Precio pagando con bitcoin : r
d) Precio unitario: r
Aerolíneas:
a) Precio con tarjeta de débito: r
b) Precio con tarjeta de crédito: r
c) Precio pagando con bitcoin : r
d) Precio unitario: r
La diferencia de precio es : r “
5. Carga forzada de datos
Km: 7090
Aerolineas Argentinas: $162965
Latam: $ 159339
6. Salir
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "borradorFunciones.h"


int main(void)
{
	setbuf(stdout, NULL);
	int opcionIngresada;
	int kilometrosCargados, precioCargadoAerolineas, precioCargadoLatam;
	float kilometrosIngresados, precioIngresadoAerolineas, precioIngresadoLatam;
	float debitoAerolineas, creditoAerolineas, bitcoinAerolineas, precioUnitarioAerolineas;
	float debitoLatam, creditoLatam, bitcoinLatam, precioUnitarioLatam;
	float diferenciaDePrecios;
	float valorBitcoin, descuentoDebito, recargoCredito;
	int banderaCalculo, banderaIngresoPrecios;
	float kilometrosActual, precioAerolineasActual, precioLatamActual;

	kilometrosActual = 0, precioAerolineasActual = 0; precioLatamActual = 0;
	banderaCalculo = 0, banderaIngresoPrecios = 0;
	descuentoDebito = 0.9;
	recargoCredito = 1.25;
	valorBitcoin = 4606954.55;


	do
	{
		opcionIngresada = mainMenu(kilometrosActual, precioAerolineasActual, precioLatamActual);

		switch(opcionIngresada)
		{
			case 1:
				kilometrosIngresados = ingresarFloat(1, 1000000, 'K'); //"\nIngrese la distancia en kilometros: ", "\nError, reingrese los Kilometros: "); // EL PROBLEMA ESTA EN QUE NO PODEMOS MANDAR DOS CHARS, PORQUE PARA ESO NECEISTAMOS PUNTEROS!!!!!!!CON UNO CREO QUE SI ES POSIBLE, PERO UNO SOLO
				kilometrosActual = kilometrosIngresados;
				break;
			case 2:
				precioIngresadoAerolineas = ingresarFloat(1, 1000000, 'A'); //"\nIngrese el precio para la empresa Aerolineas: ", "\nError, reingrese el precio: ");
				precioAerolineasActual = precioIngresadoAerolineas;
				precioIngresadoLatam = ingresarFloat(1, 1000000, 'L'); // "\nIngrese el precio para la empresa Latam: ", "\nError, reingrese el precio: ");
				precioLatamActual = precioIngresadoLatam;
				banderaIngresoPrecios = 1;
				break;
			case 3:
				/*
				  	debito = precio*0.9;
					credito = precio*1.25;
					float valorBitcion = 4606954.55;
					bitcoin = precio /valorBitcoin;
					precioUnitario = precio/kmIngresados
					unsigned diferenciaDePrecios //estamos probando no sabemos si es correcto
					sino, se puede hacer un if si la diferencia da negativo, si es el caso multiplicas el resutlado
					 por -1, pasa que estamos viendo como ahorrarnos ese if
					diferenciaDePrecios = precioA - precioB;	*/
					if(kilometrosActual > 0 && banderaIngresoPrecios == 1)
					{
						 debitoAerolineas = operarPrecio(precioAerolineasActual, descuentoDebito);
						 creditoAerolineas = operarPrecio(precioAerolineasActual, recargoCredito);
						 bitcoinAerolineas = dividir(precioAerolineasActual, valorBitcoin);
						 precioUnitarioAerolineas = dividir(precioAerolineasActual, kilometrosIngresados);

						 debitoLatam = operarPrecio(precioLatamActual, descuentoDebito);
						 creditoLatam = operarPrecio(precioLatamActual, recargoCredito);
						 bitcoinLatam = dividir(precioLatamActual, valorBitcoin);
						 precioUnitarioLatam = dividir(precioLatamActual, kilometrosIngresados);

						 diferenciaDePrecios = calcularDiferencia(precioLatamActual, precioAerolineasActual);
						 banderaCalculo = 1;
					}
					else
					{
						printf("\nError, debe ingresar kilometros y precios antes de calcular tarifas.(Boton 1 y 2)");
					}
				break;
			case 4:
				if(banderaCalculo == 1)
				{
					printf("\nKMs Ingresados: %2f km\n\n", kilometrosActual);
					mostrarAerolineas(precioAerolineasActual, debitoAerolineas, creditoAerolineas, bitcoinAerolineas, precioUnitarioAerolineas);
					mostrarLatam(precioLatamActual, debitoLatam, creditoLatam, bitcoinLatam, precioUnitarioLatam);
					printf("\nLa diferencia de precio es: $ %2f\n", diferenciaDePrecios);
				}
				else
				{
					printf("Error, debe calcular los gastos previamente(boton 3).\n");
				}
				break;
			case 5:
				kilometrosCargados = 7090;
				kilometrosActual = kilometrosCargados;
				precioCargadoAerolineas= 162965;
				precioAerolineasActual = precioCargadoAerolineas;
				precioCargadoLatam = 159339;
				precioLatamActual = precioCargadoLatam;
				banderaIngresoPrecios = 1;
				break;
			case 6:
				printf("\nHas salido del menu.");
				break;
			default:
				printf("\nError, reingrese una opcion valida: ");
				break;
		}
	}while(opcionIngresada != 6);
	return EXIT_SUCCESS;
}

