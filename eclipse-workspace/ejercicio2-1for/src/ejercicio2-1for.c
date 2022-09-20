/*Name        : ejercicio2-1.c ahora con for
 Author      : SEBASTIAN SERRANO
 Division	 : K1
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 Ejercicio 2-1: Ingresar 5 números enteros calcular y mostrar el promedio de los números. Probar la aplicación con distintos valores.*/

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	setbuf(stdout, NULL);

	int i;
	int nroIngresado;
	int acumuladorEnteros;
	float promedio;

	acumuladorEnteros = 0;

	for(i=0;i<5;i++)
	{
		printf("Ingrese cinco numeros enteros.\n");
		scanf("%d", &nroIngresado);
		acumuladorEnteros += nroIngresado;
	}

	promedio = (float)acumuladorEnteros / i;

	printf("\nEl promedio de todos los numeros es: %2f",promedio);
}
